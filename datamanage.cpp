#include "datamanage.h"
#include <QCoreApplication>

dataManage::dataManage()
{
    initializeDB();
}

void dataManage::initializeDB()
{

    dataBase = QSqlDatabase::addDatabase("QSQLITE");

    QString createPath = QCoreApplication::applicationDirPath();
    createPath += "/TestLeak.db";

    dataBase.setDatabaseName(createPath);
    if(!dataBase.open())
    {
        qDebug()<<dataBase.lastError();
        qFatal("failed to connect.");
        return;
    }
    else
    {
        qDebug()<<"success!";
    }
    qDebug()<<dataBase;
    sql_query = QSqlQuery::QSqlQuery(dataBase);

}


void dataManage::exec(QString sql )
{
    lock.lock();
    sql_query.prepare(sql);

    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
        qDebug()<<"exec faile!";
    }
    lock.unlock();
}

QStringList dataManage::selectAllData(QString str)
{
    lock.lock();
    sql_query.prepare(str);

    if(!sql_query.exec())
    {
        qDebug()<<dataBase.lastError();
        qDebug()<<"Select all data faile!";
    }

    sql_query.next();

    QStringList list;
    for(int i = 0;i < 15;i++)
    {
        list.append(sql_query.value(i).toString());
    }

    lock.unlock();
    return list;
}

bool dataManage::insertData(QString sqlStr)
{
    lock.lock();
    sql_query.prepare(sqlStr);

    if(!sql_query.exec())
    {
        qDebug()<<dataBase.lastError();
        qDebug()<<"Insert faile!";
        lock.unlock();
        return false;
    }
    lock.unlock();
    return true;

}

//void dataManage::createTable(QString tableName,QString rankName)
//{
//    lock.lock();

//    QString create_Sql = "create table if not exists "  + tableName +"  (  " + rankName + " ); ";


//    sql_query.prepare(create_Sql);
//    if(!sql_query.exec())
//    {
//        qDebug()<<dataBase.lastError();
//        qDebug()<<"Create table faile!";
//    }
//    lock.unlock();
//}

//void dataManage::insertData(QString tableName,QString insertStr )
//{
//    lock.lock();
//    QString insert_Sql = "insert into " + tableName + " values( " + insertStr + " );";

//    sql_query.prepare(insert_Sql);

//    if(!sql_query.exec())
//    {
////        qDebug()<<insert_Sql;
//        qDebug()<<dataBase.lastError();
//        qDebug()<<"Insert faile!";
//    }
//    lock.unlock();
//}

//void dataManage::deleteData(QString str)
//{
//    lock.lock();
//    sql_query.prepare(str);

//    if(!sql_query.exec())
//    {
//        qDebug()<<dataBase.lastError();
//        qDebug()<<"Delete data faile!";
//    }
//    lock.unlock();
//}


//QString dataManage::selectData(QString  selectStr)//没有用到
//{
//    lock.lock();
////    QString select_Sql = "select "+selectStr +" from " + tableName+ selectF+";";

//    sql_query.prepare(selectStr);

//    if(!sql_query.exec())
//    {
//        qDebug()<<dataBase.lastError();
//        qDebug()<<"Select faile!";
//        return NULL;
//    }

//    sql_query.next();
//    QString str = sql_query.value(0).toString();
//    lock.unlock();
//    if(!str.isEmpty())
//    {
//        return str;
//    }
//    else
//    {
//        return NULL;
//    }

//}

//QString dataManage::existsSelect(QString tableName,QString fileName,QString filePath)
//{
//    lock.lock();
//    QString select_Sql  = "select * from " + tableName + " where FileName = '" + fileName + "' and Path = '" +filePath +"' ;";
//    sql_query.prepare(select_Sql);

//    if(!sql_query.exec())
//    {
//        qDebug()<<dataBase.lastError();
//        qDebug()<<"Exists select faile!";
//        return NULL;
//    }

//    sql_query.next();
//    QString lastModifyTime = sql_query.value("lastModifyTime").toString();
//    lock.unlock();
//    if(!lastModifyTime.isEmpty())
//    {
//        return lastModifyTime;
//    }
//    else
//    {
//        return NULL;
//    }

//}

//void dataManage::updateSql(QString tableName,QString updateValue,QString updateStr)
//{
//    lock.lock();
//    QString update_Sql  = "update  " + tableName + updateValue + updateStr + ";";
//    sql_query.prepare(update_Sql);

//    if(!sql_query.exec())
//    {
//        qDebug()<<dataBase.lastError();
//        qDebug()<<"Update faile!";
//    }
//    lock.unlock();
//}


//QSqlQuery* dataManage::Query(QString sql)
//{
//    lock.lock();
//    QSqlQuery *p_query = new QSqlQuery(sql, dataBase);
//    if(p_query->exec())
//    {
//        //p_query->finish();
//        lock.unlock();
//      //p_query->next();
//        // qDebug()<<dataBase;
//       // qDebug()<<p_query->value(1).toString();
//       // qDebug()<<p_query->value("ID").toInt();
//        return p_query;
//    }else
//    {
//        lock.unlock();
//        qDebug()<<dataBase.lastError();
//        return NULL;
//    }

//}

