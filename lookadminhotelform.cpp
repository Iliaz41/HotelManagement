#include "lookadminhotelform.h"
#include "ui_lookadminhotelform.h"

LookAdminHotelForm::LookAdminHotelForm(Queue<Hotel> * queue) :
    queue(queue),
    ui(new Ui::LookAdminHotelForm)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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

LookAdminHotelForm::~LookAdminHotelForm()
{
    delete ui;
}

void LookAdminHotelForm::on_sortMark_clicked()
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

void LookAdminHotelForm::on_sortMoney_clicked()
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

void LookAdminHotelForm::on_delete_2_clicked()
{
    if (queue->size() < 1) {
        QMessageBox::critical(nullptr, "Удаление отеля", "Нет отелей для удаления!");
        return;
    }
    for (int i = ui->spinBox->text().toInt() - 1; i < queue->size() - 1; i++) {
        queue->operator[](i) = queue->operator[](i + 1);
    }
    queue->popTail();
    QMessageBox::information(nullptr, "Удаление отеля", "Отель удалён успешно!");
    ui->tableWidget->clear();
    ui->spinBox->setMaximum(queue->size());
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
    Files::saveHotel(queue, "hotel.txt");
}

void LookAdminHotelForm::on_back_clicked()
{
    this->close();
    delete this;
}
