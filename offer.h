#pragma once

#include "hotel.h"

class Offer : public Hotel {
private:
    int day, month, year, number_of_seats;
public:
    explicit Offer(const string &name = "", double mark = 0, int money = 0, int numberOfSeats = 0,
            int day = 0, int month = 0, int year = 0);
    ~Offer();
    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    int getNumberOfSeats() const;
    void setNumberOfSeats(int numberOfSeats);
};
