/****************************************************************************
** Meta object code from reading C++ file 'uploadthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uploadthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uploadthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UpLoadThread_t {
    QByteArrayData data[14];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UpLoadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UpLoadThread_t qt_meta_stringdata_UpLoadThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UpLoadThread"
QT_MOC_LITERAL(1, 13, 9), // "start_sig"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "send_sig"
QT_MOC_LITERAL(4, 33, 10), // "commit_sig"
QT_MOC_LITERAL(5, 44, 10), // "delete_sig"
QT_MOC_LITERAL(6, 55, 13), // "keepAlive_sig"
QT_MOC_LITERAL(7, 69, 9), // "readyRead"
QT_MOC_LITERAL(8, 79, 10), // "start_tran"
QT_MOC_LITERAL(9, 90, 9), // "send_data"
QT_MOC_LITERAL(10, 100, 11), // "commit_tran"
QT_MOC_LITERAL(11, 112, 9), // "keepAlive"
QT_MOC_LITERAL(12, 122, 11), // "delete_data"
QT_MOC_LITERAL(13, 134, 9) // "login_usr"

    },
    "UpLoadThread\0start_sig\0\0send_sig\0"
    "commit_sig\0delete_sig\0keepAlive_sig\0"
    "readyRead\0start_tran\0send_data\0"
    "commit_tran\0keepAlive\0delete_data\0"
    "login_usr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpLoadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UpLoadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UpLoadThread *_t = static_cast<UpLoadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_sig(); break;
        case 1: _t->send_sig(); break;
        case 2: _t->commit_sig(); break;
        case 3: _t->delete_sig(); break;
        case 4: _t->keepAlive_sig(); break;
        case 5: _t->readyRead(); break;
        case 6: _t->start_tran(); break;
        case 7: _t->send_data(); break;
        case 8: _t->commit_tran(); break;
        case 9: _t->keepAlive(); break;
        case 10: _t->delete_data(); break;
        case 11: _t->login_usr(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UpLoadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpLoadThread::start_sig)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UpLoadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpLoadThread::send_sig)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UpLoadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpLoadThread::commit_sig)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UpLoadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpLoadThread::delete_sig)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (UpLoadThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpLoadThread::keepAlive_sig)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UpLoadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_UpLoadThread.data,
      qt_meta_data_UpLoadThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UpLoadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpLoadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UpLoadThread.stringdata0))
        return static_cast<void*>(const_cast< UpLoadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int UpLoadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void UpLoadThread::start_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UpLoadThread::send_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void UpLoadThread::commit_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void UpLoadThread::delete_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void UpLoadThread::keepAlive_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
