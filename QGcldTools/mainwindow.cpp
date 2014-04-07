#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qconvertdialogure.h"
#include "qbezierpoly.h"
#include "qcityroadmap.h"
#include "qcityposition.h"
#include "qcubepoly.h"
#include "qpolytime.h"
#include "qcollectxiaoqiandialogure.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->convertDialogue,SIGNAL(clicked()),this,SLOT(clickConvertDialogue()));
    connect(ui->bezierPoly, SIGNAL(clicked()),this, SLOT(clickConvertBezierPoly()));
    connect(ui->cityRoadMap, SIGNAL(clicked()), this, SLOT(clickCityRoadMap()));
    connect(ui->cityPosition, SIGNAL(clicked()), this, SLOT(clickCityPosition()));
    connect(ui->cubePoly, SIGNAL(clicked()), this, SLOT(clickCubePoly()));
    connect(ui->tracePoints, SIGNAL(clicked()), this ,SLOT(clickTracePoint()));
    connect(ui->xiaoqianCollect, SIGNAL(clicked()), this, SLOT(clickXiaoqianCollect()));
    connect(ui->build_res, SIGNAL(clicked()), this, SLOT(clickBuildResource()));
    connect(ui->buildAndroid, SIGNAL(clicked()), this, SLOT(clickBuildAndroid()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickConvertDialogue()
{
    QString filePath = QString("/home/luxiaodong/Dropbox/dialogue.xml");
    //QString filePath = QString("/Users/ruizhan/Dropbox/work/dialogue.xml");
    QConvertDialogure convert;
    convert.parse(filePath);
}

void MainWindow::clickConvertBezierPoly()
{
    QString filePath = QString("/home/luxiaodong/Dropbox/work/bezierpoly.txt");
    //QString filePath = QString("/Users/ruizhan/Dropbox/work/bezierpoly.txt");
    QBezierPoly bezierPoly;
    bezierPoly.parse(filePath);
}

void MainWindow::clickCityRoadMap()
{
    //QString filePath = QString("/home/luxiaodong/Dropbox/work/cityRoadMap.txt");
    QString filePath = QString("/Users/ruizhan/Dropbox/work/cityRoadMap.txt");
    QCityRoadMap cityMap;
    cityMap.parse(filePath);
}

void MainWindow::clickCityPosition()
{
    //QString filePath = QString("/home/luxiaodong/Dropbox/work/cityRoadMap.txt");
    QString filePath = QString("/Users/ruizhan/Dropbox/work/cityPosition.lua");
    QCityPosition city;
    city.parse(filePath);
}

void MainWindow::clickCubePoly()
{
//    QString filePath = QString("/Users/ruizhan/Dropbox/work/polyTable.txt");
//    QString filePath = QString("/home/luxiaodong/Project/Git/Matlab/gcld/data/world/polyTable.txt");
//    QCubePoly poly;
//    poly.parse(filePath);

    QList<int> list;
    for(int i=0; i<11; ++i)
    {
        list.append(i+1);
    }

    for(int i=10000; i < 10; ++i)
    {
        list.append(i+1);
    }

    foreach(int index, list)
    {
        QString filePath = QString("/home/luxiaodong/Project/Git/Matlab/gcld/data/juben/polyTable_%1.txt").arg(index);
        QCubePoly poly;
        poly.parse2(filePath);
    }
}

void MainWindow::clickTracePoint()
{
//    QString filePath = QString("/Users/ruizhan/Dropbox/work/timeTable.txt");
//    QString filePath = QString("/home/luxiaodong/Project/Git/Matlab/gcld/data/world/timeTable.txt");
//    QPolyTime poly;
//    poly.parse(filePath);

    QList<int> list;
    for(int i=0; i<11; ++i)
    {
        list.append(i+1);
    }

    for(int i=10000; i < 10; ++i)
    {
        list.append(i+1);
    }

    foreach(int index, list)
    {
        QString filePath = QString("/home/luxiaodong/Project/Git/Matlab/gcld/data/juben/timeTable_%1.txt").arg(index);
        QPolyTime poly;
        poly.parse2(filePath);
    }
}

void MainWindow::clickXiaoqianCollect()
{
    QString filePath = QString("/Users/ruizhan/Dropbox/work/constant2.lua");
    QCollectXiaoqianDialogure collect;
    collect.parse(filePath);
}

void MainWindow::clickBuildResource()
{
    QSettings settings("reign", "QGcldTools");
    QString oldFilePath = settings.value("build_resources_dir","").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, QString("Open Directory"), oldFilePath, QFileDialog::ShowDirsOnly);
    if( filePath.isEmpty() == true)
    {
        return ;
    }

    if( QFile::exists(filePath) == true)
    {
        QProcess::execute(QString("./build_resources.sh") , QStringList()<<filePath);
        settings.setValue("build_resources_dir", filePath);
        QMessageBox::information(this,"build_Resources","Love is Over");
    }
}

void MainWindow::clickBuildAndroid()
{
    //资源assert没进来
    QSettings settings("reign", "QGcldTools");
    QString oldFilePath = settings.value("build_android_dir","").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, QString("Open Directory"), oldFilePath, QFileDialog::ShowDirsOnly);
    if( filePath.isEmpty() == true)
    {
        return ;
    }

    if( QFile::exists(filePath) == true)
    {
        QProcess::execute(QString("./build_android.sh") , QStringList()<<filePath);
        settings.setValue("build_android_dir", filePath);
        QMessageBox::information(this,"build_Resources","Love is Over");
    }
}



