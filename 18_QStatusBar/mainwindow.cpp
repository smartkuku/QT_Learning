#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create object for the label and progress bar
    statusLabel = new QLabel(this);
    statusProgressBar = new QProgressBar(this);

    // set text for the label
    statusLabel->setText("Status Label");

    // make progress bar text invisible
    statusProgressBar->setTextVisible(false);

    // add the two control to the status bar
    ui->statusbar->addPermanentWidget(statusLabel);
    ui->statusbar->addPermanentWidget(statusProgressBar,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionMyMenuAction_triggered()
{
    ui->statusbar->showMessage("Status");
    statusProgressBar->setValue(51);
}
