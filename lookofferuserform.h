#ifndef LOOKOFFERUSERFORM_H
#define LOOKOFFERUSERFORM_H

#include <QWidget>
#include "lookofferadminform.h"

namespace Ui {
class LookOfferUserForm;
}

class LookOfferUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit LookOfferUserForm(string login = "", Queue<Offer> *queue = nullptr);
    ~LookOfferUserForm();

private slots:
    void on_back_clicked();

    void on_sortMark_clicked();

    void on_sortMoney_clicked();

    void on_dateEarly_clicked();

    void on_dateLate_clicked();

    void on_buy_clicked();

private:
    Ui::LookOfferUserForm *ui;
    Queue<Offer> *queue;
    string login;
};

#endif // LOOKOFFERUSERFORM_H
