
# bootqt
### This basically is a design for Qt components inspired by bootstrap. I tried making everything look like bootstrap as much as I could however there's a ton of things I couldn't add


## BPushButton

### Usage:
```c++
// NOTE: You want to create the BPushButton on the heap.
// Otherwise it might get destroyed.

BPushButton* pushButton = new BPushButton(parent, design)
// OR
BPushButton* pushButton = new BPushButton(parent, int r, int g, int b);
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
    void SeteDefaultStyles(int r, int g, int b);
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