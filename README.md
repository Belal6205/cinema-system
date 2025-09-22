# Cinema GUI

A C++ GUI application for managing a cinema’s movies, customers, and reservations, built using Qt. This project was created as part of a programming fundamentals course.

## Features

- Browse and display available movies
- Register new customers
- Book tickets and select seats via a graphical interface
- Cancel reservations
- View registered seats for reservations

## How It Works

The application provides a user-friendly graphical interface to:
1. View a list of movies
2. Register customers
3. Book tickets for movies, choosing seats visually
4. Cancel reservations
5. View seat arrangements for a reservation

All data is managed in memory during runtime (no file/database persistence).

## Getting Started

### Prerequisites

- Qt 6 (or compatible version)
- C++ compiler (e.g., MinGW, MSVC)

### Build & Run

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/cinema-gui.git
   ```
2. Open the project in Qt Creator or your preferred IDE.
3. Configure the project and build it (usually just press the build/run button in Qt Creator).
4. Run the application.

## Project Structure

- `main.cpp` – Entry point
- `mainwindow.cpp` / `mainwindow.h` – Main window logic and UI
- `*.h` – Header files for core classes (cinema, customer, movie, reservation, seats)
- `build/` – Build artifacts

## Example

The GUI provides buttons and forms for all main actions (browsing movies, registering customers, booking/canceling tickets, viewing seats).

## License

This project is for educational purposes.
