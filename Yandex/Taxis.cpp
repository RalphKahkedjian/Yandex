#include "Taxis.h"
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void CheckAvailability() {
    cout << "Checking If Available...\n";
    Sleep(2000);  
}

void WaitOrCancel() {
    char choice;
    cout << "Do you wish to cancel the ride ? Enter Q for yes, and any other key if no. \n";
    cin >> choice;
    if (choice == 'q' || choice == 'Q') {
        exit(0);
    }
    map<int, string> didYouKnow = {
       {0, "Yandex Taxi is one of the leading ride-hailing services in Russia, operating in over 15 countries worldwide.\n"},
       {1, "Yandex Taxi offers various ride options, including economy, comfort, and business class, catering to a wide range of customer needs.\n"},
       {2, "Yandex Taxi drivers use a special app that helps them navigate efficiently, optimizing routes and reducing waiting times for passengers.\n"}
    };

    srand(time(0));
    int randomIndex = rand() % 3;
    cout << didYouKnow[randomIndex] << endl;
    char userInput = ' ';
    cout << "Time remaining for the taxi to arrive:  \n";
 
    cout << "Waiting for the taxi to arrive..." << endl;
    Sleep(1000);  


    cout << "Taxi has arrived!\n";
    int price = 10 + rand() % 30;
    int pay;
    cout << "Pay " << price << " €\n";
    cout << "Paying: ";
    cin >> pay;
    if (pay > price * 2) {
        int change = price - pay;
        cout << "\nThank you and " <<  change << "€ is for you. "<< "Enjoy your day\n";
    }
    else if (pay > price) {
        cout << "\nThank you for riding with us and for your additional tips!\n";
    }
    else if (pay == price) {
        cout << "\nThank you for riding with us, Enjoy your day!\n";
    }
    else {
        cout << "See you in jail\n";
    }
}

void DisplayTaxis(int choice) {
    vector<Taxi> taxis;
    srand(time(0));

    switch (choice) {
    case 1:
        taxis.push_back(Taxi("Yerevan", "Dilijan", 500.00, "Tigran", 101));
        taxis.push_back(Taxi("Gyumri", "Stepanakert", 399.99, "Aram", 221));
        taxis.push_back(Taxi("Shushi", "Vanadzor", 450.50, "Artur", 333));
        taxis.push_back(Taxi("Vagharshapat", "Yerevan", 670.25, "Arayik", 402));
        break;
    case 2:
        taxis.push_back(Taxi("Tbilisi", "Batumi", 400.0, "Giorgi", 1011));
        taxis.push_back(Taxi("Tbilisi", "Kutaisi", 450.0, "Nika", 2910));
        taxis.push_back(Taxi("Batumi", "Zugdidi", 350.0, "Tamar", 1290));
        break;
    case 3:
        taxis.push_back(Taxi("Moscow", "St. Petersburg", 300.0, "Ivan", 21));
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

    int id;
    cout << "Enter the booking ID you want to order: \n";
    cin >> id;

    bool isIdFound = false;
    for (const auto& taxi : taxis) {
        if (taxi.id == id) {
            isIdFound = true;
            int random = 1 + rand() % 3;
            CheckAvailability();
            if (random == 1 || random == 2) {
                cout << "Taxi with ID " << id << " is free for booking." << endl;
                WaitOrCancel();
            }
            else{
                cout << "Taxi with ID " << id << " is busy in a ride." << endl;
            }
            break;
        }
    }

    if (!isIdFound) {
        cout << "No such taxi ID found.\n";
    }
}
