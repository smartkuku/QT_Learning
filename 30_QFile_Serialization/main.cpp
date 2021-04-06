#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QMap>
#include <QDebug>

class Student
{
public:
    int ID;
    QString Name;

    // ostream, << overloading
    friend QDataStream& operator<<(QDataStream &out, const Student &s)
    {
        out << s.ID << s.Name;
        return out;
    }

    // istream, >> overloading
    friend QDataStream& operator>>(QDataStream &in, Student &s)
    {
        s = Student();
        in >> s.ID >> s.Name;
        return in;
    }

};

void SaveClass()
{
    Student s1;
    s1.ID = 1;
    s1.Name = "Ravel";

    Student s2;
    s2.ID = 2;
    s2.Name = "Schonberg";


    QString filename = "F:/QT/QT_Learning/30_QFile_Serialization/serialclass.txt";
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_1);

    out << s1 << s2;

    file.flush();
    file.close();
}

void LoadClass()
{
    Student s1;
    Student s2;

    QString filename = "F:/QT/QT_Learning/30_QFile_Serialization/serialclass.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);

    in >> s1 >> s2;

    file.close();

    qDebug() << s1.Name << "'s ID is " << s1.ID;
    qDebug() << s2.Name << "'s ID is " << s2.ID;
}


void Save()
{
    QString filename = "F:/QT/QT_Learning/30_QFile_Serialization/serial.txt";
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    int MyPass = 999;
    QMap<int, QString> map;

    map.insert(1, "uno");
    map.insert(2, "dos");
    map[3] = "tres";

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_1);

    out << MyPass << map;

    file.flush();
    file.close();
}

void Load()
{
    QString filename = "F:/QT/QT_Learning/30_QFile_Serialization/serial.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    int MyPass;
    QMap<int, QString> map;

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);

    in >> MyPass >> map;

    file.close();

    qDebug() << "MyPass = " << MyPass;
    foreach(QString item, map.values())
        qDebug() << item;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Save();
    Load();

    SaveClass();
    LoadClass();

    return a.exec();
}
