#include "vendingMachine.h"

	VendingMachine::VendingMachine(int id, int capacity)
	{
		this->id = id;
		this->capacity = capacity;
	}

	void VendingMachine::AddSlot(Slot& other)
	{
		if (capacity >= loadedQuantity + 1)
		{
			this->loadedQuantity += 1;
			this->freeSpace = this->capacity - this->loadedQuantity;
			loadedSlots.push_back(other);
			std::cout << "� ����������� ������� �������� ���� ID_" << loadedSlots.back().getId() <<
				", �������� ��������� ������: " << this->freeSpace << std::endl;
		}
		else
			std::cout << "������� ��������� ������, ��� �������� ���������� �����" << std::endl;
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