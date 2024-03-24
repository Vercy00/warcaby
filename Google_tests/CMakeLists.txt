cmake_minimum_required(VERSION 3.26)
project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run core/engine_tests.cpp
        entities/board_tests.cpp
        helpers/calculate_tests.cpp
        helpers/formatter_tests.cpp
        helpers/load_res_tests.cpp
)

target_link_libraries(Google_Tests_run sfml-graphics)
target_link_libraries(Google_Tests_run warcaby_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)