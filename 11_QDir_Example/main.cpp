#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // forward slash for directory separator
    QDir dir1("F:/Qt");
    QString path = "F:/Qt/test";
    QDir dir2(path);

    // output: true false

    qDebug()<<dir1.path()<<"exist:"<<dir1.exists();
    qDebug()<<dir2.path()<<"exist:"<<dir2.exists();

    if(!dir2.exists())
    {
        qDebug()<<"Creating "<<path<<"directory";
        dir2.mkpath(path);
        qDebug()<<dir2.path()<<"exist:"<<dir2.exists();
    }

    QDir dir3;
    foreach(QFileInfo item, dir3.drives())
        qDebug()<<item.absoluteFilePath();

    foreach(QFileInfo item, dir1.entryInfoList())
    {
        if(item.isDir())
            qDebug()<<"Dir: "<<item.absoluteFilePath();
        if(item.isFile())
            qDebug()<<"File: "<<item.absoluteFilePath();
    }

    return a.exec();
}
