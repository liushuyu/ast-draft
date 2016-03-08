#include "qast.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"SYS Drive: "<< qast::get_sysdrive() << endl << "BL:" << qast::get_bloader();
    qDebug() << "File:" << qast::get_ptable();
    qDebug() << "Free:" << qast::get_freespace();
    return a.exec();
}
