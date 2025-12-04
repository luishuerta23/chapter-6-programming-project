#include <iostream>
using namespace std;

/*
    getScore
    Prompts the user to enter a judge's score between 0 and 10.
    Preconditions:
        - Input must be numeric and must fall within the inclusive range [0, 10].
    Postconditions:
        - Returns a validated double score to the caller.
*/
double getScore();

/*
    isLower
    Accepts two numbers and returns true if the first value
    is less than or equal to the second value.
    Postconditions:
        - Returns a Boolean result.
*/
bool isLower(double a, double b);

/*
    isHigher
    Accepts two numbers and returns true if the first value
    is greater than or equal to the second value.
    Postconditions:
        - Returns a Boolean result.
*/
bool isHigher(double a, double b);

/*
    calcAverage
    Accepts:
        - total of all scores
        - minimum score
        - maximum score
    Preconditions:
        - total should represent 5 scores.
    Postconditions:
        - Returns the average of the middle three scores.
*/
double calcAverage(double total, double minScore, double maxScore);

int main() {
    double score;
    double total = 0;
    double minScore, maxScore;

    cout << "Star Search Score Calculator\n";

    // First judge
    score = getScore();
    minScore = score;
    maxScore = score;
    total += score;

    // Remaining 4 judges
    for (int i = 0; i < 4; i++) {
        score = getScore();
        total += score;

        if (isLower(score, minScore))
            minScore = score;

        if (isHigher(score, maxScore))
            maxScore = score;
    }

    // Compute final score
    double average = calcAverage(total, minScore, maxScore);

    cout << "\nFinal Performer Score: " << average << endl;

    return 0;
}

double getScore() {
    double score;
    cout << "\nEnter judge's score on a scale of 0-10: ";
    cin >> score;

    while (score < 0 || score > 10) {
        cout << "Invalid score! Please enter a value between 0 and 10: ";
        cin >> score;
    }

    return score;
}

bool isLower(double a, double b) {
    return (a <= b);
}

bool isHigher(double a, double b) {
    return (a >= b);
}

double calcAverage(double total, double minScore, double maxScore) {
    // Remove highest and lowest, divide remaining by 3
    return (total - minScore - maxScore) / 3.0;
}
