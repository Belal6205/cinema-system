#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "Seats.h"

class Movie {
    std::string title;
    std::string genre;
    int releaseYear;
    float duration;
    std::string startTime;
    Seats seats;

public:
    Movie(const std::string& t, const std::string& g, int rYear, float d, const std::string& st, int rows, int cols)
        : title(t), genre(g), releaseYear(rYear), duration(d), startTime(st), seats(rows, cols) {}

    void setTitle(const std::string& t) {
        title = t;
    }

    std::string getTitle() const {
        return title;
    }

    void setGenre(const std::string& g) {
        genre = g;
    }

    std::string getGenre() const {
        return genre;
    }

    void setReleaseYear(int rYear) {
        releaseYear = rYear;
    }

    int getReleaseYear() const {
        return releaseYear;
    }

    void setDuration(float d) {
        duration = d;
    }

    float getDuration() const {
        return duration;
    }

    void setStartTime(const std::string& st) {
        startTime = st;
    }

    std::string getStartTime() const {
        return startTime;
    }

    void displayInfo() const {
        std::cout << "Title: " << title << "\n"
                  << "Genre: " << genre << "\n"
                  << "Release Year: " << releaseYear << "\n"
                  << "Duration: " << duration << " hours\n"
                  << "Start Time: " << startTime << "\n";
    }

    Seats& getSeats() {
        return seats;
    }
};

#endif // MOVIE_H
