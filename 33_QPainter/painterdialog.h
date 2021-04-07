#ifndef PAINTERDIALOG_H
#define PAINTERDIALOG_H

#include <QDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class PainterDialog; }
QT_END_NAMESPACE

class PainterDialog : public QDialog
{
    Q_OBJECT

public:
    PainterDialog(QWidget *parent = nullptr);
    ~PainterDialog();

private:
    Ui::PainterDialog *ui;

protected:
    void paintEvent(QPaintEvent *e);
};
#endif // PAINTERDIALOG_H
