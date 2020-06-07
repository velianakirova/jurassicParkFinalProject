#pragma once
#include "foodFactory.h"


bool Warehouse::isEqual(const char* strOne, const char* strTwo) {
	int lenOne = strlen(strOne);
	int lenTwo = strlen(strTwo);
	if (lenOne != lenTwo) return false;
	for (int i = 0; i < lenOne; i++) {
		if (strOne[i] != strTwo[i]) return false;
	}
	return true;
}

void Warehouse::storeFood(const char* food) {
	if (isEqual(food, "grass")) {
		this->grass++;
	}
	else if (isEqual(food, "fish")) {
		this->fish++;
	}
	else if (isEqual(food, "meat")) {
		this->meat++;
	}
	else cout << "Unknown type of food. There is a chance that the dinosaur will be left without food.\n";

}

void Warehouse::printInfo()const {
	cout << "Park`s warehouse contains: " << this->grass << " tones of grass, " << this->fish << " tones of fish, " << this->meat << " tones of meat.\nWe have food for all the dinosaurs.";
}
