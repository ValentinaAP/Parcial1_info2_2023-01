cmake_minimum_required(VERSION 3.5)

project(codigo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(codigo main.cpp)

install(TARGETS codigo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
