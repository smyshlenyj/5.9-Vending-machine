#include <iostream>
#include "snack.h"

Snack::Snack(const std::string& name, int weight, double price)
	: _name(name), _weight(weight), _price(price)
{
}

void Snack::setPrice(double newPrice)
{
	_price = newPrice;
}