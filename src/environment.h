#pragma once

#include <string>

namespace sc
{
  namespace system
  {
    std::string getenv(const std::string &name);
    void putenv(const std::string &name, const std::string &value = std::string());
    void clearenv(const std::string &name);
    std::string getApplicationDir();
  }
}