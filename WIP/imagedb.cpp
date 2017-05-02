#include "imagedb.h"
#include <QDir>
#include <iostream>

ImageDB::ImageDB()
{

}

ImageDB::ImageDB(QString p){
    path = p;
}

void ImageDB::buildDB(QPlainTextEdit *csl)
{

    // source :http://stackoverflow.com/questions/36005814/load-images-from-folder-with-qt
    // StackOverflow, User : Apin, Date : Mar 15 2016
    QDir dir(path);
    QStringList filter;
    filter << QLatin1String("*.png");
    filter << QLatin1String("*.jpeg");
    filter << QLatin1String("*.jpg");
    dir.setNameFilters(filter);
    QFileInfoList filelistinfo = dir.entryInfoList();
    QStringList fileList;
    nbImg  = filelistinfo.size();
    csl->insertPlainText(" Images loaded : " + QString::number(filelistinfo.size()) );
    foreach (const QFileInfo &fileinfo, filelistinfo) {
        QString imageFile = fileinfo.absoluteFilePath();
    // END OF SOURCE
        csl->insertPlainText("\n" + imageFile );
    }
}




