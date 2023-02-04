cmake_minimum_required(VERSION 3.2)
add_library(Engine SHARED engine.hpp engine.cpp)
set_target_properties(Engine PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(logger)
target_link_libraries(Engine Logger)
