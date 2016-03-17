#ifndef MOUSECONTROL_H
#define MOUSECONTROL_H

#include <QObject>

class MouseControl : public QObject/////класс осуществляет работу с мышью
{
    Q_OBJECT

    Q_PROPERTY(int X READ GetX WRITE SetX)
    Q_PROPERTY(int Y READ GetY WRITE SetY)
private:
 int heightScreen;
 int widthScreen;

public:
    explicit MouseControl(QObject *parent = 0);
    int GetX();
    int GetY();

signals:

public slots:

    void PositionSet(int x, int y);
    void SetX(int x);
    void SetY(int y);
    void LeftClick();
    void RigthClick();
};

#endif // MOUSECONTROL_H
