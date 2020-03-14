MACRO(ImportModule ModuleName)
    cmake_minimum_required(VERSION 3.0)

    project(${ModuleName})

    aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRCS)

    target_sources(${EXE_NAME} PUBLIC ${SRCS})
    target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
ENDMACRO()


