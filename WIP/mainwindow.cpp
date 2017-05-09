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
    // init the QGraphicScene
    scene = new QGraphicsScene(ui->BaseImageView);
    // Remove scroll bars
    ui->BaseImageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->BaseImageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Disable buttons until ready for use
    ui->ButtonProcess->setEnabled(false);
    ui->ConsoleOutpout->setVisible(false);
    ui->ButtonLower->setEnabled(false);
    // Basic init of the input image
    baseImg = new BaseImage;
    csl->insertPlainText(" Done\nWaiting for user based input...");
}

MainWindow::~MainWindow()
{
    csl->insertPlainText(" Killing Mainwindow ...\n");
    delete baseImg;
    delete scene;
    delete ui;
}

void MainWindow::on_File_Open_triggered()
{   // Called upon click on the "Open file" menu or its shortcut. Pop up a dialog box for the user to select
    // a file with the specified formats. If the dialog return is empty, skip, else display the image.

    csl->appendPlainText("Opening file selection...\nWaiting for file selection...");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QDir::currentPath(),
                                                    tr("Images (*.jpeg *.jpg *.png)"));

    // checking that a file has been selected
    if (!fileName.isNull())
    {
        if (baseImg->setImage(fileName)) // set the QPixmap, checking the reeturn bool for success
        {
            csl->insertPlainText(" Done\nAdress: "+fileName+"\n");
            baseImg->DisplayImg(scene,ui->BaseImageView);
            // enqble the button to lower the resolution
            ui->ButtonLower->setEnabled(true);
        }
        else csl->insertPlainText(" Error loading");
    } // Displaying
    else
        csl->insertPlainText(" Operation canceled, no file selected");
}

void MainWindow::on_ButtonDB_clicked()
{
    //Called upon click on the Load DB button. Pops-up a window for the user to select a folder that should contain images.
    // Once the path of the folder is retrived, build a ImageDB item, wich will then process the DB. Check the ImageDB::Functions for more details.

    csl->insertPlainText(" Waiting for the user to select a folder...");
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select DB folder"));

   // checking that a folder has been selected
    if(!folderPath.isEmpty())
    {
        // Init imageDB
        DB = new ImageDB(folderPath);
        csl->insertPlainText(" Done\nAdress: "+folderPath+"\n");
        csl->insertPlainText(" Generating Data...\n");

        // Retrive all the images path in a list
        DB->buildDB(csl);
        csl->insertPlainText(" Done\nReady for processing");
        ui->ButtonProcess->setEnabled(true);
    }
}


void MainWindow::on_VerboseCheck_clicked()
{   // Display or not the verbose QPlainTextEdit according to the checkbox status

    if (ui->VerboseCheck->isChecked())
        csl->setVisible(true); // If the checkbox is checked, display
    else
        csl->setVisible(false); // else hide

}

void MainWindow::on_File_Save_triggered()
{   // Save the image with the png format
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
