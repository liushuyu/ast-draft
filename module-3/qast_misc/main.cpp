#include "qast.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Calculating...";
    QString res = qast::qast_sha256sum("/home/liushuyu/liushuyu.tar.xz");
    qDebug() << "\r" << res;
    return a.exec();
}
