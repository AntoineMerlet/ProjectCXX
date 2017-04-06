#include "baseimage.h"

BaseImage::BaseImage()
{
}

BaseImage::BaseImage(QString p)
{
    setPath(p);
}

BaseImage::~BaseImage()
{

}

void BaseImage::resizeImage(const unsigned int &, const unsigned int &)
{

}

BaseImage BaseImage::lowerResolution(const unsigned int &)
{

}

bool BaseImage::setPath(QString p)
{
    if (!p.isEmpty()) path=p;
}

QString BaseImage::getPath()
{
    return p;
}
