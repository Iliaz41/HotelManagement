#include "lookofferadminform.h"
#include <QDate>
#include "ui_lookofferadminform.h"

LookOfferAdminForm::LookOfferAdminForm(Queue<Offer>*queue) :
    queue(queue),
    ui(new Ui::LookOfferAdminForm)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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

LookOfferAdminForm::~LookOfferAdminForm()
{
    delete ui;
}

void LookOfferAdminForm::on_back_clicked()
{
    this->close();
    delete this;
}

void LookOfferAdminForm::on_sortMark_clicked()
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
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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

void LookOfferAdminForm::on_sortMoney_clicked()
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
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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

void LookOfferAdminForm::on_delete_2_clicked()
{
    if (queue->size() < 1) {
        QMessageBox::critical(nullptr, "Удаление предложения", "Нет предложений для удаления!");
        return;
    }
    for (int i = ui->spinBox->text().toInt() - 1; i < queue->size() - 1; i++) {
        queue->operator[](i) = queue->operator[](i + 1);
    }
    queue->popTail();
    QMessageBox::information(nullptr, "Удаление предложения", "Предложение удалёно успешно!");
    ui->tableWidget->clear();
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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
    Files::saveOffer(queue, "offer.txt");
}

void LookOfferAdminForm::on_dateLate_clicked()
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
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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

void LookOfferAdminForm::on_dateEarly_clicked()
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
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queue->size());
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
