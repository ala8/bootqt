#include "bnav.h"

BNav::BNav(QWidget* parent, QString grid, int itemCount, int r, int g, int b)
{
    this->SetDefaultWidget(parent, grid, parent->size());
}

void BNav::SetDefaultWidget(QWidget* parent, QString grid, QSize parentSize)
{

    // column navbar (default)
    if (grid == COLUMN)
    {

        this->QNav = new QWidget(parent);

        int width = parentSize.width();
        int height = parentSize.height() / 10;

        if (height < 70)
            height = 70;

        this->m_setWidgetGeo(width, height);

    } // row navbar
    else if (grid == ROW)
    {

        this->QNav = new QWidget(parent);

        int width = parentSize.width() / 5;
        int height = parentSize.height();

        if (width < 70)
            width = 70;

        this->m_setWidgetGeo(width, height);

    } // Invalid grid
    else
    {
        QMessageBox::critical(parent, "BNav error", "BNav: SetDefaultWidget(QWidget*, QString, QSize) -> Invalid grid. Use either ROW or COLUMN to fix this problem.", QMessageBox::Ok);
    }

}

void BNav::m_setWidgetGeo(int width, int height)
{
    this->QNav->resize(width, height);
    this->QNav->move(0, 0);

    this->QNav->setStyleSheet("background-color: red");
}

BNav::~BNav()
{
    // delete the QNav widget
    delete this->QNav;

    // Delete everything in the navItems vector
    for (auto item : this->navItems)
        delete item;
}
