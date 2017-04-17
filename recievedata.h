#ifndef RECIEVEDATA_H
#define RECIEVEDATA_H
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
class RecieveData : public QThread
{
    Q_OBJECT
public:
    RecieveData();


public:
    bool isRun;
    bool state;

    QSerialPort* m_serialport;
    QTimer* timer;
    QStringList m_returnList;

protected:
    virtual void run();


public :
    void RecvData();

signals:
    void sendData(QStringList);


};

#endif // RECIEVEDATA_H
