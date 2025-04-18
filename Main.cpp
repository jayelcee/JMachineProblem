/*  STAR PLATINUM GROUP MEMBERS
    Jairell Louis J. Ignacio [Lead Programmer]
    Shahani Fe D. Vicio      [Programmer 1]
    Jasmine L. Camasura      [Programmer 2] */

#include <iomanip>
#include <iostream>
#include <string>

#include "Data.h"
using namespace std;

int Menu();

int main()
{
    MovieStore store;
    store.OpenMovieFile();
    store.OpenCustomerFile();
    store.OpenRentFile();

Start:
    system("cls||clear");
    const int choice = Menu();
    system("cls||clear");

    if (choice == 1)
    {
        store.AddMovie();
    }
    else if (choice == 2)
    {
        store.RentMovie();
    }
    else if (choice == 3)
    {
        store.ReturnMovie();
    }
    else if (choice == 4)
    {
        store.ShowMovieDetails();
    }
    else if (choice == 5)
    {
        store.DisplayMovies();
    }
    else if (choice == 6)
    {
        store.CheckVideoAvailability();
    }
    else if (choice == 7)
    {
        store.CustomerMaintenance();
    }
    else if (choice == 8)
    {
        store.SaveMovieFile();
        store.SaveCustomerFile();
        store.SaveRentFile();
        system("clear||cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(52, ' ') << "STAR PLATINUM'S MOVIE RENTAL SERVICE SYSTEM\n";
        cout << string(35, ' ') << "=============================================================================\n\n";
        cout << setw(98) << "Final Project in Data Structures and Algorithms\n";
        cout << setw(90) << "S E C T I O N  T N 0 2\n\n\n\n";
        cout << setw(66) << "Created by:\n\n";
        cout << setw(81) << "Camasura, Jasmine L.\n\n";
        cout << setw(86) << "Ignacio, Jairell Louis J.\n\n";
        cout << setw(82) << "Vicio, Shahani Fe D.\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << "\n\n\n\n\n\n\n\n";

        return 0;
    }
    else
    {
        if (!cin) cin.clear();
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(56, ' ') << "INVALID ENTRY! PLEASE TRY AGAIN.\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }

    std::cout << string(38, ' ') << "Press enter to continue...";
    cin.ignore(10000, '\n');
    std::string pause;
    std::getline(std::cin, pause);

    goto Start;
}

int Menu()
{
    int choice;
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(28, ' ') << "==========================================================================================\n";
    cout << string(50, ' ') << "HEY THERE, MOVIE GEEK! WHAT CAN I DO FOR YOU?" << "\n";
    cout << string(28, ' ') << "==========================================================================================\n\n";
    cout << string(56, ' ') << "[1] Insert a New Movie\n\n";
    cout << string(56, ' ') << "[2] Rent a Movie\n\n";
    cout << string(56, ' ') << "[3] Return a Movie\n\n";
    cout << string(56, ' ') << "[4] Show Movie Details\n\n";
    cout << string(56, ' ') << "[5] Display All Movies\n\n";
    cout << string(56, ' ') << "[6] Check Movie Availability\n\n";
    cout << string(56, ' ') << "[7] Customer's Maintenance\n\n";
    cout << string(56, ' ') << "[8] Exit Program\n\n";
    cout << string(28, ' ') << "==========================================================================================\n";
    cout << string(31, ' ') << "Please choose an option... ";
    cin >> choice;

    return choice;
}