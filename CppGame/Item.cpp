//Use with Item.h
#include "stdafx.h"
#include "Item.h"

using namespace std;

string itemNames[10] = { "Normal Armor", "Stick", 
"Dark Armor", "Big Stick", "An Armor", "An Sword", "thingy", "thingy2", "thingy3", "thingy5" };

string itemBlurb[10] = { "Normal Armor: an armor made of mesh or something",
"Stick: a slightly sharp stick you found off of the ground", 
"Dark Armor: its like normal armor, but painted black", 
"Big Stick: a slightly bigger stick you found off of the ground, its not particularly better than a stick", 
"An Armor: its armor, it doesn't look and or smell good", 
"An Sword: its a sword you found off the ground, it doesn't look or smell good", 
"thingy: something that you found on the ground, it looks cool at least", 
"thingy2: something that you found on the ground, it smells good at least", 
"thingy3: something that you found on the ground, it makes a pleasant sound", 
"thingy4: something that you found on the ground, it tastes like strawberries" };

bool itemTemp[10] = { false,false,false,false,false,false,false,false,false,false };

string itemType[10] = { "armor", "weapon", "armor", "weapon", "armor", "weapon", "item", "item", "item", "item" };

unsigned int StatsType[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

unsigned int StatsTypeItems[10] = { 1, 2, 3, 1, 2, 3, 1, 1, 1, 1 };

void Item::setTemp(bool Temp) {
	temp = Temp;
}

bool Item::getTemp() {
	return temp; 
}

string Item::stringTemp() {
	if (temp = true) { return "Temporary"; }
	else {
		return "Permanent";
	}
}

void Item::setType(string Type) { 
	type = Type;
}

string Item::getType() { 
	return type;
}

void Item::setEquipState(bool State) { 
	equip = State;
}

bool Item::getEquipState() {
	return equip;
}

void Item::setRandItem() {
	size_t randIndex = (rand() % 10);
	setType(itemType[randIndex]);
	setName(itemNames[randIndex]);
	setBlurb(itemBlurb[randIndex]);
	setTemp(itemTemp[randIndex]);
	setAttackingStat(StatsType[randIndex]);
	setDefendingStat(StatsType[randIndex]);
}

void Item::ItemToString() {
	toString();
	cout << "Is Temporary: " << stringTemp() << endl
		<< "Equip State : " << getEquipState() << endl
		<< "Type : " << getType();
}

Item* Item::getNextItemPtr() const {
	return nextItemPtr;
}