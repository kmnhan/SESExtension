set(PROJECT_NAME UIExtension_Library)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "cexports.def"
)
source_group("" FILES ${no_group_source_files})

set(Headers
    "environment.h"
    "uiextension_library.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "cexports.cpp"
    "environment.cpp"
    "uiextension_library.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${no_group_source_files}
    ${Headers}
    ${Sources}
)



################################################################################
# Target
################################################################################
set(ROOT_NAMESPACE UIExtension_Library)

add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

################################################################################
# Setup pybind11
################################################################################

set(ENV{UIEXT_CONDA_ENV} "$ENV{USERPROFILE}\\miniconda3\\envs\\erlab")
set(PYTHON_EXECUTABLE "$ENV{UIEXT_CONDA_ENV}\\python.exe")
set(ENV{PYTHONPATH} "$ENV{UIEXT_CONDA_ENV}\\Lib\\site-packages")

target_compile_definitions(${PROJECT_NAME} PRIVATE -DCUSTOM_SYS_PATH="\"$ENV{HOME}/miniconda3/envs/erlab/Lib/site-packages\"")
add_subdirectory(pybind11)
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed -lstdc++fs)

#[=========================================[ 
################################################################################
# Post build events
################################################################################


if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    add_custom_command_if(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMANDS
        COMMAND   $<CONFIG:Debug> copy /Y $<SHELL_PATH:${OUTPUT_DIRECTORY}>${TARGET_NAME}$ENV{TargetExt} D:\\prereleases\\tmp\\SES1.6.1_Win64_Package\\SES_1.6.1_Win64\\dll\\UserInterfaces\\Manipulator
        COMMAND $<CONFIG:Release> copy /Y $<SHELL_PATH:${OUTPUT_DIRECTORY}>${TARGET_NAME}$ENV{TargetExt} D:\\prereleases\\tmp\\SES1.6.1_Win64_Package\\SES_1.6.1_Win64\\dll\\UserInterfaces\\Manipulator
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    add_custom_command_if(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMANDS
        COMMAND   $<CONFIG:Debug> copy /Y $<SHELL_PATH:${OUTPUT_DIRECTORY}>${TARGET_NAME}$ENV{TargetExt} D:\\prereleases\\tmp\\SES1.6.1_Win64_Package\\SES_1.6.1_Win64\\dll\\UserInterfaces\\Manipulator
        COMMAND $<CONFIG:Release> copy /Y $<SHELL_PATH:${OUTPUT_DIRECTORY}>${TARGET_NAME}$ENV{TargetExt} D:\\prereleases\\tmp\\SES1.6.1_Win64_Package\\SES_1.6.1_Win64\\dll\\UserInterfaces\\Manipulator
    )
endif()
]=========================================]
