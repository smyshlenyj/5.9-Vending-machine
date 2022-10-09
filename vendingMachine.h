#pragma once
#include "snack.h"
#include "slot.h"

class VendingMachine
{
	int id = 0;
	int capacity = 0;
	int loadedQuantity = 0;
	int freeSpace = capacity - loadedQuantity;
	std::vector<Slot> loadedSlots;

public:
	VendingMachine(int id, int capacity);
	void AddSlot(Slot& other); // add slot to vending machine
	int getEmptySlotsCount() { return this->freeSpace; }
	int getId() { return this->id; };
	int getLevelOfLoad(); // get quantity of loaded snacks
	void sellSnack(int slot);
};