#include <stdexcept>

class FileNotFoundException : public std::runtime_error
{
 public:
  FileNotFoundException(const std::string& message)
      : std::runtime_error(message)
  {
  }
};
