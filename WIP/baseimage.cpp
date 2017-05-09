#include "baseimage.h"

BaseImage::BaseImage()
    :QPixmap()
{
    image = new QImage;

}

BaseImage::BaseImage( QString p)
    :QPixmap(p)
{
    setPath(p);
    image = new QImage;
    setImage(p);

}

BaseImage::~BaseImage()
{
}

void BaseImage::lowerResolution()
{
    // Lower the resolution of the image by using the average method. The square defined by newH and newW will by applied
    // iteratively on the image, and calulate the mean of the submatrix below this filter. The result is then used to create a pixel in
    // a brand new QImage named lowImage. The spatial organisation of each pixel is kept. In order to fix the boundaries problem,
    // this function just ignores the right and bottom pixel which cannot fit in the filter.

    // setting the matrix size
    newH = 20;
    newW = 20;
    // get image size
    int h = image->height();
    int w = image->width();
    // create a new image with set size according to base image size and mask size
    lowImage = new QImage( int( w / newW), int( h / newH), QImage::Format_RGB32);
    // parsing the image with the filter. placing the top left pixel of the filter on the top left pixel of the image.
    // The filter is then moved regarding newW and newH
    for ( int i = 0; i <= w - newW; i = i + newW){
        for ( int j = 0; j <= h - newH; j = j + newH){
            // Init the mean variable for this iteration
            int totalR = 0;
            int totalG = 0;
            int totalB = 0;
            // looping insinde the resulting submatrix
            for ( int k = i; k < i + newW; k++){
                for ( int l = j; l < j + newH; l++){
                    // get the color of the current pixel
                    QColor currentpixel(image->pixel(k,l));
                    // add the corresponding channels
                    totalR += currentpixel.red();
                    totalG += currentpixel.green();
                    totalB += currentpixel.blue();
                }
            }
            // division to get the mean.
            totalR /= newW * newH;
            totalG /= newW * newH;
            totalB /= newW * newH;
            // creating the resulting color as a qRGB
            QRgb result = qRgb( totalR, totalG, totalB);
            // create on the new image the resulting pixel
            lowImage->setPixel( int( i / newW), int( j / newH), result);
        }
    }
}

bool BaseImage::setImage( QString p)
{
    // bad implementation, TODO
    this->load( p);
    return image->load( p);
}

void BaseImage::DisplayImg( QGraphicsScene *scene, QGraphicsView *BaseImageView )
{
   //Display the given Qpixmap igm by fitting it into the QGraphicsView while keeping the aspect ratio
    // NEED TO REDO
        scene->clear();
        QPixmap tmp = *this;
        scene->addPixmap( tmp); // Add the QPixmap to the scene
        BaseImageView->setScene( scene); // Add the scene to the QGraphics view
        BaseImageView->fitInView( this->rect(), Qt::KeepAspectRatio); // Fit with ratio keeping

}

void BaseImage::Displaylow( QGraphicsScene *scene, QGraphicsView *BaseImageView)
{
    //Display the given Qpixmap igm by fitting it into the QGraphicsView while keeping the aspect ratio
    // NEED TO REDO
         scene->clear();
         QPixmap tmp = QPixmap::fromImage( *lowImage);
         scene->addPixmap( tmp); // Add the QPixmap to the scene
         BaseImageView->setScene( scene); // Add the scene to the QGraphics view
         BaseImageView->fitInView( lowImage->rect(), Qt::KeepAspectRatio); // Fit with ratio keeping
}


bool BaseImage::setPath( QString p)
{
    if ( !p.isEmpty()){
        path = p;
        return 1;}
    else return 0;
}

QString BaseImage::getPath()
{
    // Return the absolute path of the original image
    return path;
}

QImage* BaseImage::getlowImage()
{
    // Return the low resolution version of the image.
    if ( lowImage->isNull())
        lowerResolution();
    return lowImage;
}

QRgb BaseImage::getMean()
{
    if(mean == 0){
        // get image size
        int h = image->height();
        int w = image->width();
        int totalR = 0;
        int totalG = 0;
        int totalB = 0;
        for ( int i = 0; i < w; i++){
            for ( int j = 0; j < h; j++){
                QColor currentpixel( image->pixel( i, j));
                // add the corresponding channels
                totalR += currentpixel.red();
                totalG += currentpixel.green();
                totalB += currentpixel.blue();
            }
        }
        // division to get the mean.
        totalR /= h * w;
        totalG /= h * w;
        totalB /= h * w;
        // creating the resulting color as a qRGB
        mean = qRgb( totalR, totalG, totalB);
    }
    return mean;
}
