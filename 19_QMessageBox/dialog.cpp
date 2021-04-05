#include "dialog.h"
#include "ui_dialog.h"
#include <QRadioButton>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    int ret;

    // Property-based API
    if(ui->radioButton->isChecked())
    {
       QMessageBox msgBox;
       msgBox.setText("The document has been modified.");
       ret = msgBox.exec();
    }
    // A better approach
    else if(ui->radioButton_2->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Application");
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save changes?");
        msgBox.setStandardButtons(QMessageBox::Save|
                                  QMessageBox::Discard|
                                  QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        ret = msgBox.exec();
    }
    // Warning
    // radioButton_3
    else
    {
        ret = QMessageBox::warning(this, tr("My Application"),
                                   tr("Do you want to save the changes?"),
                                   QMessageBox::Save|
                                   QMessageBox::Discard|
                                   QMessageBox::Cancel);

    }

    switch(ret)
    {
    case QMessageBox::Save:
        // Todo: Save code
        break;
    case QMessageBox::Discard:
        // Todo: Discard code
        break;
    case QMessageBox::Cancel:
        // Todo: Cancel the operation
        break;
    default:
        // Should never be reached
        break;
    }

}
