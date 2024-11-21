#include "Auth.h"
#include <iostream>
#include <cstdlib>

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

    cout << "\n Welcome to Yandex Taxi! \n" << endl;
}
