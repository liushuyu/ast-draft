#include "qast.h"

qast::qast(QObject *parent) : QObject(parent)
{

}

QString qast::qast_sha256sum(QByteArray indata, bool) {
    return QString(QCryptographicHash::hash(indata,QCryptographicHash::Sha256).toHex());
}

QString qast::qast_sha256sum(QString filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File error!";
        return NULL;
    }
    return qast::qast_sha256sum(file.readAll(), 0);
}

QString qast::qast_md5FileDownloadersum(QByteArray indata, bool){
    return QString(QCryptographicHash::hash(indata,QCryptographicHash::Md5).toHex());
}

QString qast::qast_md5sum(QString filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File error!";
        return NULL;
    }
    return qast::qast_md5sum(file.readAll(), 0);
}

qast::DownloadFile(QUrl FileUrl, QObject *parent): QObject(parent) {
    connect(&m_WebCtrl, SIGNAL (finished(QNetworkReply*)),  this, SLOT (fileDownloaded(QNetworkReply*)) );
    QNetworkRequest request(FileUrl);
    m_WebCtrl.get(request);
}

qast::~DownloadFile(){

}

void qast::fileDownloaded(QNetworkReply *pReply) {
    m_DownloadedData = pReply->readAll();
     //emit a signal
     pReply->deleteLater();
     emit downloaded();
}

QByteArray qast::downloadedData() const {
    return m_DownloadedData;
   }
