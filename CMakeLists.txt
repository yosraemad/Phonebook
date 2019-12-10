cmake_minimum_required(VERSION 3.15)
project(Phonebook C)

set(CMAKE_C_STANDARD 99)

add_executable(Phonebook main.c validation.h useroptions.h useroptions.cpp useroptions.c io.c io.h models.h models.c)