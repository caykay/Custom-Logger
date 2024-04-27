#pragma once

#include <filesystem>
#include <string>

namespace log4cxx
{
class Logger;
}

using FilePath = std::filesystem::path;

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

void Test();

class ILogger
{
 public:
  ILogger();
  ILogger(const FilePath &configFilePath);

  bool Log(Level level, const std::string &message) const;
  // Sets the max log level for this logger
  void SetLevel(Level level);
  void SetPatternLayout(const std::string &patternLayout);

 private:
  bool ConfigureLogger(const FilePath &filePath);

  std::shared_ptr<log4cxx::Logger> m_logger;
  bool m_usingBasicConfig = false;
};
}  // namespace CKLogger
