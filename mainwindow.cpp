#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , movieCount(0)
    , customerCount(0)
    , reservationCount(0)
{
    ui->setupUi(this);

    // Create the stacked widget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Create the main menu page
    mainMenuPage = new QWidget();
    QVBoxLayout *mainMenuLayout = new QVBoxLayout(mainMenuPage);
    browseMoviesButton = new QPushButton("Browse Movies", this);
    registerCustomerButton = new QPushButton("Register Customer", this);
    bookTicketsButton = new QPushButton("Book Tickets", this);
    cancelReservationButton = new QPushButton("Cancel Reservation", this);
    viewRegisteredSeatsButton = new QPushButton("View Registered Seats", this);

    mainMenuLayout->addWidget(browseMoviesButton);
    mainMenuLayout->addWidget(registerCustomerButton);
    mainMenuLayout->addWidget(bookTicketsButton);
    mainMenuLayout->addWidget(cancelReservationButton);
    mainMenuLayout->addWidget(viewRegisteredSeatsButton);

    stackedWidget->addWidget(mainMenuPage);

    // Create the browse movies page
    browseMoviesPage = new QWidget();
    QVBoxLayout *browseMoviesLayout = new QVBoxLayout(browseMoviesPage);
    moviesTextEdit = new QTextEdit(this);
    moviesTextEdit->setPlaceholderText("Movies will be displayed here");
    backToMenuButtonFromBrowse = new QPushButton("Back to Menu", this);

    browseMoviesLayout->addWidget(moviesTextEdit);
    browseMoviesLayout->addWidget(backToMenuButtonFromBrowse);

    stackedWidget->addWidget(browseMoviesPage);

    // Create the register customer page
    registerCustomerPage = new QWidget();
    QVBoxLayout *registerCustomerLayout = new QVBoxLayout(registerCustomerPage);
    QHBoxLayout *customerInfoLayout = new QHBoxLayout();
    customerNameLineEdit = new QLineEdit(this);
    customerNameLineEdit->setPlaceholderText("Enter customer name");
    customerEmailLineEdit = new QLineEdit(this);
    customerEmailLineEdit->setPlaceholderText("Enter customer email");
    customerInfoLayout->addWidget(customerNameLineEdit);
    customerInfoLayout->addWidget(customerEmailLineEdit);
    submitCustomerButton = new QPushButton("Submit", this);
    backToMenuButtonFromRegister = new QPushButton("Back to Menu", this);

    registerCustomerLayout->addLayout(customerInfoLayout);
    registerCustomerLayout->addWidget(submitCustomerButton);
    registerCustomerLayout->addWidget(backToMenuButtonFromRegister);

    stackedWidget->addWidget(registerCustomerPage);

    // Create the book tickets page
    bookTicketsPage = new QWidget();
    QVBoxLayout *bookTicketsLayout = new QVBoxLayout(bookTicketsPage);
    QHBoxLayout *movieSelectionLayout = new QHBoxLayout();
    QHBoxLayout *customerSelectionLayout = new QHBoxLayout();
    QHBoxLayout *seatSelectionLayout = new QHBoxLayout();

    QLabel *selectMovieLabel = new QLabel("Select Movie:", this);
    movieSelectionComboBox = new QComboBox(this);
    QLabel *selectCustomerLabel = new QLabel("Select Customer:", this);
    customerSelectionComboBox = new QComboBox(this);
    QLabel *seatRowLabel = new QLabel("Seat Row:", this);
    seatRowSpinBox = new QSpinBox(this);
    seatRowSpinBox->setMinimum(1);
    QLabel *seatColLabel = new QLabel("Seat Column:", this);
    seatColSpinBox = new QSpinBox(this);
    seatColSpinBox->setMinimum(1);

    movieSelectionLayout->addWidget(selectMovieLabel);
    movieSelectionLayout->addWidget(movieSelectionComboBox);
    customerSelectionLayout->addWidget(selectCustomerLabel);
    customerSelectionLayout->addWidget(customerSelectionComboBox);
    seatSelectionLayout->addWidget(seatRowLabel);
    seatSelectionLayout->addWidget(seatRowSpinBox);
    seatSelectionLayout->addWidget(seatColLabel);
    seatSelectionLayout->addWidget(seatColSpinBox);

    bookTicketButton = new QPushButton("Book Ticket", this);
    backToMenuButtonFromBook = new QPushButton("Back to Menu", this);

    bookTicketsLayout->addLayout(movieSelectionLayout);
    bookTicketsLayout->addLayout(customerSelectionLayout);
    bookTicketsLayout->addLayout(seatSelectionLayout);
    bookTicketsLayout->addWidget(bookTicketButton);
    bookTicketsLayout->addWidget(backToMenuButtonFromBook);

    stackedWidget->addWidget(bookTicketsPage);

    // Create the cancel reservation page
    cancelReservationPage = new QWidget();
    QVBoxLayout *cancelReservationLayout = new QVBoxLayout(cancelReservationPage);
    reservationListWidget = new QListWidget(this);
    cancelSelectedReservationButton = new QPushButton("Cancel Selected Reservation", this);
    backToMenuButtonFromCancel = new QPushButton("Back to Menu", this);

    cancelReservationLayout->addWidget(reservationListWidget);
    cancelReservationLayout->addWidget(cancelSelectedReservationButton);
    cancelReservationLayout->addWidget(backToMenuButtonFromCancel);

    stackedWidget->addWidget(cancelReservationPage);

    // Create the view registered seats page
    viewRegisteredSeatsPage = new QWidget();
    QVBoxLayout *viewRegisteredSeatsLayout = new QVBoxLayout(viewRegisteredSeatsPage);
    QLabel *reservationIDForViewLabel = new QLabel("Reservation ID:", this);
    reservationIDForViewSpinBox = new QSpinBox(this);
    reservationIDForViewSpinBox->setMinimum(1);
    seatsTableWidget = new QTableWidget(this);
    seatsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    viewSeatsButton = new QPushButton("View Seats", this);
    backToMenuButtonFromView = new QPushButton("Back to Menu", this);

    viewRegisteredSeatsLayout->addWidget(reservationIDForViewLabel);
    viewRegisteredSeatsLayout->addWidget(reservationIDForViewSpinBox);
    viewRegisteredSeatsLayout->addWidget(viewSeatsButton);
    viewRegisteredSeatsLayout->addWidget(seatsTableWidget);
    viewRegisteredSeatsLayout->addWidget(backToMenuButtonFromView);

    stackedWidget->addWidget(viewRegisteredSeatsPage);

    // Connect buttons to slots
    connect(browseMoviesButton, &QPushButton::clicked, this, &MainWindow::showBrowseMoviesPage);
    connect(registerCustomerButton, &QPushButton::clicked, this, &MainWindow::showRegisterCustomerPage);
    connect(bookTicketsButton, &QPushButton::clicked, this, &MainWindow::showBookTicketsPage);
    connect(cancelReservationButton, &QPushButton::clicked, this, &MainWindow::showCancelReservationPage);
    connect(viewRegisteredSeatsButton, &QPushButton::clicked, this, &MainWindow::showViewRegisteredSeatsPage);

    connect(backToMenuButtonFromBrowse, &QPushButton::clicked, this, &MainWindow::showMainMenuPage);
    connect(backToMenuButtonFromRegister, &QPushButton::clicked, this, &MainWindow::showMainMenuPage);
    connect(backToMenuButtonFromBook, &QPushButton::clicked, this, &MainWindow::showMainMenuPage);
    connect(backToMenuButtonFromCancel, &QPushButton::clicked, this, &MainWindow::showMainMenuPage);
    connect(backToMenuButtonFromView, &QPushButton::clicked, this, &MainWindow::showMainMenuPage);

    connect(submitCustomerButton, &QPushButton::clicked, this, &MainWindow::registerCustomer);
    connect(bookTicketButton, &QPushButton::clicked, this, &MainWindow::bookTicket);
    connect(cancelSelectedReservationButton, &QPushButton::clicked, this, &MainWindow::cancelReservation);
    connect(viewSeatsButton, &QPushButton::clicked, this, &MainWindow::viewRegisteredSeats);

    // Initialize by showing the main menu page
    stackedWidget->setCurrentIndex(0);

    // Hardcoding some movies for demonstration
    movies[movieCount++] = new Movie("Inception", "Sci-Fi", 2010, 2.5, "18:00", 10, 10);
    movies[movieCount++] = new Movie("The Matrix", "Action", 1999, 2.0, "20:00", 10, 10);
    movies[movieCount++] = new Movie("Interstellar", "Sci-Fi", 2014, 3.0, "22:00", 10, 10);

    // Populate movie and customer combo boxes
    updateMovieAndCustomerLists();
    updateReservationList();
}

