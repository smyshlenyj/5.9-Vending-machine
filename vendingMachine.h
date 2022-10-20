#pragma once
#include "snack.h"
#include "slot.h"

class VendingMachine
{
private:
	int _id = 0;
	int _capacity = 0;
	int _loadedQuantity = 0;
	int _freeSpace = _capacity - _loadedQuantity;
	std::vector<Slot*> loadedSlots;

public:
	VendingMachine(int id, int capacity);
	void addSlot(Slot* slot); 
	int getEmptySlotsCount() const { return _freeSpace; }
	int getId() const { return _id; };
	int getLevelOfLoad() const;
	void sellSnack(int slot);
};