#ifndef QAST_H
#define QAST_H
#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>


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
