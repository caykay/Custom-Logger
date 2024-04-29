#include "Logger.h"

#include <log4cxx/helpers/exception.h>
#include <log4cxx/logger.h>

#include <iostream>

namespace CKLogger
{
Logger::Logger(log4cxx::LoggerPtr logger)
{
  // use the basic configurator (logs using a console appender)
  m_logger = logger;
}

bool Logger::Log(Level level, const std::string& msg) const
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
  catch (log4cxx::helpers::Exception e)
  {
    return false;
  }
  return true;
}
}  // namespace CKLogger
