cmake_minimum_required(VERSION 3.0)

project(Open-ClosedPrinciple)

set(EXE_NAME main)

add_executable(${EXE_NAME} main.cpp)

set(folders)

ListSubDirs(folders ${CMAKE_CURRENT_SOURCE_DIR})

foreach(folder ${folders})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${folder})
endforeach(folder ${folders})
