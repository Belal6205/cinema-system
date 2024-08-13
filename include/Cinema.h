#ifndef CINEMA_H
#define CINEMA_H

#include <string>

class Cinema {
    std::string name;
    std::string location;

public:
    Cinema(const std::string& n, const std::string& loc) : name(n), location(loc) {}

    void setName(const std::string& n) {
        name = n;
    }

    std::string getName() const {
        return name;
    }

    void setLocation(const std::string& loc) {
        location = loc;
    }

    std::string getLocation() const {
        return location;
    }
};

#endif // CINEMA_H
