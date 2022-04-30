cmake_minimum_required(VERSION 3.22)
project(CLionTestProj)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLionTestProj main.cpp Board.cpp Board.h Cell.cpp Cell.h)
