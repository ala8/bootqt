#include "bpushbutton.h"
#include <QDebug>

BPushButton::BPushButton(QWidget* parent)
{
    this->QPush = new QPushButton();

    if (parent != nullptr)
    {
        this->QPush->setParent(parent);
    }

    this->QPush->setText("BPushButton");
    this->QPush->resize(100, 50);
    this->bSeteDefaultStyles("primary");
}


void BPushButton::bSetParent(QWidget* parent)
{
    if (parent != nullptr)
    {
        this->QPush->setParent(parent);
    }
}

void BPushButton::bSeteDefaultStyles(QString style)
{

    // Similar to btn btn-primary
    if (style == "primary")
    {
        this->QPush->setStyleSheet(
            "QPushButton {background-color:"
            PRIMARY
            "; border-radius: 8px; border: 1px solid #0d2133} QPushButton:hover { background-color:"
            DARK_PRIMARY
            ";} QPushButton:pressed {background-color: "
            PRESS_PRIMARY
            ";}"
        );
    }
}

BPushButton::~BPushButton()
{
    delete this->QPush;
}
