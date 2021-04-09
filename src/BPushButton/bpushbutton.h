#ifndef BPUSHBUTTON_H
#define BPUSHBUTTON_H

#include <QPushButton>

#define PRIMARY 57, 129, 191
#define SECONDARY 108, 117, 125
#define SUCCESS 40, 167, 69
#define DANGER 220, 53, 69
#define WARNING 255, 198, 28
#define INFO 29, 162, 184
#define LIGHT 248, 249, 250
#define DARK 52, 58, 64

#define NORMALBUTTON 0
#define NAVBUTTON 1

class BPushButton
{

public:
    QPushButton* QPush;
    BPushButton(QWidget* parent = nullptr, int r = 57, int g = 129, int b = 191);
    ~BPushButton();

    void SetParent(QWidget* parent);
    void SetDefaultStyles(int r, int g, int b, int additional_styles = NORMALBUTTON);
    void AppendStyleSheet(QString style);
    void SetText(QString string);
};

#endif // BPUSHBUTTON_H
