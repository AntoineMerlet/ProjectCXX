#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QFileDialog>

bool verbose = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    csl = ui->ConsoleOutpout; // the verbose console shortcut
    csl->appendPlainText("*** APPLICATION STARTED ***\n");
    csl->appendPlainText("Setting up UI...");
    scene = new QGraphicsScene(ui->BaseImageView);
    ui->ButtonProcess->setEnabled(false);
    ui->ConsoleOutpout->setVisible(false);
    baseImg = new BaseImage;
    csl->insertPlainText(" Done\nWaiting for user based input...");

}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;

}

void MainWindow::on_File_Open_triggered()
{   // Called up click on the "Open file" menu or its shortcut. Pop up a dialog box for the user to select
    // a file with the specified formats. If the dialog return is empty, skip, else display the image.

    csl->appendPlainText("Opening file selection...\nWaiting for file selection...");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QDir::currentPath(),
                                                    tr("Images (*.jpeg *.jpg *.png)"));

    if (!fileName.isNull())
    {
        if (baseImg->loadFromPath("C:/Qt/Qt5.2.0/Tools/QtCreator/bin/build-ProjectCXX-Desktop_Qt_5_2_0_MSVC2010_32bit_OpenGL-Debug/Chrysanthemum.jpg")) // set the QPixmap
        {
            csl->insertPlainText(" Done\nAdress: "+fileName);
            baseImg->DisplayImg(scene,ui->BaseImageView);
        }
        else csl->insertPlainText(" Error loading");
    } // Displaying
    else
        csl->insertPlainText(" Operation canceled, no file selected");
}

void MainWindow::on_ButtonDB_clicked()
{
    bool AllGood = false;

    AllGood = true;
    if (AllGood)
            ui->ButtonProcess->setEnabled(true);
}


void MainWindow::on_VerboseCheck_clicked()
{   // Display or not the verbose QPlainTextEdit according to the checkbox status

    if (ui->VerboseCheck->isChecked())
        csl->setVisible(true); // If the checkbox is checked, display
    else
        csl->setVisible(false); // else hide

}

void MainWindow::on_File_Save_triggered()
{   // Save the final image with the png format
    csl->appendPlainText("Opening file selection...\nWaiting for file selection...");

    QString fileName = QFileDialog::getSaveFileName(this,
                                 tr("Save the image"),
                                 "",
                                 tr("Images (*.png)"));
    if (!fileName.isNull()){
        outputImage=baseImg;
        outputImage->save(fileName, "png"); // Saving
        csl->insertPlainText("File saved\nAdress: "+fileName);}
    else
        csl->insertPlainText("Operation canceled, no file selected");
}


