#include <iostream>
#include "snack.h"

Snack::Snack(std::string name, int weight, double price)
	: name(name), weight(weight), price(price)
{
}

void Snack::setPrice(double newPrice)
{
	this->price = newPrice;
}