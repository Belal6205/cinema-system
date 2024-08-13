#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <iostream>
#include "Customer.h"
#include "Movie.h"

class Reservation {
    static int nextID;
    int reservationID;
    Customer customer;
    Movie* movie;
    int* reservedSeats; // Dynamic array to store reserved seat indices
    int seatCount;

public:
    Reservation(const Customer& cust, Movie* mov);
    ~Reservation();

    int getReservationID() const;
    void addSeat(int row, int col);
    void cancel();
    void displayReservation() const;
    Movie* getMovie() const;
};

// Define the static member variable
inline int Reservation::nextID = 1;

// Define the constructor
inline Reservation::Reservation(const Customer& cust, Movie* mov)
    : reservationID(nextID++), customer(cust), movie(mov), seatCount(0) {
    reservedSeats = new int[mov->getSeats().getRows() * mov->getSeats().getCols()](); // Allocate based on max possible seats
}

// Define the destructor
inline Reservation::~Reservation() {
    delete[] reservedSeats;
}

// Define the member functions
inline int Reservation::getReservationID() const {
    return reservationID;
}

inline void Reservation::addSeat(int row, int col) {
    reservedSeats[seatCount++] = row * movie->getSeats().getCols() + col; // Store seat index as 1D array
}

inline void Reservation::cancel() {
    for (int i = 0; i < seatCount; ++i) {
        int row = reservedSeats[i] / movie->getSeats().getCols();
        int col = reservedSeats[i] % movie->getSeats().getCols();
        movie->getSeats().freeSeat(row + 1, col + 1); // Adjust back to 1-based indexing
    }
    seatCount = 0;
}

inline void Reservation::displayReservation() const {
    std::cout << "Reservation ID: " << reservationID << "\n"
              << "Customer: " << customer.getName().toStdString() << " (" << customer.getEmail().toStdString() << ")\n"
              << "Movie: " << movie->getTitle().toStdString() << "\n"
              << "Seats: ";
    for (int i = 0; i < seatCount; ++i) {
        int row = reservedSeats[i] / movie->getSeats().getCols();
        int col = reservedSeats[i] % movie->getSeats().getCols();
        std::cout << "(" << row + 1 << ", " << col + 1 << ") "; // Display as 1-based indexing
    }
    std::cout << std::endl;
}

inline Movie* Reservation::getMovie() const {
    return movie;
}

#endif // RESERVATION_H
