# SESExtension
Custom user interface to SES.

# Disclaimer
This user interface has not been tested with real analyzers. Use at your own risk.

# Building
## Setup build environment
- Install latest [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/) or install [MinGW-w64](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain).
- Install cmake & git
    ```bash
    winget install -e --id Kitware.CMake
    winget install --id Git.Git -e --source winget
    ```
- Clone and setup vcpkg
    ```bash
    git clone https://github.com/kmnhan/SESExtension.git
    cd SESExtension
    .\vcpkg\bootstrap-vcpkg.bat
    .\vcpkg\vcpkg install cppzmq
    ```
- Install cppzmq
    ```bash
    .\vcpkg\vcpkg install cppzmq
    ```
