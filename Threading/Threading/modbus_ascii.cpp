#include "modbus_ascii.h"

modbus_ascii::modbus_ascii(QObject *parent,AbstractSerial *port):
        QObject(parent)
{
    this->port=port;

    in_thread=new Input_Thread(this,port);
    out_thread=new Output_Thread(this,port);
    connect(in_thread,SIGNAL(isRead(QByteArray)),this,SLOT(ResponseHandling(QByteArray)));

    connect(in_thread,SIGNAL(isRead(QByteArray)),this,SIGNAL(FRAME_RECIEVED()));

    in_thread->start();

    connect(this,SIGNAL(WriteToOut_Thread(QByteArray)),out_thread,SLOT(Send(QByteArray)));
    out_thread->start();

    response_waiting=0;//устройство пока не посылало запроса

    timer=new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SIGNAL(DEVICE_NOT_CONNECTED()));
}

modbus_ascii::~modbus_ascii()
{
    in_thread->quit();

    //in_thread->exit();
    delete in_thread;
    out_thread->quit();
    //out_thread->exit();
    delete out_thread;
}

QByteArray modbus_ascii::RequestHoldingRegisters(qint8 dev_addr,qint16 first_reg_addr,qint16 num_reg)
{
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->ReadHld);

    mb_request.append(((char*)(&first_reg_addr))[1]);
    mb_request.append(((char*)(&first_reg_addr))[0]);

    mb_request.append(((char*)(&num_reg))[1]);
    mb_request.append(((char*)(&num_reg))[0]);

    mb_request=Handle_Request(mb_request);//обработка

    emit this->WriteToOut_Thread(mb_request);

    qDebug( "SEND DATA:  %s",mb_request.data())  ;


    return mb_request;
}

void modbus_ascii::RequestHoldingRegisters(qint8 dev_addr,MB_Register reg)
{
    this->reg=reg;
    RequestHoldingRegisters(dev_addr,reg.address,reg.length);
}

QByteArray modbus_ascii::SetSingleRegister(qint8 dev_addr,qint16 reg_addr,quint16 value)
{
    QByteArray mb_request;

    mb_request.append(dev_addr);
    mb_request.append(this->WriteReg);
    mb_request.append(((char*)(&reg_addr))[1]);
    mb_request.append(((char*)(&reg_addr))[0]);

    mb_request.append(((char*)(&value))[1]);
    mb_request.append(((char*)(&value))[0]);

    mb_request=Handle_Request(mb_request);//обработать кадр

    emit this->WriteToOut_Thread(mb_request);
    //last_request=mb_request;??? проверка ошибки команды

     qDebug( "SEND DATA:  %s",mb_request.data())  ;
    return mb_request;
}

QByteArray modbus_ascii::SetMultipleRegisters(qint8 dev_addr, qint16 first_reg_addr,qint16 num_reg,QByteArray values)
{
//не реализовано
}

QByteArray modbus_ascii::CalibrateRequest(quint8 dev_addr,quint8 point ,float cl_val)
{
//реализовать
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->Calibrate);

    mb_request.append(point);

    mb_request.append(((unsigned char*)&cl_val)[3]);//положим в кадр значение тока float
    mb_request.append(((unsigned char*)&cl_val)[2]);
    mb_request.append(((unsigned char*)&cl_val)[1]);
    mb_request.append(((unsigned char*)&cl_val)[0]);

    mb_request=Handle_Request(mb_request);
    emit this->WriteToOut_Thread(mb_request);
    qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}

quint8  modbus_ascii::LRC(QByteArray data)
{
    quint8 lrc=0,i=0;  /* LRC char initialized */
    bool ok=false;

    for(i=0;i<data.length();i+=2)
    {
        lrc+=data.mid(i,2).toUShort(&ok,16);
    }

    lrc=((lrc^0xFF)+1)&0xFF;
    return lrc;
}

