#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->pushButton->setToolTip(
                "<h2><b><font color='red'>MyList</font></b></h2>"
                "<ol>"
                "<li>First</li>"
                "<li>Second</li>"
                "<li>Third</li>"
                "</ol>"
                );

    ui->pushButton_2->setToolTip(
                "<img src=':/files/image/open.png'/>Open"
                );
}

Dialog::~Dialog()
{
    delete ui;
}

