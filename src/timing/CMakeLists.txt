# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called gallery_SOURCES containing all .cpp files:
if (WITH_MPI)
    set(timing_HEADERS
            timing/NodeAwareModel.h
            timing/BasicPerformanceModel.h
            timing/partitioning_timing.h
    )
    set(timing_SOURCES
            ""
    )
else ()
    set(timing_HEADERS
            ""
    )
    set(timing_SOURCES
            ""
    )
endif()

set(timing_HEADERS
        timing/NodeAwareModel.h
        timing/BasicPerformanceModel.h
        timing/partitioning_timing.h
        ${timing_HEADERS}
        PARENT_SCOPE)

set(timing_SOURCES
        ""
        ${timing_SOURCES}
        PARENT_SCOPE)