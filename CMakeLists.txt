cmake_minimum_required(VERSION 3.5)

project(libcfxp)
add_compile_options(-std=c11 -Wall -Werror)

file(GLOB_RECURSE src src/cfxp/*.c)

add_library(lib_static STATIC ${src})
set_target_properties(lib_static PROPERTIES OUTPUT_NAME cfxp)
target_include_directories(lib_static PUBLIC src/)

add_executable(tests ${src} src/tests.c)
target_compile_options(tests PUBLIC -g)
target_include_directories(tests PUBLIC src/)

file(GLOB headers src/cfxp/*.h)
install(FILES ${headers} DESTINATION include/cfxp)
install(FILES build/libcfxp.a DESTINATION lib)
