cmake_minimum_required(VERSION 3.19)
project(21f_pa02_stv_and_miles)

set(CMAKE_CXX_STANDARD 14)

set(files src/main.cpp src/DSVector.h src/Data.h src/itr.h src/list.h src/AVLTree.h)

add_executable(21f_pa02_stv_and_miles ${files})
