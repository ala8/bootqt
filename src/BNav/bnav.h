#ifndef BNAV_H
#define BNAV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QSize>
#include <vector>

#define COLUMN "col"
#define ROW "row"

#define PRIMARY 57, 129, 191
#define SECONDARY 108, 117, 125
#define SUCCESS 40, 167, 69
#define DANGER 220, 53, 69
#define WARNING 255, 198, 28
#define INFO 29, 162, 184
#define LIGHT 248, 249, 250
#define DARK 52, 58, 64

class BNav
{

private:

    void m_setWidgetGeo(int width, int height);

public:
    QWidget* QNav;
    std::vector<QPushButton*> navItems;

    BNav(QWidget* parent = nullptr, QString grid = COLUMN, int itemCount = 4, int r = 57, int g = 129, int b = 191);
    ~BNav();

    void SetDefaultWidget(QWidget* parent, QString grid, QSize parentSize);
};

#endif // BNAV_H
