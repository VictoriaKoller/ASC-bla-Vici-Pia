cmake_minimum_required(VERSION 3.20)

set( CMAKE_CXX_COMPILER "C:\\msys64\\ucrt64\\bin\\g++.exe" )
set( CMAKE_C_COMPILER "C:\\msys64\\ucrt64\\bin\\gcc.exe" )
project(ASC_bla)

set (CMAKE_CXX_STANDARD 17)

include_directories(src)


find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)

execute_process(
  COMMAND "${Python_EXECUTABLE}" -m pybind11 --cmakedir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE PYBIND11_DIR)
list(APPEND CMAKE_PREFIX_PATH "${PYBIND11_DIR}")
find_package(pybind11 CONFIG REQUIRED)


add_subdirectory (demos)


pybind11_add_module(bla src/bind_bla.cpp)

install (TARGETS bla DESTINATION ASCsoft)
install (FILES src/vector.hpp DESTINATION ASCsoft/include)


