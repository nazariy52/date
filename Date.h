#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    bool valid() const;

    int daysInMonth() const;

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);

    void incrementDay();
    Date& operator++();
    Date& operator--();
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    Date& operator=(const Date& other);
    Date& operator+=(int days);
    Date& operator-=(int days);
    int operator()() const;

    void fromString(const char* dateStr);
    const char* toString() const;
};

#endif
