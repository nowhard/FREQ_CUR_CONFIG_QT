#ifndef MODBUS_ASCII_H
#define MODBUS_ASCII_H

#include <QByteArray>
#include <QObject>
#include <abstractserial.h>
#include <QTimer>
#include <QString>
#include "input_thread.h"
#include "output_thread.h"
#include "mb_register.h"

class modbus_ascii : public QObject
{
    Q_OBJECT
public:
    modbus_ascii(QObject *parent,AbstractSerial *port);//конструктор
    ~modbus_ascii();//деструктор

    QByteArray RequestHoldingRegisters(qint8 dev_addr,qint16 first_reg_addr,qint16 num_reg);
    QByteArray SetSingleRegister(qint8 dev_addr,qint16 reg_addr,quint16 value);
    QByteArray SetMultipleRegisters(qint8 dev_addr, qint16 first_reg_addr,qint16 num_reg,QByteArray values);

    QByteArray CalibrateRequest(quint8 dev_addr,quint8 point ,float cl_val);
//-------------------------------------------------------------------------------------------------------------------------------------------------------
    QByteArray ADC_Tune_Request(quint8 dev_addr,quint8 ADC1_ADC2_SETTINGS,quint8 ADC3_ADC4_SETTINGS,quint8 ADC5_ADC6_SETTINGS,quint8 ADC7_ADC8_SETTINGS);
    QByteArray DAC_Tune_Request(quint8 dev_addr, float dac_val);//установка тока на цап
    QByteArray Get_Dev_Info_Request(quint8 dev_addr);//получить пакет информации об устройстве
    QByteArray Set_Dev_Info_Request(quint8 dev_addr,quint16 ID,QString Description);//установить информацию об устройстве

    QByteArray Get_Dev_Info_Handling(QByteArray response);
    void Set_Dev_Info_Handling(QByteArray response);

    QByteArray Set_Dev_Address(quint8 dev_addr_old,quint8 dev_addr_new);//настроить адрес устройства

    QByteArray Get_Dev_Settings(quint8 dev_addr);//получить настройки цап, ацп
    void Get_Dev_Settings_Handling(QByteArray response);//обработать поступившие данные настройки устройства

//-------------------------------------------------------------------------------------------------------------------------------------------------------
    void RequestHoldingRegisters(qint8 dev_addr,MB_Register reg);
    enum {FirstPoint=0x1,SecondPoint=0x2,FirstCompensation=0x3,SecondCompensation=0x4};

    ///public slots:
private:

    QByteArray Handling_Read_Hold_Respnse(QByteArray hld_resp);
    enum {ReadHld=0x3,WriteReg=0x6,WriteMultipleRegs=0x10,Calibrate=0xCA,GetInfo=0x2D,SetInfo=0x2C,ADC_Settings=0x21,DAC_Settings=0x22,SetDevAddress=0x2E,GetDevSettings=0x2F};//функции, реализуемые протоколом


    quint8 LRC(QByteArray data);
//--------------------------------------------------------------------------------
   quint8 Char_To_Bin(unsigned char Character);//символ в число
//--------------------------------------------------------------------------------
    QByteArray Handle_Request(QByteArray request);//обработка запроса в ASCII и присоединение LRC
//--------------------------------------------------------------------------------
    AbstractSerial *port;
    QByteArray response;
    QByteArray last_request;//последний запрос к устройству
    QByteArray registers;   //считываемые регистры

    bool response_waiting;//ведущий ожидает ответа

    Input_Thread *in_thread;//входной поток данных//
    Output_Thread *out_thread;

    MB_Register reg;
    QTimer *timer;


public slots:
     void ResponseHandling(QByteArray response);// обрабатываем ответ и выдаем результат в виде массива регистров
signals:
     void CRC_OK(bool OK);
     void FRAME_RECIEVED();
     void WRITE_REG_OK(bool OK);
     void READ_REG_OK(bool OK);
     void SET_INFO_OK(bool OK);
     void GET_INFO_OK(bool OK,quint16 ID, QString Description);
     void UNCNOWN_COMMAND(void);
     void NOT_IMPLEMENTED(void);
     void DEVICE_NOT_CONNECTED(void);

     void CALIBRATE_OK(bool OK);

     void SET_ADDR_OK(bool OK);
     void SET_ADC_SETTINGS_OK(bool OK);
     void SET_DAC_SETTINGS_OK(bool OK);

     void GET_DEV_SETTINGS_OK(bool OK, QByteArray response);

     void IsRead(QByteArray reg);
     void IsRead(MB_Register reg,QByteArray value);
     void WriteToOut_Thread(QByteArray request);
};

#endif // MODBUS_ASCII_H
