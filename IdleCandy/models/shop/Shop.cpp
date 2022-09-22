#include "Shop.h"

Shop::Shop(const std::string& name)
{
	this->_items = {};
	this->_name = name;
	this->_money = 0;

	this->AddItem(Goods(Candy(CandyType::CANDY_CANE, 10), 25));
	this->AddItem(Goods(Candy(CandyType::LOLLIPOP, 10), 50));
	this->AddItem(Goods(Candy(CandyType::TAGADA, 10), 100));
}

Candy Shop::BuyItem(const int index, const int amount)
{
	Candy candy = this->_items[index].GetCandy();
	candy.SetAmount(amount);
	this->_items[index].GetCandy().UpdateAmount(-amount);

	return candy;
}
