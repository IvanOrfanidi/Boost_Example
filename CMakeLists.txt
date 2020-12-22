# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(boost_example)

# Option
set(CMAKE_CXX_STANDARD 17)

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror
        -Wall
    )
endif()

# Sources files
set(SOURCES_SPLIT
    split/main.cpp
)
set(SOURCES_THREAD
    thread/main.cpp
)

# Compiling targets
add_executable(${PROJECT_NAME}_split ${SOURCES_SPLIT})
add_executable(${PROJECT_NAME}_thread ${SOURCES_THREAD})


# Boost flags
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

if(UNIX)
    set(CMAKE_THREAD_LIBS_INIT "-lpthread")
    set(CMAKE_HAVE_THREADS_LIBRARY ON)
    set(CMAKE_USE_WIN32_THREADS_INIT OFF)
    set(CMAKE_USE_PTHREADS_INIT ON)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
endif()

# Find boost
if(WIN32)
    find_package(Boost COMPONENTS thread)
elseif(UNIX)
    # Boost components
    set(BOOST_COMPONENTS
        system
        filesystem
        thread
        date_time
        chrono
        serialization
    )
    find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
endif()


# Include and link boost
target_link_libraries(${PROJECT_NAME}_split ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_thread ${Boost_LIBRARIES} Boost::thread)
