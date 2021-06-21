CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(imp LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(imp src/main.cpp)

target_include_directories(imp PRIVATE src)
target_compile_options(imp PRIVATE -Weverything -Werror -std=c++20
  -Wno-c++98-compat
)
