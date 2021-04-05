#ifndef COMBOBOXDIALOG_H
#define COMBOBOXDIALOG_H

#include <QDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ComboBoxDialog; }
QT_END_NAMESPACE

class ComboBoxDialog : public QDialog
{
    Q_OBJECT

public:
    ComboBoxDialog(QWidget *parent = nullptr);
    ~ComboBoxDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ComboBoxDialog *ui;
};
#endif // COMBOBOXDIALOG_H
