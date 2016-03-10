#include "qast.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"SYS Drive: "<< qast::get_sysdrive() << endl << "BL:" << qast::get_bloader();
    qDebug() << "Part Table:" << qast::get_ptable();
    qDebug() << "Free:" << qast::get_freespace();
    qDebug() << "CPU:" << qast::get_cpuarch();
    qDebug() << "RAM:" << qast::get_memsize();
    qDebug() << "OS Kernel Version:" << qast::get_os_kver();
    return 0;
    //return a.exec();
}
