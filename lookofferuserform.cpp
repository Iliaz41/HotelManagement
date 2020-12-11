#include "lookofferuserform.h"
#include <QDate>
#include "ui_lookofferuserform.h"

LookOfferUserForm::LookOfferUserForm(string login, Queue<Offer> *queue) :
    queue(queue), login(login),
    ui(new Ui::LookOfferUserForm)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Дата"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Количество свободных мест"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
        QDate date(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(date.toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(queue->operator[](i).getNumberOfSeats())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

LookOfferUserForm::~LookOfferUserForm()
{
    delete ui;
}

void LookOfferUserForm::on_back_clicked()
{
    this->close();
    delete this;
}

void LookOfferUserForm::on_sortMark_clicked()
{
    for (int i = 0; i < queue->size(); i++) {
        for (int j = queue->size() - 1; j > i; j--) {
            if (queue->operator[](i).getMark() < queue->operator[](j).getMark()) {
                Offer tmp = queue->operator[](i);
                queue->operator[](i) = queue->operator[](j);
                queue->operator[](j) = tmp;
            }
        }
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Дата"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Количество свободных мест"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
        QDate date(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(date.toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(queue->operator[](i).getNumberOfSeats())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void LookOfferUserForm::on_sortMoney_clicked()
{
    for (int i = 0; i < queue->size(); i++) {
        for (int j = queue->size() - 1; j > i; j--) {
            if (queue->operator[](i).getMoney() > queue->operator[](j).getMoney()) {
                Offer tmp = queue->operator[](i);
                queue->operator[](i) = queue->operator[](j);
                queue->operator[](j) = tmp;
            }
        }
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Дата"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Количество свободных мест"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
        QDate date(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(date.toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(queue->operator[](i).getNumberOfSeats())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void LookOfferUserForm::on_dateEarly_clicked()
{
    for (int i = 0; i < queue->size(); i++) {
        for (int j = queue->size() - 1; j > i; j--) {
            if (QDate(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay()) > QDate(queue->operator[](j).getYear(), queue->operator[](j).getMonth(), queue->operator[](j).getDay())) {
                Offer tmp = queue->operator[](i);
                queue->operator[](i) = queue->operator[](j);
                queue->operator[](j) = tmp;
            }
        }
    }
    ui->tableWidget->setColumnCount(5);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Дата"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Количество свободных мест"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
        QDate date(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(date.toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(queue->operator[](i).getNumberOfSeats())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void LookOfferUserForm::on_dateLate_clicked()
{
    for (int i = 0; i < queue->size(); i++) {
        for (int j = queue->size() - 1; j > i; j--) {
            if (QDate(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay()) < QDate(queue->operator[](j).getYear(), queue->operator[](j).getMonth(), queue->operator[](j).getDay())) {
                Offer tmp = queue->operator[](i);
                queue->operator[](i) = queue->operator[](j);
                queue->operator[](j) = tmp;
            }
        }
    }
    ui->tableWidget->setColumnCount(5);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Дата"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Количество свободных мест"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
        QDate date(queue->operator[](i).getYear(), queue->operator[](i).getMonth(), queue->operator[](i).getDay());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(date.toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(queue->operator[](i).getNumberOfSeats())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void LookOfferUserForm::on_buy_clicked()
{
    int number = ui->spinBox->text().toInt() - 1;
    int tick = ui->spinBox_2->text().toInt();
    if (tick > queue->operator[](number).getNumberOfSeats()) {
        QMessageBox::critical(nullptr, "Покупка мест", "Вы не можете купить столько мест!");
        return;
    }
    string file = login + ".txt";
    Queue<Offer> *queueT = new Queue<Offer>();
    Files::openOffer(queueT, file.c_str());
    Offer offer(queue->operator[](number).getName(), queue->operator[](number).getMark(), queue->operator[](number).getMoney(),
            tick, queue->operator[](number).getDay(), queue->operator[](number).getMonth(), queue->operator[](number).getYear());
    queueT->pushTail(offer);
    Files::saveOffer(queueT, file.c_str());
    queue->operator[](number).setNumberOfSeats(queue->operator[](number).getNumberOfSeats() - tick);
    queue->operator[](number).setMoney(queue->operator[](number).getMoney() + tick * 10);
    Files::saveOffer(queue, "offer.txt");
    Queue<Hotel> *queueH = new Queue<Hotel>();
    Files::openHotel(queueH, "hotel.txt");
    for (int i = 0; i < queueH->size(); i++) {
        if (queueH->operator[](i).getName() == queue->operator[](number).getName()) {
            queueH->operator[](i).setMoney(queueH->operator[](i).getMoney() + tick * 10);
        }
    }
    Files::saveHotel(queueH, "hotel.txt");
    ui->tableWidget->setItem(number, 5, new QTableWidgetItem(QString::number(queue->operator[](number).getNumberOfSeats())));
    ui->tableWidget->setItem(number, 2, new QTableWidgetItem(QString::number(queue->operator[](number).getMoney())));
    QMessageBox::information(nullptr, "Покупка мест", "Места куплены!");
}
