#include "signals.h"

Signals::Signals(QObject *parent) : QObject(parent)
{

}

 void Signals::recieverUsb(int Command){
     switch (Command) {
     case 0:
         emit this->pressButton0();
         break;
     case 1:
         emit this->pressButton1();
         break;
     case 2:
         emit this->pressButton2();
         break;
     case 3:
         emit this->pressButton3();
         break;
     case 4:
         emit this->pressButton4();
         break;
     case 5:
         emit this->pressButton5();
         break;
     case 6:
         emit this->pressButton6();
         break;
     case 7:
         emit this->pressButton7();
         break;
     case 8:
         emit this->pressButton8();
         break;
     case 9:
         emit this->pressButton9();
         break;
     case 10:
         emit this->pressButton10();
         break;
     case 11:
         emit this->pressButton11();
         break;
     case 12:
         emit this->pressButton12();
         break;
     case 13:
         emit this->pressButton13();
         break;
     case 14:
         emit this->pressButton14();
         break;
     case 15:
         emit this->pressButton15();
         break;
     case 16:
         emit this->pressButton16();
         break;
     case 17:
         emit this->pressButton17();
         break;
     case 18:
         emit this->pressButton18();
         break;
     case 19:
         emit this->pressButton19();
         break;
     case 20:
         emit this->pressButton20();
         break;
     case 21:
         emit this->pressButton21();
         break;
     case 22:
         emit this->pressButton22();
         break;
     case 23:
         emit this->pressButton23();
         break;
     case 24:
         emit this->pressButton24();
         break;
     case 25:
         emit this->pressButton25();
         break;
     case 26:
         emit this->pressButton26();
         break;
     case 27:
         emit this->pressButton27();
         break;
     case 28:
         emit this->pressButton28();
         break;
     case 29:
         emit this->pressButton29();
         break;
     case 30:
         emit this->pressButton30();
         break;
     case 31:
         emit this->pressButton31();
         break;
     case 32:
         emit this->pressButton32();
         break;
     case 33:
         emit this->pressButton33();
         break;
     case 34:
         emit this->pressButton34();
         break;
     case 35:
         emit this->pressButton35();
         break;

     }
 }
