#pragma once

#include <iostream>
using namespace std;

class Hotel {
private:
    string name;
    double mark;
    int money;
public:
    explicit Hotel(const string &name = "", double mark = 0, int money = 0);
    ~Hotel();
    const string &getName() const;
    void setName(const string &name);
    double getMark() const;
    void setMark(double mark);
    int getMoney() const;
    void setMoney(int money);
};
