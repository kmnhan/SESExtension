#include "uiextension_library.h"
#include "environment.h"

#include <Windows.h>

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

  char* getLibInfo()
  {
    return "UIExtension_Library 1.0.0-beta.1";
  }

  char* getSpectrumInfo()
  {
      return "Test Spectrum Info=12345\nanother Spectrum Info=this is a string\nthe last one=hmm";
  }


private:
  HWND mainWindow_ = nullptr;
  std::string sesBaseDir_;
};

UIExtension_Library::UIExtension_Library()
  : p_(new UIExtension_Library_P)
{
}

UIExtension_Library::~UIExtension_Library()
{
}

int UIExtension_Library::initialize(void* mainWindow)
{
  return p_->initialize((HWND)mainWindow);
}

void UIExtension_Library::finalize()
{
  p_->finalize();
}

char * UIExtension_Library::getLibInfo()
{
  return p_->getLibInfo();
}

char* UIExtension_Library::getSpectrumInfo()
{
    return p_->getSpectrumInfo();
}
