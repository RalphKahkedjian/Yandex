#ifndef TAXIS_H
#define TAXIS_H

#include <string>
using namespace std;

// Basic struct declaring attributes and a constructor

struct Taxi {
    string fcity;
    string tcity;
    double price;
    string driverName;
    int id;

    Taxi(string f, string t, double p, string d, int i)
        : fcity{ f }, tcity{ t }, price{ p }, driverName{ d }, id{ i } {};
};

void DisplayTaxis(int location);

#endif 
