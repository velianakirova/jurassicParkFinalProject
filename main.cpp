#include "cage.h"
#include "smallCage.h"
#include "mediumCage.h"
#include "largeCage.h"
#include "cageFactory.h"
#include "foodFactory.h"
#include "personnel.h"
using namespace std;

vector<Cage*> cages;
Warehouse warehouse;
Personnel personnel;
const char* filePath = "parkInformation.txt";



bool isEquall(const char* strOne, const char* strTwo) {
	int lenOne = strlen(strOne);
	int lenTwo = strlen(strTwo);
	if (lenOne != lenTwo) return false;
	for (int i = 0; i < lenOne; i++) {
		if (strOne[i] != strTwo[i]) return false;
	}
	return true;
}

bool ifDinosaurExist(const vector<Cage*> cagesN, const char* name) {
	for (int i = 0; i < cagesN.size(); i++) {
		for (int j = 0; j < cagesN[i]->getCount(); j++) {
			if (isEquall(cagesN[i]->getDinosaurFromIndex(j).getName(), name)) {
				return true;
			}
		}
	}
	return false;
}


void loadParkInformation(const char* file) {
	ifstream info;
	info.open(file, ios::in);
	cout << "Hello, dear visitor. We present you the information about our park: \n";
	if (info.is_open()) {
		char line[200];
		while (!info.eof()) {
			info.getline(line, 200);
			cout << line << endl;
		}
		info.close();
	}
	else cout << "There was a problem loading the information." << endl;
}

