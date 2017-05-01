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
    ui->ButtonLower->setEnabled(false);
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
        if (baseImg->loadFromPath(fileName)) // set the QPixmap
        {
            csl->insertPlainText(" Done\nAdress: "+fileName+"\n");
            baseImg->DisplayImg(scene,ui->BaseImageView);

            ui->ButtonLower->setEnabled(true);
        }
        else csl->insertPlainText(" Error loading");
    } // Displaying
    else
        csl->insertPlainText(" Operation canceled, no file selected");
}

void MainWindow::on_ButtonDB_clicked()
{
    bool AllGood = false;
    // source :http://stackoverflow.com/questions/36005814/load-images-from-folder-with-qt
    // StackOverflow, User : Apin, Date : Mar 15 2016
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select DB folder"));
    if(!folderPath.isEmpty())
    {
        QDir dir(folderPath);
        QStringList filter;
        filter << QLatin1String("*.png");
        filter << QLatin1String("*.jpeg");
        filter << QLatin1String("*.jpg");
        dir.setNameFilters(filter);
        QFileInfoList filelistinfo = dir.entryInfoList();
        QStringList fileList;
        foreach (const QFileInfo &fileinfo, filelistinfo) {
            QString imageFile = fileinfo.absoluteFilePath();
            csl->insertPlainText("Adress: "+imageFile+"\n");

        }
    }
    // end of source
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
    csl->appendPlainText("Opening file selection...\nWaiting for file selection...\n");

    QString fileName = QFileDialog::getSaveFileName(this,
                                 tr("Save the image"),
                                 "",
                                 tr("Images (*.png)"));
    if (!fileName.isNull()){
        outputImage=baseImg;
        outputImage->save(fileName, "png"); // Saving
        csl->insertPlainText("File saved\nAdress: "+fileName+"\n");}
    else
        csl->insertPlainText("Operation canceled, no file selected\n");
}



void MainWindow::on_ButtonLower_clicked()
{
    // lower the resolution of the loaded image and display the result
    csl->insertPlainText("Lowering resolution ...");
    baseImg->lowerResolution();
    csl->insertPlainText("Done\n");
    csl->insertPlainText("Displaying result ...");
    baseImg->Displaylow(scene,ui->BaseImageView);
    csl->insertPlainText("Done\n");
}
