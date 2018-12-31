cmake_minimum_required (VERSION 3.9.0)
project (BsZenLib)

# Add necessary compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
   CMAKE_CXX_COMPILER_ID MATCHES "AppleClang" OR
   CMAKE_CXX_COMPILER_ID MATCHES "GNU")
   # This is what the example file does, is this really needed at a global scale?
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -g")
endif()

# Make sure to use the C++14 standard
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

###############################################################################
#                            Add external libraries                           #
###############################################################################

# Let CMake know where to find the Findbsf.cmake file (at current folder)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

# Find bsf libraries and headers
find_package(bsf REQUIRED)

add_subdirectory(lib/ZenLib)

###############################################################################
#                               Add main library                              #
###############################################################################
add_library(BsZenLib
  src/ImportStaticMesh.cpp
  src/ImportTexture.cpp
  src/ImportZEN.cpp
  )

target_link_libraries(BsZenLib PRIVATE bsf zenload vdfs utils)
target_include_directories(BsZenLib PRIVATE include/BsZenLib)

target_link_libraries(BsZenLib PUBLIC vdfs)
target_include_directories(BsZenLib PUBLIC include)

###############################################################################
#                               Add Samples, etc                              #
###############################################################################
add_subdirectory(samples)