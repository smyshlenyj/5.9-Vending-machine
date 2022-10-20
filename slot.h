#pragma once
#include <vector>

class Slot
{
public:
	int _id = 0;
	int _capacity = 0;
	int _loadedQuantity = 0;
	int _freeSpace = 0;
	std::vector<Snack*> loadedSnacks;

public:
	Slot(int id, int capacity);
	void addSnack(Snack* other);
	int getId() const { return _id; }
	int getLoadedQuantity() const { return _loadedQuantity; }
	void receiveSnack();
};