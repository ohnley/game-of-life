#include "./Board.h"
#include <iostream>
#define REANIMATE_REQ 3

void print_board(Board& b){

    for (const std::vector<Cell>& row : b.get_board()){
        for (const Cell& c : row){
            if (c.is_alive()) std::cout << 'X' << ' ';
            else std::cout << '.' << ' ';
        }
        std::cout << '\n';
    }
}

void step(Board& b){
    std::unordered_set<Cell, CellHash> cells_to_kill;
    std::unordered_set<Cell, CellHash> cells_to_reanimate;

    for (Cell c : b.get_living_cells()){
        int neighbors_alive = 0;
        for (Cell neighbor : b.get_surrounding_cells(c)) {
            if (neighbor.is_alive()) neighbors_alive++;
            else {
                if (!(cells_to_reanimate.count(neighbor))){
                    if (b.get_num_living_neighbors(neighbor) == REANIMATE_REQ){
                        cells_to_reanimate.insert(neighbor);
                    }
                }
            }
        }
        if (!(neighbors_alive == 3 || neighbors_alive == 2)){
            cells_to_kill.insert(c);
        }
    }

    for (Cell kill : cells_to_kill){
//        std::cout << "killing x: " << kill.get_col() << " row: " << kill.get_row() << std::endl;
        b.kill_cell(kill);
    }
    for (Cell reanimate : cells_to_reanimate){
        b.reanimate_cell(reanimate);
    }
}


int main() {

    int cols = 11;
    int rows = 11;

    Board b = Board(rows, cols);

    std::vector<int> p = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    };

    b.set_board(p);

    while (true) {
        print_board(b);
        step(b);
        std::cout << std::endl << "-----------" << std::endl;
        char dummy = std::cin.get();
        if (dummy == 'x') break;
//        std::cout << "print dummy: " << dummy << std::endl;
    }
    return 0;
}
