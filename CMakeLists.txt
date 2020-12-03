cmake_minimum_required(VERSION 3.17)
project(game)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)


add_executable(game main.cpp Window.h Window.cpp Game.h Game.cpp)

target_link_libraries(game sfml-graphics sfml-audio)