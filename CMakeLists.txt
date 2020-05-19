cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(discord_bot_with_modules)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_subdirectory(external/sleepy-discord)
add_subdirectory(modules)

set(CMAKE_POSITION_INDEPENDENT_CODE OFF)
add_subdirectory(discord_bot)
