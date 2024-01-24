cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "- CAD -") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(${SRC_DIR}/qt_occ_draw)
# add_subdirectory(${SRC_DIR}/oce-upstream-V7_5_0beta)
# add_subdirectory(${SRC_DIR}/libdxfrw)

















