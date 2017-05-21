#include "imagedb.h"
#include <QDir>
#include <vector>
using namespace std;

ImageDB::ImageDB()
{
    // Default constructor
}

ImageDB::ImageDB(ImageDB* db)
{
    // Copy Constructor
    setPath(db->getPath());
    setData(db->getData());
    setNbImg(db->getNbImg());
}

ImageDB::ImageDB(QString p)
{
    // Constructor based on the data path p
    setPath(p);
}

ImageDB::~ImageDB()
{
    // Destructor
    data.clear();
}

void ImageDB::buildDB(const int& size)
{
    // Instanciate images contained in dir into the vector data, while performing image
    // scaling.

    // source :http://stackoverflow.com/questions/36005814/load-images-from-folder-with-qt
    // StackOverflow, User : Apin, Date : Mar 15 2016

    QDir dir(path);
    QStringList filter;
    filter << QLatin1String("*.png");
    filter << QLatin1String("*.jpeg");
    filter << QLatin1String("*.jpg");
    dir.setNameFilters(filter);
    QFileInfoList filelistinfo = dir.entryInfoList();
    QStringList fileList;
    setNbImg(filelistinfo.size());
    // END OF SOURCE

    // Go through every file
    data.clear();
    means.clear();
    foreach (const QFileInfo& fileinfo, filelistinfo) {

        // Get file name
        QString filePath = fileinfo.absoluteFilePath();

        QImage *tmp= new QImage();
        tmp->load(filePath);

        // Generate pixelized version
        QImage *low = new QImage(tmp->scaled(size,size, Qt::KeepAspectRatio));

        // add data to vector
        data.push_back(low);
        means.push_back(computeMean(tmp));
        delete tmp;
    }


}

QImage* ImageDB::bestMatch(const QColor& color)
{
    // Try to find the best match in the DataBase given a color
    // Base on the mean absolute difference otpimisation fucntion

    // Counters for RGB and Total
    int diffR, diffG, diffB, diffT;

    // Base score, 3 channels, max 255/channel
    int opti = 255 * 3;

    // best result
    QImage* best;

    // Parse the vector
    std::vector<QImage*>::iterator it1 = data.begin();
    std::vector<QColor*>::iterator it2 = means.begin();

    // loop on both vectors at the same time
    for (it1, it2; it1 != data.end(), it2 !=means.end(); it1++, it2++) {

        // Get current item
        QImage* currentImg = *it1;
        QColor* currentMean = *it2;

        // Compute the absolute mean difference
        diffR = abs(color.red() -  currentMean->red());
        diffG = abs(color.green() - currentMean->green());
        diffB = abs(color.blue() -  currentMean->blue());

        // Total mean absolute difference
        diffT = diffR + diffG + diffB;

        // Check if new best result
        if (diffT < opti) {
            best = currentImg;

            // Update best goal
            opti = diffT;
        }
    }
    return best;
}



QColor* ImageDB::computeMean(QImage *img){
        // Computes the mean value of lowImage

        // get image size
        int h = img->height();
        int w = img->width();

        // init counters in RGB
        int totalR = 0;
        int totalG = 0;
        int totalB = 0;

        // Goign through the image
        for ( int i = 0; i < w; i++){
            for ( int j = 0; j < h; j++){

                // get the current pixel value
                QColor currentpixel( img->pixel( i, j));

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
        return new QColor( totalR, totalG, totalB);
    }


