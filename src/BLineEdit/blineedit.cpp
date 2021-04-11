#include "blineedit.h"

BLineEdit::BLineEdit(QWidget* parent, const QString& placeholder)
{
    this->QLine = new QLineEdit();
    this->SetParent(parent);

    this->SetDefaultStyles();
    this->SetPlaceholder(placeholder);

    this->QLine->resize(200, 40);
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

    style.append("QLineEdit {border-radius: 5px; border: 1px solid gray; background-color: #e8e8e8;} QLineEdit:focus {border: 3px solid #71cdf5}");


    this->QLine->setStyleSheet(style);
}

void BLineEdit::SetPlaceholder(const QString& placeholder)
{
    this->QLine->setPlaceholderText(placeholder);
}

void BLineEdit::AppendStyleSheet(const QString& new_style)
{
    QString style = this->QLine->styleSheet();
    style.append(" ");
    style.append(new_style);

    this->QLine->setStyleSheet(style);
}

QString BLineEdit::GetText() const
{
    return this->QLine->text();
}

void BLineEdit::SetText(const QString& text)
{
    this->QLine->setText(text);
}

int BLineEdit::x() const
{
    return this->QLine->x();
}

int BLineEdit::y() const
{
    return this->QLine->y();
}

int BLineEdit::Width() const
{
    return this->QLine->width();
}

int BLineEdit::Height() const
{
    return this->QLine->height();
}

void BLineEdit::SetGeometry(int x, int y, int width, int height)
{
    this->QLine->setGeometry(x, y, width, height);
}

void BLineEdit::Move(int x, int y)
{
    this->QLine->move(x, y);
}

void BLineEdit::Resize(int x, int y)
{
    this->QLine->resize(x, y);
}

BLineEdit::~BLineEdit()
{
    delete this->QLine;
}
