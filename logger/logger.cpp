#include "Logger.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>

static size_t g_instanceNumber = 0; // Each instance of Logger gets a unique incrementing number
size_t Logger::g_logMessageCount = 0; // Global counter to count the number of log messages and print them as line numbers in the log file

Logger::Logger(const std::string& filename, LogLevel logLevel)
  : m_currentLogLevel(logLevel)
  , m_instanceNumber(++g_instanceNumber) // Each instance of Logger gets a unique incrementing number
{
  // Only print to file if a filename was provided and the file was opened successfully
  if (!filename.empty())
  {
    m_logfile.open(filename, std::ios::app);

    if (!m_logfile.is_open())
    {
      std::cerr << "Failed to open log file '" << filename << "'!" << std::endl;
    }
    else
    {
      std::cout << "Successfully opened log file '" << filename << "' in append mode." << std::endl;
      std::cout << "Logger " << m_instanceNumber << " started with log level " << getLogLevelString(m_currentLogLevel) << ".\n" << std::endl;
    }
  }
  else
  {
    std::cout << "Logger " << m_instanceNumber << " started without a log file.\n" << std::endl;
  }
}

Logger::~Logger()
{
  if (m_logfile.is_open())
  {
    this->log("Logger stopped.", LogLevel::MAX_PRIORITY); // Log a message with the maximum priority before closing the log file, so that it is always logged
    std::cout << "Closing log file..." << std::endl;
    m_logfile.close();
  }
}

void Logger::log(const std::string& message, LogLevel const level)
{
  ++g_logMessageCount; // Each log message gets a unique incrementing number

  // Compose log message with timestamp and log level
  std::string const levelStr  = getLogLevelString(level);
  std::string const timestamp = getCurrentTimestamp();

  std::ostringstream logMessage;
  logMessage << "[logger " << m_instanceNumber << "] ["
             << std::setw(3) << g_logMessageCount
             << std::setw(0) // Reset width to default
             << "] [" << timestamp << "] ["
             << std::setw(4) << levelStr
             << std::setw(0)
             << "] " << message;

  // Log to console
  std::cout << logMessage.str() << std::endl;

  // Log to file if the log level is equal or greater than the current log level
  if (m_logfile.is_open() && level >= m_currentLogLevel)
  {
    m_logfile << logMessage.str() << std::endl;
  }
}

/**
 * @brief Converts the `LogLevel` enum to a string representation.
 *
 * @param level The `LogLevel` to convert.
 * @return A string representation of the `LogLevel`.
 */
std::string Logger::getLogLevelString(LogLevel const level) const
{
  switch (level)
  {
    case LogLevel::INFO:          return "INFO";
    case LogLevel::WARNING:       return "WARN";
    case LogLevel::ERROR:         return "ERRR";
    case LogLevel::MAX_PRIORITY:  return "MAXP";
    default:                      return "UNKN";
  }
}

/**
 * @brief Gets the current timestamp as a string.
 *
 * @return The current timestamp in a string format.
 */
std::string Logger::getCurrentTimestamp(void) const
{
  auto now        = std::chrono::system_clock::now();
  auto in_time_t  = std::chrono::system_clock::to_time_t(now); // Convert to a C-style time type
  std::ostringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X"); // 'put_time' is a manipulator that formats the time, while 'localtime' converts the time to local time. '%Y-%m-%d %X' formats a date and time string in the form YYYY-MM-DD HH:MM:SS
  return ss.str();
}
