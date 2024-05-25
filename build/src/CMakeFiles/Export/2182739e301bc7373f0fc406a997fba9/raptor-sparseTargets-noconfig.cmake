#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "raptor::raptor-sparse" for configuration ""
set_property(TARGET raptor::raptor-sparse APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(raptor::raptor-sparse PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libraptor-sparse.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libraptor-sparse.dylib"
  )

list(APPEND _cmake_import_check_targets raptor::raptor-sparse )
list(APPEND _cmake_import_check_files_for_raptor::raptor-sparse "${_IMPORT_PREFIX}/lib/libraptor-sparse.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
