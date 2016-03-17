#ifndef KEYBOARDCONTROL_H
#define KEYBOARDCONTROL_H

#include <QObject>
#include <QString>
#include <QMap>
#include <windows.h>

class KeyBoardControl : public QObject////класс осуществляет работу с клавиатурой
{
    Q_OBJECT
public:
    explicit KeyBoardControl(QObject *parent = 0);

private:
     QMap<QString, WORD> key;


signals:



public slots:
    void KeyPress(QString Key);
    void KeyPress(QString Key1,QString Key2);
    void KeyPress(QString Key1,QString Key2,QString Key3);
};

/*
QMap<QString, int> key=
{
                {"Escape",	0x01000000},
                {"Tab",	0x01000001},
                //{"Backtab",	0x01000002},
                {"Backspace",	0x01000003},
                {"Return",	0x01000004},
                {"Enter",	0x01000005},
                {"Insert",	0x01000006},
               // {"Delete",	0x01000007},
                {"Pause",	0x01000008},


                {"SysReq",	0x0100000a},
                {"Clear",	0x0100000b},
                {"Home",	0x01000010},
                {"End",	0x01000011},
                {"Left",	0x01000012},
                {"Up",	0x01000013},
                {"Right",	0x01000014},
                {"Down",	0x01000015},
                {"PageUp",	0x01000016},
                {"PageDown",	0x01000017},
                {"Shift",	0x01000020},

                {"Alt",	0x01000023},
                {"CapsLock",	0x01000024},
                {"NumLock",	0x01000025},
                {"ScrollLock",	0x01000026},
                {"F1",	0x01000030},
                {"F2",	0x01000031},
                {"F3",	0x01000032},
                {"F4",	0x01000033},
                {"F5",	0x01000034},
                {"F6",	0x01000035},
                {"F7",	0x01000036},
                {"F8",	0x01000037},
                {"F9",	0x01000038},
                {"F10",	0x01000039},
                {"F11",	0x0100003a},
                {"F12",	0x0100003b},



                {"Space",	0x20},


                {"Plus",	0x2b},
               // Qt::Key_Comma	0x2c
                {"Minus",	0x2d},
              //  Qt::Key_Period	0x2e
                {"Slash",	0x2f},
                {"0",	0x30},
               {"1",	0x31},
                {"2",	0x32},
                {"3",	0x33},
                {"4",	0x34},
                {"5",	0x35},
                {"6",	0x36},
                {"7",	0x37},
                {"8",	0x38},
                {"9",	0x39},

                {"A",	0x41},
                {"B",	0x42},
                {"C",	0x43},
                {"D",	0x44},
                {"E",	0x45},
                {"F",	0x46},
                {"G",	0x47},
                {"H",	0x48},
                {"I",	0x49},
                {"J",	0x4a},
                {"K",	0x4b},
                {"L",	0x4c},
                {"M",	0x4d},
                {"N",	0x4e},
                {"O",	0x4f},
                {"P",	0x50},
                {"Q",	0x51},
                {"R",	0x52},
                {"S",	0x53},
                {"T",	0x54},
                {"U",	0x55},
                {"V",	0x56},
                {"W",	0x57},
                {"X",	0x58},
                {"Y",	0x59},
                {"Z",	0x5a},
                {"BracketLeft",	0x5b},
                {"Backslash",	0x5c},
                {"BracketRight",	0x5d}

};
*/
#endif // KEYBOARDCONTROL_H
