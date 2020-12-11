#include "lookuserhotelform.h"
#include "ui_lookuserhotelform.h"

LookUserHotelForm::LookUserHotelForm(Queue<Hotel> *queue) :
    queue(queue),
    ui(new Ui::LookUserHotelForm)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
    ui->spinBox_2->setMinimum(1);
    ui->spinBox_2->setMaximum(10);
    ui->tableWidget->setColumnCount(3);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

LookUserHotelForm::~LookUserHotelForm()
{
    delete ui;
}

void LookUserHotelForm::on_sortMark_clicked()
{
    for (int i = 0; i < queue->size(); i++) {
        for (int j = queue->size() - 1; j > i; j--) {
            if (queue->operator[](i).getMark() < queue->operator[](j).getMark()) {
                Hotel tmp = queue->operator[](i);
                queue->operator[](i) = queue->operator[](j);
                queue->operator[](j) = tmp;
            }
        }
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void LookUserHotelForm::on_sortMoney_clicked()
{
    for (int i = 0; i < queue->size(); i++) {
        for (int j = queue->size() - 1; j > i; j--) {
            if (queue->operator[](i).getMoney() > queue->operator[](j).getMoney()) {
                Hotel tmp = queue->operator[](i);
                queue->operator[](i) = queue->operator[](j);
                queue->operator[](j) = tmp;
            }
        }
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void LookUserHotelForm::on_back_clicked()
{
    this->close();
    delete this;
}

void LookUserHotelForm::on_delete_2_clicked()
{
    string file = queue->operator[](ui->spinBox->text().toInt() - 1).getName() + ".txt";
    Queue<int>*markQueue = new Queue<int>();
    Files::openMark(markQueue, file.c_str());
    int mark = ui->spinBox_2->text().toInt();
    markQueue->pushTail(mark);
    double average = 0;
    for (int i = 0; i < markQueue->size(); i++) {
        average += markQueue->operator[](i);
    }
    average /= markQueue->size();
    Files::saveMark(markQueue, file.c_str());
    queue->operator[](ui->spinBox->text().toInt() - 1).setMark(average);
    Queue<Offer> *queueOffer = new Queue<Offer>();
    Files::openOffer(queueOffer, "offer.txt");
    for(int i = 0; i < queueOffer->size(); i++) {
        if (queueOffer->operator[](i).getName() == queue->operator[](ui->spinBox->text().toInt() - 1).getName()) {
            queueOffer->operator[](i).setMark(average);
        }
    }
    Files::saveOffer(queueOffer, "offer.txt");
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queue->size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queue->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queue->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queue->operator[](i).getMoney())));
    }
    ui->tableWidget->resizeColumnsToContents();
}
