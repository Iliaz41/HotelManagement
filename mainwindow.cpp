#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminmenuwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_clicked()
{
    this->close();
    delete this;
}

void MainWindow::on_continue_2_clicked()
{
    string login;
    if (ui->username->text() == "") {
        AdminMenuWindow*w = new AdminMenuWindow;
        w->setVisible(true);
    } else {
        login = ui->username->text().toStdString();
        Queue<QString>*queue = new Queue<QString>();
        Files::openUser(queue, "user.txt");
        bool flag = false;
        for (int i = 0; i < queue->size(); i++) {
            if (login == queue->operator[](i).toStdString()) {
                flag = true;
            }
        }
        if (!flag) {
            queue->pushTail(QString::fromStdString(login));
            Files::saveUser(queue, "user.txt");
            string file = login + ".txt";
            ofstream on(file.c_str());
            on.close();
        }
        UserMenuWindow* w = new UserMenuWindow(login);
        w->setVisible(true);
    }
    this->close();
}
