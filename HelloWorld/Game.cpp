#include "GLFW/glfw3.h"
#include <iostream>

#include "Engine/Renderer/Window.h"
#include "Log.h"
#include "Game.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		std::cout << "E is being pressed" << std::endl;
	}
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << xpos << "::" << ypos << std::endl;
}

void Game::Init()
{
	Logger logger = CreateLogger();
	
	if (!glfwInit()) 
	{
		logger.Error("Could not initiate GLFW (OPENGL)");
		return;
	}

	Window window = CreateWindow(&logger);
	if (!window.container) 
	{
		logger.Error("Window isn't ready");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window.container);

	glfwSetKeyCallback(window.container, key_callback);
	glfwSetCursorPosCallback(window.container, cursor_position_callback);

	while (!glfwWindowShouldClose(window.container)) 
	{
		// Clearing
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Drawing - Triangle
		glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.0f, 0.5f);
			glVertex2f(0.5f, -0.5f);
		glEnd();

		// Drawing - Quadralatral
		glBegin(GL_QUADS);
			glVertex2f(-0.3f, -0.3f);
			glVertex2f(-0.3f, 0.3f);
			glVertex2f(0.3f, 0.3f);
			glVertex2f(0.3f, -0.3f);
		glEnd();

		// Update
		glfwPollEvents();
		glfwSwapBuffers(window.container);
	}

	glfwTerminate();
}

Logger Game::CreateLogger()
{
	Logger logger;
	logger.SetLevel(logger.LogLevelDebug);
	logger.Info("Creating Logger");
	return logger;
}

Window Game::CreateWindow(Logger* logger)
{
	logger->Info("Creating window");
	Window window;
	window.container = glfwCreateWindow(800, 600, "Title", NULL, NULL);
	window.logger = logger;
	return window;
}
