#pragma once

#include "../../Log.h"

class Window {
public:
	int width, height;
	Logger *logger;

	void Draw();
};

