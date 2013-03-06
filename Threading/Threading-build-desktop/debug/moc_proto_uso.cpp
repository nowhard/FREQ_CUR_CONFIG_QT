/****************************************************************************
** Meta object code from reading C++ file 'proto_uso.h'
**
** Created: Tue 28. Feb 14:10:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/proto_uso.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proto_uso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_proto_uso[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x05,
      58,   49,   10,   10, 0x05,
      89,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,  114,   10,   10, 0x0a,
     147,   49,   10,   10, 0x0a,
     186,  177,   10,   10, 0x0a,
     225,  114,   10,   10, 0x0a,
     257,   49,   10,   10, 0x0a,
     342,  295,   10,   10, 0x0a,
     409,   49,   10,   10, 0x0a,
     462,  435,   10,   10, 0x0a,
     536,  510,   10,   10, 0x0a,
     590,   49,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_proto_uso[] = {
    "proto_uso\0\0request\0WriteToOut_Thread(QByteArray)\0"
    "response\0DEV_INFO_RESPONSED(QByteArray)\0"
    "GET_ALL_DATA_RESPONSED()\0dev_addr\0"
    "GET_DEV_INFO_REQ(qint8)\0"
    "GET_DEV_INFO_RESP(QByteArray)\0settings\0"
    "CHANNEL_SET_PARAMETERS_REQ(QByteArray)\0"
    "CHANNEL_ALL_GET_DATA_REQ(qint8)\0"
    "CHANNEL_ALL_GET_DATA_RESP(QByteArray)\0"
    "dev_addr,new_addr,dev_name,version,description\0"
    "CHANNEL_SET_ADDRESS_DESC(quint8,quint8,QString,QByteArray,QString)\0"
    "REQUEST_ERROR(QByteArray)\0"
    "dev_addr,channel,point,num\0"
    "CHANNEL_SET_CALIBRATE(quint8,quint8,char,ulong)\0"
    "dev_addr,channel,mode,K,C\0"
    "CHANNEL_SET_CALIBRATE(quint8,quint8,char,float,float)\0"
    "ResponseHandling(QByteArray)\0"
};

const QMetaObject proto_uso::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_proto_uso,
      qt_meta_data_proto_uso, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &proto_uso::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *proto_uso::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *proto_uso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_proto_uso))
        return static_cast<void*>(const_cast< proto_uso*>(this));
    return QObject::qt_metacast(_clname);
}

int proto_uso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: WriteToOut_Thread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: DEV_INFO_RESPONSED((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: GET_ALL_DATA_RESPONSED(); break;
        case 3: GET_DEV_INFO_REQ((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 4: GET_DEV_INFO_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: CHANNEL_SET_PARAMETERS_REQ((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: CHANNEL_ALL_GET_DATA_REQ((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 7: CHANNEL_ALL_GET_DATA_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: CHANNEL_SET_ADDRESS_DESC((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 9: REQUEST_ERROR((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: CHANNEL_SET_CALIBRATE((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3])),(*reinterpret_cast< ulong(*)>(_a[4]))); break;
        case 11: CHANNEL_SET_CALIBRATE((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 12: ResponseHandling((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void proto_uso::WriteToOut_Thread(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void proto_uso::DEV_INFO_RESPONSED(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void proto_uso::GET_ALL_DATA_RESPONSED()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
