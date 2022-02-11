cmake_minimum_required(VERSION 3.21)
project(clib C)

set(CMAKE_C_STANDARD 99)

add_executable(clib src/main.c hdrs/library.h src/library.c hdrs/tests.h src/tests.c)
