#include "Feedback.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

//Taxi's feedback
void FeedbackSystem::AddFeedback(const string& comment) {

    //Push new object into the stack
    Feedback newFeedback(comment);
    feedbackStack.push(newFeedback);

    Sleep(1000);
    cout << "Thank you for your feedback! We'll Get Back To You Soon\n";
}
