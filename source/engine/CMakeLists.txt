cmake_minimum_required(VERSION 3.2)

list(APPEND ENGINE_SOURCE_FILES Engine.hpp Engine.cpp EntryPoint.hpp Core.hpp include/HexEngine.hpp)
set(ENGINE_LIBRARY_TYPE "SHARED")
add_library(${ENGINE_NAME} ${ENGINE_LIBRARY_TYPE} ${ENGINE_SOURCE_FILES})

set_target_properties(${ENGINE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${ENGINE_NAME} PROPERTIES PREFIX "")
add_subdirectory(libs)

target_link_libraries(${ENGINE_NAME} glfw)
target_link_libraries(${ENGINE_NAME} glad)
target_link_libraries(${ENGINE_NAME} glm)
target_link_libraries(${ENGINE_NAME} spdlog)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
target_link_libraries(${ENGINE_NAME} OpenGL::GL)

include_directories("libs/glfw/include")
include_directories("libs/glad/include")
include_directories("libs/glm/")
include_directories("libs/spdlog/include")
include_directories("libs/stb")
