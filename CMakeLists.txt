# http://docs.opencv.org/trunk/db/df5/tutorial_linux_gcc_cmake.html
cmake_minimum_required(VERSION 2.8)
project(rifp)

# https://stackoverflow.com/questions/11588855/how-do-you-set-cmake-c-compiler-and-cmake-cxx-compiler-for-building-assimp-for-i
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 14)

# https://stackoverflow.com/questions/1620918/cmake-and-libpthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(include)
set(SOURCE_FILES
    test.cpp
)
add_executable(rifp ${SOURCE_FILES})
target_link_libraries( rifp ${OpenCV_LIBS} Threads::Threads )
