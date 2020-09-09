add_library(extern_cuew STATIC src/cuew.c)
target_include_directories(extern_cuew PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
