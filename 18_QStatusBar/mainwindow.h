#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionMyMenuAction_triggered();

private:
    Ui::MainWindow *ui;

    // add reference to Label and ProgressBar
    QLabel *statusLabel;
    QProgressBar *statusProgressBar;
};
#endif // MAINWINDOW_H
