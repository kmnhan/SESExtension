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
    "clients.h"
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
# Setup pybind11
################################################################################
# set(PYTHON_EXECUTABLE "C:\\Program Files\\Python311\\python.exe")
# add_subdirectory(pybind11)
# find_package(Python3 COMPONENTS Interpreter Development)

################################################################################
# Target
################################################################################
set(ROOT_NAMESPACE UIExtension_Library)

find_package(cppzmq REQUIRED)

add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} cppzmq)

# zmqclient is for test purposes 

# add_executable(zmqclient zmqclient.cpp)
# target_link_libraries(zmqclient cppzmq)