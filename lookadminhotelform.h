#ifndef LOOKADMINHOTELFORM_H
#define LOOKADMINHOTELFORM_H

#include <QWidget>
#include "hotel.h"
#include "adminmenuwindow.h"
#include "Queue.h"


namespace Ui {
class LookAdminHotelForm;
}

class LookAdminHotelForm : public QWidget
{
    Q_OBJECT

public:
    explicit LookAdminHotelForm(Queue<Hotel> *queue = nullptr);
    ~LookAdminHotelForm();

private slots:
    void on_sortMark_clicked();

    void on_sortMoney_clicked();

    void on_delete_2_clicked();

    void on_back_clicked();

private:
    Ui::LookAdminHotelForm *ui;
    Queue<Hotel> *queue;
};

#endif // LOOKADMINHOTELFORM_H
