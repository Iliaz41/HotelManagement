#include "addhotelform.h"
#include "ui_addhotelform.h"

AddHotelForm::AddHotelForm(Queue<Hotel>*queue) :
    queue(queue),
    ui(new Ui::AddHotelForm)
{
    ui->setupUi(this);
}

AddHotelForm::~AddHotelForm()
{
    delete ui;
}

void AddHotelForm::on_pushButton_2_clicked()
{
    string hotel = ui->lineEdit->text().toStdString();
    for (int i = 0; i < queue->size(); i++) {
        if (hotel == queue->operator[](i).getName()) {
            QMessageBox::critical(nullptr, "Добавление отеля", "Такой отель уже существует!");
            return;
        }
    }
    Hotel newHotel(hotel, 0, 0);
    hotel = hotel + ".txt";
    ofstream on(hotel.c_str());
    on.close();
    queue->pushTail(newHotel);
    Files::saveHotel(queue, "hotel.txt");
    QMessageBox::information(nullptr, "Добавление отеля", "Отель успешно добавлен!");
    this->close();
    delete this;
}

void AddHotelForm::on_pushButton_clicked()
{
    this->close();
    delete this;
}
