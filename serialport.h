#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>



class SerialPort : public QObject////работа с серал портом
{
    Q_OBJECT

public:
SerialPort();
    ~SerialPort();

private slots:
    void readSerial();

private:

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;

protected:
    QObject *viewer;
signals:
    SendComand(int);
     snapshotSerial();

};

#endif // SERIALPORT_H
