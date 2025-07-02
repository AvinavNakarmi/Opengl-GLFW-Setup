cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)

# GLFW
add_subdirectory(libs/glfw)
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/utils
    ${CMAKE_SOURCE_DIR}/src/utils/Object
    ${CMAKE_SOURCE_DIR}/src/utils/Math
    ${CMAKE_SOURCE_DIR}/src/utils/shader
    libs/glfw/include
)

# GLAD
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC include)

# Collect all utility source files
file(GLOB_RECURSE UTILS_SOURCES ${CMAKE_SOURCE_DIR}/src/utils/*.cpp)

# Your executable with all required source files
add_executable(OpenGLProject src/main.cpp ${UTILS_SOURCES})

# Link libraries
target_link_libraries(OpenGLProject glad glfw ${CMAKE_DL_LIBS})
