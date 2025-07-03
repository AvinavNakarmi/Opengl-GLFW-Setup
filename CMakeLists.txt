cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)
# ImGui
file(GLOB IMGUI_SOURCES
    libs/imgui/*.cpp
    libs/imgui/backends/imgui_impl_glfw.cpp
    libs/imgui/backends/imgui_impl_opengl3.cpp
)
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
# GLM
include_directories(${CMAKE_SOURCE_DIR}/libs/glm)

# GLAD
add_library(glad src/glad.c)
add_library(imgui ${IMGUI_SOURCES})
target_include_directories(glad PUBLIC include)
target_include_directories(imgui PUBLIC
    libs/imgui
    libs/imgui/backends
)
target_link_libraries(imgui glfw) # Also link OpenGL if needed
# Collect all utility source files
file(GLOB_RECURSE UTILS_SOURCES ${CMAKE_SOURCE_DIR}/src/utils/*.cpp)

# Your executable with all required source files
add_executable(OpenGLProject src/main.cpp ${UTILS_SOURCES})

# Link libraries

target_link_libraries(OpenGLProject glad glfw ${CMAKE_DL_LIBS})
target_link_libraries(OpenGLProject imgui)
