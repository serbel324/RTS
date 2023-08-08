cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

# SFML
set(SFML_PREFIX ${CMAKE_SOURCE_DIR}/contrib/SFML)

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
target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system)
