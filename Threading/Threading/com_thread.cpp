#include "com_thread.h"

COM_Thread::COM_Thread(QObject *parent,unsigned int time) :
    QThread(parent)
{
    thread_time=time;
    timer = new QTimer();
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SIGNAL(Tick()));
    timer->start();
}

void COM_Thread::run()
{
    for(int i=0;i<100;i++)
    {
        emit ThreadValue(i);
        this->usleep(thread_time);
    }

    exec();
}
