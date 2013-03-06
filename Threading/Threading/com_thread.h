#ifndef COM_THREAD_H
#define COM_THREAD_H

#include <QThread>
#include <QTimer>

class COM_Thread : public QThread
{
    Q_OBJECT
public:
    explicit COM_Thread(QObject *parent,unsigned int time);
    void run();
private:
    unsigned int thread_time;
    QTimer *timer;
signals:
    void ThreadValue(int value);
    void Tick();
public slots:

};

#endif // COM_THREAD_H
