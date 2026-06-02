cmake_minimum_required(VERSION 3.29)
project(cs480a1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cs480a1
    bots.cpp
    bots.hpp)
