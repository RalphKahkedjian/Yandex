#include "Taxis.h"
#include "History.h"
#include <iomanip> 
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// Map where it has int key, and the value vector (calling the constructor in the taxi header file) which has the taxi data
map<int, vector<Taxi>> taxiData = {
    {1, {
        Taxi("Yerevan", "Dilijan", 500.00, "Tigran", 101),
        Taxi("Gyumri", "Stepanakert", 399.99, "Aram", 221),
        Taxi("Shushi", "Vanadzor", 450.50, "Artur", 333),
        Taxi("Vagharshapat", "Yerevan", 670.25, "Arayik", 402)
    }},
    {2, {
        Taxi("Tbilisi", "Batumi", 400.0, "Giorgi", 1011),
        Taxi("Tbilisi", "Kutaisi", 450.0, "Nika", 2910),
        Taxi("Batumi", "Zugdidi", 350.0, "Tamar", 1290)
    }},
    {3, {
        Taxi("Moscow", "St. Petersburg", 300.0, "Ivan", 21),
        Taxi("Moscow", "Kazan", 350.0, "Alexei", 43),
        Taxi("St. Petersburg", "Sochi", 400.0, "Olga", 23)
    }}
};

// Function to check if Taxi is available or not and added a timeout

void CheckAvailability() {
    cout << "Checking If Available...\n";
    Sleep(2000);
}

// Function where the user would either wait for the taxi, or he/she could cancel it before arriving

void WaitOrCancel() {
    char choice;
    cout << "Do you wish to cancel the ride? Enter Q for yes, and any other key if no. \n";
    cin >> choice;
    if (choice == 'q' || choice == 'Q') {
        exit(0);
    }

    // For fun, we added DYK using map while the user is waiting for the taxi, By generating random value below, it will choose 1/3 following statements.
    map<int, string> didYouKnow = {
       {0, "Yandex Taxi is one of the leading ride-hailing services in Russia, operating in over 15 countries worldwide.\n"},
       {1, "Yandex Taxi offers various ride options, including economy, comfort, and business class, catering to a wide range of customer needs.\n"},
       {2, "Yandex Taxi drivers use a special app that helps them navigate efficiently, optimizing routes and reducing waiting times for passengers.\n"}
    };

    srand(time(0));
    int randomIndex = rand() % 3;
    cout << didYouKnow[randomIndex] << endl;
    char userInput = ' ';
 
    cout << "Waiting for the taxi to arrive..." << endl;
    Sleep(2000);
    system("cls");

    cout << "Taxi has arrived!\n";
    int price = 10 + rand() % 30;           // Price will be between 10 and 30 euros
    int pay;
    cout << "Pay " << price << " �\n";
    cout << "Paying: ";
    cin >> pay;

    cout << "Driver checking the payment...\n";
    Sleep(1000);

    if (pay > price * 2) {                  // if the user paid double the price, the drivr will return the remaining change
        int change = pay - price;
        cout << "\nThank you and " << change << "� is for you. " << "Enjoy your day\n";
    }
    else if (pay > price) {                // if it's not the double, assume that the user paid extra tips
        cout << "\nThank you for riding with us and for your additional tips!\n";
    }
    else if (pay == price) {
        cout << "\nThank you for riding with us, Enjoy your day!\n";
    }
    else {
        cout << "\nSee you in jail\n";
    }
}

void DisplayTaxis(int choice) {
    if (taxiData.find(choice) == taxiData.end()) {
        cout << "Invalid choice.\n";
        return;
    }

    // The following will be filled based on which location the user chose and which booking id
    vector<Taxi> taxis = taxiData[choice];
    for (const auto& taxi : taxis) {
        cout << "From: " << taxi.fcity << " to: " << taxi.tcity << endl;
        cout << "Price: " << fixed << setprecision(2) << taxi.price << " �" << endl;
        cout << "Driver: " << taxi.driverName << endl;
        cout << "ID: " << taxi.id << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }

    // The user should enter a specific booking ID based on the output so he/she can book
    int id;
    cout << "Enter the booking ID you want to order: \n";
    cin >> id;

    bool isIdFound = false;

    // Foreach taxi in taxis
    for (const auto& taxi : taxis) {
        if (taxi.id == id) {
            isIdFound = true;

            // Created a random number generator from 1 to 3, if random = 1 | 2, then the driver is available, else if 3 then busy ( to make it more realistic only  

            int random = 1 + rand() % 3;
            CheckAvailability();
            if (random == 1 || random == 2) {           
                cout << "Taxi with ID " << id << " is free for booking." << endl;
                WaitOrCancel();
                BookingHistory.AddBooking("| Booking ID: " + to_string(id) +
                    ", From: " + taxi.fcity +
                    ", To: " + taxi.tcity +
                    ", Driver: " + taxi.driverName +
                    ", Price: " + to_string(taxi.price) + " �");
            }
            else {
                cout << "Taxi with ID " << id << " is busy in a ride." << endl;
            }
            break;
        }
    }

    // If user entered an ID not found in the taxiData

    if (!isIdFound) {
        cout << "No such taxi ID found.\n";
    }
}

