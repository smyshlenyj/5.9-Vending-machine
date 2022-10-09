#pragma once
#include <vector>

class Slot
{
	int id = 0;
	int capacity = 0;
	int loadedQuantity = 0;
	int freeSpace = 0;
	std::vector<Snack> loadedSnacks;

public:
	Slot(int id, int capacity);
	void AddSnack(Snack&); // load snack to slot
	int getId() { return id; }
	int getLoadedQuantity() { return loadedQuantity; }
	void receiveSnack();
};