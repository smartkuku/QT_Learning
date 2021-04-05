#include "comboboxdialog.h"
#include "ui_comboboxdialog.h"

ComboBoxDialog::ComboBoxDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ComboBoxDialog)
{
    ui->setupUi(this);

    // Fill the items of the ComboBox
    for(int i=0;i<10;i++)
        ui->comboBox->addItem("item " + QString::number(i));
}

ComboBoxDialog::~ComboBoxDialog()
{
    delete ui;
}


void ComboBoxDialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "Item Selection",
                             ui->comboBox->currentText());
}
