@echo off
setlocal

:: Create build directory if it doesn't exist
if not exist build (
    mkdir build
)

:: Navigate to build folder
cd build

:: Run CMake and build the project
cmake ..
cmake --build . --config Debug

:: Run the executable if build succeeded
if exist Debug\OpenGLProject.exe (
    echo Running OpenGLProject.exe
    Debug\OpenGLProject.exe
) else (
    echo Build failed or executable not found.
)

pause
