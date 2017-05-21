#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    // init the QGraphicScene
    scene = new QGraphicsScene(ui->BaseImageView);

    // Remove scroll bars
    ui->BaseImageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->BaseImageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Disable buttons until ready for use
    ui->ButtonProcess->setEnabled(false);
    ui->ConsoleOutpout->setVisible(false);
    ui->ButtonLower->setEnabled(false);

    csl->insertPlainText(" Done\nWaiting for user based input...");

    // Init attributes
    baseImg = new QImage;
    lowImage = new QImage;
    result = new QImage;
    DB = new ImageDB;
}

MainWindow::~MainWindow()
{
    // Destructor
    csl->insertPlainText(" Killing Mainwindow ...\n");
    delete scene;
    delete csl;

    delete baseImg;
    delete DB;
    delete lowImage;
    delete result;

    delete ui;
}

void MainWindow::DisplayImg(QImage *img){
    // Display the image img on the QGraphicScene with ratio keeping

    // clear the scene from previous images
    scene->clear();
    QPixmap tmp = QPixmap::fromImage( *img);

    // Add the QPixmap to the scene
    scene->addPixmap( tmp);

    // Add the scene to the QGraphics view
    ui->BaseImageView->setScene( scene);

    // Fit with ratio keeping
    ui->BaseImageView->fitInView( img->rect(), Qt::KeepAspectRatio);
}

void MainWindow::on_File_Open_triggered()
{   // Called upon click on the "Open file" menu or its shortcut. Pop up a dialog box for the user to select
    // a file with the specified formats. If the dialog return is empty, skip, else display the image.

    csl->appendPlainText("\n*** IMAGE SELECTION STARTED ***\n");

    csl->appendPlainText("Waiting for file selection...");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QDir::currentPath(),
                                                    tr("Images (*.jpeg *.jpg *.png)"));
    // checking that a file has been selected
    if (!fileName.isNull())
    {
        // Basic init of the input image
        baseImg = new QImage(fileName);

        csl->insertPlainText(" Done\nAdress: "+fileName+"\n");

        DisplayImg(baseImg);

        // enable the button to lower the resolution
        ui->ButtonLower->setEnabled(true);
        ui->ButtonDB->setEnabled(false);
        ui->ButtonProcess->setEnabled(false);
    }
    else
        csl->insertPlainText(" Operation canceled, no file selected\n");
}

void MainWindow::on_ButtonDB_clicked()
{
    //Called upon click on the Load DB button. Pops-up a window for the user to select a folder that should contain images.
    // Once the path of the folder is retrived, build a ImageDB item, wich will then process the DB. Check the ImageDB::Functions for more details.

    csl->appendPlainText("\n*** LOADING DATABASE ***\n\n");

    csl->insertPlainText("Waiting for the user to select a folder...");

    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select DB folder"));

    // checking that a folder has been selected
    if(!folderPath.isEmpty())
    {
        // Init imageDB
        DB = new ImageDB(folderPath);

        csl->insertPlainText(" Done\nAdress: "+folderPath+"\n");
        csl->insertPlainText("Generating Data (Might take a while)...");

        // Retrive all the images path in a list
        DB->buildDB(subImageSize);


        csl->insertPlainText(" Done! "+ QString::number(DB->getNbImg()) +"images loaded.\nReady for processing");

        ui->ButtonProcess->setEnabled(true);
    }
}


void MainWindow::on_VerboseCheck_clicked()
{
    // Display or not the verbose QPlainTextEdit according to the checkbox status

    if (ui->VerboseCheck->isChecked())

        // If the checkbox is checked, display
        csl->setVisible(true);
    else
        // else hide
        csl->setVisible(false);
}

void MainWindow::on_File_Save_triggered()
{
    // Save the image with the png format
    csl->appendPlainText("*** SAVING RESULT ***\n\n");

    csl->appendPlainText("Opening file selection...\nWaiting for file selection...\n");

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save the image"),
                                                    "",
                                                    tr("Images (*.png)"));
    if (!fileName.isNull()){
        result->save(fileName, "png"); // Saving
        csl->insertPlainText("File saved\nAdress: "+fileName+"\n");}
    else
        csl->insertPlainText("Operation canceled, no file selected\n");
}



void MainWindow::on_ButtonLower_clicked()
{
    // lower the resolution of the loaded image and display the result
    csl->appendPlainText("*** SCALING IMAGE ***\n\n");

    csl->insertPlainText("Lowering resolution...");

    // Lowering
    lowImage = new QImage(baseImg->scaled(ImageSize,ImageSize, Qt::KeepAspectRatio));

    csl->insertPlainText(" Done\n");
    csl->insertPlainText("Displaying result...");

    // Displaying
    DisplayImg(lowImage);

    csl->insertPlainText(" Done");

    ui->ButtonDB->setEnabled(true);
}

void MainWindow::on_ButtonProcess_clicked()
{
    // Process the Loaded image according to the DataBase

    csl->appendPlainText("\n*** PROCESSING IMAGE ***\n\n");

    // Main function
    Artify();

    csl->insertPlainText("Displaying result ...");

    // Dispaly
    DisplayImg(result);

    csl->insertPlainText(" Done\n");
}


void MainWindow::Artify()
{
    // Replace evry pixel in baseImg->lowImage by an image in DB which is the
    // best match

    // Retreive the image


    // get Width and Height
    int h = lowImage->height();
    int w = lowImage->width();


    // best result for a given pixel initialization
    QImage* bestResult ;

    // Prepare the result image with good size
    result = new QImage( w * subImageSize, h * subImageSize, QImage::Format_RGB32);

    // for every pixel in the lowImage
    for ( int i = 0; i < w; i++){
        for ( int j = 0; j < h; j++){

            // Get current pixel
            QColor currentpixel(lowImage->pixel( i,j));

            // Get the best result in the DataBase
            bestResult = DB->bestMatch(currentpixel);

            // Get pixelized version

            // For every pixel in the ebst match low resolution
            for (int k = 0; k< bestResult->width();k++){
                for (int l = 0; l < bestResult->height(); l++){

                    // Get current pixel
                    QColor currentMatch =bestResult->pixel(k,l);

                    // Place on res at the good position
                    result->setPixel(i * subImageSize + k, j * subImageSize + l, currentMatch.rgb());
                }
            }
        }
    }
}

void MainWindow::on_File_Quit_triggered()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_SpinImage_valueChanged(int arg1)
{
        ImageSize=arg1;
}

void MainWindow::on_SpinSubImage_valueChanged(int arg1)
{
        subImageSize=arg1;
}

