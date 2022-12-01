// Section 2 Task 3 - Jayden Everest - 270168415
// Includes
#include <iostream>
// Complex number class, stores both real & imaginary parts
class Complex {
private: 
    float real, imaginary; // Complex number components
public:
    // Default constructor, retrieves complex values from user
    Complex() {
        std::cout << "Enter real value: ";
        std::cin >> real;
        std::cout << "Enter imaginary value: ";
        std::cin >> imaginary;
    }
    // Overloaded constructor, sets complex values to parameters
    Complex(float r, float i) {
        real = r;
        imaginary = i;
    }
    // Complex value getters
    float getR() { return real; };
    float getI() { return imaginary; };
    // Displays entire complex number
    void display() {
        if (real != 0) { // Stops real from being displayed if 0 (E.G 3i vs 0 + 3i)
            std::cout << real; // Displays real
            if (imaginary == 0) return; // Stops imaginary from being displayed if 0 (E.G 2 vs 2 + 0i)
        };
        std::cout << (imaginary > 0 ? " + " : " - ") << abs(imaginary) << 'i'; // Displays imaginary
    }
    // Overloads + operator
    Complex operator +(Complex complexB) {
        return Complex(real + complexB.getR(), imaginary + complexB.getI());
    }
    // Overloads - operator
    Complex operator -(Complex complexB) {
        return Complex(real - complexB.getR(), imaginary - complexB.getI());
    }
    // Overloads * operator
    Complex operator *(Complex complexB) {
        // Follows formula "(a + bi) * (c + di) = (ac - bd) + (ad + bc)i"
        return Complex(real * complexB.getR() - imaginary * complexB.getI(), 
            real * complexB.getI() + imaginary * complexB.getR());
    }
};

// Main method, creates and manipulates 2 complex numbers
int main()
{
    Complex complexA = Complex(3, 2); // Initalizes complex number A
    std::cout << "1st Complex Number: ";
    complexA.display();
    std::cout << "\n\nEnter 2nd Complex Number Values: \n";
    Complex complexB = Complex(); // Initializes complex number B
    while (true) { // Main menu loop
        std::cout << "\n\nChoose operation from menu:\n" <<
            "1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit\n: ";
        int option;
        std::cin >> option; // Get selected option
        while (option > 4 || option < 1) { // Check option is within range
            std::cout << "Choice out of range!\nPlease try again: ";
            std::cin >> option;
        }
        
        if (option == 4) return 0; // Quits program
        // Code shared by all options (Excl. exit option)
        std::cout << "C1: ";
        complexA.display();
        std::cout << "\nC2: ";
        complexB.display();
        std::cout << "\nC3: ";
        // Executes selected option operation
        switch (option) {
            case 1: // Addition
                (complexA + complexB).display();
                break;
            case 2: // Subtraction
                (complexA - complexB).display();
                break;
            case 3: // Multiplication
                (complexA * complexB).display();
        }
    }
}