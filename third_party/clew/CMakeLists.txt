add_library(extern_clew ${SRC} src/clew.c)
target_include_directories(extern_clew PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_compile_definitions(extern_clew PRIVATE
	-DCL_USE_DEPRECATED_OPENCL_1_1_APIS
)
