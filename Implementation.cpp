#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Data.h"
using namespace std;
using namespace nlohmann;

void MovieStore::DisplayMovies()
{
    DisplayMovies(videoList);
}

//Display All Movies - Programmer 1
void MovieStore::DisplayMovies(vector<VideoAdt>& movies)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << left;
    cout << string(13, ' ') << "==================================================================================================================================================\n";
    cout << string(65, ' ') << "D I S P L A Y  A L L  M O V I E S\n";
    cout << string(13, ' ') << "==================================================================================================================================================\n\n";
    cout << string(25, ' ') << setw(10) << "ID" << setw(30) << "TITLE" << setw(15) << "GENRE" << setw(30) << "PRODUCTION" << setw(15) << "COPIES" << setw(25) << "IMAGE" << "\n";
    cout << string(13, ' ') << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
    
    for (auto& video : movies)
    {
        cout << string(25, ' ') << setw(10) << video.Id;
        cout << setw(30) << video.Title;
        cout << setw(15) << video.Genre;
        cout << setw(30) << video.Production;
        cout << setw(15)  << video.Copies;
        cout << setw(25) << video.Image << endl;
    }

    cout << "\n" << string(13, ' ') << "==================================================================================================================================================\n";
}

//Add Movie - Programmer 1
void MovieStore::AddMovie()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(57, ' ') << "I N S E R T  A  N E W  M O V I E\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int count = videoList.size() + 1;

    cout << string(48, ' ') << "Movie ID       : " << count << "\n";

    cout << '\n' << string(48, ' ') << "Movie Title    : ";
    string title;
    cin.ignore();
    getline(cin, title);

    cout << '\n' << string(48, ' ') << "Movie Genre    : ";
    string genre;
    getline(cin, genre);

    cout << '\n' << string(48, ' ') << "Production     : ";
    string producer;
    getline(cin, producer);

    cout << '\n' << string(48, ' ') << "Image Filename : ";
    string image;
    getline(cin, image);

    int copies;
    cout << '\n' << string(48, ' ') << "Copies Count   : ";
    cin >> copies;

    videoList.push_back({count, copies, title, genre, producer, image});
    sort(videoList.begin(), videoList.end());

    cout << endl;
    cout << string(48, ' ') << "Movie has been inserted successfully!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
}

void MovieStore::ReturnMovie()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(61, ' ') << "R E T U R N  A  M O V I E\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << endl;
        cout << string(48, ' ') << "Movie not found!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    int customerCode;
    cout << "\n" << string(48, ' ') << "Enter the customer code: ";
    cin >> customerCode;

    auto customer = GetCustomer(customerCode);
    if (!customer)
    {
    cout << endl;
    cout << string(48, ' ') << "Customer not found!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    ReturnMovie(*customer, *movie);
}

void MovieStore::ShowMovieDetails()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(56, ' ') << "S H O W  M O V I E  D E T A I L S\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
    cout << endl;
    cout << string(48, ' ') << "Movie not found!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    cout << endl;
    ShowMovieDetails(*movie);
    cout << "\n" << string(35, ' ') << "=============================================================================\n";
}

void MovieStore::CheckVideoAvailability()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "C H E C K  M O V I E  A V A I L A B I L I T Y\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << endl;
        cout << "\n" << string(48, ' ') << "Movie not found!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }
    else if (movie->Copies > 0)
    {
        cout << endl;
        ShowMovieDetails(*movie);
        cout << "\n" << string(48, ' ') << "Movie is available!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }
    else
    {
        cout << endl;
        cout << string(48, ' ') << "Movie is not available!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }
}

void MovieStore::CustomerMaintenance()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(54, ' ') << "C U S T O M E R  M A I N T E N A N C E\n";
    cout << string(35, ' ') << "=============================================================================\n\n";
    cout << string(60, ' ') << "[1] Add New Customer\n\n";
    cout << string(60, ' ') << "[2] Customer Details\n\n";
    cout << string(60, ' ') << "[3] List All Movies Rented\n\n";
    cout << string(35, ' ') << "=============================================================================\n";

    int choice;
    cout << string(38, ' ') << "Please choose an option... ";
    cin >> choice;

    system("clear||cls");

    if (choice == 1)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(57, ' ') << "A D D  A  N E W  C U S T O M E R\n";
        cout << string(35, ' ') << "=============================================================================\n\n";

        int count = customerQueue.size() + 1;

        cout << string(48, ' ') << "Customer ID : " << count;

        string name;
        cin.ignore();
        cout << "\n\n" << string(48, ' ') << "Name        : ";
        getline(cin, name);

        string address;
        cout << '\n' << string(48, ' ') << "Address     : ";
        getline(cin, address);

        customerQueue.push_back({count, name, address});

        cout << "\n\n" << string(48, ' ') << "New Customer Added Successfully!\n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
    }
    else if (choice == 2)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(54, ' ') << "S H O W  C U S T O M E R  D E T A I L S\n";
        cout << string(35, ' ') << "=============================================================================\n\n";

        int customerCode;
        cout << string(48, ' ') << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = GetCustomer(customerCode);
        if (!customer)
        {
            cout << "\n\n" << string(48, ' ') << "Customer not found!\n" << endl;
            cout << string(35, ' ') << "=============================================================================\n";
            return;
        }

        ShowCustomerDetails(*customer);
    }
    else if (choice == 3)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(56, ' ') << "LIST OF MOVIES RENTED BY A CUSTOMER\n";
        cout << string(35, ' ') << "=============================================================================\n\n";

        int customerCode;
        cout << string(48, ' ') << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = GetCustomer(customerCode);
        if (!customer)
        {
            cout << "\n\n" << string(48, ' ') << "Customer not found!\n" << endl;
            cout << string(35, ' ') << "=============================================================================\n";
            return;
        }

        auto movies = GetMoviesByCustomer(*customer);

        ShowCustomerDetails(*customer);
        for (auto& video : movies)
        {
            cout << "\n" << string(48, ' ') << "Video ID    : " << video.Id << endl;
            cout << string(48, ' ') << "Movie Title : " << video.Title << endl;
        }
        cout << '\n' << string(35, ' ') << "=============================================================================\n";
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(56, ' ') << "INVALID ENTRY! PLEASE TRY AGAIN.\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }
}

