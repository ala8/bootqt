#ifndef BPUSHBUTTON_H
#define BPUSHBUTTON_H

#include <QPushButton>

#define PRIMARY 51, 122, 183

class BPushButton
{

public:
    QPushButton* QPush;
    BPushButton(QWidget* parent = nullptr);

    void bSetParent(QWidget* parent);
    void bSetText(QString text);
    void bSeteDefaultStyles(QString style = "primary");
};

#endif // BPUSHBUTTON_H
