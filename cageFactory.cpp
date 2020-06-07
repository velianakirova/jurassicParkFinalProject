#pragma once
#include "cageFactory.h"


bool CageFactory::isEqualto(const char* strOne, const char* strTwo) {
	int lenOne = strlen(strOne);
	int lenTwo = strlen(strTwo);
	if (lenOne != lenTwo) return false;
	for (int i = 0; i < lenOne; i++) {
		if (strOne[i] != strTwo[i]) return false;
	}
	return true;
}


Cage* CageFactory::make(const char* type) {
	Cage* newCage = nullptr;
	if (isEqualto(type, "small")) {
		newCage = new SmallCage("");
	}
	else if (isEqualto(type, "medium")) {
		newCage = new MediumCage("");
	}
	else if (isEqualto(type, "large")) {
		newCage = new LargeCage("");
	}
	else {
		throw UnknownCageType(type);
	}

	return newCage;
}



UnknownCageType::UnknownCageType(const char*& type) {
	char temp[50] = "Unknown cage type. ";
	message = new char[strlen(temp) + 1];
	for (int i = 0; i < strlen(temp) + 1; i++) {
		message[i] = temp[i];
	}
}

const char* UnknownCageType::what() const noexcept {
	return message;
}
