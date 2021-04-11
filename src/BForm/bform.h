#ifndef BFORM_H
#define BFORM_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <functional>
#include "../BLineEdit/blineedit.h"
#include "../BPushButton/bpushbutton.h"

#define PRIMARY 57, 129, 191
#define SECONDARY 108, 117, 125
#define SUCCESS 40, 167, 69
#define DANGER 220, 53, 69
#define WARNING 255, 198, 28
#define INFO 29, 162, 184
#define LIGHT 248, 249, 250
#define DARK 52, 58, 64

#define ALL 4148

class BForm
{
private:
    void m_initializeBGWidget();
    void m_initializeFormComponents();

public:
    BForm(QWidget* parent, const QString& formTitle = "BForm", int fieldCount = 3, int width = 500, bool submit = true, int r = 57, int g = 129, int b = 191);
    ~BForm();

    QWidget* parent;
    QString formTitle;
    int fieldCount;
    int width;
    bool submit;
    int r, g, b;

    QWidget* background;
    QLabel* titleLabel;
    std::vector<QLabel*> formLabels;
    std::vector<BLineEdit*> formInputs;
    BPushButton* formSubmit;

    void editField(int field_index, const QString& labelText, QString inputPlaceholder);
    QString getInput(int field_index) const;
    void connectSubmitted(std::function<void()> lambda);
    void Move(int x = 0, int y = 0);
    void Resize(int x, int y);

    void SetBackground(int r, int g, int b);
    QString GetFieldLabelStyleSheet(int field_index) const;
    void SetFieldLabelStyleSheet(int field_index, const QString& styles);
    void SetFormTitle(const QString& title);
    QString GetFormTitleStyleSheet() const;
    void SetFormTitleStyleSheet(const QString& styles);
};

#endif // BFORM_H
