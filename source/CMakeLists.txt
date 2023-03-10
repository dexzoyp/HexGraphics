cmake_minimum_required(VERSION 3.2)
set(ENV{CMAKE_GENERATOR} "MinGW Makefiles")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS On)
set(PROJECT_DIR CMAKE_CURRENT_SOURCE_DIR)
set("CMAKE_BUILD_TYPE" "Debug" CACHE "STRING" "" FORCE)
set(CMAKE_BUILD_DIRECTORY "../build")
add_compile_options(-fPIC)
set(CMAKE_PROJECT_NAME HexGRAPHICS)

project(${CMAKE_PROJECT_NAME})
set(SOURCE_FILES application/Application.cpp)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

set(ENGINE_NAME "Engine" CACHE INTERNAL "")
add_subdirectory(engine)

target_link_libraries(${CMAKE_PROJECT_NAME} ${ENGINE_NAME})
include_directories("engine/include")

message("[${CMAKE_PROJECT_NAME}] Current build type is: ${CMAKE_BUILD_TYPE}")
set(TARGET_PLATFORM "")
if(WIN32)
    set(TARGET_PLATFORM "WIN32")
    install(FILES "${CMAKE_BINARY_DIR}/engine/HexEngine.dll" DESTINATION ${CMAKE_BINARY_DIR})
    message("[${CMAKE_PROJECT_NAME}] Current build is for ${TARGET_PLATFORM}")
elseif(UNIX AND NOT APPLE)
    set(TARGET_PLATFORM "LINUX")
    message("[${CMAKE_PROJECT_NAME}] Current build is for ${TARGET_PLATFORM}")
endif()
