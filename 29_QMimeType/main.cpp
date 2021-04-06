#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QMimeType>
#include <QDebug>

// Returning a mimetype for a given QFile
QString mimeReturn(const QFile& file)
{
    QMimeDatabase mimeDatabase;
    QMimeType mimeType;

    mimeType = mimeDatabase.mimeTypeForFile(QFileInfo(file));

    // mp4 mpg4
    if(mimeType.inherits("video/mp4"))
        return "video/mp4";
    // mpeg mpg mpe
    else if(mimeType.inherits("video/mpeg"))
        return "video/mpeg";
    // ogv
    else if(mimeType.inherits("video/ogg"))
        return "video/ogg";
    // qt, mov
    else if(mimeType.inherits("video/quicktime"))
        return "video/quicktime";
    // avi
    else if(mimeType.inherits("video/x-msvideo"))
        return "video/x-msvideo";
    // flv
    else if (mimeType.inherits("video/x-flv"))
        return "video/x-flv";
    // webm
    else if (mimeType.inherits("video/webm"))
        return "video/webm";
    // text
    else if (mimeType.inherits("text/plain"))
        return "text";
    else
        return "";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList List;
    List << "1.txt" << "2.mp4" << "3.webm"
         << "4.mov" << "5.flv";

    foreach(QString item, List)
    {
        qDebug() << item << "==>" << mimeReturn(item);
    }

    return a.exec();
}
