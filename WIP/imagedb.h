#ifndef IMAGEDB_H
#define IMAGEDB_H
#include <QString>
#include <QPlainTextEdit>
class ImageDB
{
public:
    ImageDB();
    ImageDB(QString);
    void buildDB(QPlainTextEdit*);

private:
    QString path;
    QString nbImg;
};

#endif // IMAGEDB_H
