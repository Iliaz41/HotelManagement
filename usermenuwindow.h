#ifndef USERMENUWINDOW_H
#define USERMENUWINDOW_H

#include "Files.h"
#include "hotel.h"
#include "offer.h"
#include "Queue.h"
#include <QMainWindow>

namespace Ui {
class UserMenuWindow;
}

class UserMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMenuWindow(string login);
    ~UserMenuWindow();

private slots:
    void on_back_clicked();

    void on_LookHotel_clicked();

    void on_LookOffers_clicked();

private:
    Ui::UserMenuWindow *ui;
    Queue<Hotel> *queueH;
    Queue<Offer> *queueO;
    string login;
};

#endif // USERMENUWINDOW_H
