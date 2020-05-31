#pragma once
#include "mediumCage.h"

void MediumCage::copy(const MediumCage& other) {
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

void MediumCage::erase() {
	delete[] this->category;
	delete[] this->era;
	delete[] this->climate;
	delete[] this->dinosaur;
}


MediumCage::MediumCage(const char* climate) {
	this->capacity = 3;
	this->count = 0;
	this->category = nullptr;
	this->era = nullptr;
	this->climate = new char[strlen(climate) + 1];
	for (int i = 0; i < strlen(climate) + 1; i++) {
		this->climate[i] = climate[i];
	}
	this->dinosaur = new Dinosaur[this->capacity];
};

MediumCage::MediumCage(const MediumCage& other) {
	this->copy(other);
}

MediumCage& MediumCage::operator=(const MediumCage& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
	return *this;
}

MediumCage::~MediumCage() {
	this->erase();
}

string MediumCage::getCageType() const {
	return "medium";
}

char* MediumCage::getClimate() const {
	return this->climate;
}

char* MediumCage::getEra() const {
	return this->era;
}

char* MediumCage::getCategory() const {
	return this->category;
}

int MediumCage::getCount() const {
	return this->count;
}


void MediumCage::setClimate(const char* climatee) {
	delete[] this->climate;
	this->climate = new char[strlen(climatee) + 1];
	for (int i = 0; i < strlen(climatee) + 1; i++) {
		this->climate[i] = climatee[i];
	}
}

void MediumCage::setEra(const char* eraa) {
	delete[] this->era;
	this->era = new char[strlen(eraa) + 1];
	for (int i = 0; i < strlen(eraa) + 1; i++) {
		this->era[i] = eraa[i];
	}
}

void MediumCage::setCategory(const char* categoryy) {
	delete[] this->category;
	this->category = new char[strlen(categoryy) + 1];
	for (int i = 0; i < strlen(categoryy) + 1; i++) {
		this->category[i] = categoryy[i];
	}
}


bool MediumCage::isEmpty() {
	if (count == 0) return true;
	return false;
}

bool MediumCage::freeSpace() {
	if (this->capacity - this->count > 0) return true;
	return false;
}

bool MediumCage::isEqual(const char* strOne, const char* strTwo) {
	int lenOne = strlen(strOne);
	int lenTwo = strlen(strTwo);
	if (lenOne != lenTwo) return false;
	for (int i = 0; i < lenOne; i++) {
		if (strOne[i] != strTwo[i]) return false;
	}
	return true;
}


void MediumCage::saveCage(ostream& out) {
	if (this->category != nullptr && this->era != nullptr){
		out << " /medium cage /: ";
		for (int i = 0; i < this->count; i++) {
			if (i == this->count - 1 ) out << this->dinosaur[i].getName();
			else out << this->dinosaur[i].getName() << ", ";
		}
		out << endl;
	}
}

void MediumCage::saveDinosaurs(ostream& out) {
	if (this->category != nullptr && this->era != nullptr) {
		for (int i = 0; i < this->count; i++) {
			this->dinosaur[i].saveDinosaur(out);
		}
	}
}


void MediumCage::removeDinosaurFromCage(const char* name) {
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

void MediumCage::addNewDinosaur(const Dinosaur& dino) {
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


void MediumCage::printInfo()const {
	if (this->category != nullptr && this->era != nullptr) {
		cout << "Size: " << this->count << "   ||Category: " << this->getCategory() << "   ||Era: " << this->getEra() << "   ||Climate: " << this->getClimate();
		cout << "   ||Dinosaurs: ";
		for (int i = 0; i < this->count; i++) {
			cout << this->dinosaur[i].getName() << " ";
		}
		cout << endl;

	}

}

Dinosaur MediumCage::getDinosaurFromIndex(int index) {
	if (index < count) {
		return this->dinosaur[index];
	}
}