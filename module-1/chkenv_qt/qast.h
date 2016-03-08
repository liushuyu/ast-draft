#ifndef QAST_H
#define QAST_H
//Qt Stuff
#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QException>
//end of Qt stuff

//Below just for testing under Linux
#ifdef _WIN32
#define DEV_FILE_NAME "//./PhysicalDrive0"
#else
#define DEV_FILE_NAME "/dev/sda"
#endif
//--- :-)

class qast : public QObject
{
    Q_OBJECT
public:
    explicit qast(QObject *parent = 0);
    static QString get_sysdrive();
    static QString get_ptable();
    static QString get_bloader();
signals:

public slots:
};

#endif // QAST_H
