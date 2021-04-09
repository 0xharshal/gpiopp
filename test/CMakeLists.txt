cmake_minimum_required(VERSION 3.0.0)
project(gpiopp_test VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(../)
add_executable(gpiopp_test main.cpp)
target_link_libraries(gpiopp_test gpiopp)
