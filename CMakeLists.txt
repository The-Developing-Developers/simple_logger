cmake_minimum_required(VERSION 3.12)
project(LoggerProject)

# Option to build tests. Keep it OFF if you are including this project as a submodule, and therefore likely not interested in building the tests.
option(BUILD_LOGGER_TESTS "Build the tests" OFF)

# Add the logger subdirectory
add_subdirectory(logger)

# Optionally, add the tests subdirectory if BUILD_TESTS is ON
if(BUILD_LOGGER_TESTS)
    add_subdirectory(tests)
endif()