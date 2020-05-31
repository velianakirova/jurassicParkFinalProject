#pragma once
#include "dinosaur.h"


void Dinosaur::copy(const Dinosaur& other) {
	this->name = new char[strlen(other.name) + 1];
	this->gender = new char[strlen(other.gender) + 1];
	this->era = new char[strlen(other.era) + 1];
	this->category = new char[strlen(other.category) + 1];
	this->kind = new char[strlen(other.kind) + 1];
	this->food = new char[strlen(other.food) + 1];

	for (int i = 0; i < strlen(other.name) + 1; i++) {
		this->name[i] = other.name[i];
	}
	for (int i = 0; i < strlen(other.gender) + 1; i++) {
		this->gender[i] = other.gender[i];
	}
	for (int i = 0; i < strlen(other.era) + 1; i++) {
		this->era[i] = other.era[i];
	}
	for (int i = 0; i < strlen(other.category) + 1; i++) {
		this->category[i] = other.category[i];
	}
	for (int i = 0; i < strlen(other.kind) + 1; i++) {
		this->kind[i] = other.kind[i];
	}
	for (int i = 0; i < strlen(other.food) + 1; i++) {
		this->food[i] = other.food[i];
	}
}

void Dinosaur::erase() {
	delete[] this->name;
	delete[] this->gender;
	delete[] this->era;
	delete[] this->category;
	delete[] this->kind;
	delete[] this->food;
}

Dinosaur::Dinosaur() {
	this->name = nullptr;
	this->gender = nullptr;
	this->era = nullptr;
	this->category = nullptr;
	this->kind = nullptr;
	this->food = nullptr;

};

Dinosaur::Dinosaur(const char* name, const char* gender, const char* era, const char* category, const char* kind, const char* food) {
	this->name = new char[strlen(name) + 1];
	this->gender = new char[strlen(gender) + 1];
	this->era = new char[strlen(era) + 1];
	this->category = new char[strlen(category) + 1];
	this->kind = new char[strlen(kind) + 1];
	this->food = new char[strlen(food) + 1];

	for (int i = 0; i < strlen(name) + 1; i++) {
		this->name[i] = name[i];
	}
	for (int i = 0; i < strlen(gender) + 1; i++) {
		this->gender[i] = gender[i];
	}
	for (int i = 0; i < strlen(era) + 1; i++) {
		this->era[i] = era[i];
	}
	for (int i = 0; i < strlen(category) + 1; i++) {
		this->category[i] = category[i];
	}
	for (int i = 0; i < strlen(kind) + 1; i++) {
		this->kind[i] = kind[i];
	}
	for (int i = 0; i < strlen(food) + 1; i++) {
		this->food[i] = food[i];
	}

}

Dinosaur::Dinosaur(const Dinosaur& other) {
	this->copy(other);
}

Dinosaur& Dinosaur::operator=(const Dinosaur& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
	return*this;
}

Dinosaur::~Dinosaur() {
	this->erase();
}


char* Dinosaur::getName()const {
	return this->name;
}

char* Dinosaur::getEra() const {
	return this->era;
}

char* Dinosaur::getCategory() const {
	return this->category;
}

char* Dinosaur::getFood() const {
	return this->food;
}


void Dinosaur::setName(const char* Name) {
	delete[] this->name;
	this->name = new char[strlen(Name) + 1];
	for (int i = 0; i < strlen(Name) + 1; i++) {
		this->name[i] = Name[i];
	}
}

void Dinosaur::setGender(const char* gender) {
	delete[] this->gender;
	this->gender = new char[strlen(gender) + 1];
	for (int i = 0; i < strlen(gender) + 1; i++) {
		this->gender[i] = gender[i];
	}
}

void Dinosaur::setEra(const char* era) {
	delete[] this->era;
	this->era = new char[strlen(era) + 1];
	for (int i = 0; i < strlen(era) + 1; i++) {
		this->era[i] = era[i];
	}
}

void Dinosaur::setCategory(const char* category) {
	delete[] this->category;
	this->category = new char[strlen(category) + 1];
	for (int i = 0; i < strlen(category) + 1; i++) {
		this->category[i] = category[i];
	}
}

void Dinosaur::setKind(const char* kind) {
	delete[] this->kind;
	this->kind = new char[strlen(kind) + 1];
	for (int i = 0; i < strlen(kind) + 1; i++) {
		this->kind[i] = kind[i];
	}
}

void Dinosaur::setFood(const char* food) {
	delete[] this->food;
	this->food = new char[strlen(food) + 1];
	for (int i = 0; i < strlen(food) + 1; i++) {
		this->food[i] = food[i];
	}
}

void Dinosaur::saveDinosaur(ostream& out) {

	out << name << "   | " << " " << gender << "  |  " << era << "  |  " << category << "  |  " << kind << "  |   " << food << endl;
}


void Dinosaur::printInfo() const {
	for (int i = 0; i < strlen(this->name) + 1; i++) {
		cout << this->name[i];
	}
	for (int i = 0; i < strlen(this->gender) + 1; i++) {
		cout << this->gender[i];
	}
	for (int i = 0; i < strlen(this->era) + 1; i++) {
		cout << this->era[i];
	}
	for (int i = 0; i < strlen(this->category) + 1; i++) {
		cout << this->category[i];
	}
	for (int i = 0; i < strlen(this->kind) + 1; i++) {
		cout << this->kind[i];
	}
	for (int i = 0; i < strlen(this->food) + 1; i++) {
		cout << this->food[i];
	}
	cout << endl;
}