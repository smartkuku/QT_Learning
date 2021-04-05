#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // populate the items of the list
    for(int i=0;i<10;i++)
        ui->listWidget->addItem("Item "+QString::number(i));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    // Get the pointer to the currently selected item.
    QListWidgetItem *item = ui->listWidget->currentItem();

    // Set the text color and its background coloer using the pointer to the item
    item->setTextColor(Qt::white);
    item->setBackgroundColor(Qt::blue);
}
