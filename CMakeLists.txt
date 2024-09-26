cmake_minimum_required(VERSION 3.23)
project(SFML_2D_Array)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TwoDVector.cpp TwoDVector.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(SFML_2D_Array WIN32 ${SOURCE_FILES})
else ()
    add_executable(SFML_2D_Array ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH C:/Users/super/CLionProjects/cmake_modules)
set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_2D_Array ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# cmake_minimum_required(VERSION 3.23)
# project (SFML_2D_Array)

# set(CMAKE_CXX_STANDARD 14)

# add_executable(SFML_2D_Array main.cpp)