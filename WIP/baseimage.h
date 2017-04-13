#ifndef BASEIMAGE_H
#define BASEIMAGE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>

class BaseImage : public QPixmap
{
public:
    // Constructors
    BaseImage();
    BaseImage(QString);
    ~BaseImage();

    BaseImage lowerResolution(const unsigned int &);
    bool loadFromPath(QString);
    void DisplayImg(QGraphicsScene*, QGraphicsView*);


    bool setPath(QString);
    QString getPath();
private:
    QString path;
    QImage *image;
};

#endif // BASEIMAGE_H
