#include "qast.h"

qast::qast(QObject *parent) : QObject(parent)
{

}

QString qast::get_sysdrive() {
    QString sys_drive = (getenv("SystemDrive") == NULL) ? getenv("SystemDrive") : "" ;
    return (sys_drive + "/"); //This is convient in CPP!
}

QString qast::get_bloader(){
    if (QFile::exists(QDir::toNativeSeparators(get_sysdrive() + "NTLDR"))){
        return "LOADER_NTLDR";
    }else{
        if (QFile::exists(QDir::cleanPath(QDir::toNativeSeparators(get_sysdrive() + "Windows/boot")))) {
            return "LOADER_BCD";
        }else{
            return "LOADER_UNKNOWN";
        }
    }
}

QString qast::get_ptable(){
    const QString dev_file = QDir::toNativeSeparators("//./PhysicalDrive0");
    return "not_yet";
}
