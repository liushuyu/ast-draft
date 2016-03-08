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
        if (QFile::exists(QDir::cleanPath(QDir::toNativeSeparators(get_sysdrive() + "Windows/boot")))) { //Test for automatic clean up function
            return "LOADER_BCD";
        }else{
            return "LOADER_UNKNOWN";
        }
    }
}

QString qast::get_ptable(){
    qDebug() << DEV_FILE_NAME;
    const QString dev_file = QDir::toNativeSeparators(DEV_FILE_NAME); //Translate '\' and '/'
    QFile file(dev_file);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "No data";
            return NULL;
        }
        QByteArray in_data = file.read(128);
        QString sample = "EFI PART";
        QByteArray sample_bin = sample.toUtf8();
        for (int i = 0; i < 8; i++) {
                if (in_data.at(i) == sample_bin.at(i)) {
                    continue;
                }else{
                    return "MBR";
                }
        }
        return "GPT";
}

qint64 qast::get_freespace(){
    QStorageInfo storage = QStorageInfo::root();
    qDebug() << storage.rootPath();
    if (storage.isReadOnly())
        qDebug() << "isReadOnly:" << storage.isReadOnly();

    qDebug() << "name:" << storage.name();
    qDebug() << "fileSystemType:" << storage.fileSystemType();
    qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
    qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";
    return storage.bytesAvailable();
}
