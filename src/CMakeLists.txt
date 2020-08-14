# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

find_library(DL_LIB NAMES dl)
add_library(dl SHARED IMPORTED)
set_target_properties(dl PROPERTIES IMPORTED_LOCATION ${DL_LIB})

find_package(Threads REQUIRED)

add_library(sgxptrace SHARED ptrace.c inferior_status.c enclave_context.c)

target_link_libraries(sgxptrace dl Threads::Threads)

target_compile_options(sgxptrace PRIVATE -Wall -Werror -Wno-attributes
                                         -Wmissing-prototypes -m64)

# RTLD_NEXT requires _GNU_SOURCE to be defined.
target_compile_definitions(sgxptrace PRIVATE -DOE_BUILD_UNTRUSTED -D_GNU_SOURCE)

set_property(TARGET sgxptrace PROPERTY LIBRARY_OUTPUT_DIRECTORY
                                       ${PROJECT_BINARY_DIR})

