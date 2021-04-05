#ifndef BLINEEDIT_H
#define BLINEEDIT_H

#include <QLineEdit>

class BLineEdit
{
public:
    QLineEdit* QLine;

    BLineEdit(QWidget* parent = nullptr, QString placeholder = "");
    ~BLineEdit();

    void SetParent(QWidget* parent);
    void SetDefaultStyles();
    void SetPlaceholder(QString placeholder);
    void AppendStyleSheet(QString new_style);
};

#endif // BLINEEDIT_H
