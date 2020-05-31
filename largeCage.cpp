#pragma once
#include "largeCage.h"


void LargeCage::copy(const LargeCage& other) {
	this->category = new char[strlen(other.category) + 1];
	this->era = new char[strlen(other.era) + 1];
	this->climate = new char[strlen(other.climate) + 1];
	this->dinosaur = new Dinosaur[other.capacity];
	for (int i = 0; i < strlen((other.category) + 1); i++) {
		this->category[i] = other.category[i];
	}
	for (int i = 0; i < strlen(other.era) + 1; i++) {
		this->era[i] = other.era[i];
	}
	for (int i = 0; i < strlen(other.climate) + 1; i++) {
		this->climate[i] = other.climate[i];
	}
	for (int i = 0; i < other.count; i++) {
		this->dinosaur[i] = other.dinosaur[i];
	}
	this->count = other.count;
	this->capacity = other.capacity;

}

void LargeCage::erase() {
	delete[] this->category;
	delete[] this->era;
	delete[] this->climate;
	delete[] this->dinosaur;
}


LargeCage::LargeCage(const char* climate) {
	this->capacity = 10;
	this->count = 0;
	this->category = nullptr;
	this->era = nullptr;
	this->climate = new char[strlen(climate) + 1];
	for (int i = 0; i < strlen(climate) + 1; i++) {
		this->climate[i] = climate[i];
	}
	this->dinosaur = new Dinosaur[this->capacity];
};

LargeCage::LargeCage(const LargeCage& other) {
	this->copy(other);
}

LargeCage& LargeCage::operator=(const LargeCage& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
	return *this;
}

LargeCage::~LargeCage() {
	this->erase();
}


string LargeCage::getCageType() const {
	return "large";
}

char* LargeCage::getClimate() const {
	return this->climate;
}

char* LargeCage::getEra() const {
	return this->era;
}

char* LargeCage::getCategory() const {
	return this->category;
}

int LargeCage::getCount() const {
	return this->count;
}

Dinosaur LargeCage::getDinosaurFromIndex(int index) {
	if (index < count) {
		return this->dinosaur[index];
	}
}


void LargeCage::setClimate(const char* climatee) {
	delete[] this->climate;
	this->climate = new char[strlen(climatee) + 1];
	for (int i = 0; i < strlen(climatee) + 1; i++) {
		this->climate[i] = climatee[i];
	}
}

void LargeCage::setEra(const char* eraa) {
	delete[] this->era;
	this->era = new char[strlen(eraa) + 1];
	for (int i = 0; i < strlen(eraa) + 1; i++) {
		this->era[i] = eraa[i];
	}
}

void LargeCage::setCategory(const char* categoryy) {
	delete[] this->category;
	this->category = new char[strlen(categoryy) + 1];
	for (int i = 0; i < strlen(categoryy) + 1; i++) {
		this->category[i] = categoryy[i];
	}
}


bool LargeCage::isEmpty() {
	if (count == 0) return true;
	return false;
}

bool LargeCage::freeSpace() {
	if (this->capacity - this->count > 0) return true;
	return false;
}

bool LargeCage::isEqual(const char* strOne, const char* strTwo) {
	int lenOne = strlen(strOne);
	int lenTwo = strlen(strTwo);
	if (lenOne != lenTwo) return false;
	for (int i = 0; i < lenOne; i++) {
		if (strOne[i] != strTwo[i]) return false;
	}
	return true;
}


void LargeCage::saveCage(ostream& out) {
	if (this->category != nullptr && this->era != nullptr) {
		out << " /large cage /: ";
		for (int i = 0; i < this->count; i++) {
			if (i == this->count - 1) out << this->dinosaur[i].getName();
			else out << this->dinosaur[i].getName() << ", ";
		}
		out << endl;
	}
}

void LargeCage::saveDinosaurs(ostream& out) {
	if (this->category != nullptr && this->era != nullptr) {
		for (int i = 0; i < this->count; i++) {
			this->dinosaur[i].saveDinosaur(out);
		}
	}
}


void LargeCage::removeDinosaurFromCage(const char* name) {
	Dinosaur* temp = new Dinosaur[count];
	for (int i = 0, j = 0; i < count; i++, j++) {
		if (dinosaur[j].getName() != NULL && isEqual(dinosaur[i].getName(), name)) {
			if (i < count - 1) {
				temp[i] = dinosaur[j + 1];
				j++;
				count--;
			}
			else {
				count--;
			}
		}
		else {
			if (dinosaur[j].getName() != NULL) {
				temp[i] = dinosaur[j];
			}

		}
	}
	delete[] this->dinosaur;
	this->dinosaur = temp;
}

void LargeCage::addNewDinosaur(const Dinosaur& dino) {
	if (count >= capacity) cout << "Full";
	else {
		if (count == 0) {
			this->dinosaur[0] = dino;
			this->category = new char[strlen(dino.getCategory()) + 1];
			this->era = new char[strlen(dino.getEra()) + 1];
			for (int j = 0; j < strlen(dino.getCategory()) + 1; j++) {
				this->category[j] = dino.getCategory()[j];
			}
			for (int j = 0; j < strlen(dino.getEra()) + 1; j++) {
				this->era[j] = dino.getEra()[j];
			}
			++count;
		}
		else if (isEqual(this->category, dino.getCategory()) && isEqual(this->era, dino.getEra())) {
			Dinosaur* temp = new Dinosaur[this->count + 1];
			for (size_t i = 0; i < this->count; ++i)
			{
				temp[i] = this->dinosaur[i];
			}
			temp[this->count] = dino;
			++count;

			delete[] this->dinosaur;
			this->dinosaur = temp;
		}
		else {
			cout << dino.getName() << " cannot coexist in the same cage with dinosaurs from other era ar category.\n";
		}
	}
}


void LargeCage::printInfo()const {
	if (this->category != nullptr && this->era != nullptr) {
		cout << "Size: " << this->count << "   ||Category: " << this->getCategory() << "   ||Era: " << this->getEra() << "   ||Climate: " << this->getClimate();
		cout << "   ||Dinosaurs: ";
		for (int i = 0; i < this->count; i++) {
			cout << this->dinosaur[i].getName() << " ";
		}
		cout << endl;

	}

}