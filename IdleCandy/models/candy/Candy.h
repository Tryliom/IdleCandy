#pragma once
#include <string>

enum class CandyType
{
	LOLLIPOP = 1,
	CANDY_CANE = 3,
	TAGADA = 5
};

class Candy
{
private:
	CandyType _type;
	int _amount;
public:
	Candy();
	Candy(CandyType type, int amount);

	CandyType GetType() const { return this->_type; }
	int GetMoneyGeneration() const { return static_cast<int>(this->_type); }
	int GetTotalMoneyGeneration() const { return this->_amount * GetMoneyGeneration(); }
	void UpdateAmount(const int amount) { this->_amount += amount; }
	int GetAmount() const { return this->_amount; }
	std::string GetName() const;
	void SetAmount(const int amount) { this->_amount = amount; }
};

