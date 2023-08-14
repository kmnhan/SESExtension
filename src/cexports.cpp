#include "uiextension_library.h"

#include <Windows.h>

namespace
{
  static UIExtension_Library gMono;
}

extern "C"
{
  int __stdcall GDS_UI_Initialize(HWND mainWindow)
  {
    return gMono.initialize(mainWindow);
  }

  void __stdcall GDS_UI_Finalize()
  {
    gMono.finalize();
  }

  const char *__stdcall GDS_UI_GetLibInfo()
  {
    return gMono.getLibInfo();
  }

  const char *__stdcall GDS_UI_GetSpectrumInfo()
  {
    return gMono.getSpectrumInfo();
  }
}
