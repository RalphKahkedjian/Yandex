#include "Taxis.h"
#include <iostream>
#include <vector>

using namespace std;

void DisplayTaxis(int choice) {
	vector<Taxi> taxis;

	switch (choice) {
	case 1:
		taxis.push_back(Taxi("Yerevan", "Dilijan", 500.00, "Tigran", 101));
		taxis.push_back(Taxi("Gyumri", "Stepanakert", 399.99, "Aram",221));
		taxis.push_back(Taxi("Shushi", "Vanadzor", 450.50, "Artur", 333));
		taxis.push_back(Taxi("Vagharshapat", "Yerevan", 670.25, "Arayik", 402));
		break;
	case 2:
		taxis.push_back(Taxi("Tbilisi", "Batumi", 400.0, "Giorgi", 1011));
		taxis.push_back(Taxi("Tbilisi", "Kutaisi", 450.0, "Nika", 2910));
		taxis.push_back(Taxi("Batumi", "Zugdidi", 350.0, "Tamar", 1290));
		break;
	case 3:
		taxis.push_back(Taxi("Moscow", "St. Petersburg", 300.0, "Ivan",21));
		taxis.push_back(Taxi("Moscow", "Kazan", 350.0, "Alexei", 43));
		taxis.push_back(Taxi("St. Petersburg", "Sochi", 400.0, "Olga", 23));
		break;
	default:
		cout << "Invalid choice.\n";
		return;
	}

	for (const auto& taxi : taxis) {
		cout << "From: " << taxi.fcity << " to: " << taxi.tcity << endl;
		cout << "Price: " << taxi.price << endl;
		cout << "Driver: " << taxi.driverName << endl;
		cout << "ID: " << taxi.id << endl;
		cout << "---------------------------------" << endl;

		cout << endl;
	}
}