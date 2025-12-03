#include <iostream>
#include <iomanip>
using namespace std;

// Named global constants for minimum and maximum Fahrenheit temperatures
const int MIN_FAHRENHEIT = 0;
const int MAX_FAHRENHEIT = 20;

/*
    getCelsius

    This function converts a temperature from Fahrenheit to Celsius.

    Input:
        - A temperature value in degrees Fahrenheit.

    Preconditions:
        - The Fahrenheit value should be a valid numeric temperature.
          (No specific range is required for this function to work.)

    Postconditions:
        - Returns the equivalent temperature in degrees Celsius as a double.
        - Does not perform any output; it only performs the conversion
          and returns the Celsius value to the caller.
*/
double getCelsius(double fahrenheit);

int main() {
    // Field width for table alignment
    const int FIELD_WIDTH = 10;

    // Table title
    cout << "Celsius Temperature Table" << endl;
    cout << "-------------------------" << endl;

    // Column headers
    cout << setw(FIELD_WIDTH) << "Fahrenheit"
        << setw(FIELD_WIDTH) << "Celsius" << endl;
    cout << setw(FIELD_WIDTH) << "---------"
        << setw(FIELD_WIDTH) << "-------" << endl;

    // Format numeric output: fixed with 1 decimal place
    cout << fixed << setprecision(1);

    // Loop through Fahrenheit values from MIN_FAHRENHEIT to MAX_FAHRENHEIT
    for (int f = MIN_FAHRENHEIT; f <= MAX_FAHRENHEIT; f++) {
        double c = getCelsius(static_cast<double>(f));

        // Right aligned values in each column
        cout << setw(FIELD_WIDTH) << f
            << setw(FIELD_WIDTH) << c << endl;
    }

    return 0;
}

double getCelsius(double fahrenheit) {
    // Formula: C = (5.0 / 9.0) * (F - 32)
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}
