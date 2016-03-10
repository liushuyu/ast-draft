#include "qast.h"

qast::qast(QObject *parent) : QObject(parent) {}

int qast::backup_mbr(QString root_dev, QString dest_file) {
  QFile mbr_stream(QDir::toNativeSeparators(root_dev));
  if (!mbr_stream.open(QIODevice::ReadOnly)) {
    qDebug() << "Failed to Open Device";
    //std::cout << "Failure!" << std::endl;
    return -1;
  }
  //QByteArray mbr_data = mbr_stream.read(512); //According to Wikipeadia MBR size is 512 bytes :-)
  QByteArray mbr_data = mbr_stream.read(1024);
  mbr_stream.close();
  QFile mbr_out(QDir::toNativeSeparators(dest_file));
  if (!mbr_out.open(QIODevice::ReadWrite)) {
    qDebug() << "Unable to save data!";
    return -1;
  }
  if (!mbr_out.write(mbr_data, mbr_data.size())) {
    std::cout << "Failure!";
  };
  mbr_out.close();
  return 0;
}

int qast::backup_esp(QString ptable, QString dest_file) {
    if (ptable == "GPT") {
        QStringList proc_args;
        proc_args << "W:\\" << "/s";
        proc.start("mountvol", proc_args);
        proc.waitForFinished(5000); //timeout:5seconds
        if (proc.exitCode() != 0) {
            qDebug() << "Failed to mount ...";
            proc.kill();
            return -1;
        }
        try{
            QFile::copy("W:/efi/boot/bootx64.efi", dest_file);
        }catch (...) {
            qDebug() << "Failed to backup!";
        }
    }else if(ptable == "MBR") {

    }else{
        //WTF is this?
        qDebug() << "[WTF]";
        return -1;
    }
}
