#ifndef OUTPUT_THREAD_H
#define OUTPUT_THREAD_H

#include <QThread>
#include <QByteArray>
#include <abstractserial.h>
#include "serial_io.h"

class Output_Thread : public QThread
{
    Q_OBJECT
public:
    Output_Thread(QObject *parent,AbstractSerial *port);
    ~Output_Thread();
    void run();
signals:
    void Send_OK(bool OK);
public slots:
    void Send(QByteArray out_data);//посылка данных
private:
    QByteArray data;
    AbstractSerial *port;//порт вывода
};

#endif // OUTPUT_THREAD_H
