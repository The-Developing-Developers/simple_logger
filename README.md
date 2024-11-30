<!-- omit in toc -->
# Simple C++ Logger

- [Description](#description)
- [How to Use](#how-to-use)
  - [Copy the Files](#copy-the-files)
  - [CMake](#cmake)
- [Demo/Test Executable](#demotest-executable)
  - [Build Script](#build-script)


# Description

This repository contains a very simple C++ logger class that can be used to log messages to the console and/or to a file. The logger supports three log levels: `INFO`, `WARNING`, and `ERROR`. The log level can be set when creating the logger object.


# How to Use

This logger is a header-only library. You can either:
- Copy the `logger.h` and `logger.tpp` files to your project.
- Include this repository as a submodule of your project, and build with CMake.

In either case, you can use the logger by including the `logger.h` header file in your project, and creating a logger object using the `Logger` class. You can see the provided [test program](#demotest-executable) for an example of how to use the logger.


## Copy the Files

You just need to copy the `logger.h` and `logger.tpp` files to any directory in your project. Then, include the `logger.h` header file in your project where you want to use the logger. You can find the `logger.h` and `logger.tpp` files in the `include/logger` directory of this repository.


## CMake

This project includes a `CMakeLists.txt` file that can be used to include the logger as a dependency in your project.
To use the logger in your project, you can clone it as a submodule in your project, and include the logger's root `CMakeLists.txt` file in your project's `CMakeLists.txt` file. The logger's `CMakeLists.txt` file will automatically make itself available to your project, so that you can include it in your project's target.

Supposing you have cloned the logger repository as a submodule in the `external/logger` directory, you just need to include the following lines in your project's `CMakeLists.txt` file:

```CMake
add_subdirectory(external/logger)
target_link_libraries(your_target_name PRIVATE SimpleLogger)
```

- The `add_subdirectory(external/logger)` line should be added after defining the project and before defining any targets that depend on the logger.
- The `target_link_libraries(your_target_name PRIVATE SimpleLogger)` line should be added after defining the target that will use the logger.

Here is a simple example of how it should be structured:

```CMake
cmake_minimum_required(VERSION 3.12)
project(YourProjectName VERSION 1.0.0 LANGUAGES CXX)

# Add the logger subdirectory
add_subdirectory(external/logger)

# Define your target
add_executable(your_target_name main.cpp)

# Link the logger library to your target
target_link_libraries(your_target_name PRIVATE SimpleLogger)
```

# Demo/Test Executable

This repository includes a [test program](tests/main_tests.cpp) that demonstrates how to use the logger.

Building the test program is disabled by default, so that it does not create unnecessary artefacts in your project.

You can enable building the test program by setting the `BUILD_TEST` option to `ON` in your project's `CMakeLists.txt` file, or by passing the `-DBUILD_TEST=ON` option to the `cmake` command.

The executable will be created in the `build/tests` directory of the repository's subdirectory.


## Build Script

If you are just interested in building the test program, you can use the provided Python script. The script will compile the program and create an executable file under the `build/tests` directory. The test program will log messages to the console and to a file named `logfile.txt`.

The build script will autodetect the platform and use the appropriate build system generator. You can also specify the generator to use by passing the name of the generator.

**WARNING**: The Python script requires:
- **Python 3.8** or later.
- **CMake 3.12** or later.

Invoke the script from the root directory of the logger repository:
- Linux / MacOS:
  ```
  python3 ./scripts/build.py
  ```
- Windows:
  ```PowerShell
  python .\scripts\build.py
  ```

For example, if you wish to specify the generator to be used by CMake, you can pass the generator name as an argument to the script:
- Linux / MacOS:
  ```
  python3 ./scripts/build.py "Unix Makefiles"
  ```
- Windows:
  ```PowerShell
  python .\scripts\build.py "Visual Studio 16 2019"
  ```