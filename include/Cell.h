//
// Created by John Flatley on 4/28/22.
//

#ifndef CLIONTESTPROJ_CELL_H
#define CLIONTESTPROJ_CELL_H

#include <vector>
#include <ostream>

class Cell {
    private:
        int _col;
        int _row;
        bool _alive;

    public:
        Cell(int col, int row, bool alive);
        friend bool operator== (const Cell& c1, const Cell& c2);
        int get_row() const {return _row;}
        int get_col() const {return _col;}
        bool is_alive() const;
        std::vector<int> get_surrounding_cell_cords() const;

        void set_dead();
        void set_alive();
};

class CellHash {
    public:
        size_t operator() (const Cell& c) const {
            size_t h1 = std::hash<int>{}(c.get_col());
            size_t h2 = std::hash<int>{}(c.get_row());
            return h1 ^ (h2 << 1);
        }
};


std::ostream& operator<< (std::ostream& out, const Cell& c);


#endif //CLIONTESTPROJ_CELL_H
