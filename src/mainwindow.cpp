#include "mainwindow.h"

#include "src/BPushButton/bpushbutton.h"
#include "src/BLineEdit/blineedit.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(350, 500);


    // BPushButton example:

    BPushButton* bp = new BPushButton(this, PRIMARY);

    // move the BPushButton through QPush
    bp->QPush->move(5, 5);

    // change the text of the BPushButton
    bp->QPush->setText("Changed the text");

    // resize the button
    bp->QPush->resize(150, 50);

    // how to use connect()
    connect(bp->QPush, &QPushButton::clicked, [&]() {
        QMessageBox::information(this, "Clicked", "BPushButton was clicked");
    });



    // BLineEdit example:
    BLineEdit* bl = new BLineEdit(this, "BLineEdit input field");

    // Move the lineEdit through QLine member
    bl->QLine->move(5, 60);
}

MainWindow::~MainWindow()
{
}

