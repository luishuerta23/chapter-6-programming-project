#include <iostream>
#include <cmath>
using namespace std;

// Global constants
const double SQFT_PER_GALLON = 110.0;
const double HRS_PER_GALLON = 8.0;
const double LABOR_RATE = 25.0;

/*
    getRooms
    Prompts user for number of rooms.
    Preconditions:
        Must be at least 1.
    Postconditions:
        Returns validated room count.
*/
int getRooms();

/*
    getSqFt
    Prompts user for square footage of a room.
    Preconditions:
        Value must be >= 0.
    Postconditions:
        Returns validated square footage.
*/
double getSqFt();

/*
    getPricePerGallon
    Prompts user for paint price.
    Preconditions:
        Must be >= $10.
    Postconditions:
        Returns validated paint price.
*/
double getPricePerGallon();

/*
    gallonsForRoom
    Calculates gallons of paint needed for a room.
    Postconditions:
        Returns gallons rounded UP to the next whole gallon.
*/
int gallonsForRoom(double sqft);

/*
    displayEstimate
    Outputs final totals: gallons, labor hours, paint cost, labor cost, total.
*/
void displayEstimate(double paintCharge, int gallonsNeeded,
    double laborCharge, double laborHours);

int main() {
    double paintCharge = 0, laborCharge = 0;
    double laborHours = 0;
    int gallonsNeeded = 0;

    int numRooms = getRooms();

    for (int i = 0; i < numRooms; i++) {
        cout << "\n--- Room " << (i + 1) << " ---\n";

        double sqft = getSqFt();
        int gallons = gallonsForRoom(sqft);
        gallonsNeeded += gallons;

        double price = getPricePerGallon();
        paintCharge += gallons * price;

        // Labor hours and charge
        double roomLabor = (sqft / SQFT_PER_GALLON) * HRS_PER_GALLON;
        laborHours += roomLabor;
        laborCharge += roomLabor * LABOR_RATE;
    }

    displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours);

    return 0;
}

int getRooms() {
    int rooms;
    cout << "Enter number of rooms: ";
    cin >> rooms;

    while (rooms < 1) {
        cout << "Invalid! Must be at least 1 room. Try again: ";
        cin >> rooms;
    }

    return rooms;
}

double getSqFt() {
    double sqft;
    cout << "Enter square feet of wall space: ";
    cin >> sqft;

    while (sqft < 0) {
        cout << "Invalid! Square feet cannot be negative. Try again: ";
        cin >> sqft;
    }

    return sqft;
}

double getPricePerGallon() {
    double price;
    cout << "Enter price per gallon: ";
    cin >> price;

    while (price < 10) {
        cout << "Invalid! Paint price must be at least $10. Try again: ";
        cin >> price;
    }

    return price;
}

int gallonsForRoom(double sqft) {
    int gallons = (sqft + SQFT_PER_GALLON - 1) / SQFT_PER_GALLON;
    return gallons;
}


void displayEstimate(double paintCharge, int gallonsNeeded,
    double laborCharge, double laborHours) {

    cout << "\n===== Paint Job Estimate =====\n";
    cout << "Gallons of paint required: " << gallonsNeeded << endl;
    cout << "Hours of labor required:   " << laborHours << endl;
    cout << "Cost of paint:             $" << paintCharge << endl;
    cout << "Labor charges:             $" << laborCharge << endl;
    cout << "----------------------------------\n";
    cout << "Total Cost:                $"
        << (paintCharge + laborCharge) << endl;
}
