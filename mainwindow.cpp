#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keyboardcontrol.h"
#include "messagescr.h"
#include <QtScript>
#include "controlprogram.h"
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include "serialport.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this -> setTrayIconActions();
    this -> showTrayIcon();

    Message.setTextEdit(ui->scriptEditor);

     timerTest->start(10);

    QDir dir("../script");

    QObject::connect(&serial1,SIGNAL(snapshotSerial()), this, SLOT(snapshotSignal()));
    QObject::connect(&serial1,SIGNAL(SendComand(int)), &Event, SLOT(recieverUsb(int)));


    QStringList dirs = dir.entryList( QStringList() << "*.keys");



    QTimer *timerTest = new QTimer(this);
       //**connect(timerTest, SIGNAL(timeout()), this, SLOT(updateCaptionTest()));
       //**timerTest->start(1000);



    /*прогружаем деволтный скрипт*/


    QDir dirDefault("../script/defaultScript/default.keys");
    QFile fileDefault(dirDefault.path());

    if(!fileDefault.open(QIODevice::ReadOnly))
         ErrorCritical("Нет скрипта по умолчанию. Дабавьте его  и повторите попытку.");
    Program.defaultScript=fileDefault.readAll();
   // start= startWork.evaluate(Program.defaultScript);



    for(int i=0; i<dirs.length();i++)
    {           

           QScriptEngine startWork;

           QScriptValue scriptControl = startWork.newQObject(&Program);
           startWork.globalObject().setProperty("Control",scriptControl);

           QScriptValue scriptMessage = startWork.newQObject(&Message);
           startWork.globalObject().setProperty("Message",scriptMessage);//Keyboard.KeyPress('A','B','V')

           QScriptValue scriptEvent = startWork.newQObject(&Event);
           startWork.globalObject().setProperty("Event",scriptEvent);




         //  QScriptValue start;
           QDir dir1("../script/"+dirs[i]);

           QFile file(dir1.path());

           if(!file.open(QIODevice::ReadOnly))
                qDebug()<<"Error read file";


            QString buf=file.readAll();
            Program.ScriptControlVector.append(buf);
            QScriptValue start= startWork.evaluate(buf);



         //проверки на валидность
         if(start.isError()) ui->scriptEditor->append("Ошибка выполнения скрипта "+dirs[i]);



             if(Program.NameExeVector[i]=="") ui->scriptEditor->append("НЕ указано целевое приложение в "+dirs[i]);


    }

    for(int i=0;i<Program.NameExeVector.length();i++) {
        qDebug()<<"Test:Name";
        qDebug()<<Program.NameExeVector[i];
      //  qDebug()<<ProgramVector[i]->ScriptControl.readAll();

        qDebug()<<"Test:Script";
        qDebug()<<Program.ScriptControlVector[i];
    }
qDebug()<<"Default";
qDebug()<<Program.defaultScript;

     qDebug()<< " Спиок скриптов "<<dirs;


}

void MainWindow::InitializeNewScriptEngine(QString Script){

scriptEngine.pushContext();


        QScriptValue scriptControl = scriptEngine.newQObject(&Program);
        scriptEngine.globalObject().setProperty("Control",scriptControl);


QScriptValue scriptKeyControl = scriptEngine.newQObject(&KeyBoardControler);
scriptEngine.globalObject().setProperty("Keyboard",scriptKeyControl);

QScriptValue scriptMessage = scriptEngine.newQObject(&Message);
scriptEngine.globalObject().setProperty("Message",scriptMessage);//Keyboard.KeyPress('A','B','V')

QScriptValue scriptEvent = scriptEngine.newQObject(&Event);
scriptEngine.globalObject().setProperty("Event",scriptEvent);

QScriptValue scriptMouse = scriptEngine.newQObject(&Mouse);
scriptEngine.globalObject().setProperty("Mouse",scriptMouse);


QScriptValue scriptTestText = scriptEngine.newQObject(ui->scriptEditor);
scriptEngine.globalObject().setProperty("TestText",scriptTestText);

   // QTimer *timerTest = new QTimer(this);

    //timerTest->start(10);
    QScriptValue scriptTimer = scriptEngine.newQObject(timerTest);

    scriptEngine.globalObject().setProperty("Timer10ms",scriptTimer);

    QScriptValue result = scriptEngine.evaluate(Script);//Message.showMessage('Hello from Script')

    if(result.isError()){

        qDebug()<<"Error";

    }
      // buf=&scriptEngine;
}

