cmake_minimum_required(VERSION 3.14)
project(odev)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(odev main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(odev ${OpenCV_LIBS})