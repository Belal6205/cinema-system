#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
    std::string name;
    std::string email;

public:
    Customer(const std::string& n, const std::string& e) : name(n), email(e) {}

    void setName(const std::string& n) {
        name = n;
    }

    std::string getName() const {
        return name;
    }

    void setEmail(const std::string& e) {
        email = e;
    }

    std::string getEmail() const {
        return email;
    }
};

#endif // CUSTOMER_H
