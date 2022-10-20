#pragma once
#include <iostream>

class Snack
{
private:
	const std::string _name;
	int _weight;
	double _price;

public:
	Snack(const std::string& name, int weight, double price);
	std::string getName() const { return _name; }
	double getPrice() const { return _price; };
	void setPrice(double newPrice);
};