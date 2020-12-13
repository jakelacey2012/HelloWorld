#pragma once

#include "GLFW/glfw3.h";
#include "../../Log.h"

class Window {
public:
	GLFWwindow* container;
	Logger *logger;

	void Draw();
};

