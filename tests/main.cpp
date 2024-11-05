#include "logger.h"

int main(void)
{
  // Create a logger instance with a log file and a minimum log level of INFO
  Logger logger("logfile.txt", Logger::LogLevel::INFO);

  // Log messages with different severity levels
  logger.log("This is an info message.", Logger::LogLevel::INFO);
  logger.log("This is a warning message.", Logger::LogLevel::WARNING);
  logger.log("This is an error message.", Logger::LogLevel::ERROR);
  logger.log("This is a max priority message.", Logger::LogLevel::MAX_PRIORITY);

  // Create another logger instance without a log file
  Logger consoleLogger;
  consoleLogger.log("This message is logged to the console only.", Logger::LogLevel::INFO);

  return 0;
}