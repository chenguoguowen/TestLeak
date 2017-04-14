#ifndef UPLOADTHREAD_H
#define UPLOADTHREAD_H

#include <QThread>
#include "datamanage.h"
#include <QTcpSocket>
#include "data.h"
#include <QDateTime>
class UpLoadThread : public QThread
{
    Q_OBJECT
public:
    explicit UpLoadThread(dataManage *DB, QTcpSocket* tcpSocket, std::vector<std::pair<QString, QString>>* Addrs, QString user_name);
    ~UpLoadThread();
    bool isRun;

signals:
    void start_sig();
    void send_sig();
    void commit_sig();
    void delete_sig();
    void keepAlive_sig();
public slots:
    void readyRead();
    void start_tran();
    void send_data();
    void commit_tran();
    void keepAlive();
    void delete_data();
    void login_usr();
//    void Stop();


protected:
    virtual void run();
private:
    dataManage *db;
    QTcpSocket* pTcpSocket;
    ushort work_tags;
    QStringList list;
    QString user_name_login;
//    QSqlQuery* query;
    std::vector<std::pair<QString, QString>>* Addrs;
    int state;
    int index;

    QDateTime time;
    QDateTime time1;
};

#endif // UPLOADTHREAD_H
