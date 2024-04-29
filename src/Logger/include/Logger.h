#pragma once

#include <memory>
#include <string>

namespace log4cxx
{
class Logger;
}

namespace CKLogger
{
// log levels in order of low to high priority)
enum class Level
{
  NONE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  FATAL
};

class LogManager;

class Logger
{
  // Only the LogManager can call a Logger Constructor
  friend class LogManager;

 protected:
  Logger(std::shared_ptr<log4cxx::Logger>);

 public:
  using LoggerPtr = std::shared_ptr<Logger>;

  bool Log(Level level, const std::string &message) const;

 private:
  std::shared_ptr<log4cxx::Logger> m_logger;

  bool m_usingBasicConfig = false;
};
}  // namespace CKLogger
