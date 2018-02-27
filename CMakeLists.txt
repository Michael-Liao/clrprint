# TOP
cmake_minimum_required(VERSION 3.0)

#project name
project(clrprint)
subdirs(include src)

IF(CMAKE_BUILD_TYPE STREQUAL Debug)
  add_definitions(-DDEBUG)
ENDIF()
