#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_File_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   QDir::currentPath(),
                                                    tr("Images (*.jpeg *.jpg)"));
    QImage image(fileName);

    QPixmap pixmap(fileName);
    scene->addPixmap(pixmap);
    ui->view->setScene(scene);
    ui->view->show();

}
