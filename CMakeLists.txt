cmake_minimum_required(VERSION 3.26)
project(warcaby_project)

set(CMAKE_CXX_STANDARD 17)

include_directories(warcaby)
add_subdirectory(warcaby)

add_subdirectory(Google_tests)