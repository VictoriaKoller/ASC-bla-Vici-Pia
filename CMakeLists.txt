cmake_minimum_required(VERSION 3.20)

set( CMAKE_CXX_COMPILER "C:\\msys64\\ucrt64\\bin\\g++.exe" )
set( CMAKE_C_COMPILER "C:\\msys64\\ucrt64\\bin\\gcc.exe" )
project(ASC_bla)

set (CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory (demos)






