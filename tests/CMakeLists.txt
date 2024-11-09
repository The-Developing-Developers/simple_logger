# Define the test executable
add_executable(SimpleLogger_Tests main_tests.cpp)

# Link the test executable to the header-only library
# This ensures that SimpleLogger's include path is added to the test executable
target_link_libraries(SimpleLogger_Tests INTERFACE SimpleLogger)

# Ensure that the include path for SimpleLogger is correctly propagated
target_include_directories(SimpleLogger_Tests PRIVATE ${PROJECT_SOURCE_DIR}/include/logger)

# # Add the test executable to the CTest framework
# Optionally, add the test executable to the CTest framework if needed
# add_test(NAME Test_1 COMMAND SimpleLogger_Tests)

