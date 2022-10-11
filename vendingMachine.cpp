#include "vendingMachine.h"

VendingMachine::VendingMachine(int id, int capacity)
{
	this->id = id;
	this->capacity = capacity;
}

void VendingMachine::addSlot(Slot& other)
{
	if (capacity >= loadedQuantity + 1)
	{
		this->loadedQuantity += 1;
		this->freeSpace = this->capacity - this->loadedQuantity;
		loadedSlots.push_back(other);
		std::cout << "В вендинговый аппарат загружен слот ID_" << loadedSlots.back().getId() <<
			", осталось незанятых мест под слоты: " << this->freeSpace << std::endl;
	}
	else
		std::cout << "Попытка загрузить больше, чем доступно свободного места" << std::endl;
}

int VendingMachine::getLevelOfLoad()
{
	int loaded = 0;
	for (Slot slot : this->loadedSlots)
		loaded += slot.getLoadedQuantity();

	return loaded;
}

void VendingMachine::sellSnack(int slot)
{
	this->loadedSlots[slot].receiveSnack();
}