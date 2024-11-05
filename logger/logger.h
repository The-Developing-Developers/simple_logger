/**
 * @file logger.h
 *
 * @brief Public interface of the Logger class.
 **/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

/**
 * @class Logger
 * @brief A simple logging class to log messages to a file and the console.
 *
 * The `Logger` class provides functionality to log messages with different severity levels (`INFO`, `WARNING`, `ERROR`). \n
 * Pass a file name to the constructor to create a log file. The log file is opened in append mode. \n
 * Pass a log level to the constructor to set the minimum log level to log to file. \n
 */
class Logger
{
public:
  /**
   * @enum LogLevel
   * @brief Defines the severity levels for logging.
   */
  enum class LogLevel
  {
    INFO,
    WARNING,
    ERROR,
    MAX_PRIORITY, // Messages that are not errors or warnings, but must still be logged to file

    HOW_MANY // Number of log levels
  };

  /**
   * @brief Constructs a Logger object.
   *
   * @param filename The optional name of the log file.
   * @param logLevel The optional minimum log level to log to file.
   */
  explicit Logger(const std::string& filename = "", LogLevel logLevel = LogLevel::INFO);

  /**
   * @brief Destroys the Logger object and closes the log file.
   */
  ~Logger();

  /**
   * @brief Logs a message with the specified severity level.
   *
   * @param message The message to log.
   * @param level The severity level of the message (default is `LogLevel::INFO`).
   */
  void log(const std::string& message, LogLevel level = LogLevel::INFO);

private:
  std::ofstream m_logfile; // Logs are written to this file
  LogLevel m_currentLogLevel; // Determines the minimum log level to log to file
  size_t m_instanceNumber; // Unique identifier for each instance of the Logger class
  static size_t g_logMessageCount; // Global counter to count the number of log messages

  std::string getLogLevelString(LogLevel level) const;
  std::string getCurrentTimestamp() const;
};

#endif // LOGGER_H