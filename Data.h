#pragma once
#include <deque>
#include <list>
#include <string>

#include "json.hpp"

using namespace std;

struct VideoAdt
{
    int Id;
    int Copies;
    string Title;
    string Genre;
    string Production;
    string Image;

    bool operator<(const VideoAdt& other) const
    {
        return Id < other.Id;
    }
	
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(VideoAdt, Id, Copies, Title, Genre, Production, Image)
};

struct CustomerAdt
{
    int Id;
    string Name;
    string Address;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CustomerAdt, Id, Name, Address)
};

struct RentAdt
{
    int CustomerId;
    int VideoId;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RentAdt, CustomerId, VideoId)

    bool operator==(const RentAdt& other) const
    {
        return CustomerId == other.CustomerId && VideoId == other.VideoId;
    }
};

class MovieStore
{
private:
    deque<CustomerAdt> customerQueue;
    vector<VideoAdt> videoList;
    vector<RentAdt> rentList;

    bool RentMovie(CustomerAdt& customer, VideoAdt& video);

    bool ReturnMovie(CustomerAdt& customer, VideoAdt& video);

    static void ShowMovieDetails(VideoAdt& video);

    static void ShowCustomerDetails(CustomerAdt& video);

    vector<VideoAdt> GetMoviesByCustomer(CustomerAdt& customer);

    CustomerAdt* GetCustomer(int id);

    VideoAdt* GetVideo(int id);

    void DisplayMovies(vector<VideoAdt>& movies);

public:
    void RentMovie();

    void DisplayMovies();

    void OpenCustomerFile();

    void AddMovie();

    void ReturnMovie();

    void ShowMovieDetails();

    void CheckVideoAvailability();

    void OpenMovieFile();

    void OpenRentFile();

    void SaveMovieFile();

    void SaveCustomerFile();

    void CustomerMaintenance();

    void SaveRentFile();
};