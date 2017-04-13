#include "baseimage.h"

BaseImage::BaseImage()
    :QPixmap()
{
    image = new QImage;
}

BaseImage::BaseImage(QString p)
    :QPixmap(p)
{
    setPath(p);
    image = new QImage;
}

BaseImage::~BaseImage()
{
}

BaseImage BaseImage::lowerResolution(const unsigned int &Msize)
{
    int h = image->height();
    int w = image->width();

    return 0;
}

bool BaseImage::loadFromPath(QString p)
{
    if (this->load(p))
    {
        image->load(p);
        return 1;
    }
    else return 0;
}

void BaseImage::DisplayImg(QGraphicsScene *scene, QGraphicsView *BaseImageView )
{
   //Display the given Qpixmap igm by fitting it into the QGraphicsView while keeping the aspect ratio
        QPixmap tmp = *this;
        scene->addPixmap(tmp); // Add the QPixmap to the scene
        BaseImageView->setScene(scene); // Add the scene to the QGraphics view
        BaseImageView->fitInView(this->rect(),Qt::KeepAspectRatio); // Fit with ratio keeping

}

bool BaseImage::setPath(QString p)
{
    if (!p.isEmpty()){
        path=p;
        return 1;}
    else return 0;
}

QString BaseImage::getPath()
{
    return path;
}
