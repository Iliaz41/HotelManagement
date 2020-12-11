#include "offer.h"

Offer::Offer(const string &name, double mark, int money,
        int numberOfSeats, int day, int month, int year) : Hotel(name, mark, money), number_of_seats(numberOfSeats), day(day), month(month), year(year) {}

int Offer::getDay() const {
    return day;
}

void Offer::setDay(int day) {
    Offer::day = day;
}

int Offer::getMonth() const {
    return month;
}

void Offer::setMonth(int month) {
    Offer::month = month;
}

int Offer::getYear() const {
    return year;
}

void Offer::setYear(int year) {
    Offer::year = year;
}


int Offer::getNumberOfSeats() const {
    return number_of_seats;
}

void Offer::setNumberOfSeats(int numberOfSeats) {
    Offer::number_of_seats = numberOfSeats;
}
