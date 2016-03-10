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
#include <QProcess>
//end of Qt stuff
#include <iostream>
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
    static int backup_mbr(QString root_dev, QString dest_file);
    static int backup_esp(QString ptable, QString dest_file); //Param: ptable :"GPT" or "MBR"
signals:

protected:
    QProcess proc;

public slots:
};

#endif // QAST_H
