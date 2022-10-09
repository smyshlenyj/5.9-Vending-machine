#pragma once
#include <iostream>

class Snack
{
	std::string name;
	int weight;
	double price;

public:
	Snack(std::string name, int weight, double price);
	std::string getName() { return name; }
	double getPrice() { return price; };
	void setPrice(double newPrice);
};