
#include "bform.h"

BForm::BForm(QWidget* arg_parent, const QString& arg_formTitle, int arg_fieldCount, int arg_width, bool arg_submit, int arg_r, int arg_g, int arg_b)
    : parent(arg_parent), formTitle(arg_formTitle), fieldCount(arg_fieldCount), width(arg_width), submit(arg_submit), r(arg_r), g(arg_g), b(arg_b)
{
    this->m_initializeBGWidget();
    this->m_initializeFormComponents();
}

void BForm::m_initializeBGWidget()
{
    this->background = new QWidget(this->parent);
    this->background->resize(width, this->fieldCount * 60 + 93);
}

void BForm::m_initializeFormComponents()
{
    // Form title
    this->titleLabel = new QLabel(this->background);
    this->titleLabel->setText(this->formTitle);
    this->titleLabel->resize(this->width, 60);
    this->titleLabel->setStyleSheet("QLabel {font-size: 30px; qproperty-alignment: AlignCenter;}");


    // Form labels
    for (int i = 0; i < this->fieldCount; i++)
    {
        QLabel* fieldLabel = new QLabel(this->background);
        fieldLabel->setText("form label " + QString::number(i) + ":");
        fieldLabel->move(30, 60 * i + 100);
        fieldLabel->setStyleSheet("QLabel {font-size: 18px;}");

        this->formLabels.push_back(fieldLabel);
    }

    // Form inputs
    for (int i = 0; i < this->fieldCount; i++)
    {
        BLineEdit* formInput = new BLineEdit(this->background, "placeholder " + QString::number(i) + "");
        formInput->Resize(this->width / 2, formInput->QLine->size().height());
        formInput->Move(200, 60 * i + 93);

        this->formInputs.push_back(formInput);
    }


    // Submit
    if (this->submit)
    {
        this->formSubmit = new BPushButton(this->background, this->r, this->g, this->b);
        this->formSubmit->Resize(250, 50);
        int submitWidth = this->formSubmit->QPush->width();
        this->formSubmit->Move(this->width / 2 - submitWidth / 2, 93 + this->fieldCount * 60 + 10);
        this->formSubmit->SetText("Submit");

        int bgHeight = this->background->height();
        int newHeight = bgHeight + this->formSubmit->QPush->height() + 50;
        this->background->resize(this->background->width(), newHeight);
    }
}

void BForm::editField(int field_index, const QString& labelText, QString inputPlaceholder)
{
    this->formLabels[field_index]->setText(labelText);
    this->formInputs[field_index]->SetPlaceholder(inputPlaceholder);
}

QString BForm::getInput(int field_index) const
{
    return this->formInputs[field_index]->QLine->text();
}

void BForm::connectSubmitted(std::function<void ()> lambda)
{
    if (submit)
        this->background->connect(this->formSubmit->QPush, &QPushButton::clicked, lambda);
}

void BForm::Move(int x, int y)
{
    this->background->move(x, y);
}

void BForm::Resize(int x, int y)
{
    this->background->resize(x, y);
}

int BForm::x() const
{
    return this->background->x();
}

int BForm::y() const
{
    return this->background->y();
}

int BForm::Width() const
{
    return this->background->width();
}

int BForm::Height() const
{
    return this->background->height();
}

void BForm::SetBackground(int r, int g, int b)
{
    QString styles = "QWidget {background-color: rgb(" + QString::number(r) + ", " + QString::number(g) + ", " + QString::number(b) + "); border-radius: 15px;}";
    this->background->setStyleSheet(styles);
}

QString BForm::GetFieldLabelStyleSheet(int field_index) const
{
    return this->formLabels[field_index]->styleSheet();
}

void BForm::SetFieldLabelStyleSheet(int field_index, const QString& styles)
{
    if (field_index == ALL)
    {
        for (auto label : this->formLabels)
            label->setStyleSheet(styles);
    }
    else
        this->formLabels[field_index]->setStyleSheet(styles);
}

void BForm::SetFormTitle(const QString& title)
{
    this->titleLabel->setText(title);
}

QString BForm::GetFormTitleStyleSheet() const
{
    return this->titleLabel->styleSheet();
}

void BForm::SetFormTitleStyleSheet(const QString& styles)
{
    this->titleLabel->setStyleSheet(styles);
}

BForm::~BForm()
{
    delete this->titleLabel;

    for (auto label : this->formLabels)
        delete label;

    for (auto input : this->formInputs)
        delete input;

    if (this->submit)
        delete this->formSubmit;

    delete this->background;
}
