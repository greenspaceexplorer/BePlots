cmake_minimum_required(VERSION 3.23)

project(beplots VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${CMAKE_SOURCE_DIR}/include/BePlotsConfig.h.in BePlotsConfig.h)

add_executable(beplots ${CMAKE_SOURCE_DIR}/src/BePlots.cxx)

target_include_directories(beplots PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
    )

# Attempt to search for ROOT in /cern if ROOTSYS isn't defined, which could happen in some odd IDE environments.
if(DEFINED ENV{ROOTSYS})
    message("Found ROOTSYS at $ENV{ROOTSYS}")
    #list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS}) # enable searches your defined path.  Probably not needed.
else()
    message("ROOTSYS not found.  Searching in /cern.")
    message("  => This will match the first ROOT install it finds, which might not be what you want!")
    list(APPEND CMAKE_PREFIX_PATH /cern)     # enable searches in old-school cern paths
endif()
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})                # include if you need to capture ROOT compile options

target_link_libraries(beplots PUBLIC ROOT::Core ROOT::Physics ROOT::MathCore)
