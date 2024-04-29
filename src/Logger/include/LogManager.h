#pragma once

#include <map>

#include "Logger.h"

/*
 * TODO
 * 1. Handle both:
 *    - all logs being configured in a single file
 *    - logs configured in separate independent files
 * 2. Can use the .config extension. Perhaps we need to create a custom
 * configurator that allows for a few other possible extensions*/

namespace CKLogger
{
class LogManager
{
 public:
  using LogManagerPtr = LogManager *;
  using LogManagerRef = LogManager &;
  using LoggerMap = std::map<std::string, Logger::LoggerPtr>;
  // using LogManagerRef = LogManager *;

  ~LogManager();

  // TODO: add guards against getting an instance with a different config file
  // maybe have a separate static function for configuring the log manager
  // maybe we do not even need to call GetInstance publicly, all methods could
  // be static and GetInstance could be internal
  static LogManagerRef GetInstance(const std::string &logConfig = "");
  Logger::LoggerPtr GetRootLogger() const;
  Logger::LoggerPtr GetLogger(const std::string &name) const;

 private:
  LogManager(const std::string &logConfig = "");
  LogManager(LogManager &);
  void operator=(LogManager &);

  static LogManagerPtr m_instance;

  // loggers
  Logger::LoggerPtr rootLogger;
  LoggerMap loggers;
};
}  // namespace CKLogger
