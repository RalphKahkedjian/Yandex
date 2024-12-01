#include "History.h"
#include <iostream>
#include <Windows.h>
using namespace std;

History BookingHistory;

void History::AddBooking(const string& booking) {
    bookingHistory.push(GetTimestamp() + booking);
}

void History::DisplayHistory() {
    cout << "Fetching Your Booked Taxis History...\n";
    Sleep(1200);

    if (bookingHistory.empty()) {
        cout << "No booking history available.\n";
        return;
    }

    queue<string> history = bookingHistory;
    cout << "\nBooking History:\n";
    while (!history.empty()) {
        cout << "- " << history.front() << endl;
        history.pop();
    }
}
