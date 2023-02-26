cmake_minimum_required(VERSION 3.2)
file(GLOB STB_IMAGE_SOURCE_FILES stb_image.h)
add_library(stb_image STATIC ${STB_IMAGE_SOURCE_FILES})
set_target_properties(stb_image PROPERTIES LINKER_LANGUAGE CXX)
