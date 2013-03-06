#include "input_thread.h"

#define MODE_ASCII 0

Input_Thread::Input_Thread(QObject *parent,AbstractSerial *port) :
    QThread(parent)
{
        this->port=port;
        //connect(port,SIGNAL(readyRead()),this,SLOT(ReadPort()));
}

void Input_Thread::run()
{
    QByteArray ba;
    QByteArray head;
    qint8 i;

    head.append((char)0xD7);
    head.append((char)0x00);
    while (1)
    { 
       // usleep(2000);
        if ((port->bytesAvailable() > 0) && port->isOpen() )
        {
           ba.append(port->read(256));
          // qDebug()<< ba.toHex();
           while((i=ba.indexOf(head,3))>0)
           {
              // qDebug()<<ba.mid(i,2).toHex()<<" DETECTED from "<<i;
               ba.remove(i+1,1);
                //qDebug() << "D7 00 DETECTED";
           }

            if(ba.mid(6,ba.length()-6).length()==ba[5])
            {
                    emit isRead(ba);
                    emit ReadOK(true);
                    qDebug() << "Readed is : " << ba.size() << " bytes";
                   // qDebug()<< ba.toHex();
                     usleep(300);
                     ba.clear();
            }
            else
            {
                if(ba.mid(6,ba.length()-6).length()>ba[5])
                {
                    emit ReadOK(false);
                    qDebug() << "Readed is FALSE "<<ba.size()<<" bytes";
                   // qDebug()<< ba.toHex();
                     ba.clear();
                }
            }
        }

        msleep(1);
    }

}

 void Input_Thread::ReadPort(void)
 {
     /*QByteArray ba;
     ba.clear();
     ba = port->readAll();
     emit isRead(ba);
     emit ReadOK(true);
     qDebug() << "Readed is : " << ba.size() << " bytes";*/
 }

 Input_Thread::~Input_Thread()
 {
   this->terminate();
 }
