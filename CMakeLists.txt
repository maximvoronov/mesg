cmake_minimum_required(VERSION 3.0)

project(mesg LANGUAGES C)

add_executable(mesg main.c)

install(TARGETS mesg RUNTIME DESTINATION bin)
