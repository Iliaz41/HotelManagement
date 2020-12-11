#include "addofferform.h"
#include "ui_addofferform.h"

AddOfferForm::AddOfferForm(Queue<Offer>*queueO, Queue<Hotel>* queueH) :
    ui(new Ui::AddOfferForm), queueO(queueO), queueH(queueH)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit->setValidator(new QIntValidator(0, 99));
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(queueH->size());
    ui->tableWidget->setColumnCount(3);
    QTableWidgetItem *w = new QTableWidgetItem("Название отеля");
    ui->tableWidget->setHorizontalHeaderItem(0, w);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Оценка"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выручка отеля"));
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(nullptr);
    for (int i = 0; i < queueO->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(queueO->operator[](i).getName())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(queueO->operator[](i).getMark())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(queueO->operator[](i).getMoney())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

AddOfferForm::~AddOfferForm()
{
    delete ui;
}

void AddOfferForm::on_pushButton_clicked()
{
    int day = ui->dateEdit->date().day();
    int month = ui->dateEdit->date().month();
    int year = ui->dateEdit->date().year();
    int number = ui->spinBox->text().toInt() - 1;
    string name = queueH->operator[](number).getName();
    double mark = queueH->operator[](number).getMark();
    int numberOfSeats = ui->lineEdit->text().toInt();
    Offer offer(name, mark, queueH->operator[](number).getMoney(), numberOfSeats, day, month, year);
    queueO->pushTail(offer);
    Files::saveOffer(queueO, "offer.txt");
    QMessageBox::information(nullptr, "Добавление предложения", "Предложение добавлено!");
    this->close();
    delete this;
}

void AddOfferForm::on_pushButton_2_clicked()
{
    this->close();
    delete this;
}
