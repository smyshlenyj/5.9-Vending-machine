#include "vendingMachine.h"

VendingMachine::VendingMachine(int id, int capacity)
{
	_id = id;
	_capacity = capacity;
}

void VendingMachine::addSlot(Slot* slot)
{
	if (_capacity >= _loadedQuantity + 1)
	{
		_loadedQuantity += 1;
		_freeSpace = _capacity - _loadedQuantity;
		loadedSlots.push_back(slot);
		std::cout << "В вендинговый аппарат загружен слот ID_" << loadedSlots.back()->getId() <<
			", осталось незанятых мест под слоты: " << _freeSpace << std::endl;
	}
	else
	{
		std::cout << "Попытка загрузить больше, чем доступно свободного места" << std::endl;
	}
}

int VendingMachine::getLevelOfLoad() const
{
	int loaded = 0;
	for (Slot* slot : loadedSlots)
	{
		loaded += slot->getLoadedQuantity();
	}

	return loaded;
}

void VendingMachine::sellSnack(int slot)
{
	loadedSlots[slot]->receiveSnack();
}