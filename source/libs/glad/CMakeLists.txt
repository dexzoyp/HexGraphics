cmake_minimum_required(VERSION 3.2)
add_library(glad STATIC include/glad/glad.h include/KHR/khrplatform.h src/glad.c)
include_directories(include)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE CXX)
