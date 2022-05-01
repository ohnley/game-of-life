
#include "../include/Board.h"
#include <iostream>

const int REANIMATE_REQ = 3;
const int UNDERPOP_THRESH = 2;
const int OVERPOP_THRESH = 3;

namespace game_of_life_logic {
    void print_board(Board &b) {

        for (const std::vector<Cell> &row: b.get_board()) {
            for (const Cell &c: row) {
                if (c.is_alive()) std::cout << 'X' << ' ';
                else std::cout << '.' << ' ';
            }
            std::cout << '\n';
        }
    }

    void step(Board &b) {
        std::unordered_set<Cell, CellHash> cells_to_kill;
        std::unordered_set<Cell, CellHash> cells_to_reanimate;

        for (Cell c: b.get_living_cells()) {
            int neighbors_alive = 0;
            for (Cell neighbor: b.get_surrounding_cells(c)) {
                if (neighbor.is_alive()) neighbors_alive++;
                else {
                    if (!(cells_to_reanimate.count(neighbor))) {
                        if (b.get_num_living_neighbors(neighbor) == REANIMATE_REQ) {
                            cells_to_reanimate.insert(neighbor);
                        }
                    }
                }
            }
            if (!(neighbors_alive >= UNDERPOP_THRESH && neighbors_alive <= OVERPOP_THRESH)) {
                cells_to_kill.insert(c);
            }
        }

        for (Cell kill: cells_to_kill) {
            b.kill_cell(kill);
        }
        for (Cell reanimate: cells_to_reanimate) {
            b.reanimate_cell(reanimate);
        }
    }
}
