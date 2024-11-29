#include "Auth.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

Auth::Auth(string n, string e, string p, int a)
    : name{ n }, email{ e }, password{ p }, age{ a } {
    if (age < 18) {
        cout << "Error: You have no access to use Yandex Taxi application." << endl;
        exit(0);
    }

    regex emailRegex(R"((\w+)(\.{1}\w+)?@\w+\.\w+)");
    if (!regex_match(email, emailRegex)) {
        cout << "Error: Invalid email format." << endl;
        exit(0);
    }

    cout << "\nWelcome to Yandex Taxi! \n" << endl;
}

void Auth::DisplayProfile() const {
    
    cout << left << setw(15) << "Name:" << name << endl;
    cout << left << setw(15) << "Email:" << email << endl;
    cout << left << setw(15) << "Password:" << "******" << endl;
    cout << left << setw(15) << "Age:" << age << endl;
}
