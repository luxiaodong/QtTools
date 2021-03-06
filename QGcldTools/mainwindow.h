#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QProcess>
#include <QFileDevice>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void clickCityRoadMap();
    void clickCityPosition();
    void clickCubePoly();
    void clickTracePoint();
    void clickUtf8Convert();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
