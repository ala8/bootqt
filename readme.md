




# bootqt
#### This is a pack of predesigned Qt components and their designs are close to Bootstrap's. Bootqt has shortcuts for designed components such as buttons, input fields, navbars and forms. Bootqt was created to be a personal project for personal use but I decided to publish it into github for my portfolio and to work on it regularly. To wrap up, this isn't professional code nor is it the most efficient.

<br />

## BPushButton

### Usage:
```c++
// NOTE: You want to create the BPushButton on the heap.
// Otherwise it might get destroyed.

BPushButton* pushButton = new BPushButton(QWidget* parent = nullptr, design);
// OR
BPushButton* pushButton = new BPushButton(QWidget* parent = nullptr, int r = 57, int g = 129, int b = 191);
```

BPushButton will create a QPushButton as a public class member called "QPush" and design it accordingly.
```c++
class BPushButton
{

public:
    QPushButton* QPush;
    BPushButton(QWidget* parent = nullptr, int r = 57, int g = 129, int b = 191);
    ~BPushButton();

    void SetParent(QWidget* parent);
    void SetDefaultStyles(int r, int g, int b);
    void AppendStyleSheet(QString style);
};
```
As you can see, you cannot for example use members of QPushButton through BPushButton. You will have to call them through ```QPush->member```. Here's an example:
```c++
#include "src/bpushbutton.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    BPushButton* bp = new BPushButton(this, PRIMARY);

    // change the text of the BPushButton
    bp->QPush->setText("Changed the text");

    // resize the button
    bp->QPush->resize(150, 50);

    // how to use connect()
    connect(bp->QPush, &QPushButton::clicked, [&]() {
        QMessageBox::information(this, "Clicked", "BPushButton was clicked");
    });
}
```
You can also change the stylesheet by using ```bp->QPush->setStyleSheet()``` and if you want to append, BPushButton has a method called ```AppendStyleSheet(QString style)``` which takes in the style that you want to append.

### Designs
These are the designs bootqt has. They are somewhat similar to the Bootstrap ones.
```c++
#define PRIMARY 57, 129, 191
#define SECONDARY 108, 117, 125
#define SUCCESS 40, 167, 69
#define DANGER 220, 53, 69
#define WARNING 255, 198, 28
#define INFO 23, 162, 184
#define LIGHT 248, 249, 250
#define DARK 52, 58, 64
```
<br />
<br />

## BLineEdit
### Usage:
```c++
BLineEdit* lineEdit = new BLineEdit(QWidget* parent = nullptr, QString placeholder = "");
```

Similar to BPushButton, BLineEdit will create a QLineEdit named "QLine" as a public class member. After creation it will be designed automatically.

```c++
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
```
To access the QLineEdit, you have to use  ```bLineEdit->QLine```, similar to BPushButton. Here's an example:

```c++
BLineEdit* bl = new BLineEdit(this, "BLineEdit input field");

// Move the lineEdit through QLine member
bl->QLine->move(5, 60);
```

You can append to the stylesheet through ```bLineEdit->AppendStyleSheet(QString style);```. If you want to overwrite the styles, you'll have to do it via ```QLine``` member.

<br />
<br />

## BNav
### Usage:
```c++
BNav* nav = new BNav(QWidget* parent = nullptr, QString grid = COLUMN, int itemCount = 4, DESIGN)
```

BNav is a navigation bar that can have navigation items (basically BPushButtons but slightly edited). Items can be listed both vertically (ROW) or horizontally (COLUMN). The bar items can also be connected to a click event.

BNav class:
```c++
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
    void SetParent(QWidget* parent);
    void SetItemText(int item_index, const QString& text);
};
```

``parent`` will contain the parent of the BNav. ``itemCount`` contains the number of elements (items) in the BNav and ``grid`` will determine if the items are going to listed horizontally (COLUMN) or vertically (ROW).

``navItems`` is an vector of BPushButtons which are going to be the BNav items. ``QNav`` is a QWidget, basically a background or a "base" for the nav items.

### Example:
```c++
auto lamb = [&](){
    QMessageBox::information(this, "Message", "A nav item was clicked", QMessageBox::Ok);
};

BNav* bn = new BNav(this, ROW, 4, DARK);

bn->SetItemText(0, "Menu");
bn->SetItemText(1, "Create");
bn->SetItemText(2, "Items");
bn->SetItemText(3, "Profile");

bn->SetClickedConnection(0, lamb);
```
outcome:
<br />
![enter image description here](https://cdn.discordapp.com/attachments/732283331185475606/830347512333467679/unknown.png)

Using ``SetClickedConnection(item_index, lambda)`` you can connect a nav item to a click event. If you want to connect to additional events, you'll have to do it manually with ``connect()``.

NOTE: It's very recommended to NOT TO capture by reference, instead copy the pointers by using ``[=](){}``.

You can change the text on the item using ``SetItemText(item_index, text)``. You can also design the item through the BPushButton vector ``navItems``. The default design of the BPushButtons will be the same design you passed into the BNav constructor.

<br />
<br />

## BForm

BForm is a responsive form class that will create and design a form automatically.

### Usage:
```c++
BForm* form = new BForm(QWidget* parent, const QString& formTitle = "BForm", int fieldCount = 3, int width = 500, bool submit = true, SUBMIT_DESIGN = PRIMARY);
```

The constructor takes a pointer to the parent QWidget of the form, a form title, the sum fields (a field is a row with a label and an input field), the width of the form which is recommended to leave as 500, a boolean value that represents if a submit button is wanted and a design for the submit button.

BForm class:
```c++
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
    void SetBackground(int r, int g, int b);
    QString GetFieldLabelStyleSheet(int field_index) const;
    void SetFieldLabelStyleSheet(int field_index, const QString& styles);
    void SetFormTitle(const QString& title);
    QString GetFormTitleStyleSheet() const;
    void SetFormTitleStyleSheet(const QString& styles);
};
```
BForm will create a QWidget into the parent and add a title, fields and a submit button if necessary. You can get input from the input fields by using the method ``getInput(field_index)`` which takes in the index of the input field in the vector ``formInputs``. The input labels will be numbered according to each fields index.

You can obviously also connect the submit button to a click event aka submission event using a lambda. You can connect everything manually but a click event method ``connectSubmitted(lambda)``.

NOTE: the lambda MUST NOT capture by reference. Your application will crash. You have to use ``[=](){}`` if you want your lambda to capture.

You can get and set the stylesheet of the title and the form labels through BForm's methods. You can always edit the components manually and it's recommended to check the source and how certain components are made, if you wish to make any changes manually.

### Example:
```c++
// BForm example:
BForm* bf = new BForm(this, "Form title", 3, 500, true, LIGHT);
bf->Move(100, 200);

bf->editField(0, "Email:", "email@example.com");
bf->editField(1, "Username:", "username");
bf->editField(2, "Password:", "password");

bf->SetBackground(DARK);
bf->SetFieldLabelStyleSheet(ALL, "font-size: 18px; color: white;");
bf->SetFormTitleStyleSheet("font-size: 30px; color: white;");

bf->connectSubmitted([=](){
    QString email = bf->getInput(0);
    QMessageBox::information(this, "form submitted", "your email is: " + email);
});
```
