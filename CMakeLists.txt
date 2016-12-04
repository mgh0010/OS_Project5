cmake_minimum_required(VERSION 3.6)
project(OS_Project5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES address.cpp address.h vm_sim.cpp)
add_executable(OS_Project5 ${SOURCE_FILES})
