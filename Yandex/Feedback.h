// TBS by Johnny

#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>
#include <stack>
#include <list>

using namespace std;

struct Feedback {
    string comment;       //If the user wants to add an optional comment

    Feedback(const string& c) : comment(c) {}
};

class FeedbackSystem {
private:
    stack<Feedback> feedbackStack;  //Storing feedbacks

public:
    //Adding feedbacks
    void AddFeedback(const string& comment);
};

#endif