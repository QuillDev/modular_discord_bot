cmake_minimum_required(VERSION 3.16)

project(discord_bot)

include_directories(include)

add_executable(discord_bot src/main.cpp src/DiscordBot.cpp)
target_link_libraries(discord_bot dl sleepy-discord)