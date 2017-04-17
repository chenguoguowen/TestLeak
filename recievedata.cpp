#include "recievedata.h"

RecieveData::RecieveData()
{
    m_serialport= new QSerialPort();
    m_serialport->setPortName("COM2");
    m_serialport->open(QIODevice::ReadWrite);

    m_serialport->setBaudRate(9600);
    m_serialport->setDataBits(QSerialPort::Data8);
    m_serialport->setParity(QSerialPort::NoParity);
    m_serialport->setStopBits(QSerialPort::OneStop);
    m_serialport->setFlowControl(QSerialPort::NoFlowControl);

    isRun = true;

}


void RecieveData::run()
{

    while(isRun)
    {
        RecvData();
    }
}

void RecieveData::RecvData()
{
    QString recieveData;
    recieveData = m_serialport->readLine();

    if(recieveData.isEmpty())
    {
        sleep(2);
        return;
    }

    m_returnList.clear();
    m_returnList = recieveData.split(",");

    if(m_returnList[0].compare("Leak") != 0)
    {
        qDebug()<<"Not leak data!";
        QMessageBox::warning(NULL,"Tips","Not leak data!");
        return;
    }

    if(m_returnList.length() != 13 || m_returnList[12].indexOf("\r\n") == -1)
    {
        qDebug()<<"Not full data!";
        QMessageBox::warning(NULL,"Tips","Not full data!");
        return;
    }
    else
    {
        m_returnList[12].remove("\r\n");
    }

//    qDebug()<<recieveData;
//    qDebug()<<m_returnList;

    recieveData.clear();

    emit sendData(m_returnList);

}