QByteArray modbus_ascii::Handling_Read_Hold_Respnse(QByteArray hld_resp)
{
    quint16 byte_counter=0;
    QByteArray regs_content;

    if(hld_resp[0]==last_request[0] && hld_resp[1]==last_request[1])
    {
        emit READ_REG_OK(true);
        byte_counter=hld_resp[2];//счетчик полученных байт

        for(quint8 i=3;i<3+byte_counter;i++)
        {
            regs_content.append(hld_resp[i]);
        }

        return regs_content;
    }
    else
    {
        emit READ_REG_OK(false);
        return NULL;
    }
}

QByteArray modbus_ascii::Handle_Request(QByteArray request)//обработка запроса в ASCII и присоединение LRC
{
    QByteArray handled_request;
    quint8 lrc=0;

    last_request=request;

    handled_request.append(':');//начало кадра
    handled_request.append(request.toHex());

    //сформировать LRC и окончание кадра
    lrc=LRC(handled_request.right(handled_request.length()-1));
    if(lrc>=0 && lrc<=0xF)
    {
        handled_request.append(QByteArray::number(0x0, 16)/*.toUpper()*/);
    }

    handled_request.append(QByteArray::number(lrc, 16)/*.toUpper()*/);

    handled_request.append(0xD);
    handled_request.append(0xA);

    response_waiting=true;//запрос пошел
    timer->start(1000);

    return handled_request.toUpper();
}

void modbus_ascii::ResponseHandling(QByteArray response)//обработка ответа ведомого устройства
{
    QByteArray handled_response;
    quint8 lrc_true=0,lrc=0,i,dev_adress=0;
    bool ok;

    QByteArray frame=response.mid(1,response.length()-5);//выделяем кадр без заголовка, LRC и окончания

    lrc_true=LRC(frame);
    lrc=response.mid(response.length()-4,2).toUShort(&ok,16);

    qDebug("Frame Recieved %s",response.data());

    if(lrc_true!=lrc || !ok || !response_waiting)
    {
        emit CRC_OK(false);
        return ;
    }
    else
    {
        emit CRC_OK(true);

        response_waiting=false;//запрос окончен

        //проверим адрес
        dev_adress=response.mid(1,2).toUShort(&ok,16);

         if(dev_adress==last_request[0] && ok )
         {
            for(i=0;i<frame.length();i+=2)
            {
                handled_response.append(frame.mid(i,2).toUShort(&ok,16));
                if(!ok)
                {
                    return ;
                }
            }


            //проверить адрес устройства???
            switch(handled_response[1])
            {
                case ReadHld:
                {
                    registers=Handling_Read_Hold_Respnse(handled_response);
                    emit IsRead(reg,registers);
                     qDebug() << "Read OK "<<lrc;
                }
                break;

                case WriteReg:
                {
                    if(response==last_request)
                    {
                        emit WRITE_REG_OK(true);
                         qDebug() << "Write OK "<<lrc;
                    }
                    else
                    {
                        emit WRITE_REG_OK(false);
                        qDebug() << "Write ERR "<<lrc;
                    }
                }
                break;

                case WriteMultipleRegs:
                {
                    emit NOT_IMPLEMENTED();
                }
                break;

                case GetInfo:
                {
                    Get_Dev_Info_Handling(handled_response);
                }
                break;

                case SetInfo:
                {
                    Set_Dev_Info_Handling(handled_response);
                }
                break;

                case GetDevSettings:
                {
                    Get_Dev_Settings_Handling(handled_response);
                }
                break;

                case Calibrate:
                {
                    //emit NOT_IMPLEMENTED();
                    emit CALIBRATE_OK(true);
                }
                break;

                case ADC_Settings:
                {
                    emit this->SET_ADC_SETTINGS_OK(true);
                }
                break;

                case DAC_Settings:
                {
                    emit this->SET_DAC_SETTINGS_OK(true);
                }
                break;

                case SetDevAddress:
                {
                    emit this->SET_ADDR_OK(true);
                }
                break;

                default:
                {
                    emit UNCNOWN_COMMAND();
                }
                break;
            }
        }
    }
}
//-------------------------запросы------------------------------------------------------------
QByteArray modbus_ascii::ADC_Tune_Request(quint8 dev_addr,quint8 ADC1_ADC2_SETTINGS, quint8 ADC3_ADC4_SETTINGS, quint8 ADC5_ADC6_SETTINGS, quint8 ADC7_ADC8_SETTINGS)
{
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->ADC_Settings);
    mb_request.append(ADC1_ADC2_SETTINGS);
    mb_request.append(ADC3_ADC4_SETTINGS);
    mb_request.append(ADC5_ADC6_SETTINGS);
    mb_request.append(ADC7_ADC8_SETTINGS);

    mb_request=Handle_Request(mb_request);//обработать кадр

    emit this->WriteToOut_Thread(mb_request);
     qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}
