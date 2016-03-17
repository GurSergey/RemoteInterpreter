#ifndef PROCESSSNAPSHOT_H
#define PROCESSSNAPSHOT_H

#include <QObject>

class ProcessSnapshot : public QObject///класс осуществляет работу с идент приложения
{
    Q_OBJECT
public:
    explicit ProcessSnapshot(QObject *parent = 0);

signals:


public slots:
    QString nameOfCurrentProgram();
};

#endif // PROCESSSNAPSHOT_H
