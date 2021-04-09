#include "bnav.h"
#include <QDebug>

BNav::BNav(QWidget* arg_parent, QString arg_grid, int arg_itemCount, int arg_r, int arg_g, int arg_b)
    : parent(arg_parent), grid(arg_grid), itemCount(arg_itemCount), r(arg_r), g(arg_g), b(arg_b)
{
    this->m_setDefaultWidget();
    this->m_initNavItems();
}

void BNav::m_setDefaultWidget()
{

    QSize parentSize = this->parent->size();

    // column navbar (default)
    if (this->grid == COLUMN)
    {

        this->QNav = new QWidget(this->parent);

        int width = parentSize.width();
        int height = parentSize.height() / 10;

        if (height < 70)
            height = 70;

        this->m_setWidgetGeo(width, height);

    } // row navbar
    else if (this->grid == ROW)
    {

        this->QNav = new QWidget(this->parent);

        int width = parentSize.width() / 5;
        int height = parentSize.height();

        if (width < 70)
            width = 70;

        this->m_setWidgetGeo(width, height);

    } // Invalid grid
    else
    {
        QMessageBox::critical(this->parent, "BNav error", "BNav: m_setDefaultWidget(QWidget*, QString, QSize) -> Invalid grid. Use either ROW or COLUMN to fix this problem.", QMessageBox::Ok);
    }


}

void BNav::m_setWidgetGeo(int width, int height)
{
    this->QNav->resize(width, height);
    this->QNav->move(0, 0);

    this->QNav->setStyleSheet("QWidget {background-color: red}");
}

void BNav::m_initNavItems()
{
    if (this->grid == COLUMN)
    {

        int btnWidth = this->parent->size().width() / this->itemCount;

        for (int i = 0; i < this->itemCount; i++)
        {

            BPushButton* item = new BPushButton(this->QNav, this->r, this->g, this->b);
            item->SetText("item " + QString::number(i));
            item->QPush->resize(btnWidth, this->QNav->size().height());
            item->QPush->move(btnWidth * i, this->QNav->geometry().y());
            item->SetDefaultStyles(this->r, this->g, this->b, NAVBUTTON);
            this->navItems.push_back(item);
        }

    }


    else if (this->grid == ROW)
    {
        int btnHeight = this->parent->size().height() / this->itemCount;

        for (int i = 0; i < this->itemCount; i++)
        {
            BPushButton* item = new BPushButton(this->QNav, this->r, this->g, this->b);
            item->SetText("item " + QString::number(i));
            item->QPush->resize(this->QNav->size().width(), btnHeight);
            item->QPush->move(this->QNav->geometry().x(), btnHeight * i);
            item->SetDefaultStyles(this->r, this->g, this->b, NAVBUTTON);
            this->navItems.push_back(item);
        }
    }

    else
    {
        QMessageBox::critical(parent, "BNav error", "BNav: m_initNavItems(QWidget*, QString, QSize) -> Invalid grid. Use either ROW or COLUMN to fix this problem.", QMessageBox::Ok);
    }
}

void BNav::SetClickedConnection(int button_index, std::function<void()> lambda)
{
    this->parent->connect(this->navItems[button_index]->QPush, &QPushButton::clicked, lambda);
}

BNav::~BNav()
{
    // delete the QNav widget
    delete this->QNav;

    // Delete everything in the navItems vector
    for (auto item : this->navItems)
        delete item;
}