void MainWindow::snapshotSignal(){
    QString NameProgExe=snapshot.nameOfCurrentProgram();

    if(NameProgExe!=PrevProgExe)
    {
        //if(first==false){
        scriptEngine.evaluate("Event.pressButton0.disconnect(pressButton0);");
        scriptEngine.evaluate("Event.pressButton1.disconnect(pressButton1);");
        scriptEngine.evaluate("Event.pressButton2.disconnect(pressButton2);");
        scriptEngine.evaluate("Event.pressButton3.disconnect(pressButton3);");
        scriptEngine.evaluate("Event.pressButton4.disconnect(pressButton4);");
        scriptEngine.evaluate("Event.pressButton5.disconnect(pressButton5);");
        scriptEngine.evaluate("Event.pressButton6.disconnect(pressButton6);");
        scriptEngine.evaluate("Event.pressButton7.disconnect(pressButton7);");
        scriptEngine.evaluate("Event.pressButton8.disconnect(pressButton8);");
        scriptEngine.evaluate("Event.pressButton9.disconnect(pressButton9);");
        scriptEngine.evaluate("Event.pressButton10.disconnect(pressButton10);");
        scriptEngine.evaluate("Event.pressButton11.disconnect(pressButton11);");
        scriptEngine.evaluate("Event.pressButton12.disconnect(pressButton12);");
        scriptEngine.evaluate("Event.pressButton13.disconnect(pressButton13);");
        scriptEngine.evaluate("Event.pressButton14.disconnect(pressButton14);");
        scriptEngine.evaluate("Event.pressButton15.disconnect(pressButton15);");
        scriptEngine.evaluate("Event.pressButton16.disconnect(pressButton16);");
        scriptEngine.evaluate("Event.pressButton17.disconnect(pressButton17);");
        scriptEngine.evaluate("Event.pressButton18.disconnect(pressButton18);");
        scriptEngine.evaluate("Event.pressButton19.disconnect(pressButton19);");
        scriptEngine.evaluate("Event.pressButton20.disconnect(pressButton20);");
        scriptEngine.evaluate("Event.pressButton21.disconnect(pressButton21);");
        scriptEngine.evaluate("Event.pressButton22.disconnect(pressButton22);");
        scriptEngine.evaluate("Event.pressButton23.disconnect(pressButton23);");
        scriptEngine.evaluate("Event.pressButton24.disconnect(pressButton24);");
        scriptEngine.evaluate("Event.pressButton25.disconnect(pressButton25);");
        scriptEngine.evaluate("Event.pressButton26.disconnect(pressButton26);");
        scriptEngine.evaluate("Event.pressButton27.disconnect(pressButton27);");
        scriptEngine.evaluate("Event.pressButton28.disconnect(pressButton28);");
        scriptEngine.evaluate("Event.pressButton29.disconnect(pressButton29);");
        scriptEngine.evaluate("Event.pressButton30.disconnect(pressButton30);");
        scriptEngine.evaluate("Event.pressButton31.disconnect(pressButton31);");
        scriptEngine.evaluate("Event.pressButton32.disconnect(pressButton32);");
        scriptEngine.evaluate("Event.pressButton33.disconnect(pressButton33);");
        scriptEngine.evaluate("Event.pressButton34.disconnect(pressButton34);");
        scriptEngine.evaluate("Event.pressButton35.disconnect(pressButton35);");
        scriptEngine.evaluate("Timer10ms.timeout.disconnect(timer10ms);");
            scriptEngine.popContext();


       // }
        //scriptEngine.abortEvaluation("function timer()");
        int m=Program.NameExeVector.indexOf(NameProgExe);
        if(m==-1){
            ui->scriptEditor->append("default");
            qDebug()<<"Script :"<<Program.defaultScript;
            InitializeNewScriptEngine(Program.defaultScript);
           // CurrentScript=Program.defaultScript;

        }
        else{
            ui->scriptEditor->append(snapshot.nameOfCurrentProgram());
            qDebug()<<Program.ScriptControlVector[m];
            InitializeNewScriptEngine(Program.ScriptControlVector[m]);
            //CurrentScript=Program.ScriptControlVector[m];
        }
        first==false;
       // PrevScript=CurrentScript;

    }
    PrevProgExe=snapshot.nameOfCurrentProgram();

}

