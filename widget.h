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
#include "datamanage.h"

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
    QSerialPort* m_serialport;
    QTimer* timer;
    QStringList m_resulteList;
    QString m_barCode;

    dataManage* DB;

public:
    void handingRevData();
    void saveData();

    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent ( QKeyEvent * event );
//    void keyReleaseEvent ( QKeyEvent * event );

public slots:
    void on_pushButton_clicked();
    void updateAA();
};

#endif // WIDGET_H
