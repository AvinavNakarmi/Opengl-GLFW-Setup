#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "vector.h"
#include "matrix.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

bool keys[1024] = {false};
bool mouseDown = false;
double mousePosXDragStart, mousePosYDragStart;

unsigned int width = 800;
unsigned int height = 800;

struct MousePos
{
	double x, y;
	MousePos operator-(const MousePos &b)
	{
		return {x - b.x, y - b.y};
	}
	MousePos operator+(const MousePos &b)
	{
		return {x + b.x, y + b.y};
	}
};

MousePos DragStart = {0.0f, 0.0};

void framebuffer_size_callback(GLFWwindow *window, int changedWidth, int changedHeight)
{
	width = changedWidth;
	height = changedHeight;
	glViewport(0, 0, width, height);
}
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}
void mouse_down_callback(GLFWwindow *window, int button, int action, int mods)
{
	if (action == 1)
	{
		mouseDown = true;
		glfwGetCursorPos(window, &DragStart.x, &DragStart.y);
	}
	else
	{
		mouseDown = false;
		MousePos currentPos;
		glfwGetCursorPos(window, &currentPos.x, &currentPos.y);
		MousePos difference = DragStart - currentPos;
		std::cout << difference.x << difference.y << std::endl;
	}
}
void mouse_cursor_callback(GLFWwindow *window, double xpos, double ypos)
{
}
void update(Vector3 &position)
{

	if (keys[GLFW_KEY_W])
		position.y += 0.001;
	if (keys[GLFW_KEY_S])
		position.y -= 0.001;
	if (keys[GLFW_KEY_A])
		position.x -= 0.001;
	if (keys[GLFW_KEY_D])
		position.x += 0.001;
	if (keys[GLFW_KEY_Q])
		position.z -= 0.001;
	if (keys[GLFW_KEY_E])
		position.z += 0.001;
}
// Vertices coordinates
GLfloat vertices[] =
	{
		//               COORDINATES                  /     COLORS           //
		-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.5f, 0.5f, 0.5f,	 // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f,	 // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.32f,	 // Upper corner
		-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.9f, 0.45f, 0.17f, // Inner left
		0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.9f, 0.45f, 0.17f,	 // Inner right
		0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f	 // Inner down
};

// Indices for vertices order
GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right triangle
		5, 4, 1	 // Upper triangle
};

int main()
{
	// Initialize GLFW
	glfwInit();
	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow *window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_cursor_callback);
	glfwSetMouseButtonCallback(window, mouse_down_callback);
	// Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("../src/shader/default.vert", "../src/shader/default.frag");

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint uniModalID = glGetUniformLocation(shaderProgram.ID, "u_modal");
	GLuint uniViewID = glGetUniformLocation(shaderProgram.ID, "u_view");
	GLuint uniProjectionID = glGetUniformLocation(shaderProgram.ID, "u_projection");
	float theta = glm::radians(0.0f);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		glm::mat4 modal = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		theta += 0.01f;
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
		projection = glm::perspective(glm::radians(theta), (float)(width / height), 0.1f, 100.0f);
		modal = glm::rotate(modal, theta, glm::vec3(0.0f, 0.0f, 1.0f));

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		glUniformMatrix4fv(uniModalID, 1, GL_FALSE, glm::value_ptr(modal));
		glUniformMatrix4fv(uniViewID, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(uniProjectionID, 1, GL_FALSE, glm::value_ptr(projection));

		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}