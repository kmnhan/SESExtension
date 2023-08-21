cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_TOOLCHAIN_FILE C:/vcpkg/scripts/buildsystems/vcpkg.cmake)
project(UIExtension_Library)
# set(CMAKE_CXX_STANDARD 11)


################################################################################
# Sub-projects
################################################################################
add_subdirectory(src)