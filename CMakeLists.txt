cmake_minimum_required(VERSION 3.5)
project(Base)

set(CMAKE_CXX_STANDARD 17)

# GLFW
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

# GLAD
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC include)

# Your executable
add_executable(OpenGLProject src/main.cpp)

# Link everything
target_link_libraries(OpenGLProject glad glfw ${CMAKE_DL_LIBS})
