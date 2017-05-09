#ifndef IMAGEDB_H
#define IMAGEDB_H
#include <QString>
#include <QPlainTextEdit>
#include <vector>
#include <QRgb>
#include "baseimage.h"


class ImageDB
{
public:
    ImageDB();
    ImageDB( QString);
    void buildDB( QPlainTextEdit*);

private:
    QString path;
    std::vector< std::pair< BaseImage*, QRgb> > data;
    QString nbImg;
};

#endif // IMAGEDB_H
