#ifndef CINEMA_H
#define CINEMA_H

#include <QString>

class Cinema {
    QString name;
    QString location;

public:
    Cinema(const QString& n, const QString& loc) : name(n), location(loc) {}

    void setName(const QString& n) {
        name = n;
    }

    QString getName() const {
        return name;
    }

    void setLocation(const QString& loc) {
        location = loc;
    }

    QString getLocation() const {
        return location;
    }
};

#endif // CINEMA_H
