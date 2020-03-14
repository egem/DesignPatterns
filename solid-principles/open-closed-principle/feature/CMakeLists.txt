set(folders)

ListSubDirs(folders ${CMAKE_CURRENT_SOURCE_DIR})

foreach(folder ${folders})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${folder})
endforeach(folder ${folders})
