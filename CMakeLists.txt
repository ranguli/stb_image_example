cmake_minimum_required(VERSION 3.16)
project(stb_image_example VERSION 0.1)

set(SOURCE_FILES main.c)

option(STB_IMAGE_IMPLEMENTATION "stb_image implementation" ON)

if(STB_IMAGE_IMPLEMENTATION)
    add_definitions(-DSTB_IMAGE_IMPLEMENTATION)
endif()

include_directories("lib/")
set(LIB_FILES "lib/stb_image.h" "lib/stb_image.c")

add_library(stb_static STATIC ${LIB_FILES})
target_link_libraries(stb_static m)
target_compile_definitions(stb_static PUBLIC LIBRARY_HEADER_ONLY)
set_target_properties(stb_static PROPERTIES LINKER_LANGUAGE C)

add_executable(stb_image_example ${SOURCE_FILES})
target_link_libraries(stb_image_example m)
