#ifndef LOOKOFFERADMINFORM_H
#define LOOKOFFERADMINFORM_H

#include "adminmenuwindow.h"
#include "Files.h"
#include "Queue.h"
#include "hotel.h"
#include <QWidget>

namespace Ui {
class LookOfferAdminForm;
}

class LookOfferAdminForm : public QWidget
{
    Q_OBJECT

public:
    explicit LookOfferAdminForm(Queue<Offer>*queue = nullptr);
    ~LookOfferAdminForm();

private slots:
    void on_back_clicked();

    void on_sortMark_clicked();

    void on_sortMoney_clicked();

    void on_delete_2_clicked();

    void on_dateLate_clicked();

    void on_dateEarly_clicked();

private:
    Ui::LookOfferAdminForm *ui;
    Queue<Offer>*queue;
};

#endif // LOOKOFFERADMINFORM_H
