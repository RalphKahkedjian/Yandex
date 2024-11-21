#include <iostream>
#include <set>
#include <string>
#include <Windows.h>
#include "Auth.h"

using namespace std;

bool isLoading = false;

void ValidatingUser() {
    cout << "\nPlease be patient...\n";
    cout << "Did you know Yandex Taxi is global? Yes, we are located in Armenia, Georgia, Russia, Kazakhstan...\nVisit Our Website for more.\n";
    Sleep(5000);
    isLoading = true;
}

int main() {
    set<string> emailSet;
    string name, email, password;
    int age;

    cout << "Enter your name: ";
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
    }
    else {
        cout << "An error occurred due to maintenance. Please try again later." << endl;
    }

    return 0;
}
