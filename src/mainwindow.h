#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <Windows.h>
#include "BPushButton/bpushbutton.h"
#include "BLineEdit/blineedit.h"
#include "BNav/bnav.h"
#include "BForm/bform.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BPushButton* bp;
    BLineEdit* bl;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
