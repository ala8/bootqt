#ifndef BLINEEDIT_H
#define BLINEEDIT_H

#include <QLineEdit>

class BLineEdit
{
public:
    QLineEdit* QLine;

    BLineEdit(QWidget* parent = nullptr, const QString& placeholder = "");
    ~BLineEdit();

    void SetParent(QWidget* parent);
    void SetDefaultStyles();
    void SetPlaceholder(const QString& placeholder);
    void AppendStyleSheet(const QString& new_style);
    void Move(int x = 0, int y = 0);
    void Resize(int x, int y);
};

#endif // BLINEEDIT_H
