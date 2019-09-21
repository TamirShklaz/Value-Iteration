cmake_minimum_required(VERSION 3.14)
project(As5)

set(CMAKE_CXX_STANDARD 14)

add_executable(As5 main.cpp State.cpp State.h Action.cpp Action.h)