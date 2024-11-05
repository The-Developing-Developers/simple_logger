<!-- omit in toc -->
# Simple C++ Logger

- [Description](#description)
- [How to Use](#how-to-use)
- [Example](#example)
- [Test](#test)


# Description

This repository contains a simple C++ logger class that can be used to log messages to the console and/or to a file. The logger supports three log levels: `INFO`, `WARNING`, and `ERROR`. The log level can be set when creating the logger object.


# How to Use

- Include the `logger.h` header file anywhere in your project where you want to use the logger.
- Create a logger object using the `Logger` class.
- Optionally, you can pass to the constructor
  - A string with the name of the file where the logs will be written.
  - The log level (default is `INFO`).
- Use the `log` method to log messages to the console and/or to a file.
- Include the source file `logger.cpp` in your project's build system.


# Example

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


# Test

You can build the test using the provided `build.py` Python script. The script will compile the test program (TODO: and run it). The test program will log messages to the console and to a file named `logfile.txt`.
