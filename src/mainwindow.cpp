#include "mainwindow.h"

#include "src/bpushbutton.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    BPushButton* bp = new BPushButton(this);

    connect(bp->QPush, &BPushButton::clicked, [&](){
        QMessageBox::information(this, "BPushButton event", "Button clicked!");
    });
}

MainWindow::~MainWindow()
{
}

