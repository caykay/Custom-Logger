#pragma once

#include <string>

namespace CKLogger::Utils
{
std::string GetCurrentWorkingDir();
std::string GetAbsolutePath(const std::string &path);
bool PathExists(std::string path, int amode = 0);
}  // namespace CKLogger::Utils
