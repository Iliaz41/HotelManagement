#ifndef ADDHOTELFORM_H
#define ADDHOTELFORM_H

#include <QWidget>
#include <string>
#include "mainwindow.h"
#include "adminmenuwindow.h"
#include "Files.h"

namespace Ui {
class AddHotelForm;
}

class AddHotelForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddHotelForm(Queue<Hotel>*queue = nullptr);
    ~AddHotelForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddHotelForm *ui;
    Queue<Hotel>*queue;
};

#endif // ADDHOTELFORM_H
