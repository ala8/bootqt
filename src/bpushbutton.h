#ifndef BPUSHBUTTON_H
#define BPUSHBUTTON_H

#include <QPushButton>

#define PRIMARY "rgb(57, 129, 191)"
#define DARK_PRIMARY "rgb(50, 115, 171)"
#define PRESS_PRIMARY "rgb(44, 100, 148)"

class BPushButton : public QPushButton
{

public:
    QPushButton* QPush;
    BPushButton(QWidget* parent = nullptr);
    ~BPushButton();

    void bSetParent(QWidget* parent);
    void bSeteDefaultStyles(QString style = "primary");
};

#endif // BPUSHBUTTON_H
