#ifndef ADMINMENUWINDOW_H
#define ADMINMENUWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "Queue.h"
#include "Files.h"
#include "hotel.h"
#include "offer.h"
#include <QMessageBox>
#include "addhotelform.h"
#include "addofferform.h"

namespace Ui {
class AdminMenuWindow;
}

class AdminMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMenuWindow(QWidget *parent = nullptr);
    ~AdminMenuWindow();

private slots:
    void on_back_clicked();

    void on_addHotel_clicked();

    void on_addOffer_clicked();

    void on_LookHotel_clicked();

    void on_LookOffer_clicked();

private:
    Ui::AdminMenuWindow *ui;
    Queue<Hotel> *queueH;
    Queue<Offer> *queueO;
};

#endif // ADMINMENUWINDOW_H
