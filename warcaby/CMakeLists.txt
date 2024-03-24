cmake_minimum_required(VERSION 3.26)
project(warcaby)

set(CMAKE_CXX_STANDARD 17)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(warcaby main.cpp
        core/timer.cpp
        core/timer.h
        core/engine.cpp
        core/engine.h
        entities/player.cpp
        entities/player.h
        entities/board.cpp
        entities/board.h
        entities/pawn.cpp
        entities/pawn.h
        helpers/load_res.cpp
        helpers/load_res.h
        helpers/calculate.cpp
        helpers/calculate.h
        helpers/calculate.h
        helpers/formatter.cpp
        helpers/formatter.h
        helpers/draw_helper.cpp
        helpers/draw_helper.h
)

add_library(warcaby_lib STATIC
        core/timer.cpp
        core/timer.h
        core/engine.cpp
        core/engine.h
        entities/player.cpp
        entities/player.h
        entities/board.cpp
        entities/board.h
        entities/pawn.cpp
        entities/pawn.h
        helpers/load_res.cpp
        helpers/load_res.h
        helpers/calculate.cpp
        helpers/calculate.h
        helpers/calculate.h
        helpers/formatter.cpp
        helpers/formatter.h
        helpers/draw_helper.cpp
        helpers/draw_helper.h
)

target_link_libraries(warcaby_lib PRIVATE sfml-graphics)
target_compile_features(warcaby_lib PRIVATE cxx_std_17)
target_link_libraries(warcaby PRIVATE sfml-graphics)
target_compile_features(warcaby PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET warcaby
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:warcaby>
            VERBATIM)
endif()

install(TARGETS warcaby)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(warcaby PRIVATE gtest gtest_main)
target_link_libraries(warcaby_lib PRIVATE gtest gtest_main)