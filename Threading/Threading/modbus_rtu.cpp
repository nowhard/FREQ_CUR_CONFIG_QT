#include "modbus_rtu.h"


Modbus_RTU::Modbus_RTU(QObject *parent,AbstractSerial *port):
        QObject(parent)
{
    this->port=port;

    in_thread=new Input_Thread(this,port);
    out_thread=new Output_Thread(this,port);
    connect(in_thread,SIGNAL(isRead(QByteArray)),this,SLOT(ResponseHandling(QByteArray)));
    in_thread->start();


    connect(this,SIGNAL(WriteToOut_Thread(QByteArray)),out_thread,SLOT(Send(QByteArray)));
    out_thread->start();

    timer=new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SIGNAL(DEVICE_NOT_CONNECTED()));
}

Modbus_RTU::~Modbus_RTU()
{
    in_thread->quit();

    //in_thread->exit();
    delete in_thread;
    out_thread->quit();
    //out_thread->exit();
    delete out_thread;
}

QByteArray Modbus_RTU::RequestHoldingRegisters(qint8 dev_addr,qint16 first_reg_addr,qint16 num_reg)
{
    QByteArray mb_request;
    quint16 CRC;
    mb_request.append(dev_addr);
    mb_request.append(this->ReadHld);

    mb_request.append(((char*)(&first_reg_addr))[1]);
    mb_request.append(((char*)(&first_reg_addr))[0]);

    mb_request.append(((char*)(&num_reg))[1]);
    mb_request.append(((char*)(&num_reg))[0]);

    CRC=CRC16(mb_request,mb_request.length());
    mb_request.append(((char*)(&CRC))[0]);
    mb_request.append(((char*)(&CRC))[1]);

    //port->write(mb_request);
    emit this->WriteToOut_Thread(mb_request);
    last_request=mb_request;
     qDebug( "SEND DATA:  %X",mb_request.data())  ;

     timer->start(100);

     return mb_request;
}

void Modbus_RTU::RequestHoldingRegisters(qint8 dev_addr,MB_Register reg)
{
    this->reg=reg;
    RequestHoldingRegisters(dev_addr,reg.address,reg.length);
}


QByteArray Modbus_RTU::SetSingleRegister(qint8 dev_addr,qint16 reg_addr,quint16 value)
{
    QByteArray mb_request;
    quint16 CRC;
    mb_request.append(dev_addr);
    mb_request.append(this->WriteReg);
    mb_request.append(((char*)(&reg_addr))[1]);
    mb_request.append(((char*)(&reg_addr))[0]);

    mb_request.append(((char*)(&value))[1]);
    mb_request.append(((char*)(&value))[0]);

    CRC=CRC16(mb_request,mb_request.length());
    mb_request.append(((char*)(&CRC))[0]);
    mb_request.append(((char*)(&CRC))[1]);

    //port->write(mb_request);
    emit this->WriteToOut_Thread(mb_request);
    last_request=mb_request;

    qDebug( "SEND DATA:  %X",mb_request.data())  ;
    return mb_request;
}

QByteArray Modbus_RTU::SetMultipleRegisters(qint8 dev_addr, qint16 first_reg_addr,qint16 num_reg,QByteArray values)
{


}

QByteArray Modbus_RTU::CalibrateRequest(quint8 dev_addr,quint8 point ,float density)
{
    QByteArray mb_request;
    quint16 CRC;

    union
    {
        quint8 dnst[4];
        float  dnst_2;
    };

    mb_request.append(dev_addr);
    mb_request.append(this->Calibrate);
    mb_request.append(point);

    dnst_2=density;

    mb_request.append(dnst[0]);//передача float
    mb_request.append(dnst[1]);
    mb_request.append(dnst[2]);
    mb_request.append(dnst[3]);



    CRC=CRC16(mb_request,mb_request.length());
    mb_request.append(((char*)(&CRC))[0]);
    mb_request.append(((char*)(&CRC))[1]);

    emit this->WriteToOut_Thread(mb_request);
    last_request=mb_request;

    qDebug( "SEND DATA:  %X",mb_request.data())  ;
    return mb_request;
}

quint16 Modbus_RTU::CRC16(QByteArray data,quint8 len)
{
    quint16 CheckSum;
    unsigned int j;
    unsigned short i;
    CheckSum = 0xffff;
    for (j=0; j<len; j++)
    {
    CheckSum = CheckSum^(quint16)(data[j]&0xFF);
    for(i=8;i>0;i--)
            if((CheckSum)&0x0001)
            CheckSum = (CheckSum>>1)^0xa001;
            else
            CheckSum>>=1;
    }
    return CheckSum;
}

void Modbus_RTU::ResponseHandling(QByteArray response)
{
    quint16 CRC,trueCRC;
       timer->stop();

    qDebug() << "Readed: " << response.size() << " bytes";
    //qDebug( "RESP DATA:  %X",response.data())  ;

   /* for(int k=0;k<response.length();k++)
    {
        qDebug( "%X",response.data()[k])  ;
    }*/


    CRC=(quint16)((response.data()[response.length()-2])&0xFF) | ((quint16)((response.data()[response.length()-1])&0xFF))<<8 ;//здесь какая то ошибка...
    trueCRC=CRC16(response,response.length()-2);

    if(trueCRC==CRC)
    {
        qDebug("CRC true %X=%x",CRC,trueCRC);

        //продолжить обработку
        emit CRC_OK(true);

        switch(response[1])
        {
            case ReadHld:
            {
                registers=Handling_Read_Hold_Respnse(response);
                emit IsRead(registers);
                emit IsRead(reg,registers);
            }
            break;

            case WriteReg:
            {
                if(response==last_request)
                {
                    emit WRITE_REG_OK(true);
                     qDebug() << "Write OK "<<CRC;
                }
                else
                {
                    emit WRITE_REG_OK(false);
                    qDebug() << "Write ERR "<<CRC;
                }
            }
            break;

            case WriteMultipleRegs:
            {
                emit NOT_IMPLEMENTED();
            }
            break;

            case Calibrate:
            {
               /* union
                {
                    quint8 prss[4];
                    float  prss_2;
                };*/

                quint8 point=response[2];

              /*  prss[0]=response[4];
                prss[1]=response[3];
                prss[2]=response[6];
                prss[3]=response[5];*/

                emit CALIBRATE_OK(point/*,prss_2*/);
                qDebug() << "CALIBRATE OK";
            }
            break;

            default:
            {
                emit UNCNOWN_COMMAND();
            }
            break;
        }
    }
    else
    {
        qDebug("CRC false %X!=%X",CRC,trueCRC);
        //ошибка передачи данных
        emit CRC_OK(false);//сигнал ошибка CRC
    }
}

QByteArray Modbus_RTU::Handling_Read_Hold_Respnse(QByteArray hld_resp)
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
