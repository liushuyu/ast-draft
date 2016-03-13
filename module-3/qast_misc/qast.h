#ifndef QAST_H
#define QAST_H

// Qt Stuff
#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QCryptographicHash>
#include <QException>
#include <QStorageInfo>
#include <QSysInfo>
#include <QRegExp>
#include <QNetworkAccessManager>
#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QCryptographicHash>
#include <QException>
#include <QStorageInfo>
#include <QSysInfo>
#include <QRegExp>
// end of Qt stuff
#include <QNetworkRequest>
#include <QNetworkReply>
// end of Qt stuff
#include <iostream>
class qast : public QObject {
  Q_OBJECT
public:
  explicit qast(QObject *parent = 0);
  explicit DownloadFile(QUrl FileUrl, QObject *parent = 0);
  virtual ~DownloadFile();
  static QString qast_sha256sum(QByteArray indata,
                                bool isbitarray); // A little trick, whatever
                                                  // `isbitarray' is true or not
                                                  // you will select this one
  static QString qast_sha256sum(QString filename);
  static QString qast_md5sum(QByteArray indata, bool isbitarray);
  static QString qast_md5sum(QString filename);
  QByteArray downloadedData() const;

signals:
  void downloaded();

private slots:
  void fileDownloaded(QNetworkReply *pReply);

private:
  QNetworkAccessManager m_WebCtrl;
  QByteArray m_DownloadedData;
};

#endif // QAST_H
