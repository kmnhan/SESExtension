#pragma once

#include <memory>

class UIExtension_Library_P;

class UIExtension_Library
{
public:
  UIExtension_Library();
  ~UIExtension_Library();

  int initialize(void *mainWindow);
  void finalize();

  char *getLibInfo();
  char *getSpectrumInfo();

private:
  std::unique_ptr<UIExtension_Library_P> p_;
};
