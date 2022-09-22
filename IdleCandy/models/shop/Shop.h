#pragma once
#include "Goods.h"

#include <string>
#include <unordered_map>

class Shop
{
private:
	std::vector<Goods> _items;
	std::string _name;
	int _money;

public:
	explicit Shop(const std::string& name);

	void AddItem(const Goods goods) { this->_items.emplace_back(goods); }
	void AddMoney(const int money) { _money += money; }
	int GetMoney() const { return _money; }
	std::string GetName() const { return _name; }
	std::vector<Goods> GetItems() const { return _items; }

	Candy BuyItem(const int index, const int amount);
};

