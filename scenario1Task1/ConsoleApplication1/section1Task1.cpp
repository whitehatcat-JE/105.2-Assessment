// Section 1 Task 1 - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>
// Namespaces
using std::string;
// Individual user activity tracking class
class HealthActivity {
private:
    // Activity tracking & Account variables
    string username;
    int steps;
    float distance;
public:
    // Assigns temporary values to class variables (In case getActivity is run before data is retrieved)
    HealthActivity() {
        username = "Undefined";
        steps = 0;
        distance = 0.0;
    }
    // Class variable setters
    void setUsername(string name) { username = name; }
    void setSteps(int stepCount) { steps = stepCount; }
    void setDistance(float distanceTravelled) { distance = distanceTravelled; }
    // Class variable getters
    string getUsername() { return username; }
    int getSteps() { return steps; }
    float getDistance() { return distance; }
};
// Gets activity data from program user for 5 users
void setActivity(HealthActivity* userActivity) {
    for (int userIdx = 0; userIdx < 5; userIdx++) { // Loops through all 5 users (Hardcoded to 5 as requested by assessment)
        // Gets name of user
        string name;
        std::cout << "\nUser " << userIdx+1 << "\n\tEnter username: ";
        std::cin >> name;
        userActivity[userIdx].setUsername(name); // Sets username
        // Gets step count of user
        int steps;
        std::cout << "\tEnter number of steps: ";
        std::cin >> steps;
        userActivity[userIdx].setSteps(steps); // Sets step count
        // Gets distance travelled by user
        float distance;
        std::cout << "\tEnter walking/running distance (In km, without units): ";
        std::cin >> distance;
        userActivity[userIdx].setDistance(distance); // Sets distance
    }
}
// Display activity data for all 5 users
void getActivity(HealthActivity* userActivity) {
    // Activity totals (Used to find averages)
    int totalSteps = 0;
    float totalKm = 0.0;
    for (int userIdx = 0; userIdx < 5; userIdx++) { // Loops through users
        // Display user activity
        std::cout << "Name: " << userActivity[userIdx].getUsername()
            << "\nSteps: " << userActivity[userIdx].getSteps()
            << "\nWalking/Running Distance: " << userActivity[userIdx].getDistance()
            << "Km" << std::endl;
        // Add to activity totals
        totalSteps += userActivity[userIdx].getSteps();
        totalKm += userActivity[userIdx].getDistance();
    }
    // Display activity averages
    std::cout << "Average steps of 5 users: " << totalSteps / 5
        << " steps\nAverage Walking/Running distance: " << totalKm / 5.0
        << "km" << std::endl;
}
// Main method, retrieves and displays activity data for 5 users
int main() {
    std::cout << "Welcome to the Iphone health app, please enter data for 5 users below:\n"; // Intro
    HealthActivity users[5]; // Activity array declaration
    setActivity(users); // Gets activity from program user
    getActivity(users); // Displays all activity
}