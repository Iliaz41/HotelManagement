#include "adminmenuwindow.h"
#include "ui_adminmenuwindow.h"
#include "lookofferadminform.h"
#include "lookadminhotelform.h"

AdminMenuWindow::AdminMenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMenuWindow)
{
    ui->setupUi(this);
    queueH = new Queue<Hotel>();
    queueO = new Queue<Offer>();
    Files::openHotel(queueH, "hotel.txt");
    Files::openOffer(queueO, "offer.txt");
}

AdminMenuWindow::~AdminMenuWindow()
{
    delete ui;
}

void AdminMenuWindow::on_back_clicked()
{
    Files::saveHotel(queueH, "hotel.txt");
    Files::saveOffer(queueO, "offer.txt");
    MainWindow*w = new MainWindow;
    w->setVisible(true);
    this->close();
    delete this;
}


void AdminMenuWindow::on_addHotel_clicked()
{
    AddHotelForm *w = new AddHotelForm(queueH);
    w->show();
}

void AdminMenuWindow::on_addOffer_clicked()
{
    AddOfferForm *w = new AddOfferForm(queueO, queueH);
    w->show();
}

void AdminMenuWindow::on_LookHotel_clicked()
{
    LookAdminHotelForm *w = new LookAdminHotelForm(queueH);
    w->show();
}

void AdminMenuWindow::on_LookOffer_clicked()
{
    LookOfferAdminForm *w = new LookOfferAdminForm(queueO);
    w->show();
}
