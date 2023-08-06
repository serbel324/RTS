cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

# SFML
set(SFML_PREFIX ${CMAKE_SOURCE_DIR}/contrib/SFML)
if (WIN32)
    set(SFML_ROOT ${SFML_PREFIX}/mingw64)
endif()

set(INCPATH
    ${PROJECT_SOURCE_DIR}/include)

project(Core)

set(SOURCES
    camera.cpp
    color.cpp
    graphics.cpp
    frame.cpp
    input.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCPATH}
    ${SFML_ROOT}/include
)

# link SFML
# set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${SFML_ROOT}/lib/cmake/SFML)
find_package(SFML 2.6 REQUIRED COMPONENTS system graphics window NO_DEFAULT_PATH)
if (SFML_FOUND)
    target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system)
endif()
