#pragma once
#include "../candy/Candy.h"

#include <vector>

class Player
{
private:
	int _money;
	std::vector<Candy> _candies;

public:
	Player();

	void AddMoney(const int money) { this->_money += money; }
	void DecreaseMoney(const int money) { this->_money -= money; }
	int GetMoney() const { return this->_money; }
	std::vector<Candy> GetCandies() const { return this->_candies; }
	void AddCandy(const Candy candy);
	void UpdateMoney();
};
