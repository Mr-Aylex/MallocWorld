cmake_minimum_required(VERSION 3.20)
project(MallocWorld C)

set(CMAKE_C_STANDARD 11)

add_executable(MallocWorld
        src/inventory.c
        src/itemMap.c
        src/map.c
        src/game.c
        main.c
        )
