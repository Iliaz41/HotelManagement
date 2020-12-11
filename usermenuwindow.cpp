#include "mainwindow.h"
#include "usermenuwindow.h"
#include "ui_usermenuwindow.h"
#include "lookuserhotelform.h"
#include "lookofferuserform.h"

UserMenuWindow::UserMenuWindow(string login) :
    ui(new Ui::UserMenuWindow), login(login)
{
    ui->setupUi(this);
    queueH = new Queue<Hotel>();
    queueO = new Queue<Offer>();
    Files::openHotel(queueH, "hotel.txt");
    Files::openOffer(queueO, "offer.txt");
}

UserMenuWindow::~UserMenuWindow()
{
    delete ui;
}

void UserMenuWindow::on_back_clicked()
{
    Files::saveHotel(queueH, "hotel.txt");
    Files::saveOffer(queueO, "offer.txt");
    MainWindow*w = new MainWindow;
    w->setVisible(true);
    this->close();
    delete this;
}

void UserMenuWindow::on_LookHotel_clicked()
{
    LookUserHotelForm *w = new LookUserHotelForm(queueH);
    w->show();
}

void UserMenuWindow::on_LookOffers_clicked()
{
    LookOfferUserForm *w = new LookOfferUserForm(login, queueO);
    w->show();
}
