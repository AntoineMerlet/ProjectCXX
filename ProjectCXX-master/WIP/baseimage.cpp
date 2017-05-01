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

void BaseImage::lowerResolution()
{
    int h = image->height();
    int w = image->width();
    lowImage = new QImage(int(w/newW),int(h/newH), QImage::Format_RGB32);
    for (int i=0; i<=w-newW; i= i + newW){
        for (int j=0;j<=h-newH;j = j + newH){
            int totalR = 0;
            int totalG = 0;
            int totalB = 0;
            for (int k=i; k<i+newW;k++){
                for (int l=j; l< j + newH;l++){
                    QColor currentpixel(image->pixel(k,l));
                    totalR += currentpixel.red();
                    totalG += currentpixel.green();
                    totalB += currentpixel.blue();
                }
            }
            QRgb result;
            totalR /= newW*newH;
            totalG /= newW*newH;
            totalB /= newW*newH;
            result = qRgb(totalR, totalG, totalB);
            lowImage->setPixel(int(i/newW), int(j/newH), result);
        }
    }
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
             scene->clear();
        QPixmap tmp = *this;
        scene->addPixmap(tmp); // Add the QPixmap to the scene
        BaseImageView->setScene(scene); // Add the scene to the QGraphics view
        BaseImageView->fitInView(this->rect(),Qt::KeepAspectRatio); // Fit with ratio keeping

}

void BaseImage::Displaylow(QGraphicsScene *scene, QGraphicsView *BaseImageView)
{
    //Display the given Qpixmap igm by fitting it into the QGraphicsView while keeping the aspect ratio
         scene->clear();
         QPixmap tmp = QPixmap::fromImage(*lowImage);
         scene->addPixmap(tmp); // Add the QPixmap to the scene
         BaseImageView->setScene(scene); // Add the scene to the QGraphics view
         BaseImageView->fitInView(lowImage->rect(),Qt::KeepAspectRatio); // Fit with ratio keeping
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

QImage* BaseImage::getlowImage(){
    return lowImage;
}
