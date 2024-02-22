# SESExtension

Custom user interface to SES.

This library only provides the bare minimum for writing custom header entries to data saved by SES. See `cexports.def`. On calling `GDS_UI_GetSpectrumInfo`, the library attempts connection to a zmq server of socket type `REP` with a hardcoded port number and gets the header entries as a string. If the server is not running or has become unresponsive, SES will hang on saving data. The zmq client is implemented in `clients.h`. Most of the code in this library has been adapted from the monochromator and manipulator library examples provided by Scienta Omicron.

## Disclaimer

This user interface has not been tested with real analyzers. Use at your own risk.

## Getting Started

### Setup build environment

- Install latest [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/) or install [MinGW-w64](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain).
- Install cmake & git

    ```bash
    winget install -e --id Kitware.CMake
    winget install --id Git.Git -e --source winget
    ```

- Clone and setup vcpkg

    ```bash
    git clone --recurse-submodules https://github.com/kmnhan/SESExtension.git
    cd SESExtension
    .\vcpkg\bootstrap-vcpkg.bat
    .\vcpkg\vcpkg install cppzmq
    ```

- Install cppzmq

    ```bash
    .\vcpkg\vcpkg install cppzmq
    ```

### Building

Build with an appropriate compiler that matches the operating system of the data acquisition computer.

### Installing

Setup according to the SES documentation. Note that the `.dll` file for the `libzmq` library (generated on build) must be in the same directory with `UIExtension_Library.dll`.
