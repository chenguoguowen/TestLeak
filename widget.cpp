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

    QString sqlStr = "create table if not exists dataTable (ID integer primary key,BarCode varchar(50),Name varchar(50),Value varchar(50),Date varchar(50),Time varchar(50),Program varchar(50),Sequence varchar(50),Lot varchar(50),Operator varchar(50),Result varchar(50), Units varchar(50), Data1 varchar(50), Data2 varchar(50), Data3 varchar(50))";

    DB->exec(sqlStr);

    RecvData = new RecieveData();
    RecvData->start();

    upLoadData = NULL;
    m_tcpSocket = new QTcpSocket(this);

    connect(RecvData,SIGNAL(sendData(QStringList)),this,SLOT(recvData(QStringList)));

    connectIP();
    flag = false;
}

Widget::~Widget()
{
    if(RecvData != NULL)
    {
        RecvData->isRun = false;
        RecvData->wait();
        delete RecvData;
    }
    if(upLoadData != NULL)
    {
        upLoadData->isRun = false;
        upLoadData->wait();
        delete upLoadData;
    }
    if(m_tcpSocket != NULL)
    {
        delete m_tcpSocket;
    }
    delete DB;
    delete ui;
}

void Widget::connectIP()
{
     IP = "127.0.0.1";

    connect(m_tcpSocket,SIGNAL(connected()),this,SLOT(connected()));
    connect(m_tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(m_tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
    connect(&timer_connect,SIGNAL(timeout()),this,SLOT(onProgress()), Qt::QueuedConnection);


    m_tcpSocket->connectToHost(IP,61000);

    if(!m_tcpSocket->waitForConnected(5000))
    {
        QMessageBox::warning(NULL,"Reminder","No link this ip!" + m_tcpSocket->errorString(),QMessageBox::No);
        return;
    }

    upLoadData = new UpLoadThread(DB, m_tcpSocket, "869");

    timer_connect.start(4800);

    upLoadData->start();        //上传线程

    //定时检查连接是否断了
    connect(&qtime, SIGNAL(timeout()),upLoadData,SLOT(keepAlive()));
    qtime.start(1000*30);
}

void Widget::onProgress()
{
    if(flag == false)
    {
        if(upLoadData != NULL)
        {
            upLoadData->isRun = false;
            upLoadData->wait();
            delete upLoadData;
        }
        qDebug()<<m_tcpSocket;
        m_tcpSocket->close();
        m_tcpSocket->connectToHost(IP,61000);
        upLoadData = new UpLoadThread(DB, m_tcpSocket,"869");
        upLoadData->start();        //上传线程
    }
}

void Widget::connected()
{
    flag = true;
}

void Widget::disconnected()
{
    flag = false;
}

void Widget::onError(QAbstractSocket::SocketError)
{

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
        else
        {
            m_resulteList.append(m_barCode);
        }

        if(m_resulteList.isEmpty() || m_resulteList.length() != 14)
        {
            ui->lineEdit_15->setText("No data recieve!");
            break;
        }
        else
        {
            saveData();       
        }
        ui->lineEdit->setText("");
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
    QString insertSql = "insert into dataTable  (ID,BarCode,Name,Value,Date,Time,Program,Sequence,Lot,Operator,Result,Units,Data1,Data2,Data3) values ( null,'"+m_resulteList[13]+"','"+m_resulteList[0] + "','" +m_resulteList[1]+ "','" +m_resulteList[2]+ "','" +m_resulteList[3]+ "','" +m_resulteList[4]+ "','" +m_resulteList[5]+ "','" +m_resulteList[6]+ "','" +m_resulteList[7]+ "','" +m_resulteList[8]+ "','" +m_resulteList[9]+ "','" +m_resulteList[10]+ "','" +m_resulteList[11]+ "','" +m_resulteList[12] +"');";

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


void Widget::mousePressEvent(QMouseEvent* event)       //鼠标点击后聚焦条码框
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


void Widget::recvData(QStringList recv)
{
    m_resulteList = recv;
    displayData();
}

void Widget::displayData()
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


