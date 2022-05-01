#include"../include/Board.h"
#include <iostream>
#include <QApplication>
#include "QPushButton"


int main(int argc, char **argv) {

    QApplication app (argc, argv);

    QPushButton button("Hello World");
    button.show();

    return app.exec();
//    int cols = 11;
//    int rows = 11;
//
//    Board b = Board(rows, cols);
//
//    std::vector<int> p = {
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
//            0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
//            0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//
//    };
//
//    b.set_board(p);
//
//    while (true) {
//        print_board(b);
//        step(b);
//        std::cout << std::endl << "-----------" << std::endl;
//        char dummy = std::cin.get();
//        if (dummy == 'x') break;
////        std::cout << "print dummy: " << dummy << std::endl;
//    }
//    return 0;
}
