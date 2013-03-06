#include "output_thread.h"

Output_Thread::Output_Thread(QObject *parent,AbstractSerial *port) :
    QThread(parent)
{
    this->port=port;
}

void Output_Thread::Send(QByteArray out_data)//посылка данных
{
    //реализовать добавление 0 после D7 в теле протокола
    quint8 i,j=3;
    //---------------------------------------------------
    while((out_data.indexOf((char)0xD7,j))!=-1)
    {
        i=out_data.indexOf((char)0xD7,j);
        out_data.insert(i+1,(char)0x0);
        j=i+1;
         qDebug() << "D7 DETECTED";
    }
    //---------------------------------------------------

    if(port->isOpen())
    {
        data=out_data;
        qint64 snd=port->write(data.data(),data.size());
        qDebug() << "Write is : " << out_data.size() << " bytes";
        if(snd==data.size())
        {
            emit Send_OK(true);//передан весь буфер
        }
        else
        {
           emit Send_OK(false);//передан не весь буфер
        }
    }
    else
    {
        emit Send_OK(false);//порт был закрыт
    }
    usleep(2000);
}

void Output_Thread::run()
{
    exec();
    usleep(2000);
}

Output_Thread::~Output_Thread()
{
    this->terminate();
}
