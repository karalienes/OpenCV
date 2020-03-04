cmake_minimum_required(VERSION 3.14)
project(odevcalsma)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)


add_executable(odevcalsma main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(odevcalsma ${OpenCV_LIBS})