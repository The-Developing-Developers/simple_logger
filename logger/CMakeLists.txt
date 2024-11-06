cmake_minimum_required(VERSION 3.12)
project(Logger)

# Specify the source files
set(SOURCES logger.cpp)

# Specify the header files
set(HEADERS logger.h)

# Create a library target
add_library(Logger STATIC ${SOURCES} ${HEADERS})
