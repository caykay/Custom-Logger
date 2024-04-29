#include <LogManager.h>

#include <iostream>

int main(int argc, char *argv[])
{
  // CKLogger::Test();
  // test basic console logger
  auto logger =
      CKLogger::LogManager::GetInstance("/config/file.log.xml").GetRootLogger();
  logger->Log(CKLogger::Level::INFO, "Basic Configurator works as expected");
  return 0;
}
