#ifndef IMAGEDB_H
#define IMAGEDB_H
#include <QString>

class ImageDB
{
public:
    ImageDB();
    ImageDB(QString);

private:
    QString path;
    QString nbImg;
};

#endif // IMAGEDB_H
