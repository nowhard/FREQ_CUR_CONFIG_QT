/****************************************************************************
** Meta object code from reading C++ file 'proto_uso.h'
**
** Created: Thu 26. Jul 13:49:23 2012
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
       7,   14, // methods
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
     146,  114,   10,   10, 0x0a,
     197,   49,   10,   10, 0x0a,
     251,  223,   10,   10, 0x0a,
     295,   49,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_proto_uso[] = {
    "proto_uso\0\0request\0WriteToOut_Thread(QByteArray)\0"
    "response\0DEV_INFO_RESPONSED(QByteArray)\0"
    "GET_ALL_DATA_RESPONSED()\0"
    "dev_addr,cur_4_20,up_down,value\0"
    "CHANNEL_SET_PARAMETERS_REQ(qint8,bool,bool,quint8)\0"
    "REQUEST_ERROR(QByteArray)\0"
    "dev_addr,max_freq,max_queue\0"
    "CHANNEL_SET_CALIBRATE(quint8,quint8,quint8)\0"
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
        case 3: CHANNEL_SET_PARAMETERS_REQ((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4]))); break;
        case 4: REQUEST_ERROR((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: CHANNEL_SET_CALIBRATE((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 6: ResponseHandling((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
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
