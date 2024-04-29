#include <_types/_uint32_t.h>
#include <mach-o/dyld.h>
#include <unistd.h>

#include <sstream>

// TODO use macros to check for what libraries to use for some utilities
// perhaps all utility functions should be extracted to a separate utility
// namespace
#include "Utils.h"
#include "exceptions.h"

namespace CKLogger::Utils
{
const int MAX_BUFF_COUNT = 1028;

inline char separator()
{
#ifdef _WIN32
  return '\\';
#else
  return '/';
#endif
}

// TODO: cross-platform, also conside getcwd() from unistd.h
std::string GetCurrentWorkingDir()
{
  char buffRef[MAX_BUFF_COUNT];
  uint32_t buffSize = sizeof buffRef;

  if (_NSGetExecutablePath(buffRef, &buffSize) != 0)
  {
    std::ostringstream os;
    os << "Could not get current working directory, ";
    os << "At function: " << __PRETTY_FUNCTION__;
    os << ", Line: " << __LINE__ << std::endl;
    throw FileNotFoundException(os.str());
  }
  std::string s(buffRef);
  auto sepIndex = s.rfind(separator());
  if (sepIndex != std::string::npos)
  {
    return s.substr(0, sepIndex);
  }
  return s;
}

std::string GetAbsolutePath(const std::string &path)
{
  auto sep = separator();
  std::string rel = path;
  auto cwd = GetCurrentWorkingDir();

  // clean up leading separator if it exists
  if (!rel.empty() && rel[0] == sep)
  {
    rel = rel.substr(1);
  }

  rel = GetCurrentWorkingDir() + sep + rel;
  return rel;
}

bool PathExists(std::string path, int amode)
{
  return access(path.c_str(), amode) == 0;
}

// not relative or could be that the path does not exists
// bool IsPathRelative(const std::string &path) { return path[0] != separator();
// }
}  // namespace CKLogger::Utils
