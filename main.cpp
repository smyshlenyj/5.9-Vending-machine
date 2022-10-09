#include "snack.h"
#include "slot.h"
#include "vendingMachine.h"

int main()
{
	setlocale(LC_ALL, "");

	// creating new snacks
	Snack* snickers = new Snack("Snickers", 100, 77);
	Snack* mars = new Snack("Mars", 100, 77);
	
	// testing Snack getters and setters
	std::cout << "Цена " << mars->getName() << " = " << mars->getPrice() << std::endl;
	mars->setPrice(88);
	std::cout << "Цена " << mars->getName() << " = " << mars->getPrice() << std::endl;
	
	// creating new slots and filling them with snacks
	Slot* snackSlot = new Slot(0,15);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);
	snackSlot->AddSnack(*snickers);

	Slot* snackSlot2 = new Slot(1, 10);
	snackSlot2->AddSnack(*mars);
	snackSlot2->AddSnack(*mars);
	snackSlot2->AddSnack(*mars);
	snackSlot2->AddSnack(*mars);
	
	// creating new vending machine and filling it with loaded slots
	VendingMachine* machine = new VendingMachine(1, 5);
	machine->AddSlot(*snackSlot);
	machine->AddSlot(*snackSlot2);

	// testing VendingMachine getters
	std::cout << "Пустых слотов, шт.: " << machine->getEmptySlotsCount() << std::endl;
	std::cout << "В вендинговый аппарат ID_" << machine->getId() << " загружено " << machine->getLevelOfLoad() << " товаров\n";

	// try to sell snack and check whether anything has changed
	machine->sellSnack(0);
	machine->sellSnack(0);
	machine->sellSnack(0);
	machine->sellSnack(0);
	std::cout << "В вендинговый аппарат ID_" << machine->getId() << " загружено " << machine->getLevelOfLoad() << " товаров\n";


	delete snickers;
	delete mars;
	delete snackSlot;
	delete snackSlot2;
	delete machine;

	return 0;
}