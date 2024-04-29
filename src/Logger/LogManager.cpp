#include "LogManager.h"

#include <log4cxx/defaultconfigurator.h>
#include <log4cxx/file.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/helpers/loglog.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/xml/domconfigurator.h>

#include <sstream>

#include "Utils.h"

namespace
{
}  // namespace

namespace CKLogger
{
using Log4cxxLogManager = log4cxx::LogManager;

LogManager::LogManagerPtr LogManager::m_instance = nullptr;

LogManager::LogManager(const std::string &config)
{
  log4cxx::helpers::LogLog::setInternalDebugging(true);
  log4cxx::helpers::LogLog::debug("cwd: " + Utils::GetCurrentWorkingDir());
  auto path = Utils::GetAbsolutePath(config);
  log4cxx::helpers::LogLog::debug("Absolute Path: " + path);

  log4cxx::File file(path);
  log4cxx::helpers::Pool p;
  if (file.exists(p))
  {
    log4cxx::DefaultConfigurator::setConfigurationFileName(file.getPath());
    // log4cxx::xml::DOMConfigurator::configure(file.getPath());
  }
  else
  {
    std::ostringstream os;
    os << "Invalid file path: ";
    os << (config.empty() ? "empty" : file.getPath()) << std::endl;
    os << "Please use a Default Logger";
    throw log4cxx::helpers::IllegalArgumentException(os.str());
  }
}

LogManager::~LogManager() { delete m_instance; }

LogManager::LogManagerRef LogManager::GetInstance(const std::string &config)
{
  if (!m_instance)
  {
    m_instance = new LogManager(config);
  }

  return *m_instance;
}

Logger::LoggerPtr LogManager::GetRootLogger() const
{
  return std::shared_ptr<Logger>(
      new Logger(Log4cxxLogManager::getRootLogger()));
}

Logger::LoggerPtr LogManager::GetLogger(const std::string &name) const
{
  if (name.empty() || !log4cxx::LogManager::exists(name))
  {
    std::ostringstream os;
    os << "Could not find a Logger with name: ";
    os << name;
    throw log4cxx::helpers::IllegalArgumentException(os.str());
  }
  return std::shared_ptr<Logger>(
      new Logger(Log4cxxLogManager::getLogger(name)));
}
}  // namespace CKLogger
