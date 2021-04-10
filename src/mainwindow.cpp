#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(950, 400);

    /*
    // BPushButton example:

    this->bp = new BPushButton(this, PRIMARY);

    // move the BPushButton through QPush
    this->bp->QPush->move(5, 5);

    // change the text of the BPushButton
    this->bp->QPush->setText("Changed the text");

    // resize the button
    this->bp->QPush->resize(150, 50);

    // how to use connect()
    connect(bp->QPush, &QPushButton::clicked, [&]() {
        QMessageBox::information(this, "Clicked", "BPushButton was clicked");
    });



    // BLineEdit example:
    this->bl = new BLineEdit(this, "BLineEdit input field");

    // Move the lineEdit through QLine member
    this->bl->QLine->move(5, 60);
    */


    // BNav example
    auto lamb = [&](){
        QMessageBox::information(this, "Message", "A nav item was clicked", QMessageBox::Ok);
    };

    BNav* bn = new BNav(this, ROW, 4, DARK);

    bn->SetItemText(0, "Menu");
    bn->SetItemText(1, "Create");
    bn->SetItemText(2, "Items");
    bn->SetItemText(3, "Profile");

    bn->SetClickedConnection(0, lamb);
}

MainWindow::~MainWindow()
{
    delete this->bp;
    delete this->bl;
}
