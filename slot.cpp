#include "snack.h"
#include "slot.h"
#include <vector>
#include <iostream>

	Slot::Slot(int id, int capacity)
	{
		this->id = id;
		this->capacity = capacity;
	}

	void Slot::AddSnack(Snack& other)
	{
		if (this->capacity >= this->loadedQuantity + 1 && ((loadedSnacks.size() > 0 && this->loadedSnacks[0].getName() == other.getName()) || loadedQuantity == 0))
		{
			this->loadedQuantity += 1;
			this->freeSpace = this->capacity - this->loadedQuantity;
			this->loadedSnacks.push_back(other);
			std::cout << "� ���� " << this->id << " ��������� 1 ��. " << this->loadedSnacks.back().getName() <<
				", �������� ���������� ����� : " << this->freeSpace << std::endl;
		}
		else if (loadedSnacks.size() > 0 && this->loadedSnacks[0].getName() != other.getName())
			std::cout << "������ �������� ����� - �������� �������!" << std::endl;
		else
			std::cout << "������� ��������� ������, ��� �������� ���������� �����" << std::endl;
	}

	void Slot::receiveSnack()
	{
		if (this->loadedQuantity > 0)
		{
			loadedSnacks.pop_back();
			--loadedQuantity;
		}
		else
			std::cout << "������� �������� �����, �������� ��� � �������" << std::endl;
	}