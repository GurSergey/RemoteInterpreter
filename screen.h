#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>

class Screen : public QObject/////скрипт нужно для экрана
{
    Q_OBJECT
public:
    explicit Screen(QObject *parent = 0);

signals:

public slots:
};

#endif // SCREEN_H
