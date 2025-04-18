# Star Platinum Movie Rental System

## Description

The **Star Platinum Movie Rental System** is a command-line application designed for managing a movie rental store. The system allows customers to rent, return, and view movies from a catalog, while also enabling store administrators to manage movie details, customer information, and rental records. The application is built using C++ and incorporates data structures like vectors to manage the list of movies, customers, and rentals.

## Features

- **Add New Movies**: Insert new movies into the catalog with details such as title, genre, production company, image filename, and available copies.
- **Rent Movies**: Customers can rent available movies by providing a movie code and customer code.
- **Return Movies**: Customers can return rented movies by providing the movie and customer codes.
- **Display All Movies**: View a list of all movies available in the store, showing their details such as ID, title, genre, production company, available copies, and image.
- **Show Movie Details**: View detailed information about a specific movie using its unique movie code.
- **Check Movie Availability**: Check if a movie is available for rent based on its stock.
- **Customer Maintenance**: Manage customer information by adding new customers or viewing customer details, including a list of rented movies.

## Installation

To run this project, follow the steps below:

### Prerequisites
- C++ Compiler (e.g., GCC or MinGW)
- C++11 or later support

### Steps

1. Clone the repository or download the source files.

   ```bash
   git clone https://github.com/jayelcee/JMachineProblem
   ```

2. Navigate to the project directory and compile the project.

   ```bash
   cd JMachineProblem
   g++ Main.cpp Implementation.cpp -o MovieRentalSystem -std=c++11
   ```

3. After compilation, run the program.

   ```bash
   ./MovieRentalSystem
   ```

## Running the Program

Upon running the program, you will be presented with a menu where you can select different operations related to movie rentals. The options available in the menu are:

1. **Insert a New Movie**
2. **Rent a Movie**
3. **Return a Movie**
4. **Show Movie Details**
5. **Display All Movies**
6. **Check Movie Availability**
7. **Customer Maintenance**
8. **Exit Program**

For each option, you will be prompted to provide the necessary information, such as movie IDs, customer codes, and rental details.
