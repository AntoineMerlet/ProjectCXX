#ifndef BASEIMAGE_H
#define BASEIMAGE_H

#include <QPixmap>

class BaseImage : public QPixmap
{
public:
    // Constructors
    BaseImage();
    BaseImage(QString);
    ~BaseImage();

    void resizeImage(const unsigned int &,const unsigned int &);
    BaseImage lowerResolution(const unsigned int &);

    bool setPath(QString);
    QString getPath();
private:
    QString path;
};

#endif // BASEIMAGE_H
