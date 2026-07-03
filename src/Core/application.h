#pragma once
#include <iostream>
#include <glad/glad.h>
#include "window.h"
#include <GLFW/glfw3.h>

class Application
{
private:
    Window *window;
    Window *window2;

public:
    Application();
    ~Application();
    void Run();
};