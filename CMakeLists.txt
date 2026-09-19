cmake_minimum_required(VERSION 3.20)

project(MyDB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(raw_table_example
    examples/raw_table/main.cpp
    examples/raw_table/src/table.cpp
    examples/raw_table/include/mydb/user.h
    examples/raw_table/include/mydb/table.h
)

target_include_directories(raw_table_example PRIVATE
    examples/raw_table/include
)
