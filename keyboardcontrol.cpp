#include "keyboardcontrol.h"
#include <QMessageBox>
#include <windows.h>
#include <string>
#include <QMap>
KeyBoardControl::KeyBoardControl(QObject *parent) : QObject(parent)
{
      this->key.insert("Escape",	 0x1b);
      this->key.insert("Tab",	 0x9);
      //this->key.insert("Backtab",	 0x01000002);
      this->key.insert("Backspace",	0x8);
      this->key.insert("Return", 0x01000004);
      this->key.insert("Enter", 0x0d);
      this->key.insert("Insert", 0x2d);
     //this->key.insert("Delete", 0x01000007);
      this->key.insert("Pause", 0x01000008);

      this->key.insert("Ctrl", 0x11);
      this->key.insert("SysReq", 0x0100000a);
      this->key.insert("Clear", 0x0100000b);
      this->key.insert("Home", 0x24);
      this->key.insert("End", 0x23);
      this->key.insert("Left", 0x25);
      this->key.insert("Up", 0x26);
      this->key.insert("Right", 0x27);
      this->key.insert("Down", 0x28);
      this->key.insert("PageUp", 0x21);
      this->key.insert("PageDown", 0x22);
      this->key.insert("Shift", 0x10);
      this->key.insert("Alt", 0x12);
      this->key.insert("CapsLock", 0x14);
      this->key.insert("NumLock", 0x01000025);
      this->key.insert("ScrollLock", 0x91);
      this->key.insert("F1", 0x70);
      this->key.insert("F2", 0x71);
      this->key.insert("F3", 0x72);
      this->key.insert("F4", 0x73);
      this->key.insert("F5", 0x74);
      this->key.insert("F6", 0x75);
      this->key.insert("F7", 0x76);
      this->key.insert("F8", 0x77);
      this->key.insert("F9", 0x78);
      this->key.insert("F10", 0x79);
      this->key.insert("F11", 0x0100003a);
      this->key.insert("F12", 0x0100003b);

      this->key.insert("Win", 0x5b);

      this->key.insert("Space", 0x20);


      this->key.insert("Plus", 0x2b);
     // Qt::this->key_Comma	, 0x2c
      this->key.insert("Minus", 0x2d);
    //  Qt::this->key_Period	, 0x2e
      this->key.insert("Slash", 0x2f);
      this->key.insert("0", 0x30);
      this->key.insert("1", 0x31);
      this->key.insert("2", 0x32);
      this->key.insert("3", 0x33);
      this->key.insert("4", 0x34);
      this->key.insert("5", 0x35);
      this->key.insert("6", 0x36);
      this->key.insert("7", 0x37);
      this->key.insert("8", 0x38);
      this->key.insert("9", 0x39);

      this->key.insert("A", 0x41);
      this->key.insert("B", 0x42);
      this->key.insert("C", 0x43);
      this->key.insert("D", 0x44);
      this->key.insert("E", 0x45);
      this->key.insert("F", 0x46);
      this->key.insert("G", 0x47);
      this->key.insert("H", 0x48);
      this->key.insert("I", 0x49);
      this->key.insert("J", 0x4a);
      this->key.insert("K", 0x4b);
      this->key.insert("L", 0x4c);
      this->key.insert("M", 0x4d);
      this->key.insert("N", 0x4e);
      this->key.insert("O", 0x4f);
      this->key.insert("P", 0x50);
      this->key.insert("Q", 0x51);
      this->key.insert("R", 0x52);
      this->key.insert("S", 0x53);
      this->key.insert("T", 0x54);
      this->key.insert("U", 0x55);
      this->key.insert("V", 0x56);
      this->key.insert("W", 0x57);
      this->key.insert("X", 0x58);
      this->key.insert("Y", 0x59);
      this->key.insert("Z", 0x5a);
      this->key.insert("BracketLeft", 0x5b);
      this->key.insert("Backslash", 0x5c);
      this->key.insert("BracketRight", 0x5d);
}


void  KeyBoardControl::KeyPress(QString Key){

    INPUT ip; //инициализируем устройство ввода
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk=key.value(Key);///присваиваем клавишу устройству ввода

    ip.ki.dwFlags = 0;////нажимаем клавишу
    SendInput(1, &ip, sizeof(INPUT));


    //а затем отжатия клавиши
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

}

void  KeyBoardControl::KeyPress(QString Key1,QString Key2){
/*
    QMessageBox msgBox;
    msgBox.setText("Press: "+Key1+" Press: "+Key2);
    msgBox.exec();
 */
    INPUT ip1; //устройство ввода
    ip1.type = INPUT_KEYBOARD;
    ip1.ki.wScan = 0;
    ip1.ki.time = 0;
    ip1.ki.dwExtraInfo = 0;
    INPUT ip2; //устройство ввода
    ip2.type = INPUT_KEYBOARD;
    ip2.ki.wScan = 0;
    ip2.ki.time = 0;
    ip2.ki.dwExtraInfo = 0;


    ip1.ki.wVk=key.value(Key1);
    ip2.ki.wVk=key.value(Key2);

    ///нажатие клавиши
    ip1.ki.dwFlags = 0;
    SendInput(1, &ip1, sizeof(INPUT));
    ip2.ki.dwFlags = 0;
    SendInput(1, &ip2, sizeof(INPUT));


    //а затем отжатия клавиши
    ip1.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip1, sizeof(INPUT));
    ip2.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip2, sizeof(INPUT));

}

void  KeyBoardControl::KeyPress(QString Key1,QString Key2,QString Key3 ){
    /*
    QMessageBox msgBox;
    msgBox.setText("Press: "+Key1+" Press: "+Key2+" Press: "+Key3);
    msgBox.exec();
*/
    INPUT ip1; //устройство ввода
    ip1.type = INPUT_KEYBOARD;
    ip1.ki.wScan = 0;
    ip1.ki.time = 0;
    ip1.ki.dwExtraInfo = 0;
    INPUT ip2; //устройство ввода
    ip2.type = INPUT_KEYBOARD;
    ip2.ki.wScan = 0;
    ip2.ki.time = 0;
    ip2.ki.dwExtraInfo = 0;
    INPUT ip3; //устройство ввода
    ip3.type = INPUT_KEYBOARD;
    ip3.ki.wScan = 0;
    ip3.ki.time = 0;
    ip3.ki.dwExtraInfo = 0;

    ip1.ki.wVk=key.value(Key1);
    ip2.ki.wVk=key.value(Key2);
    ip3.ki.wVk=key.value(Key3);
    ///нажатие клавиши
    ip1.ki.dwFlags = 0;
    SendInput(1, &ip1, sizeof(INPUT));
    ip2.ki.dwFlags = 0;
    SendInput(1, &ip2, sizeof(INPUT));
    ip3.ki.dwFlags = 0;
    SendInput(1, &ip3, sizeof(INPUT));

    //а затем отжатия клавиши
    ip1.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip1, sizeof(INPUT));
    ip2.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip2, sizeof(INPUT));
    ip3.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip3, sizeof(INPUT));
}