//--------------------------------------------------------------------------------------------
QByteArray modbus_ascii::Get_Dev_Info_Request(quint8 dev_addr)//получить пакет информации об устройстве
{
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->GetInfo);

    mb_request=Handle_Request(mb_request);//обработать кадр

    emit this->WriteToOut_Thread(mb_request);
     qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}
//--------------------------------------------------------------------------------------------
QByteArray modbus_ascii::Set_Dev_Info_Request(quint8 dev_addr,quint16 ID,QString Description)//установить информацию об устройстве
{
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->SetInfo);

    mb_request.append(((char*)(&ID))[1]);//ID в пакет
    mb_request.append(((char*)(&ID))[0]);

    Description.resize(20);
    mb_request.append(Description);
    mb_request=Handle_Request(mb_request);

    emit this->WriteToOut_Thread(mb_request);
     qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}
//-----------------------------------------------------------------------------------------
QByteArray modbus_ascii::Get_Dev_Info_Handling(QByteArray response)//обработка ответа
{
    quint16 ID;
    QString Description;

    ID=response.mid(2,2)[0]<<8|response.mid(2,2)[1];

    qDebug("ID=%d",ID);

    Description.append(response.mid(4,response.length()-6).data());
    qDebug()<<"DESC="<<Description;
    emit this->GET_INFO_OK(true,ID,Description);

    qDebug("Read OK %s", response.constData());

    return response;
}
//-----------------------------------------------------------------------------------------
void modbus_ascii::Set_Dev_Info_Handling(QByteArray response)//обработка ответа
{
    if(response[0]==last_request[0] && response[1]==last_request[1])//проверяем адрес и функцию
    {
        emit SET_INFO_OK(true);
         qDebug("Read OK %s", response.data());
    }
    else
    {
        emit SET_INFO_OK(false);
    }
}
//-----------------------------------------------------------------------------------------
QByteArray modbus_ascii::DAC_Tune_Request(quint8 dev_addr, float dac_val)//установка тока на цап
{
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->DAC_Settings);

    mb_request.append(((unsigned char*)&dac_val)[3]);//положим в кадр значение тока float
    mb_request.append(((unsigned char*)&dac_val)[2]);
    mb_request.append(((unsigned char*)&dac_val)[1]);
    mb_request.append(((unsigned char*)&dac_val)[0]);

    mb_request=Handle_Request(mb_request);
    emit this->WriteToOut_Thread(mb_request);
    qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}
//------------------------------------------------------------------------------------------
QByteArray modbus_ascii::Set_Dev_Address(quint8 dev_addr_old,quint8 dev_addr_new)//настроить адрес устройства
{
    QByteArray mb_request;
    mb_request.append(dev_addr_old);
    mb_request.append(this->SetDevAddress);
    mb_request.append(dev_addr_new);
    mb_request=Handle_Request(mb_request);
    emit this->WriteToOut_Thread(mb_request);
    qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}
//--------------------------------------------------------------------------------------------
QByteArray modbus_ascii::Get_Dev_Settings(quint8 dev_addr)//получить настройки цап, ацп
{
    QByteArray mb_request;
    mb_request.append(dev_addr);
    mb_request.append(this->GetDevSettings);
    mb_request=Handle_Request(mb_request);
    emit this->WriteToOut_Thread(mb_request);
    qDebug( "SEND DATA:  %s",mb_request.constData())  ;
    return mb_request;
}
//--------------------------------------------------------------------------------------------
void modbus_ascii::Get_Dev_Settings_Handling(QByteArray response)//обработать поступившие данные настройки устройства
{
    GET_DEV_SETTINGS_OK(true,response);
}
