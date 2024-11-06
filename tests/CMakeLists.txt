cmake_minimum_required(VERSION 3.12)
project(LoggerTests)

# The logger directory is already added in the main CMakeLists.txt file

# Specify the test source files
set(TEST_SOURCES main.cpp)

# Create an executable target for the tests
add_executable(LoggerTests ${TEST_SOURCES})

# Link the logger library to the test executable
target_link_libraries(LoggerTests Logger)

# Add the logger directory to the include directories
target_include_directories(LoggerTests PRIVATE ${CMAKE_SOURCE_DIR}/logger)