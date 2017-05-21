#ifndef IMAGEDB_H
#define IMAGEDB_H
#include <QString>
#include <vector>
#include <QImage>
#include <QColor>


class ImageDB
{
public:
    // Constructors
    ImageDB();
    ImageDB(ImageDB *);
    ImageDB(QString);
    ~ImageDB();

    void buildDB(const int &);
    QImage* bestMatch(const QColor &);
    QColor* computeMean(QImage *img);

    // Getters
    QString getPath() const {return path;}
    std::vector<QImage*>  getData() const {return data;}
    int getNbImg() const {return nbImg;}
    std::vector<QColor*> getMeans() const {return means;}

    // Setters
    void setPath(const QString &p) {path = p;}
    void setData(const std::vector<QImage*>  &d) {data = d;}
    void setMeans(const std::vector<QColor*> &d) {means = d;}
    void setNbImg(const int &nb) {nbImg = nb;}

private:
    QString path;
    int nbImg;
    std::vector<QImage*> data;
    std::vector<QColor*> means;
};

#endif // IMAGEDB_H
