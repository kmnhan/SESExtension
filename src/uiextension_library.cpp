#include "uiextension_library.h"
#include "environment.h"
#include "clients.h"

#include <Windows.h>
#include <iostream>
#include <string>

class UIExtension_Library_P
{
public:
  UIExtension_Library_P()
  {
    sesBaseDir_ = sc::system::getenv("SES_BASE_DIR");
    if (sesBaseDir_.empty())
      sesBaseDir_ = sc::system::getApplicationDir();
  }

  ~UIExtension_Library_P()
  {
  }

  int initialize(HWND mainWindow)
  {
    mainWindow_ = mainWindow;
    return 0;
  }

  void finalize()
  {
  }

  char *getLibInfo()
  {
    std::string out = "UIExtension_Library 2.0.0";
    char *cstr = new char[out.length() + 1];
    strcpy(cstr, out.c_str());
    return cstr;
  }

  char *getSpectrumInfo()
  {
    std::string specInfo = "";
    specInfo += attrs_client::info();
    char *cstr = new char[specInfo.length() + 1];
    strcpy(cstr, specInfo.c_str());
    return cstr;
  }

private:
  HWND mainWindow_ = nullptr;
  std::string sesBaseDir_;
};

UIExtension_Library::UIExtension_Library() : p_(new UIExtension_Library_P) {}
UIExtension_Library::~UIExtension_Library() {}

int UIExtension_Library::initialize(void *mainWindow)
{
  return p_->initialize((HWND)mainWindow);
}

void UIExtension_Library::finalize()
{
  p_->finalize();
}

char *UIExtension_Library::getLibInfo()
{
  return p_->getLibInfo();
}

char *UIExtension_Library::getSpectrumInfo()
{
  return p_->getSpectrumInfo();
}
