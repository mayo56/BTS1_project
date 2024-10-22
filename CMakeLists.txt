cmake_minimum_required(VERSION 3.29)
project(convertisseur)

set(CMAKE_CXX_STANDARD 20)

add_executable(convertisseur
        main.cpp
        convertisseur.cpp
        colorize.cpp)
