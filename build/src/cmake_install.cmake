# Install script for directory: /Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/gallery/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/util/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/lib/libraptor-sparse.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libraptor-sparse.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libraptor-sparse.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libraptor-sparse.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/raptor-sparse" TYPE FILE FILES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/raptor.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/raptor-sparse/core" TYPE FILE FILES
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/types.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/vector.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/matrix.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/utilities.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/mpi_types.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/topology.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/partition.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/comm_data.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/comm_pkg.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/par_vector.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/core/par_matrix.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/raptor-sparse/gallery" TYPE FILE FILES
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/diffusion.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/laplacian27pt.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/stencil.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/random.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/matrix_IO.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/matrix_market.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/par_stencil.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/par_random.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/par_matrix_IO.hpp"
    "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/par_matrix_market.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/raptor-sparse/util/linalg" TYPE FILE FILES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/util/linalg/repartition.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/raptor-sparse/raptor-sparseTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/raptor-sparse/raptor-sparseTargets.cmake"
         "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/CMakeFiles/Export/2182739e301bc7373f0fc406a997fba9/raptor-sparseTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/raptor-sparse/raptor-sparseTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/raptor-sparse/raptor-sparseTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/raptor-sparse" TYPE FILE FILES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/CMakeFiles/Export/2182739e301bc7373f0fc406a997fba9/raptor-sparseTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/raptor-sparse" TYPE FILE FILES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/CMakeFiles/Export/2182739e301bc7373f0fc406a997fba9/raptor-sparseTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/cmake/raptor-sparse/raptor-sparseConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/cmake/raptor-sparse" TYPE FILE FILES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/CMakeFiles/raptor-sparseConfig.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/core/tests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/util/tests/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/gallery/tests/cmake_install.cmake")
endif()

