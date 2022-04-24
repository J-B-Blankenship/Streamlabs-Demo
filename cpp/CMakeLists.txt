# The following is an example CMakeLists.txt that demonstrates
# individual components available in CMake that can be combined
# in greater depth as necessary. CMake tutorial online is an
# okay resource.

# Basics, Assume at the top directory
cmake_minimum_required(VERSION 3.18.4)

project(Example VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

configure_file(Example.h.in Example.h)

add_subdirectory(SomeLibrary)

add_executable(Example example.cpp)

target_link_libraries(Example PUBLIC SomeLibrary)

target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}
    )

##############################

# Dynamic Library, Assume in that directory of the library
add_library(SomeLibrary 
    SomeFile.cpp)

# Static Library
add_library(SomeLibrary STATIC
    SomeFile.cpp)

set(installable_libs SomeLibrary)
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES SomeLibrary.h DESTINATION include)

##############################

# Add options
option(USE_SOMELIBRARY "Use some library implemented" ON)
configure_file(SomeFile.h.in SomeFile.h) #Not sure what the .in is

# Options at top level
if(USE_SOMELIBRARY)
    add_subdirectory(SomeLibrary)
    list(APPEND EXTRA_LIBS SomeLibrary)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/SomeLibrary")
endif()

add_executable(Example Example.cpp)

target_link_libraries(Example PUBLIC ${EXTRA_LIBS})

target_include_directories(Example PUBLIC
    "${PROJECT_BINARY_DIR}"
    ${EXTRA_INCLUDES}
    )

# In cpp files
#ifdef USE_SOMELIBRARY
    include "SomeLibrary.h"
#endif

# In SomeLibrary.h.in
#cmakedefine USE_SOMELIBRARY

##############################

# Adding Custom Command and Generated files
add_executable(SomeCommand SomeCommand.cpp)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/SomeCommandOutput.h
    COMMAND SomeCommand ${CMAKE_CURRENT_BINARY_DIR}/SomeCommandOutput.h
    DEPENDS SomeCommand
)

# In library
add_library(SomeLibrary
    SomeLibrary.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/SomeCommandOutput.h
    )

target_include_directories(SomeLibrary
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    )

##############################

# Set compile time options for a specific target
target_compile_options(SomeTarget PRIVATE -options)
target_link_options(SomeTarget PRIVATE -options)
