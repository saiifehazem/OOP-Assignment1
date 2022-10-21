cmake_minimum_required(VERSION 3.23)
project(Task1_BigDecimalInt_Program)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task1_BigDecimalInt_Program
        BigDecimalInt.cpp
        BigDecimalInt.h
        main.cpp)
