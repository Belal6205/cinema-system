#ifndef SEATS_H
#define SEATS_H

#include <stdexcept>
#include <iostream>

class Seats {
    int rows;
    int cols;
    int** seatMatrix;

public:
    Seats(int r, int c) : rows(r), cols(c) {
        seatMatrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            seatMatrix[i] = new int[cols]();
        }
    }

    ~Seats() {
        for (int i = 0; i < rows; ++i) {
            delete[] seatMatrix[i];
        }
        delete[] seatMatrix;
    }

    void setRows(int r) {
        rows = r;
    }

    int getRows() const {
        return rows;
    }

    void setCols(int c) {
        cols = c;
    }

    int getCols() const {
        return cols;
    }

    bool bookSeat(int row, int col) {
        row--; // Adjust for 1-based indexing
        col--; // Adjust for 1-based indexing
        if (row < 0 || row >= rows || col < 0 || col >= cols || seatMatrix[row][col] != 0) {
            return false;
        }
        seatMatrix[row][col] = 1;
        return true;
    }

    bool freeSeat(int row, int col) {
        row--; // Adjust for 1-based indexing
        col--; // Adjust for 1-based indexing
        if (row < 0 || row >= rows || col < 0 || col >= cols || seatMatrix[row][col] != 1) {
            return false;
        }
        seatMatrix[row][col] = 0;
        return true;
    }

    void displaySeats() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << (seatMatrix[i][j] == 0 ? "[ ]" : "[X]") << " ";
            }
            std::cout << std::endl;
        }
    }

    bool placeX(int row, int col) {
        row--; // Adjust for 1-based indexing
        col--; // Adjust for 1-based indexing
        if (row < 0 || row >= rows || col < 0 || col >= cols || seatMatrix[row][col] == 1) {
            return false;
        }
        seatMatrix[row][col] = 1;
        return true;
    }
};

#endif // SEATS_H
