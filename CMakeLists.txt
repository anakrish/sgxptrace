# Copyright (c) Open Enclave SDK contributors. Licensed under the MIT License.

# Version 3.1 required for CMAKE_CXX_STANDARD
cmake_minimum_required(VERSION 3.1)

# Set CMAKE_BUILD_TYPE if not specified
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif ()

if (NOT ";Debug;RelWithDebInfo;Release;" MATCHES ";${CMAKE_BUILD_TYPE};")
  message(
    FATAL_ERROR "CMAKE_BUILD_TYPE must be Debug, RelWithDebInfo or Release")
endif ()

project(sgxptrace)

add_subdirectory(src)
