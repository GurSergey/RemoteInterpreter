#ifndef SIGNALS_H
#define SIGNALS_H

#include <QObject>

class Signals : public QObject/////сигналы
{
    Q_OBJECT
public:
    explicit Signals(QObject *parent = 0);

signals:
 void pressButton0();
 void pressButton1();
 void pressButton2();
 void pressButton3();
 void pressButton4();
 void pressButton5();
 void pressButton6();
 void pressButton7();
 void pressButton8();
 void pressButton9();
 void pressButton10();
 void pressButton11();
 void pressButton12();
 void pressButton13();
 void pressButton14();
 void pressButton15();
 void pressButton16();
 void pressButton17();
 void pressButton18();
 void pressButton19();
 void pressButton20();
 void pressButton21();
 void pressButton22();
 void pressButton23();
 void pressButton24();
 void pressButton25();
 void pressButton26();
 void pressButton27();
 void pressButton28();
 void pressButton29();
 void pressButton30();
 void pressButton31();
 void pressButton32();
 void pressButton33();
 void pressButton34();
 void pressButton35();
 void pressButton36();
 void pressButton37();
 void pressButton38();
 void pressButton39();
 void pressButton40();
 void pressButton41();
 void pressButton42();
 void pressButton43();
 void pressButton44();
 void pressButton45();
 void pressButton46();
 void pressButton47();


 public slots:
    void recieverUsb(int Command);

};

#endif // SIGNALS_H
