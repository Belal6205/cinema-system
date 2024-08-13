#include <iostream>
#include "Cinema.h"
#include "Customer.h"
#include "Movie.h"
#include "Seats.h"
#include "Reservation.h"

using namespace std;

void displayMainMenu();
void handleMovieManagement(Movie** movies, int movieCount);
void handleCustomerRegistration(Customer** customers, int& customerCount);
void handleTicketBooking(Movie** movies, int movieCount, Customer** customers, int customerCount, Reservation** reservations, int& reservationCount);
void handleReservationCancellation(Reservation** reservations, int& reservationCount);
void handleViewRegisteredSeats(Reservation** reservations, int reservationCount);
void displayMovies(Movie** movies, int movieCount);
void displayReservations(Reservation** reservations, int reservationCount);

int main() {
    Cinema myCinema("Grand Cinema", "Downtown");
    const int maxMovies = 10;
    const int maxCustomers = 100;
    const int maxReservations = 100;

    Movie* movies[maxMovies];
    Customer* customers[maxCustomers];
    Reservation* reservations[maxReservations];

    int movieCount = 0;
    int customerCount = 0;
    int reservationCount = 0;

    // Hardcoding some movies
    movies[movieCount++] = new Movie("Inception", "Sci-Fi", 2010, 2.5, "18:00", 10, 10);
    movies[movieCount++] = new Movie("The Matrix", "Action", 1999, 2.0, "20:00", 10, 10);
    movies[movieCount++] = new Movie("Interstellar", "Sci-Fi", 2014, 3.0, "22:00", 10, 10);

    int choice;

    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                handleMovieManagement(movies, movieCount);
                break;
            case 2:
                handleCustomerRegistration(customers, customerCount);
                break;
            case 3:
                handleTicketBooking(movies, movieCount, customers, customerCount, reservations, reservationCount);
                break;
            case 4:
                handleReservationCancellation(reservations, reservationCount);
                break;
            case 5:
                handleViewRegisteredSeats(reservations, reservationCount);
                break;
            case 6:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    // Cleanup
    for (int i = 0; i < movieCount; ++i) {
        delete movies[i];
    }
    for (int i = 0; i < customerCount; ++i) {
        delete customers[i];
    }
    for (int i = 0; i < reservationCount; ++i) {
        delete reservations[i];
    }

    return 0;
}

void displayMainMenu() {
    cout << "\nWelcome to Grand Cinema Management System\n";
    cout << "1. Browse Movies\n";
    cout << "2. Register Customer\n";
    cout << "3. Book Tickets\n";
    cout << "4. Cancel Reservation\n";
    cout << "5. View Registered Seats\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void handleMovieManagement(Movie** movies, int movieCount) {
    cout << "\nAvailable Movies:\n";
    displayMovies(movies, movieCount);
}

void handleCustomerRegistration(Customer** customers, int& customerCount) {
    string name, email;

    cout << "\nEnter customer name: ";
    cin.ignore();  // Ignore leftover newline character
    getline(cin, name);
    cout << "Enter customer email: ";
    getline(cin, email);

    customers[customerCount++] = new Customer(name, email);
    cout << "Customer registered successfully!\n";
}

void handleTicketBooking(Movie** movies, int movieCount, Customer** customers, int customerCount, Reservation** reservations, int& reservationCount) {
    if (movieCount == 0 || customerCount == 0) {
        cout << "\nMovies or customers are not registered. Please ensure both are registered before booking tickets.\n";
        return;
    }

    int customerIndex, movieIndex, numTickets, row, col;

    cout << "\nSelect customer by index:\n";
    for (int i = 0; i < customerCount; ++i) {
        cout << i + 1 << ". " << customers[i]->getName() << endl;
    }
    cin >> customerIndex;

    cout << "\nSelect movie by index:\n";
    for (int i = 0; i < movieCount; ++i) {
        cout << i + 1 << ". " << movies[i]->getTitle() << endl;
    }
    cin >> movieIndex;

    cout << "\nEnter number of tickets to book: ";
    cin >> numTickets;

    reservations[reservationCount] = new Reservation(*customers[customerIndex - 1], movies[movieIndex - 1]);
    for (int i = 0; i < numTickets; ++i) {
        movies[movieIndex - 1]->getSeats().displaySeats();
        cout << "Enter seat row and column for ticket " << i + 1 << ": ";
        cin >> row >> col;

        try {
            if (movies[movieIndex - 1]->getSeats().bookSeat(row, col)) {
                reservations[reservationCount]->addSeat(row, col);
            } else {
                cout << "Seat is already booked or out of range. Try again.\n";
                --i;
            }
        } catch (const std::out_of_range& e) {
            cout << "Error booking seat: " << e.what() << ". Try again.\n";
            --i;
        }
    }

    reservationCount++;
    cout << "Tickets booked successfully!\n";
    reservations[reservationCount - 1]->displayReservation();
}

void handleReservationCancellation(Reservation** reservations, int& reservationCount) {
    if (reservationCount == 0) {
        cout << "\nNo reservations found.\n";
        return;
    }

    int reservationID;
    cout << "\nEnter reservation ID to cancel: ";
    cin >> reservationID;

    for (int i = 0; i < reservationCount; ++i) {
        if (reservations[i]->getReservationID() == reservationID) {
            reservations[i]->cancel();
            delete reservations[i];

            for (int j = i; j < reservationCount - 1; ++j) {
                reservations[j] = reservations[j + 1];
            }

            reservationCount--;
            cout << "Reservation canceled successfully!\n";
            return;
        }
    }

    cout << "Reservation ID not found.\n";
}

void handleViewRegisteredSeats(Reservation** reservations, int reservationCount) {
    if (reservationCount == 0) {
        cout << "\nNo reservations found.\n";
        return;
    }

    int reservationID;
    cout << "\nEnter reservation ID to view seats: ";
    cin >> reservationID;

    for (int i = 0; i < reservationCount; ++i) {
        if (reservations[i]->getReservationID() == reservationID) {
            cout << "\nSeats for Reservation ID: " << reservationID << "\n";
            reservations[i]->getMovie()->getSeats().displaySeats();
            return;
        }
    }

    cout << "Reservation ID not found.\n";
}

void displayMovies(Movie** movies, int movieCount) {
    for (int i = 0; i < movieCount; ++i) {
        movies[i]->displayInfo();
        cout << endl;
    }
}

void displayReservations(Reservation** reservations, int reservationCount) {
    for (int i = 0; i < reservationCount; ++i) {
        reservations[i]->displayReservation();
    }
}
