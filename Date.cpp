#include "Date.h"

Date::Date() : day(1), month(1), year(2000) {}

bool Date::valid() const {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth()) return false;
    return true;
}


Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    if (!valid()) {
        this->day = 1;
        this->month = 1;
        this->year = 2000;
    }
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}



int Date::daysInMonth() const {
    static const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        return 29;
    }
    return daysPerMonth[month - 1];
}

void Date::incrementDay() {
    ++day;
    if (day > daysInMonth()) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
}


Date& Date::operator++() {
    incrementDay();
    return *this;
}


Date& Date::operator--() {
    --day;
    if (day < 1) {
        --month;
        if (month < 1) {
            month = 12;
            --year;
        }
        day = daysInMonth();
    }
    return *this;
}


bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

Date& Date::operator+=(int days) {
    for (int i = 0; i < days; ++i) {
        incrementDay();
    }
    return *this;
}

Date& Date::operator-=(int days) {
    for (int i = 0; i < days; ++i) {
        --(*this);
    }
    return *this;
}

int Date::operator()() const {
    return year * 10000 + month * 100 + day;
}

void Date::fromString(const char* dateStr) {
    int d = 0, m = 0, y = 0;
    char temp[5];

    int i = 0, j = 0;
    while (dateStr[i] != '/' && dateStr[i] != '\0') {
        temp[j++] = dateStr[i++];
    }

    temp[j] = '\0';
    d = std::atoi(temp);

    ++i;
    j = 0;

    while (dateStr[i] != '/' && dateStr[i] != '\0') {
        temp[j++] = dateStr[i++];
    }

    temp[j] = '\0';
    m = std::atoi(temp);

    ++i;
    j = 0;

    while (dateStr[i] != '\0') {
        temp[j++] = dateStr[i++];
    }

    temp[j] = '\0';
    y = std::atoi(temp);

    day = d;
    month = m;
    year = y;

    if (!valid()) {
        day = 1;
        month = 1;
        year = 2000;
    }
}

const char* Date::toString() const {
    static char data[11];

    data[0] = (day / 10) + '0';
    data[1] = (day % 10) + '0';
    data[2] = '/';

    data[3] = (month / 10) + '0';
    data[4] = (month % 10) + '0';
    data[5] = '/';

    data[6] = (year / 1000) + '0';
    data[7] = ((year / 100) % 10) + '0';
    data[8] = ((year / 10) % 10) + '0';
    data[9] = (year % 10) + '0';

    data[10] = '\0';
    return data;
}

