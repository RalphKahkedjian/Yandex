#include "History.h"
#include <Windows.h>

using namespace std;

void FetchHistory() {
    cout << "Fetching Your Booked Taxis\n";
    Sleep(1500);
    system("cls");
}

void History::AddBooking(const string& booking) {
    string timestamp = GetTimestamp();
    bookingHistory.push(booking + " | Booked at: " + timestamp);
}

void History::DisplayHistory() {
    int count = 1;
    FetchHistory();
    if (bookingHistory.empty()) {
        cout << "\nNo bookings have been made yet.\n";
    }
    else {
        cout << "\nBooking History\n";
        stack<string> history = bookingHistory;

        while (!history.empty()) {
            cout << count << " - " << history.top() << endl;
            history.pop();
            count++;
        }
    }
}

bool History::IsEmpty() const {
    return bookingHistory.empty();
}
