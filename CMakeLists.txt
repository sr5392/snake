cmake_minimum_required(VERSION 3.28)
project(snake)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib REQUIRED)

add_executable(
        snake
        main.cpp
        src/snake.cpp
        src/game.cpp
        src/renderer.cpp
        src/food.cpp
)

target_include_directories(snake PRIVATE include)
target_link_libraries(snake PRIVATE raylib)
