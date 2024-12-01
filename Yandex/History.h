#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class History {
private:

    // Declaring a queue
    queue<string> bookingHistory;

    // used the same knowledge that we used in class
    string GetTimestamp() const {
        time_t now = time(0);
        tm localTime;
        localtime_s(&localTime, &now);
        return to_string(localTime.tm_mday) + '/' +
            to_string(localTime.tm_mon + 1) + '/' +
            to_string(localTime.tm_year + 1900) + ' ' +
            to_string(localTime.tm_hour) + ':' +
            to_string(localTime.tm_min) + ':' +
            to_string(localTime.tm_sec) + ' ' +
            (localTime.tm_hour < 12 ? "AM" : "PM");
    }

public:

    void AddBooking(const string& booking);
    void DisplayHistory();
};

// It will be used in the two files (taxis.cpp and the yandex.cpp), so we decided to use the extern.

extern History BookingHistory;

#endif 

// Time Complexity: O(1) for adding a booking to the queue
// Time Complexity: O(n) for displaying booking history where n is the number of bookings in the queue

