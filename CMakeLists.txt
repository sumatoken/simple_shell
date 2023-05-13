cmake_minimum_required(VERSION 3.0)
project(hsh)

file(GLOB SOURCES "*.c")

add_executable(hsh ${SOURCES})

target_compile_options(hsh PRIVATE -Wall -Werror -Wextra -pedantic)
set_property(TARGET hsh PROPERTY C_STANDARD 90)