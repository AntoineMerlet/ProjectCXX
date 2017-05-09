#include "imagedb.h"
#include <QDir>
#include <iostream>
#include <vector>
#include <QRgb>

using namespace std;

ImageDB::ImageDB()
{

}

ImageDB::ImageDB( QString p){
    path = p;
}

void ImageDB::buildDB( QPlainTextEdit *csl)
{

    // source :http://stackoverflow.com/questions/36005814/load-images-from-folder-with-qt
    // StackOverflow, User : Apin, Date : Mar 15 2016
    QDir dir( path);
    QStringList filter;
    filter << QLatin1String("*.png");
    filter << QLatin1String("*.jpeg");
    filter << QLatin1String("*.jpg");
    dir.setNameFilters(filter);
    QFileInfoList filelistinfo = dir.entryInfoList();
    QStringList fileList;
    nbImg  = filelistinfo.size();
    csl->insertPlainText("Images loaded : " + QString::number(filelistinfo.size()) + "\n");

    foreach ( const QFileInfo &fileinfo, filelistinfo) {
        QString imageFile = fileinfo.absoluteFilePath();
    // END OF SOURCE
        BaseImage* tmp = new BaseImage(imageFile);
        std::pair<BaseImage*,QRgb> tmple;
        tmple.first = tmp;
        tmple.second = QRgb;
        data.push_back(tmple);
        csl->insertPlainText(tmple.first->getPath() + " " + tmple.second.green());


    }

    for ( unsigned int i = 0; i < data.size(); i++)
    {
        std::pair< BaseImage*, QRgb> FOO = data[i];
        QRgb toto = FOO.second;
        csl->insertPlainText( FOO.first->getPath()+ "\n" );


        //do something with foo
    }





    //csl->insertPlainText( *i.+ "\n");
}




