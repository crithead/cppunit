cmake_minimum_required(VERSION 3.0)
project(CppUnitExample
    VERSION 1.0.2
    LANGUAGES CXX
)

set(GCC_CXX_FLAGS "-Wall -Wextra -Wpedantic -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_CXX_FLAGS}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(game
    src/gamemain.cpp
    src/item.cpp
    src/player.cpp
)

add_executable(test
    src/testmain.cpp
    src/item.cpp
    src/itemtest.cpp
    src/player.cpp
    src/playertest.cpp
)

target_link_libraries(test cppunit)

install(TARGETS game DESTINATION games)

