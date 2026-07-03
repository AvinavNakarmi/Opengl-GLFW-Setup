#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

class Window
{
private:
    std::string windowName = "Window";
    unsigned int width = 800;
    unsigned int height = 800;
    GLFWwindow *window;

public:
    Window();
    ~Window();
    void MakeCurrent();
    void Present();
    bool ShouldClose();
};