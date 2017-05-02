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

    void lowerResolution();
    bool loadFromPath(QString);
    void DisplayImg(QGraphicsScene*, QGraphicsView*);
    void Displaylow(QGraphicsScene*, QGraphicsView*);



    bool setPath(QString);
    QString getPath();
    QImage* getlowImage();
private:
    QString path;
    QImage *image;
    QImage *lowImage;

    int newH;
    int newW;
};

#endif // BASEIMAGE_H
