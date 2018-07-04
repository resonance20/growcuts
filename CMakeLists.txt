cmake_minimum_required(VERSION 3.8)
project(growCuts)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES library.cpp library.h)
add_library(growCuts ${SOURCE_FILES})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(growCuts ${OpenCV_LIBS})