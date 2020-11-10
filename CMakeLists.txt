cmake_minimum_required(VERSION 3.16)
project(searchEngine)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)
add_subdirectory(loadData)
add_subdirectory(lib/CWebServer)
SET(CMAKE_CXX_FLAGS -pthread)
