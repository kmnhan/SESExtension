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

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")


################################################################################
# Setup pybind11
################################################################################

set(ENV{UIEXT_CONDA_ENV} "$ENV{USERPROFILE}\\miniconda3\\envs\\erlab")
set(PYTHON_EXECUTABLE "$ENV{UIEXT_CONDA_ENV}\\python.exe")
set(ENV{PYTHONPATH} "$ENV{UIEXT_CONDA_ENV}\\Lib\\site-packages")

# target_compile_definitions(${PROJECT_NAME} PRIVATE -DCUSTOM_SYS_PATH="\"$ENV{HOME}/miniconda3/envs/erlab/Lib/site-packages\"")
add_subdirectory(pybind11)
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed)


if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "NOMINMAX;"
        "_WIN32;"
        "_WINDLL;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "NOMINMAX;"
        "_WIN32;"
        "_WINDLL;"
        "_MBCS"
    )
endif()

#[=========================================[ 
################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:NONE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:NONE
        )
    endif()
endif()

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
