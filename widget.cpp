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
    QByteArray requestData = m_serialport->readAll();
    if(!requestData.isEmpty())
    {
        ui->lineEdit->setText(requestData);
    }
    requestData.clear();
}

void Widget::on_pushButton_clicked()
{
    QByteArray TxData = "1111";
    m_serialport->write(TxData);
}

