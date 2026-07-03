
#include <iostream>
#include "Core/application.h"
void GLFWErrorCallback(int error, const char *description)
{
	std::cout << "GLFW Error " << error << ": " << description << std::endl;
}
int main()
{
	glfwSetErrorCallback(GLFWErrorCallback);
	std::cout << "program started" << std::endl;
	Application app;
	app.Run();
	return 0;
}