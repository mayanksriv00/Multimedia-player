#ifndef ABOUT_DISPLAY_H
#define ABOUT_DISPLAY_H

#include <QDialog>

namespace Ui {
class About_display;
}

class About_display : public QDialog
{
    Q_OBJECT

public:
    explicit About_display(QWidget *parent = nullptr);
    ~About_display();

private:
    Ui::About_display *ui;
};

#endif // ABOUT_DISPLAY_H
