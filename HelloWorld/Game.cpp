
#include "Engine/Renderer/Window.h"
#include "Log.h"
#include "Game.h"

void Game::Init()
{
	Logger logger = CreateLogger();
	Window window = CreateWindow(&logger);

	while (true) {
		// input - where do we get input from?
		// update - what are we updating?
		// render - what are we drawing?
	}

	window.Draw();
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
	window.height = 100;
	window.width = 200;
	window.logger = logger;
	return window;
}
