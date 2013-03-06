/****************************************************************************
** Meta object code from reading C++ file 'modbus_rtu.h'
**
** Created: Tue 18. Oct 13:57:49 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/modbus_rtu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbus_rtu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Modbus_RTU[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,
      28,   12,   11,   11, 0x05,
      47,   12,   11,   11, 0x05,
      65,   11,   11,   11, 0x05,
      83,   11,   11,   11, 0x05,
     101,   11,   11,   11, 0x05,
     130,  124,   11,   11, 0x05,
     155,  151,   11,   11, 0x05,
     184,  174,   11,   11, 0x05,
     223,  215,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     262,  253,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Modbus_RTU[] = {
    "Modbus_RTU\0\0OK\0CRC_OK(bool)\0"
    "WRITE_REG_OK(bool)\0READ_REG_OK(bool)\0"
    "UNCNOWN_COMMAND()\0NOT_IMPLEMENTED()\0"
    "DEVICE_NOT_CONNECTED()\0point\0"
    "CALIBRATE_OK(quint8)\0reg\0IsRead(QByteArray)\0"
    "reg,value\0IsRead(MB_Register,QByteArray)\0"
    "request\0WriteToOut_Thread(QByteArray)\0"
    "response\0ResponseHandling(QByteArray)\0"
};

const QMetaObject Modbus_RTU::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Modbus_RTU,
      qt_meta_data_Modbus_RTU, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Modbus_RTU::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Modbus_RTU::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Modbus_RTU::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Modbus_RTU))
        return static_cast<void*>(const_cast< Modbus_RTU*>(this));
    return QObject::qt_metacast(_clname);
}

int Modbus_RTU::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CRC_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: WRITE_REG_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: READ_REG_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: UNCNOWN_COMMAND(); break;
        case 4: NOT_IMPLEMENTED(); break;
        case 5: DEVICE_NOT_CONNECTED(); break;
        case 6: CALIBRATE_OK((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 7: IsRead((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: IsRead((*reinterpret_cast< MB_Register(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 9: WriteToOut_Thread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: ResponseHandling((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Modbus_RTU::CRC_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Modbus_RTU::WRITE_REG_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Modbus_RTU::READ_REG_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Modbus_RTU::UNCNOWN_COMMAND()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Modbus_RTU::NOT_IMPLEMENTED()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Modbus_RTU::DEVICE_NOT_CONNECTED()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Modbus_RTU::CALIBRATE_OK(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Modbus_RTU::IsRead(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Modbus_RTU::IsRead(MB_Register _t1, QByteArray _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Modbus_RTU::WriteToOut_Thread(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