MainWindow::~MainWindow()
{
    delete ui;
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
}

void MainWindow::showMainMenuPage() {
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::showBrowseMoviesPage() {
    stackedWidget->setCurrentIndex(1);
    displayMovies();
}

void MainWindow::showRegisterCustomerPage() {
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::showBookTicketsPage() {
    stackedWidget->setCurrentIndex(3);
}

void MainWindow::showCancelReservationPage() {
    stackedWidget->setCurrentIndex(4);
    updateReservationList();
}

void MainWindow::showViewRegisteredSeatsPage() {
    stackedWidget->setCurrentIndex(5);
}

void MainWindow::displayMovies() {
    moviesTextEdit->clear();
    for (int i = 0; i < movieCount; ++i) {
        moviesTextEdit->append(movies[i]->title + " (" + movies[i]->genre + ") - " + QString::number(movies[i]->releaseYear));
    }
}

void MainWindow::registerCustomer() {
    QString name = customerNameLineEdit->text();
    QString email = customerEmailLineEdit->text();

    if (name.isEmpty() || email.isEmpty()) {
        // Show an error message
        return;
    }

    customers[customerCount++] = new Customer(name, email);
    updateMovieAndCustomerLists();
}

void MainWindow::bookTicket() {
    int movieIndex = movieSelectionComboBox->currentIndex();
    int customerIndex = customerSelectionComboBox->currentIndex();
    int row = seatRowSpinBox->value();
    int col = seatColSpinBox->value();

    if (movieIndex < 0 || customerIndex < 0 || row <= 0 || col <= 0) {
        // Show an error message
        return;
    }

    Movie* selectedMovie = movies[movieIndex];
    Customer* selectedCustomer = customers[customerIndex];

    // Add logic to check if the seat is available and book it
    // For demonstration, we assume the seat is always available
    reservations[reservationCount++] = new Reservation(reservationCount + 1, selectedCustomer, selectedMovie, 1);
    // Assuming row and col start from 1 and mapping it to array starting from 0
    reservations[reservationCount - 1]->seats[0] = (row - 1) * selectedMovie->cols + (col - 1);
    updateReservationList();
}

void MainWindow::cancelReservation() {
    QListWidgetItem* selectedItem = reservationListWidget->currentItem();
    if (!selectedItem) {
        // Show an error message
        return;
    }

    int reservationID = selectedItem->data(Qt::UserRole).toInt();
    if (reservationID <= 0 || reservationID > reservationCount) {
        // Show an error message
        return;
    }

    // Find and cancel the reservation
    for (int i = 0; i < reservationCount; ++i) {
        if (reservations[i]->reservationID == reservationID) {
            delete reservations[i];
            for (int j = i; j < reservationCount - 1; ++j) {
                reservations[j] = reservations[j + 1];
            }
            --reservationCount;
            break;
        }
    }
    updateReservationList();
}

void MainWindow::viewRegisteredSeats() {
    int reservationID = reservationIDForViewSpinBox->value();
    if (reservationID <= 0 || reservationID > reservationCount) {
        // Show an error message
        return;
    }

    seatsTableWidget->clear();
    seatsTableWidget->setRowCount(10);  // Assuming 10 rows for demonstration
    seatsTableWidget->setColumnCount(10);  // Assuming 10 columns for demonstration

    // Find the reservation and display the seats
    for (int i = 0; i < reservationCount; ++i) {
        if (reservations[i]->reservationID == reservationID) {
            for (int r = 0; r < 10; ++r) {
                for (int c = 0; c < 10; ++c) {
                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setText("[ ]");
                    seatsTableWidget->setItem(r, c, item);
                }
            }

            for (int j = 0; j < reservations[i]->seatCount; ++j) {
                int row = reservations[i]->seats[j] / reservations[i]->movie->cols;
                int col = reservations[i]->seats[j] % reservations[i]->movie->cols;
                QTableWidgetItem *item = seatsTableWidget->item(row, col);
                item->setText("[X]");
                item->setBackground(Qt::black);
            }

            // Highlight the selected seat in green
            int selectedRow = reservations[i]->seats[0] / reservations[i]->movie->cols;
            int selectedCol = reservations[i]->seats[0] % reservations[i]->movie->cols;
            QTableWidgetItem *selectedItem = seatsTableWidget->item(selectedRow, selectedCol);
            selectedItem->setBackground(Qt::green);
            break;
        }
    }
}

void MainWindow::updateMovieAndCustomerLists() {
    movieSelectionComboBox->clear();
    customerSelectionComboBox->clear();

    for (int i = 0; i < movieCount; ++i) {
        movieSelectionComboBox->addItem(movies[i]->title);
    }

    for (int i = 0; i < customerCount; ++i) {
        customerSelectionComboBox->addItem(customers[i]->name);
    }
}

void MainWindow::updateReservationList() {
    reservationListWidget->clear();
    for (int i = 0; i < reservationCount; ++i) {
        QListWidgetItem* item = new QListWidgetItem(
            "Reservation ID: " + QString::number(reservations[i]->reservationID) +
                ", Customer: " + reservations[i]->customer->name +
                ", Movie: " + reservations[i]->movie->title,
            reservationListWidget
            );
        item->setData(Qt::UserRole, reservations[i]->reservationID);
        reservationListWidget->addItem(item);
    }
}
