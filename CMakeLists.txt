cmake_minimum_required(VERSION 3.6)
project(monitory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread ")

set(SOURCE_FILES main.cpp monitor.h szybki.h zwykly.h zwykly.cpp szybki.cpp)
add_executable(monitory ${SOURCE_FILES})