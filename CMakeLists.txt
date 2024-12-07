# Minimum CMake version
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(SimpleLogger VERSION 1.0.0 LANGUAGES CXX)

# When using target_link_libraries with an alias target, the INTERFACE_LINK_LIBRARIES of the aliased target are propagated to the alias
# target.
cmake_policy(SET CMP0079 NEW)

# Define the header-only library as an INTERFACE target. It does not produce any output. It is used to propagate usage requirements (such
# as include directories, compile options, and link libraries) to other targets that link against it.
add_library(${PROJECT_NAME} INTERFACE)

# Specify the include directory for the library as an INTERFACE target. Any project that links to this library will have this directory
# added to its include path.
target_include_directories(${PROJECT_NAME} INTERFACE
    ${PROJECT_SOURCE_DIR}/include
)

# Set C++ standard (optional, but recommended)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

# Option to build tests is OFF by default. You can override it by passing -DBUILD_TESTS=ON to CMake, or adding
# instruction `set(BUILD_TESTS ON)` in the parent `CMakeLists.txt`.
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    # enable_testing()
    add_subdirectory(tests)
endif()
