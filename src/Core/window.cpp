#include "window.h"
Window::Window()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
    if (!glfwInit())
    {
        std::cout << "GLFW failed to initialize\n";
    }
    else
    {
        std::cout << "GLFW initialized\n";
    }
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        throw std::runtime_error("Failed to create GLFW window.");
    }
    glfwMakeContextCurrent(window);
}
Window::~Window()
{
    if (window)
    {
        glfwDestroyWindow(window);
    }
}
void Window::MakeCurrent()
{
    glfwMakeContextCurrent(window);
}
void Window::Present()
{
    glfwSwapBuffers(window);
}
bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}
