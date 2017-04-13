#ifndef DATAMANAGE_H
#define DATAMANAGE_H

#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QDebug>
#include <QMutex>

class dataManage
{
public:
    dataManage();
    QSqlDatabase dataBase;
    QSqlQuery sql_query;
    QMutex lock;

public:
    void initializeDB();
//    void createTable(QString,QString);
//    void insertData(QString,QString);
//    QString selectData(QString);
//    QString existsSelect(QString,QString,QString);
//    void updateSql(QString,QString,QString);
    QStringList selectAllData(QString);
//    void deleteData(QString);
//    QSqlQuery* Query(QString sql);
    void exec(QString sql );
//    int selectID(QString);

};

#endif // DATAMANAGE_H
