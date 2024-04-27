#include "Logger.h"

#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/xml/domconfigurator.h>
#include <mach-o/dyld.h>

#include <iostream>

using namespace log4cxx;

namespace
{
const int MAX_CHAR = 256;
}

namespace CKLogger
{
void Test()
{
  std::cout << "something works" << std::endl;
  char excPath[MAX_CHAR + 1];
  uint32_t bufferSize = sizeof excPath;
  int res = _NSGetExecutablePath(excPath, &bufferSize);
  switch (res)
  {
    case 0:
      std::cout << "Success, executable path: " << excPath
                << ", buffer size: " << bufferSize << std::endl;
      break;
    case -1:
      std::cout << "buffer size too small: " << sizeof excPath << std::endl;
      std::cout << "required buffer size: " << bufferSize << std::endl;
      break;
    default:
      break;
  }
}

ILogger::ILogger() : m_usingBasicConfig(true)
{
  // use the basic configurator (logs using a console appender)
  BasicConfigurator::configure();
  m_logger = log4cxx::Logger::getRootLogger();
}

ILogger::ILogger(const FilePath& configFilePath)
{
  ConfigureLogger(configFilePath);
  m_logger = log4cxx::Logger::getRootLogger();
}

bool ILogger::Log(Level level, const std::string& msg) const
{
  try
  {
    switch (level)
    {
      case Level::INFO:
        m_logger->info(msg);
        break;
      case Level::DEBUG:
        m_logger->debug(msg);
        break;
      case Level::WARNING:
        m_logger->warn(msg);
        break;
      case Level::ERROR:
        m_logger->error(msg);
        break;
      case Level::FATAL:
        m_logger->fatal(msg);
        break;
      case Level::NONE:
        break;
    }
  }
  catch (helpers::Exception e)
  {
    return false;
  }
  return true;
}

void ILogger::SetLevel(Level lvl) {}

void ILogger::SetPatternLayout(const std::string& pattern)
{
  if (m_usingBasicConfig)
  {
  }
  else
  {
  }
}

bool ILogger::ConfigureLogger(const FilePath& filePath)
{
  const spi::ConfigurationStatus status =
      xml::DOMConfigurator::configure(filePath.string());
  return status == spi::ConfigurationStatus::Configured;
}
}  // namespace CKLogger
