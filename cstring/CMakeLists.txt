cmake_minimum_required(VERSION 3.16)

project(CString VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wconversion -fsanitize=leak")

add_subdirectory(tests)

add_executable(Main src/main.cpp)