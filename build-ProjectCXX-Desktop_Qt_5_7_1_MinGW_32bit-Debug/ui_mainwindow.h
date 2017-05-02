/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *File_Open;
    QAction *File_Save;
    QAction *File_Save_As;
    QAction *File_Quit;
    QAction *actionPreferences;
    QAction *actionAbout;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGraphicsView *BaseImageView;
    QPlainTextEdit *ConsoleOutpout;
    QPushButton *ButtonDB;
    QPushButton *ButtonProcess;
    QCheckBox *VerboseCheck;
    QProgressBar *progressBar;
    QPushButton *ButtonLower;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(633, 666);
        File_Open = new QAction(MainWindow);
        File_Open->setObjectName(QStringLiteral("File_Open"));
        File_Save = new QAction(MainWindow);
        File_Save->setObjectName(QStringLiteral("File_Save"));
        File_Save_As = new QAction(MainWindow);
        File_Save_As->setObjectName(QStringLiteral("File_Save_As"));
        File_Quit = new QAction(MainWindow);
        File_Quit->setObjectName(QStringLiteral("File_Quit"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BaseImageView = new QGraphicsView(centralWidget);
        BaseImageView->setObjectName(QStringLiteral("BaseImageView"));
        BaseImageView->setGeometry(QRect(20, 20, 581, 361));
        ConsoleOutpout = new QPlainTextEdit(centralWidget);
        ConsoleOutpout->setObjectName(QStringLiteral("ConsoleOutpout"));
        ConsoleOutpout->setGeometry(QRect(20, 500, 581, 111));
        ConsoleOutpout->setReadOnly(true);
        ButtonDB = new QPushButton(centralWidget);
        ButtonDB->setObjectName(QStringLiteral("ButtonDB"));
        ButtonDB->setGeometry(QRect(80, 420, 111, 41));
        ButtonProcess = new QPushButton(centralWidget);
        ButtonProcess->setObjectName(QStringLiteral("ButtonProcess"));
        ButtonProcess->setGeometry(QRect(430, 420, 111, 41));
        VerboseCheck = new QCheckBox(centralWidget);
        VerboseCheck->setObjectName(QStringLiteral("VerboseCheck"));
        VerboseCheck->setGeometry(QRect(20, 480, 70, 17));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 620, 581, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        ButtonLower = new QPushButton(centralWidget);
        ButtonLower->setObjectName(QStringLiteral("ButtonLower"));
        ButtonLower->setGeometry(QRect(250, 420, 111, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 633, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(File_Open);
        menuFile->addSeparator();
        menuFile->addAction(File_Save);
        menuFile->addAction(File_Save_As);
        menuFile->addSeparator();
        menuFile->addAction(File_Quit);
        menuOptions->addAction(actionPreferences);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        File_Open->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        File_Open->setShortcut(QApplication::translate("MainWindow", "O", Q_NULLPTR));
        File_Save->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        File_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        File_Save_As->setText(QApplication::translate("MainWindow", "Save as", Q_NULLPTR));
        File_Save_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
        File_Quit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        File_Quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        ButtonDB->setText(QApplication::translate("MainWindow", "Load DataBase", Q_NULLPTR));
        ButtonProcess->setText(QApplication::translate("MainWindow", "Process !", Q_NULLPTR));
        VerboseCheck->setText(QApplication::translate("MainWindow", "Verbose", Q_NULLPTR));
        ButtonLower->setText(QApplication::translate("MainWindow", "Lower Resolution", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
