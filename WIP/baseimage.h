#ifndef BASEIMAGE_H
#define BASEIMAGE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QRgb>

class BaseImage : public QPixmap
{
public:
    // Constructors
    BaseImage();
    BaseImage( QString);
    ~BaseImage();

    void lowerResolution();
    void DisplayImg( QGraphicsScene*, QGraphicsView*);
    void Displaylow( QGraphicsScene*, QGraphicsView*);

    bool setPath( QString);
    bool setImage( QString);
    QRgb getMean();
    QString getPath();
    QImage* getlowImage();

private:
    QString path;
    QImage *image;
    QImage *lowImage;
    QRgb mean;
    int newH;
    int newW;
};

#endif // BASEIMAGE_H
