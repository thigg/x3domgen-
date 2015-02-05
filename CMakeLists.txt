cmake_minimum_required(VERSION 3.0)

project(x3dom_generator)

add_definitions(-std=c++0x -Wall -Werror=return-type)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE srcs src/*.c* src/*.h*)

add_library(x3dom_generator ${srcs})

target_include_directories (x3dom_generator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
