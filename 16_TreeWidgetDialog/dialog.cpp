#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Set the number of columns in the tree
    ui->treeWidget->setColumnCount(2);

    // Set the headers
    ui->treeWidget->setHeaderLabels(QStringList()<<"ABC"<<"123");

    // Add root nodes
    addTreeRoot("A", "Root_first");
    addTreeRoot("B", "Root_second");
    addTreeRoot("C", "Root_third");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addTreeRoot(QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    treeItem->setText(0, name);
    treeItem->setText(1, description);

    addTreeChild(treeItem, name+"A", "Child_first");
    addTreeChild(treeItem, name+"B", "Child_first");
}

void Dialog::addTreeChild(QTreeWidgetItem *parent, QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    treeItem->setText(0, name);
    treeItem->setText(1, description);

    parent->addChild(treeItem);
}


void Dialog::on_pushButton_clicked()
{
    QBrush brush_red(Qt::red);
    ui->treeWidget->currentItem()->setBackground(0, brush_red);
    QBrush brush_green(Qt::green);
    ui->treeWidget->currentItem()->setBackground(1, brush_green);
}
