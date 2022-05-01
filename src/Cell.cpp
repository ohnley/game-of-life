//
// Created by John Flatley on 4/28/22.
//

#include "../include/Cell.h"


Cell::Cell(int col, int row, bool alive) {
    _col = col;
    _row = row;
    _alive = alive;
}

bool Cell::is_alive() const {return _alive;}
void Cell::set_alive() {_alive = true;}
void Cell::set_dead() {_alive = false;}

std::vector<int> Cell::get_surrounding_cell_cords() const {
    return std::vector<int> {
        _col - 1, _row - 1,
        _col    , _row - 1,
        _col + 1, _row - 1,
        _col - 1, _row    ,
        _col + 1, _row    ,
        _col - 1, _row + 1,
        _col    , _row + 1,
        _col + 1, _row + 1
    };
}

bool operator== (const Cell& c1, const Cell& c2) {
    return (c1._col == c2._col) && (c1._row == c2._row);
}

std::ostream& operator<< (std::ostream& out, const Cell& c){
    out << "row: " << c.get_row() << " col: " << c.get_col() << " alive: " << c.is_alive();
    return out;
}

