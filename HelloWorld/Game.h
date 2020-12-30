#pragma once

#include "Log.h"
#include "Engine/Renderer/Window.h"

class Game {
public:
	bool e;
	void Init();
	Logger CreateLogger();
	Window CreateWindow(Logger *logger);
private:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mod);
	static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
};