#ifndef MODBUS_RTU_H
#define MODBUS_RTU_H

#include <QByteArray>
#include <QObject>
#include <abstractserial.h>
#include <QTimer>
#include "input_thread.h"
#include "output_thread.h"
#include "mb_register.h"
class Modbus_RTU : public QObject
{
    Q_OBJECT
public:
    Modbus_RTU(QObject *parent,AbstractSerial *port);
    ~Modbus_RTU();
    QByteArray RequestHoldingRegisters(qint8 dev_addr,qint16 first_reg_addr,qint16 num_reg);
    QByteArray SetSingleRegister(qint8 dev_addr,qint16 reg_addr,quint16 value);
    QByteArray SetMultipleRegisters(qint8 dev_addr, qint16 first_reg_addr,qint16 num_reg,QByteArray values);

    QByteArray CalibrateRequest(quint8 dev_addr,quint8 point ,float density);

    void RequestHoldingRegisters(qint8 dev_addr,MB_Register reg);
    enum {FirstPoint=0x1,SecondPoint=0x2,FirstCompensation=0x3,SecondCompensation=0x4};

    ///public slots:
private:

    QByteArray Handling_Read_Hold_Respnse(QByteArray hld_resp);
    enum {ReadHld=0x3,WriteReg=0x6,WriteMultipleRegs=0x10,Calibrate=0xCA};//функции, реализуемые протоколом

    quint16 CRC16(QByteArray data,quint8 len);
    AbstractSerial *port;
    QByteArray response;
    QByteArray last_request;
    QByteArray registers;


    Input_Thread *in_thread;//входной поток данных//
    Output_Thread *out_thread;

    MB_Register reg;
    QTimer *timer;

public slots:
     void ResponseHandling(QByteArray response);// обрабатываем ответ и выдаем результат в виде массива регистров
signals:
     void CRC_OK(bool OK);
     void WRITE_REG_OK(bool OK);
     void READ_REG_OK(bool OK);
     void UNCNOWN_COMMAND(void);
     void NOT_IMPLEMENTED(void);
     void DEVICE_NOT_CONNECTED(void);

     void CALIBRATE_OK(quint8 point/*, float pressure*/);

     void IsRead(QByteArray reg);
     void IsRead(MB_Register reg,QByteArray value);
     void WriteToOut_Thread(QByteArray request);

};

#endif // MODBUS_RTU_H
