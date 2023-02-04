cmake_minimum_required(VERSION 3.2)
set(ENV{CMAKE_GENERATOR} "MinGW Makefiles")
set(PROJECT_NAME cmakeLearn)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS On)
set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_DIR CMAKE_CURRENT_SOURCE_DIR)
project(PROJECT_NAME)
set(SOURCE_FILES main.cpp)
add_executable(PROJECT_NAME ${SOURCE_FILES})

add_subdirectory(engine)
target_link_libraries(PROJECT_NAME Engine)
include_directories("engine")

add_subdirectory(libs/glfw)
target_link_libraries(PROJECT_NAME glfw)
include_directories("libs/glfw/include")

add_subdirectory(libs/glad)
target_link_libraries(PROJECT_NAME glad)
include_directories("libs/glad/include")

add_subdirectory(libs/glm)
target_link_libraries(PROJECT_NAME glm)
include_directories("libs/glm/")

find_package(OpenGL REQUIRED)
target_link_libraries(PROJECT_NAME OpenGL::GL)

add_subdirectory(sandbox)