int main() {
	loadParkInformation(filePath);
	ofstream out;
	out.open("parkInformationAfterChanges.txt", ios::out);


	//създаваме динозаври и предварително ги разпределяме по клетки
	cages.clear();
	Dinosaur dinko("Dinko", "Male", "triassic", "carnivorous", "chindesaurus", "meat"), deina("Deina", "Female", "cretaceous", "herbivorous", "achelousaurus", "grass"), alla("Alla", "Female", "jurassik", "aquatic", "pleisosaurus", "fish"),
		rex("Rex", "Male", "triassic", "carnivorous", "coelophysis", "meat"), lena("Lena", "Female", "cretaceous", "herbivorous", "amargasaurus", "grass"), mega("Mega", "Female", "jurassik", "aquatic", "scelidosaurus", "fish"),
		nino("Nino", "Male", "triassic", "carnivorous", "herrerasaurus", "meat"), tyranno("Tyranno", "Male", "cretaceous", "herbivorous", "cedarpelta", "grass"), elasmo("Elasmo", "Male", "jurassik", "aquatic", "mozasaurus", "fish");

	SmallCage smallOne("cold");//, smallTwo(""), smallThree("");
	MediumCage mediumOne("hot"), mediumTwo("cold");//, mediumThree("");
	LargeCage largeOne("nice");//, largeTwo("");
	smallOne.addNewDinosaur(dinko);
	mediumOne.addNewDinosaur(rex);
	mediumOne.addNewDinosaur(nino);
	mediumTwo.addNewDinosaur(deina);
	mediumTwo.addNewDinosaur(tyranno);
	mediumTwo.addNewDinosaur(lena);
	largeOne.addNewDinosaur(alla);
	largeOne.addNewDinosaur(mega);
	largeOne.addNewDinosaur(elasmo);

	cages.push_back(&smallOne);
	//cages.push_back(&smallTwo);
	//cages.push_back(&smallThree);
	cages.push_back(&mediumOne);
	cages.push_back(&mediumTwo);
	//cages.push_back(&mediumThree);
	cages.push_back(&largeOne);
	//cages.push_back(&largeTwo);

	//запазваме по 1 тон храна и назначаваме по 3-ма работници за всеки динозавър
	for (int i = 0; i < cages.size(); i++) {
		int len = cages[i]->getCount();
		for (int j = 0; j < len; j++) {
			warehouse.storeFood(cages[i]->getDinosaurFromIndex(j).getFood());
			personnel.addNewWorkers();
		}
	}

	cout << " ------------------------------------------------------";
	cout << "\n|                       M E N U:                       |\n";
	cout << "|------------------------------------------------------|\n";
	cout << "|PRESS 1|  Add new dinosaur                            |\n|-------|----------------------------------------------|\n";
	cout << "|PRESS 2|  Remove existing dinosaur                    |\n|-------|----------------------------------------------| \n";
	cout << "|PRESS 3|  Build new cage                              |\n|-------|----------------------------------------------| \n";
	cout << "|PRESS 4|  See warehouse and personnel information     |\n|-------|----------------------------------------------| \n";
	cout << "|PRESS 5|  Exit                                        |";
	cout << "\n ------------------------------------------------------\n";

	int choice;
	cout << "\nYour choice: ";
	cin >> choice;
	while (choice != 5) {
		if (choice == 1) {
			cout << "Please, enter the following information: \n";
			Dinosaur newDinosaur;
			char choiceOne[15];
			cout << "Name: ";
			cin.ignore();
			cin.getline(choiceOne, 15);
			newDinosaur.setName(choiceOne);
			cout << "Gender: ";
			cin.getline(choiceOne, 15);
			newDinosaur.setGender(choiceOne);
			cout << "Era: ";
			cin.getline(choiceOne, 15);
			newDinosaur.setEra(choiceOne);
			cout << "Category: ";
			cin.getline(choiceOne, 15);
			newDinosaur.setCategory(choiceOne);
			cout << "Kind: ";
			cin.getline(choiceOne, 15);
			newDinosaur.setKind(choiceOne);
			cout << "Food: ";
			cin.getline(choiceOne, 15);
			newDinosaur.setFood(choiceOne);

			warehouse.storeFood(newDinosaur.getFood());
			personnel.addNewWorkers();

			//проверяваме дали в парка има свободна/подходяща клетка за новия динозавър
			bool added = false;
			for (int i = 0; i < cages.size(); i++) {
				if (cages[i]->freeSpace()) {
					if (cages[i]->getCategory() == nullptr && cages[i]->getEra() == nullptr || isEquall(cages[i]->getCategory(), newDinosaur.getCategory()) && isEquall(cages[i]->getEra(), newDinosaur.getEra())) {
						cages[i]->addNewDinosaur(newDinosaur);
						cout << "Dinosaur "<< newDinosaur.getName() <<" has been successfully added.\n";
						added = true;
						break;
					}
				}
			}

			//ако няма място в подходяща клетка за новия динозавър, то ще му построим нова и ще го добавим в нея
			if (added == false) {
				cout << "We do not have a proper cage for your dinosaur. Do you want to build a new cage?(Y/N)";
				char yesOrNo;
				cin >> yesOrNo;
				if (yesOrNo == 'Y' || yesOrNo == 'y') {
					cout << "What type of cage do you want to build?\n -small \n -medium \n -large\n";
					cout << "\n >> ";
					cin.ignore();
					cin.getline(choiceOne, 15);
					try {
						cout << "Please, enter the climate: ";
						char climateChoice[10];
						cin.getline(climateChoice, 10);
						cages.push_back(CageFactory::make(choiceOne));
						cages[cages.size() - 1]->addNewDinosaur(newDinosaur);
						cages[cages.size() - 1]->setClimate(climateChoice);
						cout << "\nThe cage has been successfully builded.\n";
					}
					catch (const UnknownCageType& choiceThree) {
						cerr << choiceThree.what() << std::endl;
					}


				}
				else {
					cout << "\nYour next choice: ";
					cin >> choice;
				}
			}

			cout << "\nYour next choice: ";
			cin >> choice;
		}
		else if (choice == 2) {
			cout << "Which dinosaur do you want to remove?\n >> ";
			char choiceTwo[10];
			cin.ignore();
			cin.getline(choiceTwo, 10);
			
			
			if (ifDinosaurExist(cages, choiceTwo)) {
				cout << "\nDinosaur " << choiceTwo << " has been successfully removed.\n";
				Cage::removeDinosaur(cages, choiceTwo);
				personnel.removeWorkers();
			}
			else cout << "Dinosaur with that name was not found.\n";

			cout << "\nYour next choice: ";
			cin >> choice;
		}
		else if (choice == 3) {
			cout << "What type of cage do you want to build?\n -small \n -medium \n -large\n";
			cout << "\n >> ";
			char choiceThree[10];
			cin.ignore();
			cin.getline(choiceThree, 10);
			try {
				cages.push_back(CageFactory::make(choiceThree));
				cout << "\nThe cage has been successfully builded.\n";
			}
			catch (const UnknownCageType& choiceThree) {
				cerr << choiceThree.what() << std::endl;
			}

			cout << "\nYour next choice: ";
			cin >> choice;
		}
		else if (choice == 4) {
			cout << "________________________________________________________________________________________\n\nPersonnel:\n";
			personnel.printInfo();
			cout << "\nWarehouse:\n";
			warehouse.printInfo();
			cout << "\n______________________________________________________________________________________\n";

			cout << "\nYour next choice: ";
			cin >> choice;
		}
		else {
			cout << "\nInvalid option. Please, enter a valid number.\n >>";
			cin >> choice;
		}
	}

	out << "Name  |   Gender   |   Era   |   Category    |   Kind    |   Food   |" << endl;
	out << "--------------------------------------------------------------------" << endl;

	//запазваме промените на данните за наличните в парка динозаври
	for (int i = 0; i < cages.size(); i++) {
		cages[i]->saveDinosaurs(out);
	}

	//запазваме инф. за непразните клетки след промените
	for (int i = 0; i < cages.size(); i++) {
		if (!cages[i]->isEmpty()) {
        out << "Cage " << i + 1;
		cages[i]->saveCage(out);
		}
		
	}


	//запазваме инф. за празните клетки след промените
	int smallEmptyCages = 0;
	int mediumEmptyCages = 0;
	int largeEmptyCages = 0;
	for (int i = 0; i < cages.size(); i++) {
		if (cages[i]->isEmpty()) {
			if (cages[i]->getCageType() == "small") { smallEmptyCages++; }
			else if (cages[i]->getCageType() == "medium") { mediumEmptyCages++; }
			else { largeEmptyCages++; }
		}
	}

	out << "Empty cages: \n" << "Small cages: " << smallEmptyCages << "\nMedium cages: " << mediumEmptyCages << "\nLarge cages: " << largeEmptyCages;
	
	cout << "\nYour changes have been saved in file 'parkInformationAfterChanges.txt'.\nHope you had fun. \n";
	cout << "--------------------------------------------------------------------------\n";
	return 0;
}
