set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
add_executable(${BINARY}_load ${SOURCES} ../src/DataBaseReader/Reader.cpp ../src/DataBaseReader/Reader.h ../src/DataBaseReader/Website.h ../src/DataBaseReader/Website.cpp ../src/Socket/ClientSock.cpp  ../src/Socket/ClientSock.h)
add_library(${BINARY}_libr STATIC ${SOURCES} main.cpp)
