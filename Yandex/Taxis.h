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

// Time Complexity: O(1) for constructor initialization
// Time Complexity: O(n) for searching taxis in DisplayTaxis where n is the number of taxis in the selected location
