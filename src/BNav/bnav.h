#ifndef BNAV_H
#define BNAV_H

#include <QWidget>
#include <QMessageBox>
#include <QSize>
#include <vector>
#include <QString>
#include <functional>

#include "../BPushButton/bpushbutton.h"

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
    void m_initNavItems();
    void m_setDefaultWidget();

public:
    QWidget* QNav;
    std::vector<BPushButton*> navItems;

    int itemCount;
    QWidget* parent;
    QString grid;

    int r, g, b;

    BNav(QWidget* parent = nullptr, QString grid = COLUMN, int itemCount = 4, int r = 57, int g = 129, int b = 191);
    ~BNav();

    void SetClickedConnection(int button_index, std::function<void()> lambda);
};

#endif // BNAV_H
