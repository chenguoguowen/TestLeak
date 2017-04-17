#include "uploadthread.h"

UpLoadThread::UpLoadThread(dataManage *DB, QTcpSocket* tcpSocket, QString user_name):QThread(0)
{
    this->db = DB;
    this->pTcpSocket = tcpSocket;
    this->work_tags = 0;

    this->state = 1;
    this->index = 1;

    isRun = false;
    this->user_name_login = user_name;

    for(uint i= 1;i<15;i++)
    {
        QString ss = QString("%1").arg(i+131072);
        Addrs.append(ss);
    }
    connect(pTcpSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(this,SIGNAL(send_sig()),this,SLOT(send_data()));
    connect(this,SIGNAL(commit_sig()),this,SLOT(commit_tran()));
    connect(this,SIGNAL(delete_sig()),this,SLOT(delete_data()));
    connect(this,SIGNAL(start_sig()),this,SLOT(start_tran()));
}

UpLoadThread::~UpLoadThread()
{

}

void UpLoadThread::run()
{
    isRun = true;

    static ulong times = 0;

    login_usr();

    while(isRun)
    {
      //  QDateTime time2 = QDateTime::currentDateTime();
        //qDebug()<<"1111:"<<time2.toString("hh:mm:ss.zzz ");

        list.clear();
        list = db->selectAllData("select * from  dataTable  limit  1  offset  0;");

        if(list[1].isEmpty() && list[2].isEmpty())
        {

            qDebug()<<"No data,wait!";
            sleep(5);
            continue;
        }
        else
        {
            //qDebug()<<list;
            while(!list.isEmpty() && isRun)
            {
                if(state == 0)
                {
                    state = 1;
                    emit start_sig();
                    times = 0;
                }
                else
                {
                    if(times < 3)
                    {
                        msleep((times + 3) * 100);
                        times++;
                    }
                    else
                    {
                        times = 0;
                        state = 0;
                    }

                }
            }
        }

    }
    qDebug() << "end";
}
void UpLoadThread::readyRead()
{
    QByteArray qba;
    if(pTcpSocket->isOpen())
    {
        qba= pTcpSocket->readAll(); //读取
    }
    else
    {
        qDebug()<<"Connect IP first!";
        return;
    }

    static qint64 rec_len = 0;
    static char recvBuffer[1024] = {0};
    Header_Upload* head;
    memcpy_s(recvBuffer + rec_len, sizeof(recvBuffer), qba.begin(), qba.length());

    rec_len += qba.length();
    if(rec_len >= sizeof(Header_Upload))
    {
        head = (Header_Upload*)recvBuffer;
        if(rec_len >= head->length)
        {
            rec_len = 0;
            if(head->protocol_tags != 32)
            {
                memset(recvBuffer,'\0',1024);

                return;
            }

            if(head->protocol_tags == 32 && head->unit_tags == 0)
            {
                char err ;
                //time1 = QDateTime::currentDateTime();

                //qint64 a = time1.msecsTo(time);
                switch(head->fun_code)
                {
                case 0x42:
                    qDebug() << "send_data";
                    emit send_sig();
                    //qDebug()<<"send_data:1"<<time1.toString();
                    break;
                case 0x43:
                    qDebug() << "start_tran";
                    emit send_sig();
                    //qDebug()<< "start_tran1"<<time1.toString("hh:mm:ss.zzz ");
                    break;
                case 0x44:
                    qDebug() << "commit_tran";
                    emit delete_sig();
                    //qDebug()<<"commit_tran:1"<<time.toString("hh:mm:ss.zzz ");
                    break;
                case 0x45:
                    qDebug() << "login";
                    //emit start_sig();
                    state = 0;
                    break;
                case 0x46:
                    qDebug() << "alive";
                    break;
                case 0xC2:
                    qDebug() << "上传数据错误!";
                    err = recvBuffer[8];
                    qDebug()<<err;
//                    Stop();
                    login_usr();
                    break;
                case 0xC3:
                    qDebug() << "启动事务错误!";
                    err = recvBuffer[8];
                    qDebug()<<err;
//                    Stop();
                    login_usr();
                    break;
                case 0xC4:
                    qDebug() << "提交事务错误!";
                    err = recvBuffer[8];
                    qDebug()<<err;
//                    Stop();
                    login_usr();
                    break;
                case 0xC5:
                    qDebug() << "登录错误!";
                    err = recvBuffer[8];
                    qDebug()<<err;
//                    Stop();
                    login_usr();
                    break;
                case 0xC6:
                    qDebug() << "定时响应错误!";
                    err = recvBuffer[8];
                    qDebug()<<err;
                    err = recvBuffer[9];
                    qDebug()<<err;
//                    Stop();
                    login_usr();
                    break;
                default:
                    break;
                }

                memset(recvBuffer,'\0',1024);   //释放缓冲区
            }
        }
    }
}

void UpLoadThread::login_usr()
{

    char sendBuffer[1024];
    QByteArray ba = user_name_login.toLatin1();
    const char* userName = ba.data();
    const char* passwd = "111111";

    Header_Upload* head = (Header_Upload*) sendBuffer;
    head->work_tags = work_tags++;
    head->protocol_tags = 0x20;
    head->fun_code = 0x45;
    head->length = 8 + 3 + 1 + 6; //头长度8+用户名3，加逗号1，加密码6
    head->unit_tags = 0;

    memcpy(&sendBuffer[8], userName, 3);
    sendBuffer[11] = ',';
    memcpy(&sendBuffer[12], passwd, 6);

    pTcpSocket->write(sendBuffer,head->length);

}

void UpLoadThread::start_tran()
{
    time = QDateTime::currentDateTime();
   qDebug()<<"start_tran"<<time.toString("hh:mm:ss.zzz ");
    char sendBuffer[1024];
    Header_Upload* head = (Header_Upload*) sendBuffer;

    head->work_tags = work_tags++;
    head->protocol_tags = 0x20;
    head->fun_code = 0x43;
    head->length = 8;
    head->unit_tags = 0;

    index = 1;             //防止程序中途跳过delete步骤
    
    pTcpSocket->write(sendBuffer,head->length);
}

void UpLoadThread::delete_data()
{
    QString SqlStr;
    SqlStr = "delete from dataTable where ID = " + list[0];

    db->exec(SqlStr);

    list.clear();

    state = 0;

}

void UpLoadThread::send_data()
{    
      uint addr = 0;

    if(index == list.length())
    {
        index=1;
        emit commit_sig();
        return;
    }


    if(!list[index].isNull())
    {
        char sendBuffer[1024];
        Header_Upload* head = (Header_Upload*)sendBuffer;
        head->work_tags = work_tags++;
        head->protocol_tags = 0x20;
        head->fun_code = 0x42;

        head->length = 8 + 4 + list[index].length(); //头长度8+用户名3，加逗号1，加数据长度
        head->unit_tags = 0;
        addr = Addrs[index-1].toUInt();
        qDebug()<< list[index];
        qDebug()<<addr;

        QByteArray aa = list[index].toLatin1();
        char* a = aa.data();
        memcpy(&sendBuffer[8], &addr, 4);
        memcpy(&sendBuffer[12], a , list[index].length());
        pTcpSocket->write(sendBuffer,head->length);
    }
    else if(list[index].isEmpty() && index > 1)
    {
        index = 1;
        emit commit_sig();
    }

    index++;
}

void UpLoadThread::commit_tran()
{
  //  time = QDateTime::currentDateTime();
   //qDebug()<<"commit_tran"<<time.toString("hh:mm:ss.zzz ");
    char sendBuffer[1024];
    Header_Upload* head = (Header_Upload*) sendBuffer;
    head->work_tags = work_tags++;
    head->protocol_tags = 0x20;
    head->fun_code = 0x44;
    head->length = 8;
    head->unit_tags = 0;

    pTcpSocket->write(sendBuffer,head->length);

}

void UpLoadThread::keepAlive()
{
    char sendBuffer[1024];
    if(pTcpSocket->isOpen())
    {
        Header_Upload* head = (Header_Upload*)sendBuffer;
        head->work_tags = work_tags++;
        head->protocol_tags = 0x20;
        head->fun_code = 0x46;
        head->length = 8 + 2 ; //头长度8+状态码1+异常码1
        head->unit_tags = 0;
        sendBuffer[8] = 0x01;
        sendBuffer[9] = 0x00;

        pTcpSocket->write(sendBuffer,head->length);
    }

}


