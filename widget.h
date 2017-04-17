#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTcpSocket>
#include "datamanage.h"
#include "recievedata.h"
#include "uploadthread.h"

namespace Ui {
class Widget;
}



class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

public:
    QStringList m_resulteList;
    QString m_barCode;
    QTimer timer_connect;
    QTimer qtime;
    QString IP;
    bool flag;

    dataManage* DB;
    RecieveData* RecvData;
    UpLoadThread* upLoadData;
    QTcpSocket* m_tcpSocket;

public:
    void displayData();
    void saveData();
    void connectIP();

    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent ( QKeyEvent * event );
//    void keyReleaseEvent ( QKeyEvent * event );

public slots:
    void recvData(QStringList);
    void onProgress();
    void connected();
    void disconnected();
    void onError(QAbstractSocket::SocketError);


};

#endif // WIDGET_H
