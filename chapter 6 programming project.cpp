#include <iostream>
using namespace std;

/*
    getLength_Width
    Asks user for the length and width of a rectangle.
    Preconditions: User must enter positive numbers (> 0).
    Postconditions: Stores validated length and width in reference parameters.
*/
void getLength_Width(double& length, double& width);

/*
    calcPerimeter
    Receives validated length and width.
    Returns the calculated perimeter to the caller.
*/
double calcPerimeter(double length, double width);

/*
    calcArea
    Receives validated length and width.
    Returns the calculated area to the caller.
*/
double calcArea(double length, double width);

/*
    displayProperties
    Displays the rectangle’s perimeter and area.
    Preconditions: perimeter and area must already be calculated.
    Postconditions: prints values to the monitor.
*/
void displayProperties(double perimeter, double area);

int main() {
    double length, width;
    double perimeter, area;
    char choice = 'y';

    cout << "Rectangle Properties Program\n";
    cout << "-----------------------------\n";

    while (choice == 'y' || choice == 'Y') {

        // Get length and width
        getLength_Width(length, width);

        // Calculate results
        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);

        // Display results
        displayProperties(perimeter, area);

        // Ask user if they want to process another rectangle
        cout << "\nWould you like to process another rectangle? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    cout << "Have a nice day.\n";
    return 0;
}

void getLength_Width(double& length, double& width) {

    cout << "Enter rectangle length: ";
    cin >> length;
    while (length <= 0) {
        cout << "Invalid! Length must be > 0. Enter again: ";
        cin >> length;
    }

    cout << "Enter rectangle width: ";
    cin >> width;
    while (width <= 0) {
        cout << "Invalid! Width must be > 0. Enter again: ";
        cin >> width;
    }
}

double calcPerimeter(double length, double width) {
    return 2 * (length + width);
}

double calcArea(double length, double width) {
    return length * width;
}

void displayProperties(double perimeter, double area) {
    cout << "\nRectangle Properties:\n";
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}
