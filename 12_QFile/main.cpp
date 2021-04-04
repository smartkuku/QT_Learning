#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void write(QString filename)
{
    QFile file(filename);
    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Could not open file for writing";
        return;
    }

    // To write text, we use operator <<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right

    QTextStream out(&file);
    out << "QFile Tutorial";
    file.flush();
    file.close();
}

void read(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug() << "Could not open file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    qDebug() << myText;

    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "F:/Qt/Qt_Learning/12_QFile/MyFile.txt";
    write(filename);
    read(filename);

    return a.exec();
}
