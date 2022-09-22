#include "Game.h"

#include <conio.h>
#include <iostream>

void Game::OnTick()
{
	if (Tick % 5 == 0) // 1 second
	{
		_player.UpdateMoney();
	}
	if (Tick % 10 == 0) // 2 seconds
	{
		Status.clear();
	}
	_screen.Clear();
	Update();
	_screen.Render();
	Tick++;
}


void Game::Update()
{
	_screen.Draw(Text{ .Str = _shop.GetName() + " [" + std::to_string(_shop.GetMoney()) + "$]", .X = 15, .Y = 3, .XCentered = true});

	int i = 0;
	for (Goods goods : _shop.GetItems())
	{
		std::string name = std::to_string(goods.GetCandy().GetAmount()) + " " + goods.GetCandy().GetName();
		if (SelectedCandy == i)
		{
			name = "> " + name;
		}
		_screen.Draw(Text{ .Str = name, .X = 5, .Y = 5 + i * 2});
		_screen.Draw(Text{ .Str = std::to_string(goods.GetPrice()) + "$", .X = 25, .Y = 5 + i * 2 });
		i++;
	}

	i = 0;
	for (Candy candy : _player.GetCandies())
	{
		_screen.Draw(Text{ .Str = std::to_string(candy.GetAmount()) + " " + candy.GetName(), .X = 35, .Y = 5 + i * 2 });
		i++;
	}

	_screen.Draw(Text{ .Str = "Player money: " + std::to_string(_player.GetMoney()) + "$", .X = 50, .Y = 3, .XCentered = true});
	if (!Status.empty()) {
		_screen.Draw(Text{ .Str = Status, .X = _screen.GetWidth() / 2, .Y = _screen.GetHeight() - 10, .XCentered = true });
	}
	_screen.Draw(Text{ .Str = ">: Buy | up/bottom: Choose candy", .X = _screen.GetWidth() / 2, .Y = _screen.GetHeight() - 5, .XCentered = true});
}


void Game::Start()
{
	do
	{	
		switch (int key = _getch())
		{
		case KEY_DOWN:
			SelectedCandy++;
			if (SelectedCandy >= static_cast<int>(_shop.GetItems().size()))
			{
				SelectedCandy = 0;
			}
			break;
		case KEY_UP:
			SelectedCandy--;
			if (SelectedCandy < 0)
			{
				SelectedCandy = static_cast<int>(_shop.GetItems().size()) - 1;
			}
			break;
		case KEY_RIGHT:
			if (_player.GetMoney() < _shop.GetItems()[SelectedCandy].GetPrice())
			{
				Status = "Not enough money";
			}
			else if (_shop.GetItems()[SelectedCandy].GetCandy().GetAmount() == 0)
			{
				Status = "No more candies";
			}
			else
			{
				_player.AddCandy(_shop.BuyItem(SelectedCandy, 1));
				_shop.AddMoney(_shop.GetItems()[SelectedCandy].GetPrice());
				_player.DecreaseMoney(_shop.GetItems()[SelectedCandy].GetPrice());
				Status = "Bought 1 " + _shop.GetItems()[SelectedCandy].GetCandy().GetName();
			}
			break;
		}
	} while (true);
}
