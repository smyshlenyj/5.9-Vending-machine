#include "snack.h"
#include "slot.h"
#include "vendingMachine.h"

int main()
{
	setlocale(LC_ALL, "");

	// Создаем новые Snack
	Snack* snickers = new Snack("Snickers", 100, 77);
	Snack* mars = new Snack("Mars", 100, 77);

	std::cout << "Проверяем работу геттера и сеттера Snack:" << std::endl;
	std::cout << "Цена " << mars->getName() << " = " << mars->getPrice() << std::endl;
	mars->setPrice(88);
	std::cout << "Цена " << mars->getName() << " = " << mars->getPrice() << std::endl;
	std::cout << std::endl;

	std::cout << "Создаем новые слоты и наполняем их снэками" << std::endl;
	Slot* snackSlot = new Slot(0, 15);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*mars);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	std::cout << std::endl;

	Slot* snackSlot2 = new Slot(1, 10);
	snackSlot2->AddSnack(*mars);
	snackSlot2->AddSnack(*mars);
	snackSlot2->AddSnack(*mars);
	snackSlot2->AddSnack(*snickers);
	snackSlot2->AddSnack(*mars);
	std::cout << std::endl;

	std::cout << "Создаем вендинговый аппарат и загружаем в него слоты" << std::endl;
	VendingMachine* machine = new VendingMachine(1, 5);
	machine->AddSlot(*snackSlot);
	machine->AddSlot(*snackSlot2);
	std::cout << std::endl;

	std::cout << "Проверка геттера VendingMachine:" << std::endl;
	std::cout << "Пустых слотов, шт.: " << machine->getEmptySlotsCount() << std::endl;
	std::cout << "В вендинговый аппарат ID_" << machine->getId() << " загружено " << machine->getLevelOfLoad() << " товаров\n";
	std::cout << std::endl;

	std::cout << "Пробуем продать снэк и проверить изменилось ли что-нибудь" << std::endl;
	machine->sellSnack(0);
	machine->sellSnack(0);
	machine->sellSnack(0);
	machine->sellSnack(0);
	std::cout << "В вендинговый аппарат ID_" << machine->getId() << " загружено " << machine->getLevelOfLoad() << " товаров\n";
	std::cout << std::endl;

	delete snickers;
	delete mars;
	delete snackSlot;
	delete snackSlot2;
	delete machine;

	return 0;
}