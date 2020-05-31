#pragma once
#include <stdexcept>

#include "cage.h"
#include "smallCage.h"
#include "mediumCage.h"
#include "largeCage.h"

class CageFactory {
public:
	static Cage* make(const char*);
	static bool isEqualto(const char* strOne, const char* strTwo);
};

class UnknownCageType : public exception {
public:
	UnknownCageType(const char*&);
	const char* what() const noexcept;
private:
	char* message;
};