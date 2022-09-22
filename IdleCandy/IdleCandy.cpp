#include <iostream>
#include <windows.h>
#include <iostream>
#include <thread>

#include "models/game/Game.h"

int constexpr WIDTH = 800;
int constexpr HEIGHT = 800;

void SetupConsole()
{
	// Set console to UTF-8 in order to display emojis
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTitleA("Idle candy game");
	// Set console size
	const HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, WIDTH, HEIGHT, TRUE);
}

void main()
{
	SetupConsole();
	Game game;
	// Start a new thread to refresh the console output
	std::thread t([&game]()
		{
			while (true)
			{
				game.OnTick();
			}
		});
	t.detach();

	game.Start();
}
