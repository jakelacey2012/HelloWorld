#pragma once

#include "Log.h"
#include "Engine/Renderer/Window.h"

class Game {
public:
	void Init();
	Logger CreateLogger();
	Window CreateWindow(Logger *logger);
};