cmake_minimum_required(VERSION 3.20)
project(sortYSearch)

set(CMAKE_CXX_STANDARD 14)

add_executable(sortYSearch main.cpp
        sorts.cpp
        sorts.h
        search.cpp
        search.h
        otrosAlgoritmos.cpp
        otrosAlgoritmos.h)