void MainWindow::updateCaptionTest(){

    QString NameProgExe=snapshot.nameOfCurrentProgram();

    if(NameProgExe!=PrevProgExe)
    {
        //if(first==false){
        scriptEngine.evaluate("Event.pressButton0.disconnect(pressButton0);");
        scriptEngine.evaluate("Event.pressButton1.disconnect(pressButton1);");
        scriptEngine.evaluate("Timer10ms.timeout.disconnect(timer10ms);");
            scriptEngine.popContext();


       // }
        //scriptEngine.abortEvaluation("function timer()");
        int m=Program.NameExeVector.indexOf(NameProgExe);
        if(m==-1){
            qDebug()<<"Script :"<<Program.defaultScript;
            InitializeNewScriptEngine(Program.defaultScript);
           // CurrentScript=Program.defaultScript;

        }
        else{
            qDebug()<<Program.ScriptControlVector[m];
            InitializeNewScriptEngine(Program.ScriptControlVector[m]);
            //CurrentScript=Program.ScriptControlVector[m];
        }
        first==false;
       // PrevScript=CurrentScript;

    }
    PrevProgExe=snapshot.nameOfCurrentProgram();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_simulatePress_clicked()
{
   // while(1){}

    /*
    snapshotSignal();
    //QScriptEngine q=*buf;
emit Event.pressButton0();
*/

}



void MainWindow::ErrorCritical(QString ErrorText)
{
    QMessageBox msgBox;
    msgBox.setText("Error: "+ErrorText);
    msgBox.exec();

    //quit();

}

void MainWindow::showTrayIcon()
{
    // Создаём экземпляр класса и задаём его свойства...
    trayIcon = new QSystemTrayIcon(this);
    QIcon trayImage(":/images/abc.png");
    trayIcon -> setIcon(trayImage);
    trayIcon -> setContextMenu(trayIconMenu);

    // Подключаем обработчик клика по иконке...
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    // Выводим значок...
    trayIcon -> show();
}


void MainWindow::trayActionExecute()
{
    //QMessageBox::information(this, "TrayIcon", "Тестовое сообщение. Замените вызов этого сообщения своим кодом.");
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            this -> trayActionExecute();
            break;
        default:
            break;
    }
}


void MainWindow::setTrayIconActions()
{
    // Setting actions...
    minimizeAction = new QAction("Свернуть", this);
    restoreAction = new QAction("Восстановить", this);
    quitAction = new QAction("Выход", this);

    // Connecting actions to slots...
    connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect (restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    // Setting system tray's icon menu...
    trayIconMenu = new QMenu(this);
    trayIconMenu -> addAction (minimizeAction);
    trayIconMenu -> addAction (restoreAction);
    trayIconMenu -> addAction (quitAction);
}

void MainWindow::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    if (event -> type() == QEvent::WindowStateChange)
    {
        if (isMinimized())
        {
            this -> hide();
        }
    }
}

/*
 *
 *
   QScriptValue scriptKeyControl = scriptEngine.newQObject(&KeyBoardControler);
   scriptEngine.globalObject().setProperty("Keyboard",scriptKeyControl);

   QScriptValue scriptMessage = scriptEngine.newQObject(&Message);
   scriptEngine.globalObject().setProperty("Message",scriptMessage);//Keyboard.KeyPress('A','B','V')

   QScriptValue scriptEvent = scriptEngine.newQObject(&Event);
   scriptEngine.globalObject().setProperty("Event",scriptEvent);

   QScriptValue scriptMouse = scriptEngine.newQObject(&Mouse);
   scriptEngine.globalObject().setProperty("Mouse",scriptMouse);


   QScriptValue scriptTestText = scriptEngine.newQObject(ui->scriptEditor);
   scriptEngine.globalObject().setProperty("TestText",scriptTestText);

       QTimer *timerTest = new QTimer(this);

       timerTest->start(10);
       QScriptValue scriptTimer = scriptEngine.newQObject(timerTest);

       scriptEngine.globalObject().setProperty("Timer10ms",scriptTimer);

       QScriptValue result = scriptEngine.evaluate(Script);//Message.showMessage('Hello from Script')

       if(result.isError()){

           qDebug()<<"Error";

       }
*/

void MainWindow::on_pushButton_clicked()
{

    qDebug()<<this->Mouse.GetY();
}
