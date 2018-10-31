cmake_minimum_required(VERSION 3.12)
project(pfce_intersection)

set(CMAKE_CXX_STANDARD 14)

add_executable(pfce_intersection main.cpp Segment.cpp Segment.h)