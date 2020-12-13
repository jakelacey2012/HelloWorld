#include "GLFW/glfw3.h"

#include "Engine/Renderer/Window.h"
#include "Log.h"
#include "Game.h"

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

	while (!glfwWindowShouldClose(window.container)) 
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window.container);
		glfwPollEvents();
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
	window.container = glfwCreateWindow(640, 480, "Title", NULL, NULL);
	window.logger = logger;
	return window;
}
