#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcatchbindialog.h"
#include "qpuzzledragondialog.h"
#include "qbincomparedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->catchBin, SIGNAL(clicked()), this, SLOT(clickCatchBin()));
    connect(ui->puzzleDragon, SIGNAL(clicked()),this,SLOT(clickPuzzleDragon()));
    connect(ui->compare, SIGNAL(clicked()), this, SLOT(clickCompareBin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickCatchBin()
{
    QCatchBinDialog dialog(this);
    this->hide();
    dialog.exec();
    this->show();
}

void MainWindow::clickPuzzleDragon()
{
    QPuzzleDragonDialog dialog(this);
    this->hide();
    dialog.exec();
    this->show();
}

void MainWindow::clickCompareBin()
{
    QBinCompareDialog dialog(this);
    this->hide();
    dialog.exec();
    this->show();
}



