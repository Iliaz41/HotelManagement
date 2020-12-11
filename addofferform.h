#ifndef ADDOFFERFORM_H
#define ADDOFFERFORM_H

#include "adminmenuwindow.h"
#include "Queue.h"
#include <QWidget>
#include "offer.h"

namespace Ui {
class AddOfferForm;
}

class AddOfferForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddOfferForm(Queue<Offer>*queueO = nullptr, Queue<Hotel>* queueH = nullptr);
    ~AddOfferForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddOfferForm *ui;
    Queue<Offer> *queueO;
    Queue<Hotel> *queueH;
};

#endif // ADDOFFERFORM_H
