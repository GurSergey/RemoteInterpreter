#include "mousecontrol.h"
#include <QMessageBox>
#include <QCursor>
#include <QDesktopWidget>
#include <QApplication>
#include <windows.h>

MouseControl::MouseControl(QObject *parent) : QObject(parent)
{
this->heightScreen = QApplication::desktop()->screenGeometry().height();
this->widthScreen  = QApplication::desktop()->screenGeometry().width();
}

int MouseControl::GetX(){
    POINT curPos;
    GetCursorPos(&curPos);
    return curPos.x;
}

int MouseControl::GetY(){
    POINT curPos;
    GetCursorPos(&curPos);
    return curPos.y;
}


void MouseControl::PositionSet(int x, int y)
{
    //QCursor::pos().setX(x);
    POINT curPos;
    SetCursorPos(x, y);
    if(x<0) SetCursorPos(0, y);
    if(x>widthScreen)   SetCursorPos(widthScreen, y);

    GetCursorPos(&curPos);
    x=curPos.x;

    //QCursor::pos().setY(y);
    if(y<0) SetCursorPos(x, 0);
    if(y>heightScreen)   SetCursorPos(x, heightScreen);
}

void MouseControl::SetX(int x)
{
    POINT curPos;
    GetCursorPos(&curPos);
    int y=curPos.y;
    SetCursorPos(x, y);
    if(x<0) SetCursorPos(0, y);
    if(x>widthScreen)   SetCursorPos(widthScreen, y);

}

void MouseControl::SetY(int y)
{
    POINT curPos;
    GetCursorPos(&curPos);
    int x=curPos.x;
    SetCursorPos(x, y);
    //QCursor::pos().setY(y);
    if(y<0) SetCursorPos(x, 0);
    if(y>heightScreen)   SetCursorPos(x, heightScreen);
}

void MouseControl::LeftClick(){
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
}

void MouseControl::RigthClick(){
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали правую кнопку мыши
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили правую кнопку мыши ( НЕ ЗАБЫВАТЬ )

}




