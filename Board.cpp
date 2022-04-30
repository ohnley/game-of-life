//
// Created by John Flatley on 4/28/22.
//
#include <utility>
#include <vector>
#include "./Board.h"

// Constructors
Board::Board(int number_of_rows, int number_of_cols) :
    _num_rows(number_of_rows), _num_cols(number_of_cols){}

Board::Board(int number_of_rows, int number_of_cols, std::vector<std::vector<Cell>> board) :
    _num_rows(number_of_rows), _num_cols(number_of_cols), _board(std::move(board)) {}


// Getters
int Board::get_num_cols() const {return _num_cols;}
int Board::get_num_rows() const {return _num_rows;}
std::vector<std::vector<Cell>> Board::get_board() const {return _board;}
const std::unordered_set<Cell, CellHash>& Board::get_living_cells() const { return alive_cells;}

std::vector<Cell> Board::get_surrounding_cells(Cell& c) const{

    std::vector<int> neighbor_coords = c.get_surrounding_cell_cords();
    std::vector<Cell> neighbors;

    for (int i = 0; i < neighbor_coords.size(); i+=2){

        int col = neighbor_coords[i];
        int row = neighbor_coords[i+1];

        // check the coordinates are in range
        if (row < _num_rows && row >= 0 && col < _num_cols && col >= 0) {
            neighbors.push_back(_board[row][col]);
        }
    }
    return neighbors;
}

int Board::get_num_living_neighbors(Cell& c) const {
    std::vector<Cell> neighbors = this->get_surrounding_cells(c);

    int living = 0;
    for (Cell& n : neighbors){
        if (n.is_alive()) living++;
    }
    return living;
}

// setters
void Board::set_num_rows(int rows) { _num_rows = rows; }
void Board::set_num_cols(int cols) {_num_cols = cols;}

void Board::set_board(std::vector<std::vector<int>>& layout){
    std::vector<std::vector<Cell>> board;

    for (int row_num = 0; row_num < board.size(); row_num++) {
        std::vector<Cell> new_row;
        for (int col_num = 0; col_num < board.size(); col_num++) {
            bool alive = (layout[row_num][col_num] == 0);
            Cell c = Cell(col_num, row_num, alive);
            alive_cells.insert(c);
            new_row.emplace_back(c);
        }
        board.emplace_back(new_row);
    }
    _board = board;
}

void Board::set_board(std::vector<int>& layout) {

    if (layout.size() % _num_cols != 0 || layout.empty()){
        throw std::invalid_argument("argument 'layout' length must be a non-zero multiple of _width");
    }

    std::vector<std::vector<Cell>> board;
    std::vector<Cell> row;

    for (int i = 0; i < layout.size();) {
        Cell c = Cell(i%_num_cols, (int) i/_num_cols, (layout[i]==1));
        row.emplace_back(c);
        if (c.is_alive()) alive_cells.insert(c);
        i++;
        if (i%_num_cols == 0 && i > 0){
            board.emplace_back(row);
            row.clear();
        }
    }

    _board = board;
    this->set_num_rows((int) _board.size());
}

void Board::kill_cell(Cell c) {
    _board[c.get_row()][c.get_col()].set_dead();
    alive_cells.erase(c);
}

void Board::reanimate_cell(Cell c) {
    _board[c.get_row()][c.get_col()].set_alive();
    alive_cells.insert(c);
}

std::ostream& operator<< (std::ostream& out, const Board& b) {
    out << "num cols: " << b.get_num_cols() << " num rows: " << b.get_num_rows();
    return out;
}


