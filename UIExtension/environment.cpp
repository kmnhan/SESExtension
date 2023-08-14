#include "environment.h"

#include <windows.h>

namespace sc
{
  namespace system
  {
    std::string getenv(const std::string& variable)
    {
      std::string buffer;
      DWORD size = GetEnvironmentVariable(variable.c_str(), NULL, 0);
      if (size > 0)
      {
        buffer.resize(size);
        size = GetEnvironmentVariable(variable.c_str(), const_cast<char*>(buffer.data()), size);
        buffer.resize(size - 1);
      }
      return buffer;
    }

    void putenv(const std::string & name, const std::string &value)
    {
      SetEnvironmentVariable(name.c_str(), value.c_str());
    }

    void clearenv(const std::string & name)
    {
      SetEnvironmentVariable(name.c_str(), NULL);
    }

    std::string getApplicationDir()
    {
      std::string buffer;
      buffer.resize(MAX_PATH);
      DWORD size = GetModuleFileName(NULL, const_cast<char*>(buffer.data()), static_cast<DWORD>(buffer.size()));
      buffer.resize(size > 0 ? size - 1 : 0);
      if (buffer.back() != '\\' && buffer.back() != '/')
      {
        size_t pos = buffer.find_last_of('\\');
        if (pos == std::string::npos)
          pos = buffer.find_last_of('/');
        buffer = buffer.substr(0, pos);
      }
      return buffer;
    }
  }
}
