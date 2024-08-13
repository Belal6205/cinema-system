#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showMainMenuPage();
    void showBrowseMoviesPage();
    void showRegisterCustomerPage();
    void showBookTicketsPage();
    void showCancelReservationPage();
    void showViewRegisteredSeatsPage();
    void displayMovies();
    void registerCustomer();
    void bookTicket();
    void cancelReservation();
    void viewRegisteredSeats();
    void updateMovieAndCustomerLists();
    void updateReservationList();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;

    // Widgets for main menu
    QWidget *mainMenuPage;
    QPushButton *browseMoviesButton;
    QPushButton *registerCustomerButton;
    QPushButton *bookTicketsButton;
    QPushButton *cancelReservationButton;
    QPushButton *viewRegisteredSeatsButton;

    // Widgets for browsing movies
    QWidget *browseMoviesPage;
    QTextEdit *moviesTextEdit;
    QPushButton *backToMenuButtonFromBrowse;

    // Widgets for registering customer
    QWidget *registerCustomerPage;
    QLineEdit *customerNameLineEdit;
    QLineEdit *customerEmailLineEdit;
    QPushButton *submitCustomerButton;
    QPushButton *backToMenuButtonFromRegister;

    // Widgets for booking tickets
    QWidget *bookTicketsPage;
    QComboBox *movieSelectionComboBox;
    QComboBox *customerSelectionComboBox;
    QSpinBox *seatRowSpinBox;
    QSpinBox *seatColSpinBox;
    QPushButton *bookTicketButton;
    QPushButton *backToMenuButtonFromBook;

    // Widgets for canceling reservation
    QWidget *cancelReservationPage;
    QListWidget *reservationListWidget;
    QPushButton *cancelSelectedReservationButton;
    QPushButton *backToMenuButtonFromCancel;

    // Widgets for viewing registered seats
    QWidget *viewRegisteredSeatsPage;
    QSpinBox *reservationIDForViewSpinBox;
    QTableWidget *seatsTableWidget;
    QPushButton *viewSeatsButton;
    QPushButton *backToMenuButtonFromView;

    // Dummy data
    int movieCount;
    int customerCount;
    int reservationCount;

    struct Movie {
        QString title;
        QString genre;
        int releaseYear;
        double duration;
        QString startTime;
        int rows;
        int cols;

        Movie(QString t, QString g, int y, double d, QString s, int r, int c)
            : title(t), genre(g), releaseYear(y), duration(d), startTime(s), rows(r), cols(c) {}
    };

    Movie* movies[10];

    struct Customer {
        QString name;
        QString email;

        Customer(QString n, QString e) : name(n), email(e) {}
    };

    Customer* customers[10];

    struct Reservation {
        int reservationID;
        Customer* customer;
        Movie* movie;
        int* seats;
        int seatCount;

        Reservation(int id, Customer* c, Movie* m, int numSeats)
            : reservationID(id), customer(c), movie(m), seatCount(numSeats) {
            seats = new int[numSeats];
        }

        ~Reservation() {
            delete[] seats;
        }
    };

    Reservation* reservations[10];
};

#endif // MAINWINDOW_H