void MovieStore::RentMovie()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(62, ' ') << "R E N T  A  M O V I E\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << "\n\n" << string(48, ' ') << "Movie not found!\n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    int customerCode;
    cout << '\n' << string(48, ' ') << "Enter the customer code: ";
    cin >> customerCode;

    auto customer = GetCustomer(customerCode);
    if (!customer)
    {
        cout << "\n\n" << string(48, ' ') << "Customer not found!\n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    RentMovie(*customer, *movie);
}

bool MovieStore::RentMovie(CustomerAdt& customer, VideoAdt& video)
{
    if (video.Copies > 0)
    {
        video.Copies--;
        rentList.push_back({customer.Id, video.Id});
        cout << '\n' << string(48, ' ') << "Movie has been rented successfully!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";

        return true;
    }

        cout << '\n' << string(48, ' ') << "Movie is out of stock!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";

    return false;
}

bool MovieStore::ReturnMovie(CustomerAdt& customer, VideoAdt& video)
{
    for (auto& rent : rentList)
    {
        if (rent.CustomerId == customer.Id && rent.VideoId == video.Id)
        {
            video.Copies++;
            rentList.erase(find(rentList.begin(), rentList.end(), rent));
            cout << '\n' << string(48, ' ') << "Movie has been returned successfully!\n\n";
            cout << string(35, ' ') << "=============================================================================\n";
            return true;
        }
    }

    cout << '\n' << string(48, ' ') << "Movie is not rented by this customer!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    return false;
}

void MovieStore::ShowMovieDetails(VideoAdt& video)
{
    cout << left;
    cout << string(48, ' ') << setw(15) << "Movie ID     :" << video.Id << '\n';
    cout << string(48, ' ') << setw(15) << "Movie Title  :" << video.Title << '\n';
    cout << string(48, ' ') << setw(15) << "Movie Genre  :" << video.Genre << '\n';
    cout << string(48, ' ') << setw(15) << "Production   :" << video.Production << '\n';
    cout << string(48, ' ') << setw(15) << "Copies Count :" << video.Copies << '\n';
    cout << string(48, ' ') << setw(15) << "Movie Image  :" << video.Image << '\n';
}

void MovieStore::ShowCustomerDetails(CustomerAdt& video)
{
    cout << left;
    cout << "\n" << string(48, ' ') << "Customer ID :  " << video.Id << '\n';
    cout << string(48, ' ') << "Name        :  " << video.Name << '\n';
    cout << string(48, ' ') << "Address     :  " << video.Address << endl << endl;
    cout << string(35, ' ') << "=============================================================================\n";
}

vector<VideoAdt> MovieStore::GetMoviesByCustomer(CustomerAdt& customer)
{
    vector<VideoAdt> movies;
    for (auto& rent : rentList)
    {
        if (rent.CustomerId == customer.Id)
        {
            auto video = GetVideo(rent.VideoId);
            movies.push_back(*video);
        }
    }
    return movies;
}

CustomerAdt* MovieStore::GetCustomer(int id)
{
    for (auto& customer : customerQueue)
    {
        if (customer.Id == id)
        {
            return &customer;
        }
    }
    return nullptr;
}

VideoAdt* MovieStore::GetVideo(int id)
{
    for (auto& video : videoList)
    {
        if (video.Id == id)
        {
            return &video;
        }
    }
    return nullptr;
}

//Save Movie File - Programmer 1
void MovieStore::SaveMovieFile()
{
    ofstream openMov("Movies.json");

    json j = videoList;
    openMov << j.dump(4);
}

//Save Customer File - Programmer 1
void MovieStore::SaveCustomerFile()
{
    ofstream openCust("Customers.json");

    json j = customerQueue;
    openCust << j.dump(4);
}

void MovieStore::SaveRentFile()
{
    ofstream openRent("Rent.json");

    json j = rentList;
    openRent << j.dump(4);
}

//Opening Movie File - Programmer 1
void MovieStore::OpenMovieFile()
{
    ifstream openMov("Movies.json");

    json j;
    openMov >> j;

    videoList = j.get<vector<VideoAdt>>();
    sort(videoList.begin(), videoList.end());
}

void MovieStore::OpenRentFile()
{
    ifstream openRent("Rent.json");

    json j;
    openRent >> j;

    rentList = j.get<vector<RentAdt>>();
}

//Open Customer File - Programmer 1
void MovieStore::OpenCustomerFile()
{
    ifstream openCust("Customers.json");

    json j;
    openCust >> j;

    customerQueue = j.get<deque<CustomerAdt>>();
}