#ifndef LOOKUSERHOTELFORM_H
#define LOOKUSERHOTELFORM_H

#include <QWidget>
#include "Queue.h"
#include "adminmenuwindow.h"
#include "Files.h"
#include "hotel.h"

namespace Ui {
class LookUserHotelForm;
}

class LookUserHotelForm : public QWidget
{
    Q_OBJECT

public:
    explicit LookUserHotelForm(Queue<Hotel> *queue = nullptr);
    ~LookUserHotelForm();

private slots:
    void on_sortMark_clicked();

    void on_sortMoney_clicked();

    void on_back_clicked();

    void on_delete_2_clicked();

private:
    Ui::LookUserHotelForm *ui;
    Queue<Hotel> *queue;
};

#endif // LOOKUSERHOTELFORM_H
