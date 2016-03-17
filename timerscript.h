#ifndef TIMERSCRIPT_H
#define TIMERSCRIPT_H

#include <QObject>

class TimerScript : public QObject
{
    Q_OBJECT
public:
    explicit TimerScript(QObject *parent = 0);

signals:

public slots:
};

#endif // TIMERSCRIPT_H
