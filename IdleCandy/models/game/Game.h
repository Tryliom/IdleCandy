#pragma once
#include "../player/Player.h"
#include "../shop/Shop.h"
#include "../view/Screen.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game
{
private:
	Shop _shop;
	Player _player;
	Screen _screen;

public:
	int Tick = 0;
	int SelectedCandy = 0;
	std::string Status;
	Game() : _shop("Diabetes at arm's length") {}

	void OnTick();

	void Update();

	void Start();
};