cmake_minimum_required(VERSION 3.2)
file(GLOB LOGGER_SOURCE_FILES
       include/spdlog/*.h
       include/spdlog/details/*.h
       include/spdlog/sinks/*.h
       include/spdlog/cfg/*.h
       include/spdlog/fmt/*.h)
add_library(spdlog STATIC ${LOGGER_SOURCE_FILES})
include_directories(include)
set_target_properties(spdlog PROPERTIES LINKER_LANGUAGE CXX)
