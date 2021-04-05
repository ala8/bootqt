#include "blineedit.h"

BLineEdit::BLineEdit(QWidget* parent, QString placeholder)
{
    this->QLine = new QLineEdit();
    this->SetParent(parent);

    this->SetDefaultStyles();
    this->SetPlaceholder(placeholder);

    this->QLine->resize(200, 35);
}

BLineEdit::~BLineEdit()
{
    delete this->QLine;
}

void BLineEdit::SetParent(QWidget* parent)
{
    if (parent != nullptr)
    {
        this->QLine->setParent(parent);
    }
}

void BLineEdit::SetDefaultStyles()
{
    QString style = "";

    style.append("QLineEdit {border-radius: 5px; border: 1px solid gray} QLineEdit:focus {border: 3px solid #71cdf5}");


    this->QLine->setStyleSheet(style);
}

void BLineEdit::SetPlaceholder(QString placeholder)
{
    this->QLine->setPlaceholderText(placeholder);
}

void BLineEdit::AppendStyleSheet(QString new_style)
{
    QString style = this->QLine->styleSheet();
    style.append(" ");
    style.append(new_style);

    this->QLine->setStyleSheet(style);
}
