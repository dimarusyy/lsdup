cmake_minimum_required(VERSION 3.14)

include(cmake/dependencies.cmake)

set(LSDUP_BINARY_NAME "lsdup")
set(LSDUP_BINARY_VERSION "1.0.0")

project(lsdup 
		LANGUAGES CXX
		VERSION ${LSDUP_BINARY_VERSION})

#enable verbose makefiles
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(tests)