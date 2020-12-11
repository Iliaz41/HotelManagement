#include "hotel.h"

Hotel::Hotel(const string &name, double mark, int money) : name(name), mark(mark), money(money) {}

const string &Hotel::getName() const {
    return name;
}

void Hotel::setName(const string &name) {
    Hotel::name = name;
}

double Hotel::getMark() const {
    return mark;
}

void Hotel::setMark(double mark) {
    Hotel::mark = mark;
}

int Hotel::getMoney() const {
    return money;
}

void Hotel::setMoney(int money) {
    Hotel::money = money;
}
