#include "Auth.h"
#include "Taxis.h"
#include "History.h"
#include "Feedback.h"
#include <iostream>
#include <set>
#include <string>
#include <Windows.h>

using namespace std;

bool isLoading = false;

// Function for printing asterisks to design the navbar
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

// Function to Validate User Authentication
void ValidatingUser() {
    cout << "\nPlease be patient...\n";
    cout << "Did you know Yandex Taxi is global? Yes, we are located in Armenia, Georgia, Russia, Kazakhstan...\nVisit Our Website to know more about Yandex Taxi Service.\n";
    Sleep(5000);
    isLoading = true;
    system("cls");
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

    if (isLoading) {                                // If Validation went right then enter the if condition
        Auth auth(name, email, password, age);      // Calling the constructor
        FeedbackSystem feedbackSystem;             // Create an instance of FeedbackSystem
        Sleep(1500);                                // Set a timeout
        system("cls");                              // Clearing the terminal

        do {
            cout << "\n1. Book a ride \n";
            cout << "2. View Profile\n";
            cout << "3. View Booking History\n";
            cout << "4. Provide Feedback\n";        // Added feedback option
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

            case '4': {
                cout << "\t\nProvide Feedback\n\n";
                string comment;
                cin.ignore(); // Clear the input buffer
                cout << "Enter your feedback: ";
                getline(cin, comment);
                feedbackSystem.AddFeedback(comment);
                break;
            }

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


// Time Complexity: O(1) for signup and authentication
// Time Complexity: O(n) for booking and viewing the taxi list where n is the number of taxis in the selected region

