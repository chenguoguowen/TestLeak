#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("LeakTest");

    ui->lineEdit->setFocus(Qt::ActiveWindowFocusReason);

    setFocusPolicy(Qt::ClickFocus);  //设置这个窗口部件接收键盘焦点的方式

    DB = new dataManage();
    QString sqlStr = "create table if not exists dataTable (ID integer primary key,Name varchar(50),Value varchar(50),Date varchar(50),Time varchar(50),Program varchar(50),Sequence varchar(50),Lot varchar(50),Operator varchar(50),Result varchar(50), Units varchar(50), Data1 varchar(50), Data2 varchar(50), Data3 varchar(50))";
    DB->exec(sqlStr);

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

void Widget::keyPressEvent(QKeyEvent *event)
{
    ui->lineEdit->setFocus(Qt::ActiveWindowFocusReason);
    m_barCode = ui->lineEdit->text();

    switch(event->key())
    {
    case Qt::Key_Enter:
    case Qt::Key_Return:
    {
        if(m_barCode.isEmpty())
        {
            ui->lineEdit_15->setText("No bar code!");
            break;
        }

        if(m_resulteList.isEmpty() && m_resulteList.length() <13)
        {
            ui->lineEdit_15->setText("No data recieve!");
            break;
        }
        else
        {
            saveData();
            ui->lineEdit->setText("");
        }

        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
        ui->lineEdit_9->setText("");
        ui->lineEdit_10->setText("");
        ui->lineEdit_11->setText("");
        ui->lineEdit_12->setText("");
        ui->lineEdit_13->setText("");
        ui->lineEdit_14->setText("");
        break;
    }
    default:
        break;
    }

    m_barCode.clear();
}

void  Widget::saveData()
{
    QString insertSql = "insert into dataTable  (ID,Name,Value,Date,Time,Program,Sequence,Lot,Operator,Result,Units,Data1,Data2,Data3) values ( null,'"+m_resulteList[0] + "','" +m_resulteList[1]+ "','" +m_resulteList[2]+ "','" +m_resulteList[3]+ "','" +m_resulteList[4]+ "','" +m_resulteList[5]+ "','" +m_resulteList[6]+ "','" +m_resulteList[7]+ "','" +m_resulteList[8]+ "','" +m_resulteList[9]+ "','" +m_resulteList[10]+ "','" +m_resulteList[11]+ "','" +m_resulteList[12] +"');";
    bool insertFlag = DB->insertData(insertSql);

    if(insertFlag)
    {
        ui->lineEdit_15->setText("Save success!");
    }
    else
    {
        ui->lineEdit_15->setText("Save faile!");
    }

}


void Widget::mousePressEvent(QMouseEvent* event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
    case Qt::RightButton:
        ui->lineEdit->setFocus(Qt::ActiveWindowFocusReason);
        break;
    default:
        break;
    }
}


void Widget::updateAA()
{
    QString recieveData;
    recieveData = m_serialport->readAll();
    if(recieveData.isEmpty())
    {
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

    ui->lineEdit->setFocus(Qt::ActiveWindowFocusReason);

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
        ui->lineEdit_15->setText("");
    }
    else
    {
        ui->lineEdit_15->setText("Data error!");
        return;
    }
}


void Widget::on_pushButton_clicked()    //use for test
{
    QByteArray TxData = "1111";
    m_serialport->write(TxData);
    ui->lineEdit->setFocus(Qt::ActiveWindowFocusReason);
}

