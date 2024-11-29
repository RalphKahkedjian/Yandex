#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <regex>  // ( We read that on the internet )

using namespace std;

struct Auth {
    string name;
    string email;
    string password;
    int age;

    Auth(string n, string e, string p, int a);

    void DisplayProfile() const;
};

#endif
