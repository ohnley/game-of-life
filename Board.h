//
// Created by John Flatley on 4/28/22.
//

#ifndef CLIONTESTPROJ_BOARD_H
#define CLIONTESTPROJ_BOARD_H

#include <vector>
#include <unordered_set>
#include "./Cell.h"
#include <ostream>



class Board {
    public:

        Board(int number_of_rows, int number_of_columns);
        Board(int number_of_rows, int number_of_columns, std::vector<std::vector<Cell>> board);

        // Getters
        int get_num_cols() const;
        int get_num_rows() const;
        std::vector<std::vector<Cell>> get_board() const;
        const std::unordered_set<Cell, CellHash>& get_living_cells() const;
        std::vector<Cell> get_surrounding_cells(Cell& c) const;
        int get_num_living_neighbors(Cell& c) const;

        // Setters
        void kill_cell(Cell c);
        void reanimate_cell(Cell c);
        void set_board(std::vector<std::vector<int>>& layout);
        void set_board(std::vector<int>& layout);
        void set_num_rows(int rows);
        void set_num_cols(int cols);

    private:
        int _num_cols;
        int _num_rows;
        std::unordered_set<Cell, CellHash> alive_cells;
        std::vector<std::vector<Cell>> _board;
};

std::ostream& operator<< (std::ostream& out, const Board& b);
#endif //CLIONTESTPROJ_BOARD_H
