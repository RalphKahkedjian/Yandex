#include "Auth.h"
#include "Taxis.h"
#include "History.h"
#include <iostream>
#include <set>
#include <string>
#include <Windows.h>

using namespace std;

bool isLoading = false;

void printHeader() {
    string border = "*************************************";
    string title = "Yandex Taxi";
    int padding = (border.length() - title.length()) / 2;
    cout << border << endl;

    cout << "*";
    for (int i = 0; i < padding; i++) cout << " ";
    cout << title;
    for (int i = 0; i < padding; i++) cout << " ";
    cout << "*" << endl;
    cout << border << endl;
}

void ValidatingUser() {
    cout << "\nPlease be patient...\n";
    cout << "Did you know Yandex Taxi is global? Yes, we are located in Armenia, Georgia, Russia, Kazakhstan...\nVisit Our Website to know more about Yandex Taxi Service.\n";
    Sleep(5000);
    isLoading = true;
}

int main() {
    set<string> emailSet;
    string name, email, password;
    int age;
    int locationChoice;
    char userChoice;
    string location;

    printHeader();

    cout << endl;
    cout << "\tSign up\n";

    cout << "\nEnter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your password: ";
    getline(cin, password);

    cout << "Enter your age: ";
    cin >> age;

    ValidatingUser();

    if (isLoading) {
        Auth auth(name, email, password, age);
        Sleep(1500);
        system("cls");

        do {
            cout << "\n1. Book a ride \n";
            cout << "2. View Profile\n";
            cout << "3. View Booking History\n";
            cout << "Enter your choice, or any other key to exit: ";
            cin >> userChoice;

            system("cls");
            switch (userChoice) {
            case '1':
                cout << "\t\nBook A Taxi\n\n";

                cout << "Choose a location to see available taxis:" << endl;
                cout << "1. Armenia" << endl;
                cout << "2. Georgia" << endl;
                cout << "3. Russia" << endl;
                cout << "Enter your choice (1-3): ";
                cin >> locationChoice;
                cin.ignore();

                cout << endl;
                DisplayTaxis(locationChoice);
                break;

            case '2':
                cout << "\t\nUser Profile\n\n";
                auth.DisplayProfile();
                break;

            case '3':
                cout << "\t\nBooking History\n\n";
                BookingHistory.DisplayHistory();
                break;

            default:
                cout << "Exiting the application.\n";
                return 0;
            }

            cout << "\nDo you want to continue? (y/n): ";
            cin >> userChoice;
            system("cls");

        } while (userChoice == 'y' || userChoice == 'Y');
    }
    else {
        cout << "An error occurred due to maintenance. Please try again later." << endl;
    }

    return 0;
}
