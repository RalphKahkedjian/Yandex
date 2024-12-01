#include "History.h"
#include <iostream>
#include <Windows.h>
using namespace std;

History BookingHistory;

// Pushing the Time which is declared in the header file + the booking
void History::AddBooking(const string& booking) {
    bookingHistory.push(GetTimestamp() + booking);
}

// Function to Fetch history if empty or not ( to make it more realistic )

void History::DisplayHistory() {
    cout << "Fetching Your Booked Taxis History...\n";
    Sleep(1200);

    if (bookingHistory.empty()) {
        cout << "No booking history available.\n";
        return;
    }

    queue<string> history = bookingHistory;
    cout << "\nBooking History:\n";
    while (!history.empty()) {                      // If Queue not empty, then display
        cout << "- " << history.front() << endl;
        history.pop();
    }
}
