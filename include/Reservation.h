#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
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
    Reservation(const Customer& cust, Movie* mov)
        : reservationID(nextID++), customer(cust), movie(mov), seatCount(0) {
        reservedSeats = new int[mov->getSeats().getRows() * mov->getSeats().getCols()](); // Allocate based on max possible seats
    }

    ~Reservation() {
        delete[] reservedSeats;
    }

    int getReservationID() const {
        return reservationID;
    }

    void addSeat(int row, int col) {
        reservedSeats[seatCount++] = row * movie->getSeats().getCols() + col; // Store seat index as 1D array
    }

    void cancel() {
        for (int i = 0; i < seatCount; ++i) {
            int row = reservedSeats[i] / movie->getSeats().getCols();
            int col = reservedSeats[i] % movie->getSeats().getCols();
            movie->getSeats().freeSeat(row + 1, col + 1); // Adjust back to 1-based indexing
        }
        seatCount = 0;
    }

    void displayReservation() const {
        std::cout << "Reservation ID: " << reservationID << "\n"
                  << "Customer: " << customer.getName() << " (" << customer.getEmail() << ")\n"
                  << "Movie: " << movie->getTitle() << "\n"
                  << "Seats: ";
        for (int i = 0; i < seatCount; ++i) {
            int row = reservedSeats[i] / movie->getSeats().getCols();
            int col = reservedSeats[i] % movie->getSeats().getCols();
            std::cout << "(" << row + 1 << ", " << col + 1 << ") "; // Display as 1-based indexing
        }
        std::cout << std::endl;
    }

    Movie* getMovie() const {
        return movie;
    }
};

int Reservation::nextID = 1;

#endif // RESERVATION_H
