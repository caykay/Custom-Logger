#include <Logger.h>

#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Hello World" << std::endl;
  // CKLogger::Test();
  // test basic console logger
  auto logger = CKLogger::ILogger();
  logger.Log(CKLogger::Level::INFO, "Basic Configurator works as expected");
  return 0;
}
