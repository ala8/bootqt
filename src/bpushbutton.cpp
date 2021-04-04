#include "bpushbutton.h"
#include <QDebug>

BPushButton::BPushButton(QWidget* parent)
{
    this->QPush = new QPushButton();

    if (parent != nullptr)
    {
        this->QPush->setParent(parent);
    }

    this->bSetText("BPushButton");
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
void BPushButton::bSetText(QString text)
{
    this->QPush->setText(text);
}

void BPushButton::bSeteDefaultStyles(QString style)
{
    QPalette btnPalette = this->QPush->palette();
    btnPalette.setColor(QPalette::Button, QColor(Qt::red));
    this->QPush->setAutoFillBackground(true);
    this->QPush->setPalette(btnPalette);
    this->QPush->update();
}
