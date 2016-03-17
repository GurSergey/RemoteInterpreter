#include "serialport.h"


#include "qt_windows.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QApplication>
//#include "gui.h"

//#include <QMessageBox>

#include <QProcess>
#include <QDir>



SerialPort::SerialPort()
{

       arduino = new QSerialPort(this);
       serialBuffer = "";
       parsed_data = "";

       /*
        *   Identify the port the arduino uno is on.
        */
       bool arduino_is_available = false;
       QString arduino_uno_port_name;
       //
       //  For each available serial port
       foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
           //  check if the serialport has both a product identifier and a vendor identifier
           if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
               //  check if the product ID and the vendor ID match those of the arduino uno
               if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                       && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                   arduino_is_available = true; //    arduino uno is available on this port
                   arduino_uno_port_name = serialPortInfo.portName();
               }
           }
       }



       if(arduino_is_available){
           qDebug() << "Found the arduino port...\n";
           arduino->setPortName(arduino_uno_port_name);
           arduino->open(QSerialPort::ReadOnly);
           arduino->setBaudRate(QSerialPort::Baud9600);
           arduino->setDataBits(QSerialPort::Data8);
           arduino->setFlowControl(QSerialPort::NoFlowControl);
           arduino->setParity(QSerialPort::NoParity);
           arduino->setStopBits(QSerialPort::OneStop);
           QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
       }else{
           qDebug() << "Couldn't find the correct port for the arduino.\n";
           //QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
       }


}



//char Mode=0;







//char Mode=0;    ///////режим работы по сути ид открытого в оболочке приложения 0-стандартная главная страница оболочки



SerialPort::~SerialPort()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    //delete ui;
}




void SerialPort::readSerial()
{

serialData = arduino->readAll();

int i=serialData[0];
qDebug()<<"Serial Port: "<<i;
qDebug()<<"Serial Port (char): "<<serialData[0];

emit snapshotSerial();
emit SendComand(i);

}

