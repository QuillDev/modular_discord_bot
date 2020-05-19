cmake_minimum_required(VERSION 3.16)
project(hello)

add_library(hello SHARED ModuleHello.cpp)
set_target_properties(hello PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../../../lib)
target_link_libraries(hello sleepy-discord)