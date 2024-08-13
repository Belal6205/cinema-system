#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include "Seats.h"

class Movie {
    QString title;
    QString genre;
    int releaseYear;
    float duration;
    QString startTime;
    Seats seats;

public:
    Movie(const QString& t, const QString& g, int rYear, float d, const QString& st, int rows, int cols)
        : title(t), genre(g), releaseYear(rYear), duration(d), startTime(st), seats(rows, cols) {}

    void setTitle(const QString& t) {
        title = t;
    }

    QString getTitle() const {
        return title;
    }

    void setGenre(const QString& g) {
        genre = g;
    }

    QString getGenre() const {
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

    void setStartTime(const QString& st) {
        startTime = st;
    }

    QString getStartTime() const {
        return startTime;
    }

    void displayInfo() const {
        // Implement display logic here if needed
    }

    Seats& getSeats() {
        return seats;
    }
};

#endif // MOVIE_H
