#include "mainwindow.h"

#include "src/BPushButton/bpushbutton.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // BPushButton example:

    BPushButton* bp = new BPushButton(this, PRIMARY);

    // change the text of the BPushButton
    bp->QPush->setText("Changed the text");

    // resize the button
    bp->QPush->resize(150, 50);

    // how to use connect()
    connect(bp->QPush, &QPushButton::clicked, [&]() {
        QMessageBox::information(this, "Clicked", "BPushButton was clicked");
    });
}

MainWindow::~MainWindow()
{
}

