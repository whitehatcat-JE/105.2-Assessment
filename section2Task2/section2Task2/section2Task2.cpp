// Section 2 Task 2 - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>
#include <vector>
// Using namespaces
using std::string;
using std::vector;
// Video game superclass, for general game info
class VideoGame {
protected:
    // Game info
    string title;
    float price;
public:
    // Constructor, for setting general game info
    VideoGame(string t, float p) {
        title = t;
        price = p;
    }
    // Placeholder display method, to avoid object slicing issues with sub-class display methods
    virtual void display() {
        std::cout << "Title: " << title
            << "\nPrice: " << price;
    }
};
// Computer subclass, for computer specific info
class ComputerGame : public VideoGame {
private:
    // Computer specific info
    string operatingSystemType;
public:
    // Constructor, for setting specific and general game info
    ComputerGame(string t, float p, string o) : VideoGame(t, p) {
        operatingSystemType = o;
    }
    // Displays both general and computer specific game info
    void display() {
        std::cout << "Title: " << title
            << "\nPrice: " << price
            << "\nOS: " << operatingSystemType;
    }
};
// Console subclass, for console specific info
class ConsoleGame : public VideoGame {
private:
    // Console specific info
    string consoleType;
public:
    // Constructor, for setting specific and general game info
    ConsoleGame(string t, float p, string c) : VideoGame(t, p) {
        consoleType = c;
    }
    // Displays both general and console specific game info
    void display() {
        std::cout << "Title: " << title
            << "\nPrice: " << price
            << "\nConsole: " << consoleType;
    }
};
// Main method, gets list of video games from user and displays them
int main()
{
    vector<VideoGame*> videoGames; // Video game vector (Substituted array for vector, to allow for dynamic sizing)
    // Gets list of video games
    std::cout << "Video Games Data Entry\n**********\n\n";
    while (true) {
        // Selects whether game is console or computer specific
        std::cout << "Do you want to enter data for a Computer Game or a Console Game (o/c): ";
        char type;
        std::cin >> type;
        // Title
        std::cout << "Please enter title of " <<
            (type == 'c' ? "console game: " : "computer game: ");
        string title;
        //     Allows for titles with spaces
        if (std::cin.peek() != '\n') std::cin.putback('\n'); // Stops first char from being omitted during cin
        std::cin.ignore();

        getline(std::cin, title);
        // Price
        std::cout << "Please enter price: ";
        float price;
        std::cin >> price;
        // OS/Console name
        std::cout << "Please enter " <<
            (type == 'c' ? "console type: " : "operating system: ");
        string system;
        //     Allows for names with spaces
        if (std::cin.peek() != '\n') std::cin.putback('\n'); // Stops first char from being omitted during cin
        std::cin.ignore();

        getline(std::cin, system);
        // Stores new game in videoGames vector
        if (type == 'c') videoGames.push_back(new ConsoleGame(title, price, system));
        else videoGames.push_back(new ComputerGame(title, price, system));
        // Checks if it should continue loop
        std::cout << "Do you want to add another item (y/n): ";
        char option;
        std::cin >> option;
        if (option == 'n') break; // Breaks out of data entry loop
    }
    // Displays list of video games
    std::cout << "\nVideo Games List\n**********\n";
    for (auto game = videoGames.begin(); game != videoGames.end(); game++) {
        (*game)->display();
        std::cout << "\n**********\n";
    }
}