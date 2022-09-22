#pragma once
#include "../candy/Candy.h"

class Goods
{
private:
	Candy _candy;
	int _price;

public:
	Goods(const Candy& candy, const int price);
	
	Candy &GetCandy() { return this->_candy; }
	int GetPrice() const { return this->_price; }
};
