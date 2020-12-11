#pragma once

#include "Queue.h"
#include <fstream>
#include <QString>
#include "hotel.h"
#include "offer.h"
using namespace std;

class Files {
public:
    static void openUser(Queue<QString> *queue, const char *file) {
        ifstream in;
        in.open(file);
        if (!in.is_open()) {
            return;
        }
        string val;
        while(EOF) {
            in >> val;
            if (!in || val == "%") {
                break;
            }
            in.get();
            QString std = QString::fromStdString(val);
            queue->pushTail(std);
        }
        in.close();
    }

    static void saveUser(Queue<QString> *queue, const char *file) {
        ofstream on;
        on.open(file, std::ios_base::out);
        if (!on.is_open()) {
            return;
        }
        for (int i = 0; i < queue->size(); i++) {
            on << queue->operator[](i).toStdString();
            on << std::endl;
        }
        on << "%";
        on.close();
    }

    static void openMark(Queue<int> *queue, const char *file) {
        ifstream in;
        in.open(file);
        if (!in.is_open()) {
            return;
        }
        int val;
        while(EOF) {
            in >> val;
            if (!in) {
                break;
            }
            queue->pushTail(val);
        }
        in.close();
    }

    static void saveMark(Queue<int> *queue, const char *file) {
        ofstream on;
        on.open(file, std::ios_base::out);
        if (!on.is_open()) {
            return;
        }
        for (int i = 0; i < queue->size(); i++) {
            on << queue->operator[](i) << " ";
        }
        on << "%";
        on.close();
    }

    static void openHotel(Queue<Hotel>* queue, const char*file) {
        ifstream in;
        in.open(file);
        if (!in.is_open()) {
            return;
        }
        string name;
        double mark;
        int money;
        while(EOF) {
            getline(in, name);
            if (!in || name == "%") break;
            in >> mark >> money;
            Hotel hotel(name, mark, money);
            queue->pushTail(hotel);
            in.get();
        }
        in.close();
    }

    static void saveHotel(Queue<Hotel>* queue, const char*file) {
        ofstream on;
        on.open(file, std::ios_base::out);
        if (!on.is_open()) {
            return;
        }
        for (int i = 0; i < queue->size(); i++) {
            on << queue->operator[](i).getName() << "\n" << queue->operator[](i).getMark() << " " << queue->operator[](i).getMoney();
            on << endl;
        }
        on << "%";
        on.close();
    }

    static void openOffer(Queue<Offer> *queue, const char* file) {
        ifstream in;
        in.open(file);
        if (!in.is_open()) {
            return;
        }
        string name;
        double mark;
        int money;
        int numberOfSeats;
        int day, month, year;
        while(EOF) {
            getline(in, name);
            if (!in || name == "%") break;
            in >> mark >> money >> numberOfSeats >> day >> month >> year;
            Offer offer(name, mark, money, numberOfSeats, day, month, year);
            queue->pushTail(offer);
            in.get();
        }
        in.close();
    }

    static void saveOffer(Queue<Offer>* queue, const char* file) {
        ofstream on;
        on.open(file, std::ios_base::out);
        if (!on.is_open()) {
            return;
        }
        for (int i = 0; i < queue->size(); i++) {
            on << queue->operator[](i).getName() << "\n" << queue->operator[](i).getMark() << " " << queue->operator[](i).getMoney() << " " <<
                  queue->operator[](i).getNumberOfSeats() << " " <<
                  queue->operator[](i).getDay() << "  " << queue->operator[](i).getMonth() << "  " << queue->operator[](i).getYear();
            on << endl;
        }
        on << "%";
        on.close();
    }
};
