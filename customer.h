#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer {
    QString name;
    QString email;

public:
    Customer(const QString& n, const QString& e) : name(n), email(e) {}

    void setName(const QString& n) {
        name = n;
    }

    QString getName() const {
        return name;
    }

    void setEmail(const QString& e) {
        email = e;
    }

    QString getEmail() const {
        return email;
    }
};

#endif // CUSTOMER_H
