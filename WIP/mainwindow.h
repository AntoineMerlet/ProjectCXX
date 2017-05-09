#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include "baseimage.h"
#include "imagedb.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_File_Open_triggered();

    void on_ButtonDB_clicked();

    void on_VerboseCheck_clicked();

    void on_File_Save_triggered();

    void on_ButtonLower_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    BaseImage *baseImg;
    ImageDB *DB;
    QPixmap *outputImage;
    QPlainTextEdit *csl;
};

#endif // MAINWINDOW_H
