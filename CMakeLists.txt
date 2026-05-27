cmake_minimum_required(VERSION 4.2)
project(Collatz C)

set(CMAKE_C_STANDARD 99)

add_executable(Collatz main.c
        collatz_simple.c
        collatz_fast.c
        collatz.h
        options.h)
