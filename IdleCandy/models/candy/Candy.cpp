#include "Candy.h"

Candy::Candy()
{
	this->_type = CandyType::CANDY_CANE;
	this->_amount = 0;
}


Candy::Candy(const CandyType type, const int amount)
{
	this->_type = type;
	this->_amount = amount;
}

std::string Candy::GetName() const
{
	switch (this->_type)
	{
		case CandyType::CANDY_CANE:
			return "Candy cane";
		case CandyType::LOLLIPOP:
			return "Lollipop";
		case CandyType::TAGADA:
			return "Fraise tagada";
	}

	return "Unknown";
}
