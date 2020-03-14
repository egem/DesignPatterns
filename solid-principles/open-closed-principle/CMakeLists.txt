cmake_minimum_required(VERSION 3.0)

project(Open-ClosedPrinciple)

set(EXE_NAME main)

add_executable(${EXE_NAME} main.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/shared)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core)
