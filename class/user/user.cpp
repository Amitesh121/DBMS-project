#include <iostream>
#include "user.h"

void User::displayMenu() {
    std::cout << "\nWelcome to our DB\n";
    std::cout << "1. Insert Record\n";
    std::cout << "2. Delete Record\n";
    std::cout << "3. Update Record\n";
    std::cout << "4. View All Records\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void User::handleUserInput() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Insert Record selected.\n";
            // fucntion for insertion
            break;
        case 2:
            std::cout << "Delete Record selected.\n";
            // fucntion for insertion
            break;
        case 3:
            std::cout << "Update Record selected.\n";
            // fucntion for insertion
            break;
        case 4:
            std::cout << "View All Records selected.\n";
            // fucntion for insertion
            break;
        case 5:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
