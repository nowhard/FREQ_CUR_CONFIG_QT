#ifndef SERIAL_IO_H
#define SERIAL_IO_H

#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <abstractserial.h>
#include "input_thread.h"
#include "output_thread.h"

class Serial_IO : public QObject
{
    Q_OBJECT
public:
    explicit Serial_IO(QObject *parent, AbstractSerial *port);

signals:
    void Sym_Timeout();//таймаут 1.5 символа

    void Send_Out(QByteArray data);

public slots:
    void Send(QByteArray data);//отправить посылку на устройство
    void Start(void);//начать прием\передачу
    void Stop(void);//завершить прием\передачу
    void Response(void);//получен ответ от устройства, сигнал с данными
private:
    QByteArray data;//данные, принятые с устройства
    AbstractSerial *io_port;// последовательный порт
    //Output_Thread*  out_thread;
   // Input_Thread *in_thread;//входной поток данных//


};

#endif // SERIAL_IO_H
