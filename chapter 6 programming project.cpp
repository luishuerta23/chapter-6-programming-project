#include <iostream>
#include <string>
using namespace std;

/*
    getRegInfo
    Prompts the user to enter a region name and its number of accidents.
    Preconditions: Accident number must be >= 0.
    Postconditions: Stores the region name and validated accident count
                    into the reference parameters.
*/
void getRegInfo(string& region, int& accidents);

/*
    isLower
    Accepts two integers: newVal and currentLowest.
    Returns true if newVal <= currentLowest.
    Used to determine if a region has fewer accidents.
*/
bool isLower(int newVal, int currentLowest);

/*
    showLowest
    Displays the region with the lowest accident count.
    Preconditions: region name and accident count must be valid.
    Postconditions: Writes the results to the screen.
*/
void showLowest(string regionName, int accidentCount);

int main() {
    string region, lowestRegion;
    int accidents = 0, lowestAccidents = 0;

    cout << "Safest Driving Area Program\n";
    cout << "-----------------------------\n";

    // FIRST REGION ? establishes initial lowest values
    getRegInfo(region, accidents);
    lowestRegion = region;
    lowestAccidents = accidents;

    // Remaining 4 regions
    for (int i = 0; i < 4; i++) {
        getRegInfo(region, accidents);

        // Check if this region has fewer accidents
        if (isLower(accidents, lowestAccidents)) {
            lowestRegion = region;
            lowestAccidents = accidents;
        }
    }

    // Display the safest region
    showLowest(lowestRegion, lowestAccidents);

    return 0;
}

void getRegInfo(string& region, int& accidents) {
    cout << "\nEnter region name: ";
    cin >> region;

    cout << "Enter number of accidents for " << region << ": ";
    cin >> accidents;

    while (accidents < 0) {
        cout << "Invalid! Number of accidents must be >= 0. Enter again: ";
        cin >> accidents;
    }
}

bool isLower(int newVal, int currentLowest) {
    return (newVal <= currentLowest);
}

void showLowest(string regionName, int accidentCount) {
    cout << "\n----------------------------------\n";
    cout << "Safest Region: " << regionName << endl;
    cout << "Accidents Reported: " << accidentCount << endl;
    cout << "----------------------------------\n";
}
