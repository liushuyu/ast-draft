#include "qast.h"


qast::qast(QObject *parent) : QObject(parent)
{

}

QString qast::get_sysdrive() {
    QStorageInfo sys_storage = QStorageInfo::root();
    QString sys_drive = sys_storage.rootPath() ;
    return (QDir::cleanPath(sys_drive + "/")); //This is convient!
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
    const QString dev_file = QDir::toNativeSeparators(DEV_FILE_NAME); //Translate '\' and '/'
    QFile file(dev_file);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "No data, Perhaps permission denied";
            return NULL;
        }
        QByteArray in_data = file.read(512);
        file.close();
        magic_t ptr = magic_open(MAGIC_NONE);
        ::magic_load(ptr, NULL);
        QString mgc_res = ::magic_buffer(ptr, in_data, in_data.size());
        ::magic_close(ptr);
        if (mgc_res.contains(QRegExp("\\bMBR\\b"))){
            qDebug() << "Found MBR in libmagic match";
            return "MBR";
        }else if (mgc_res.contains(QRegExp("\\bGPT\\b"))) {
            qDebug() << "Found GPT in libmagic match";
            return "GPT";
        }else{
            qDebug() << "Unknow data found:" << mgc_res;
            return NULL;
        }
        /*APPENDIX: How to detect Grub?
         * Well, the entry offset is at MBR : 000:180h (384d)
         * There will be four character "47h 52h 55h 42h" which is "GRUB" encoded in Unicode
         * /
//        int read_offset = 446;
//        QByteArray flags_bin ;
//        flags_bin.append("\x80\x00\xee");
//        if ( in_data.at(read_offset) == flags_bin.at(0)) {
//            qDebug() << "boot flag found";
//        }
//        QString sample = "EFI PART";
//        QByteArray sample_bin = sample.toUtf8();
//        /* Not sure if below works*/
//        for (int i = 0; i < 8; i++) {
//                if (in_data.at(i) == sample_bin.at(i)) {
//                    qDebug() << "EFI Signature Match:" << "at:"<< i << "-- " <<in_data.at(i) ;
//                    continue;
//                }else{
//                    qDebug() << "EFI Signature Mismatch:" << "at:" << i << "-- read:"<< in_data.at(i) << "-- expect:" <<sample_bin.at(i);
//                    return "MBR";
//                }
//        }
//        return "GPT";
}

qint64 qast::get_freespace(){
    QStorageInfo storage = QStorageInfo::root();
    qDebug() << "Read Only:" << storage.isReadOnly();
    qDebug() << "Volume Name:" << storage.name();
    qDebug() << "File System:" << storage.fileSystemType();
    qDebug() << "Total Size:" << storage.bytesTotal()/1048576 << "MB";
    qDebug() << "Available Size:" << storage.bytesAvailable()/1048576 << "MB";
    return storage.bytesAvailable();
}

QString qast::get_cpuarch(){
    return QSysInfo::currentCpuArchitecture();
}

qint64 qast::get_memsize(){
    //Sorry, this can't be tested under Linux...
#ifdef _WIN32
   MEMORYSTATUSEX meminfo;
   meminfo.dwLength = sizeof ( meminfo );
   ::GlobalMemoryStatusEx ( &meminfo );
    return (meminfo.ullTotalPhys);
#else
    return 0;
#endif
}

QString qast::get_os_kver(){
    return QSysInfo::kernelVersion();
}
