<!-- omit in toc -->
# Simple C++ Logger

- [Description](#description)
- [How to Use](#how-to-use)
  - [General Steps](#general-steps)
  - [CMake](#cmake)
- [Test Executable (Example)](#test-executable-example)
  - [Description](#description-1)
  - [Test](#test)


# Description

This repository contains a simple C++ logger class that can be used to log messages to the console and/or to a file. The logger supports three log levels: `INFO`, `WARNING`, and `ERROR`. The log level can be set when creating the logger object.


# How to Use

## General Steps

- Include the `logger.h` header file anywhere in your project where you want to use the logger.
- Create a logger object using the `Logger` class.
- Optionally, you can pass to the constructor
  - A string with the name of the file where the logs will be written.
  - The log level (default is `INFO`).
- Use the `log` method to log messages to the console and/or to a file.
- Include the source file `logger.cpp` in your project's build system.

## CMake

This project includes a `CMakeLists.txt` file that can be used to build the logger as a static library. To use the logger in your project, you can include the logger library in your `CMakeLists.txt` file.

This is an example of how to include the logger library in your project, called `UserProject`. Suppose you have cloned the logger repository as a submodule in the `external/logger` directory:

```CMake
cmake_minimum_required(VERSION 3.12)
project(UserProject)

# Building the tests is disabled by default. Keep it OFF if you are importing the logger library to your project as a submodule.
set(BUILD_LOGGER_TESTS OFF)

# Add the submodule directory
add_subdirectory(external/logger)

# Specify the source files for the user's project
set(SOURCES main.cpp)

# Create an executable target for the user's project
add_executable(UserProject ${SOURCES})

# Link the logger library to the user's project
target_link_libraries(UserProject Logger)

# Add the logger directory to the include directories
target_include_directories(UserProject PRIVATE ${CMAKE_SOURCE_DIR}/external/logger)
```


# Test Executable (Example)

## Description

In the following example, a logger object is created with log level `WARNING`. Three messages are logged to the console and to a file named `log.txt`.

Only messages with log levels `WARNING` and `ERROR` will be logged to file. The message with log level `INFO` will be displayed only on the console, but not written to the file.

```cpp
#include "logger.h"

int main()
{
  Logger logger("log.txt", Logger::WARNING);
  logger.log(Logger::INFO, "This is an info message.");
  logger.log(Logger::DEBUG, "This is a debug message.");
  logger.log(Logger::ERROR, "This is an error message.");
  return 0;
}
```


## Test

You can build the example / test program using the provided `build.py` Python script. The script will compile the program and create an executable file under the `build` directory. The test program will log messages to the console and to a file named `logfile.txt`.

- Linux / MacOS:
  ```
  python3 ./scripts/build.py
  ```
- Windows:
  ```PowerShell
  python .\scripts\build.py
  ```