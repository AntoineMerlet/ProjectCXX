#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include "imagedb.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0);

    void DisplayImg(QImage*);
    void Artify();

    ~MainWindow();

private slots:
    void on_File_Open_triggered();

    void on_ButtonDB_clicked();

    void on_VerboseCheck_clicked();

    void on_File_Save_triggered();

    void on_ButtonLower_clicked();

    void on_ButtonProcess_clicked();

    void on_File_Quit_triggered();

    void on_SpinImage_valueChanged(int arg1);

    void on_SpinSubImage_valueChanged(int arg1);

private:
    int ImageSize = 50;
    int subImageSize = 30;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPlainTextEdit *csl;

    QImage *baseImg;
    QImage *lowImage;
    QImage *result;

    ImageDB *DB;
};

#endif // MAINWINDOW_H
