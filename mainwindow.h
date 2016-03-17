#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtScript>
#include "keyboardcontrol.h"
#include "messagescr.h"
#include "signals.h"
#include "mousecontrol.h"
#include "controlprogram.h"
#include "serialport.h"
#include "processsnapshot.h"
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_simulatePress_clicked();
    void updateCaptionTest();
    void snapshotSignal();


    void changeEvent(QEvent*);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void trayActionExecute();
    void setTrayIconActions();
    void showTrayIcon();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

     QMenu *trayIconMenu;
     QAction *minimizeAction;
     QAction *restoreAction;
     QAction *quitAction;
     QSystemTrayIcon *trayIcon;


    QScriptEngine scriptEngine;


    KeyBoardControl KeyBoardControler;
    MessageScr Message;

    Signals Event;
    MouseControl Mouse;
    ProcessSnapshot snapshot;
    ControlProgram Program;

    QString PrevProgExe="123457890";

    QString PrevScript="";
    QString CurrentScript="";
    //void startInitEngine(QScriptEngine *a,Control *s);
    void ErrorCritical(QString ErrorText);
    void InitializeNewScriptEngine(QString Script);


    QTimer *timerTest = new QTimer(this);

    bool first=true;

    SerialPort serial1;

};

#endif // MAINWINDOW_H
