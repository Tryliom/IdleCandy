#include "Player.h"

Player::Player()
{
	this->_money = 5;
	this->_candies = {};
}

void Player::AddCandy(const Candy candy)
{
	for (auto& c : this->_candies)
	{
		if (c.GetType() == candy.GetType())
		{
			c.UpdateAmount(candy.GetAmount());
			return;
		}
	}

	this->_candies.emplace_back(candy);
}

void Player::UpdateMoney()
{
	// Base generation
	this->_money += 1;

	for (auto& c : this->_candies)
	{
		this->_money += c.GetTotalMoneyGeneration();
	}
}
