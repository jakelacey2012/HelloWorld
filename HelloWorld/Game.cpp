
#include "Engine/Renderer/Window.h"
#include "Log.h"
#include "Game.h"

class Component {
public:
	virtual void Update();
	virtual void Draw();
};

class Entity {
public:
	Component *components[100];
};

class Thing: public Component {
	Logger* logger;
public:
	void SetLogger(Logger* l) {
		logger = l;
	}
	void Update(/*needs access to other players*/) { // needs access to input to be able to change certain things
		logger->Info("UPDATING_PLAYER");
		// a thing will need access to all the things to know where they area
		// 
	}
	void Draw() { // needs access to something and draw it on screen
		logger->Info("DRAWING_PLAYER");
	}
};

void Game::Init()
{
	Logger logger = CreateLogger();
	Window window = CreateWindow(&logger);

	Entity player;
	Thing thing;
	thing.SetLogger(&logger);
	player.components[0] = &thing;

	while (true) {
		player.components[0]->Update();
		player.components[0]->Draw();
	}
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
