cmake_minimum_required(VERSION 3.15)
project(DoubleStar)

include_directories(C:/vs_libs/eigen-3.3.7)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoubleStar main.cpp Body.h Body.cpp MyTypedefs.h Solver.cpp Solver.h)