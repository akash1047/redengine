cmake_minimum_required(VERSION 3.28)

project(redengine)

set(CMAKE_CXX_STANDARD 23)

add_library(redengine SHARED library.cpp
        mouse.h
        mouse.cpp
        glfw.h
        window.cpp
        window.h)

add_subdirectory(external/glfw)

target_include_directories(redengine PRIVATE
        external/glfw/include
)

target_link_libraries(redengine PRIVATE
        glfw
)