cmake_minimum_required(VERSION 3.26)
project(ECCFixerinC C)

set(CMAKE_C_STANDARD 23)
set(_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_FLAGS_DISTRIBUTION "-O3")

add_executable(ECCFixerinC main.c)
