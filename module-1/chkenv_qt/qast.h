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
#include <QStorageInfo>
#include <QSysInfo>
#include <QRegExp>
//end of Qt stuff
#include <iostream>
#include <magic.h>
//Below just for testing under Linux
#ifdef _WIN32
#include <windows.h>
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
    static qint64 get_freespace();
    static QString get_cpuarch();
    static qint64 get_memsize();
    static QString get_os_kver();
signals:

public slots:
};

#endif // QAST_H
