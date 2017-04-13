#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("LeakTest");

    m_serialport= new QSerialPort();
    m_serialport->setPortName("COM2");
    m_serialport->open(QIODevice::ReadWrite);

    m_serialport->setBaudRate(9600);
    m_serialport->setDataBits(QSerialPort::Data8);
    m_serialport->setParity(QSerialPort::NoParity);
    m_serialport->setStopBits(QSerialPort::OneStop);
    m_serialport->setFlowControl(QSerialPort::NoFlowControl);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAA()));
    timer->start(1000);

}

Widget::~Widget()
{
    delete ui;

}

void Widget::updateAA()
{
    QString recieveData;
    recieveData = m_serialport->readAll();
    if(recieveData.isEmpty())
    {
        //        ui->lineEdit->setText(m_recieveData);

        return;
    }

    qDebug()<<recieveData;
    m_resulteList.clear();
    m_resulteList = recieveData.split(",");

    recieveData.clear();

    handingRevData();
}

void Widget::handingRevData()
{
    int i = 0;

    if(m_resulteList.length() == 13)
    {
        ui->lineEdit_2->setText(m_resulteList[i++]);
        ui->lineEdit_3->setText(m_resulteList[i++]);
        ui->lineEdit_4->setText(m_resulteList[i++]);
        ui->lineEdit_5->setText(m_resulteList[i++]);
        ui->lineEdit_6->setText(m_resulteList[i++]);
        ui->lineEdit_7->setText(m_resulteList[i++]);
        ui->lineEdit_8->setText(m_resulteList[i++]);
        ui->lineEdit_9->setText(m_resulteList[i++]);
        ui->lineEdit_10->setText(m_resulteList[i++]);
        ui->lineEdit_11->setText(m_resulteList[i++]);
        ui->lineEdit_12->setText(m_resulteList[i++]);
        ui->lineEdit_13->setText(m_resulteList[i++]);
        ui->lineEdit_14->setText(m_resulteList[i++]);
    }
    else
    {
        ui->lineEdit_15->setText("Data error");
        return;
    }
}

void Widget::on_pushButton_clicked()
{
    QByteArray TxData = "1111";
    m_serialport->write(TxData);

}

