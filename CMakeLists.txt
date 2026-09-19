cmake_minimum_required(VERSION 3.20)

project(MyDB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyDB
    main.cpp
    src/table.cpp
    include/mydb/user.h
    include/mydb/table.h
)

target_include_directories(MyDB PRIVATE include)
