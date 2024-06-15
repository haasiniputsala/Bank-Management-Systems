#include <iostream>  // input and output stream operations (e.g., std::cin, std::cout).
#include <conio.h>   // console input/output operations, especially for functions like getch() and kbhit().
#include <stdio.h>   // standard input and output operations (e.g., printf, scanf, etc.).
#include <fstream>   // file input and output operations (e.g., file streams like ifstream, ofstream).
#include <windows.h> // Windows-specific functions and definitions (e.g., Sleep(), CreateFile(), etc.).

using namespace std;

// Since it's OOP we create a class called bank
class bank {
    private:
        int pin;
        float balance;
        string id,pass,name,fname,address,phone;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void existing_user();
        void withdraw();
        void deposit();
};

// Defining member function menu under bank
void bank::menu() {
    p: // Labelled p as a repeat function till exit is clicked on
    system("cls"); // System clear screen

    // Making a variable choice for main menu
    int choice;

    // Making the input type in variables for bank management
    char ch;
    string pin, pass;
    string email;

    cout << "\n\n\t\t\t Control Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n\n 2. ATM Management";
    cout << "\n\n 3. Exit";
    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice) { // Making switch case for the choices
    case 1:
        cout << "\n\n\t\tAccount Login";
        cout << "\n\n Enter your E-mail: ";
        cin >> email;
        cout << "\n\n\t\t Enter PIN: ";
        pin = ""; // Ensure pin is empty before input
        for (int i = 1; i <= 5; i++) {
            ch = getch(); // Taking user value in ch
            pin += ch;    // Adding ch value to initial pin value
            cout << "*";  // To show pin number as *
        }
        cout << "\n\n Enter Password: ";
        pass = ""; // Ensure pass is empty before input
        for (int i = 1; i <= 5; i++) {
            ch = getch(); // Taking user value in ch, overrides prev value
            pass += ch;   // Adding ch value to initial pin value
            cout << "*";  // To show pin number as *
        }
        // Debugging output
        cout << "\nEmail entered: " << email;
        cout << "\nPIN entered: " << pin;
        cout << "\nPassword entered: " << pass;
        if (email == "batman@gmail.com" && pin == "12345" && pass == "lbats") 
        {
            cout<<"\n\n\t\tLogin Successful";
            bank_management();
        }
        else 
        {
            cout << "\n\n\t\tYour Credentials are not valid. Please try again";
        }
        break;

    case 2:
        atm_management(); // atm management function call
        break;

    case 3:
        cout << "\n\n Thank you for using our services";
        exit(5); // Built-in function to exit

    default:
        cout << "\n\n Invalid Value \n Please try again";
    }
    getch(); // Will take in any character from the user
    goto p;  // To repeat again from a specific point
}
