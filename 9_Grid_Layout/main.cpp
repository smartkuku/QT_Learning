#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Grid layout with 3 buttons
    QGridLayout *gridLayout = new QGridLayout();
    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    QPushButton *b4 = new QPushButton("D");
    QPushButton *b5 = new QPushButton("E");
    QPushButton *b6 = new QPushButton("F");

    // 0th row
    gridLayout->addWidget(b1,0,0,1,1);
    gridLayout->addWidget(b2,0,1,1,1);
    gridLayout->addWidget(b3,0,2,1,1);

    // 1st row
    gridLayout->addWidget(b4,1,0,1,1);

    // 2nd row with 2-column span
    gridLayout->addWidget(b5,2,1,1,2);

    // 3rd row with 3-column span
    gridLayout->addWidget(b6,3,0,1,3);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the out layout as the main layout
    // of the widget
    w->setLayout(gridLayout);

    // Window title
    w->setWindowTitle("Grid Layout");

    // Display
    w->show();

    // Event loop
    return app.exec();
}
