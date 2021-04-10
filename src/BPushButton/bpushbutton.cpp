#include "bpushbutton.h"

BPushButton::BPushButton(QWidget* parent, int r, int g, int b)
{
    this->QPush = new QPushButton();

    this->SetParent(parent);

    this->QPush->setText("BPushButton");
    this->QPush->resize(100, 50);
    this->SetDefaultStyles(r, g, b);
}


void BPushButton::SetParent(QWidget* parent)
{
    if (parent != nullptr)
    {
        this->QPush->setParent(parent);
    }
}

void BPushButton::SetDefaultStyles(int r, int g, int b, int additional_styles)
{
    QString normalStyle = "QPushButton {background-color: rgb(";
    normalStyle.append(QString::number(r));
    normalStyle.append(", ");
    normalStyle.append(QString::number(g));
    normalStyle.append(", ");
    normalStyle.append(QString::number(b));

    if (additional_styles == NORMALBUTTON)
        normalStyle.append("); border-radius: 8px; border: 1px solid #0d2133} ");
   else if (additional_styles == NAVBUTTON)
        normalStyle.append("); border: 1px solid #0d2133} ");

    QString hoverStyle = "QPushButton:hover {background-color: rgb(";
    hoverStyle.append(QString::number(r - 15));
    hoverStyle.append(", ");
    hoverStyle.append(QString::number(g - 15));
    hoverStyle.append(", ");
    hoverStyle.append(QString::number(b - 15));
    hoverStyle.append(");} ");

    QString clickStyle = "QPushButton:pressed {background-color: rgb(";
    clickStyle.append(QString::number(r - 25));
    clickStyle.append(", ");
    clickStyle.append(QString::number(g - 25));
    clickStyle.append(", ");
    clickStyle.append(QString::number(b - 25));
    clickStyle.append(");}");

    QString style = normalStyle;
    style.append(hoverStyle);
    style.append(clickStyle);

    // WARNING & LIGHT
    if (r == 255 || r == 248)
        style.append(" QPushButton {color: black;}");

    // OTHER DESIGNS
    else
        style.append(" QPushButton {color: white;}");

    this->QPush->setStyleSheet(style);


}

void BPushButton::AppendStyleSheet(const QString& style)
{
    QString styles = this->QPush->styleSheet();
    styles.append(" ");
    styles.append(style);

    this->QPush->update();
}

void BPushButton::SetText(const QString& string)
{
    this->QPush->setText(string);
}

BPushButton::~BPushButton()
{
    delete this->QPush;
}
