cmake_minimum_required(VERSION 3.16)
project(bye)

add_library(bye SHARED ModuleBye.cpp)
set_target_properties(bye PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../../../lib)
target_link_libraries(bye sleepy-discord)