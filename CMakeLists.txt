# Minimum CMake version
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(SimpleLogger VERSION 1.0.0 LANGUAGES CXX)

# Suppress CMP0079 policy warning
cmake_policy(SET CMP0079 NEW)

# Define the header-only library as an INTERFACE target. It does not produce any output.
add_library(${PROJECT_NAME} INTERFACE)

# Specify the include directory for the library as an INTERFACE target. Any project that links to this library will have this directory
# added to its include path.
target_include_directories(${PROJECT_NAME} INTERFACE
    ${PROJECT_SOURCE_DIR}/include
)

# Set C++ standard (optional, but recommended)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

# Add the tests directory if tests are enabled
option(ENABLE_TESTS "Build tests for SimpleLogger" ON)

if(ENABLE_TESTS)
    # enable_testing()
    add_subdirectory(tests)
endif()
