#include "about_display.h"
#include "ui_about_display.h"

About_display::About_display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_display)
{
    ui->setupUi(this);
}

About_display::~About_display()
{
    delete ui;
}
