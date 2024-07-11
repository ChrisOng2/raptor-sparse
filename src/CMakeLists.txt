add_subdirectory(core)
add_subdirectory(gallery)
add_subdirectory(util)


set(sparse_HEADERS
    ${core_HEADERS}
    ${gallery_HEADERS}
    ${ext_gallery_HEADERS}
    ${util_HEADERS}
    PARENT_SCOPE
)

set(sparse_SOURCES
    ${core_SOURCES}
    ${gallery_SOURCES}
    ${util_SOURCES}
    PARENT_SCOPE
)

add_library(raptor-sparse ${core_SOURCES} ${core_HEADERS} 
	${gallery_SOURCES} ${gallery_HEADERS} ${ext_gallery_HEADERS} 
	${util_SOURCES} ${util_HEADERS}
    )
target_link_libraries(raptor-sparse PUBLIC ${MPI_C_LIBRARIES} ${METIS_LIBRARIES} 
    ${PTSCOTCH_LIBRARIES} ${PARMETIS_LIBRARIES} ${EXTERNAL_LIBS})

target_include_directories(raptor-sparse
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
)

include(GNUInstallDirs)
install(TARGETS raptor-sparse
    EXPORT raptor-sparseTargets
  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES raptor.hpp DESTINATION "include/raptor-sparse")
install(FILES ${core_HEADERS} DESTINATION "include/raptor-sparse/core")
install(FILES ${gallery_HEADERS}  DESTINATION "include/raptor-sparse/gallery")
install(FILES ${util_HEADERS} DESTINATION "include/raptor-sparse/util/linalg")
install(EXPORT raptor-sparseTargets
    FILE raptor-sparseTargets.cmake
  NAMESPACE "raptor::"
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/raptor-sparse)
export(EXPORT raptor-sparseTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/raptor-sparseTargets.cmake
  NAMESPACE "raptor::")
export(PACKAGE raptor-sparse)

configure_file(${PROJECT_SOURCE_DIR}/config/raptor-sparseConfig.cmake.in
    ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/raptor-sparseConfig.cmake @ONLY)

install(
    FILES ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/raptor-sparseConfig.cmake
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/raptor-sparse)

if(ENABLE_UNIT_TESTS)
    add_subdirectory(core/tests)
    add_subdirectory(util/tests)
    add_subdirectory(gallery/tests)
endif()
