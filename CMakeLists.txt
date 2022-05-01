cmake_minimum_required(VERSION 3.22)
project(CLionTestProj)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/Users/flatley/Qt/6.2.4/macos/lib/cmake")

find_package(Qt6Widgets REQUIRED)


add_executable(CLionTestProj
        src/main.cpp
        src/Board.cpp
        include/Board.h
        src/Cell.cpp
        include/Cell.h src/game_helper.cpp include/game_helper.h)

target_link_libraries(CLionTestProj Qt6::Widgets)