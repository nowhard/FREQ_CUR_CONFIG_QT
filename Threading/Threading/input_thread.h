#ifndef INPUT_THREAD_H
#define INPUT_THREAD_H

#include <QThread>
#include <QByteArray>
#include <abstractserial.h>
#include <QDebug>

class Input_Thread : public QThread
{
    Q_OBJECT
public:
    explicit Input_Thread(QObject *parent,AbstractSerial *port);
    ~Input_Thread();
    void run();

signals:
    void isRead(QByteArray data);
    void ReadOK(bool ok);

public slots:
private slots:
    void ReadPort(void);

private:
    AbstractSerial *port;
    enum {MIN_PACK_LENGTH=0x5};
    quint8 Recieve_Count;//счетчик принятых

};

#endif // INPUT_THREAD_H
