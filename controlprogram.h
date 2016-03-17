#ifndef CONTROLPROGRAM_H
#define CONTROLPROGRAM_H

#include <QObject>
#include <QFile>
#include <QVector>

class ControlProgram : public QObject  ////класс содержит схемы управления
{
    Q_OBJECT
public:
    explicit ControlProgram(QObject *parent = 0);

    QVector <QString> ScriptControlVector;
    QVector <QString> NameExeVector;


    QString defaultScript;



signals:
public slots:
    void NameProgram(QString Name);

};
/*
class Control : public QObject/////скрипт нужно для экрана
{
    Q_OBJECT
public:
    explicit Screen(QObject *parent = 0);

signals:

public slots:
};
*/
#endif // CONTROL_H
