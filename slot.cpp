#include "snack.h"
#include "slot.h"
#include <vector>
#include <iostream>

Slot::Slot(int id, int capacity)
{
	_id = id;
	_capacity = capacity;
}

void Slot::addSnack(Snack* snack)
{
	if (_capacity >= _loadedQuantity + 1 && ((loadedSnacks.size() > 0 && loadedSnacks[0]->getName() == snack->getName()) || _loadedQuantity == 0))
	{
		_loadedQuantity += 1;
		_freeSpace = _capacity - _loadedQuantity;
		loadedSnacks.push_back(snack);
		std::cout << "В слот " << _id << " загружена 1 шт. " << loadedSnacks.back()->getName() <<
			", осталось свободного места : " << _freeSpace << std::endl;
	}
	else if (loadedSnacks.size() > 0 && loadedSnacks[0]->getName() != snack->getName())
	{
		std::cout << "Ошибка загрузки слота - конфликт товаров!" << std::endl;
	}
	else
	{
		std::cout << "Попытка загрузить больше, чем доступно свободного места" << std::endl;
	}
	//std::cout << loadedSnacks.back() << "\n";
}

void Slot::receiveSnack()
{
	if (_loadedQuantity > 0)
	{
		loadedSnacks.pop_back();
		--_loadedQuantity;
	}
	else
	{
		std::cout << "Попытка получить товар, которого нет в наличии" << std::endl;
	}
}