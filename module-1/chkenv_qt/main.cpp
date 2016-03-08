#include "qast.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"SYS Drive: "<< qast::get_sysdrive() << endl << "BL:" << qast::get_bloader();
    return a.exec();
}
