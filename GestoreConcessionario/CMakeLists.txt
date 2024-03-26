cmake_minimum_required(VERSION 3.26)
project(GestoreConcessionario)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestoreConcessionario main.cpp
        Macchina.h
        Macchina.cpp)
