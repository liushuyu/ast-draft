#include "qast.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << qast::backup_mbr(DEV_FILE_NAME, "/home/liushuyu/mbr.bin");
    return a.exec();
}
