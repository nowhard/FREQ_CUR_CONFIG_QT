/****************************************************************************
** Meta object code from reading C++ file 'modbus_ascii.h'
**
** Created: Tue 18. Oct 13:57:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/modbus_ascii.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbus_ascii.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_modbus_ascii[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   14,   13,   13, 0x05,
      30,   13,   13,   13, 0x05,
      47,   14,   13,   13, 0x05,
      66,   14,   13,   13, 0x05,
      84,   14,   13,   13, 0x05,
     120,  102,   13,   13, 0x05,
     154,   13,   13,   13, 0x05,
     172,   13,   13,   13, 0x05,
     190,   13,   13,   13, 0x05,
     213,   14,   13,   13, 0x05,
     232,   14,   13,   13, 0x05,
     250,   14,   13,   13, 0x05,
     276,   14,   13,   13, 0x05,
     314,  302,   13,   13, 0x05,
     355,  351,   13,   13, 0x05,
     384,  374,   13,   13, 0x05,
     423,  415,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     462,  453,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_modbus_ascii[] = {
    "modbus_ascii\0\0OK\0CRC_OK(bool)\0"
    "FRAME_RECIEVED()\0WRITE_REG_OK(bool)\0"
    "READ_REG_OK(bool)\0SET_INFO_OK(bool)\0"
    "OK,ID,Description\0GET_INFO_OK(bool,quint16,QString)\0"
    "UNCNOWN_COMMAND()\0NOT_IMPLEMENTED()\0"
    "DEVICE_NOT_CONNECTED()\0CALIBRATE_OK(bool)\0"
    "SET_ADDR_OK(bool)\0SET_ADC_SETTINGS_OK(bool)\0"
    "SET_DAC_SETTINGS_OK(bool)\0OK,response\0"
    "GET_DEV_SETTINGS_OK(bool,QByteArray)\0"
    "reg\0IsRead(QByteArray)\0reg,value\0"
    "IsRead(MB_Register,QByteArray)\0request\0"
    "WriteToOut_Thread(QByteArray)\0response\0"
    "ResponseHandling(QByteArray)\0"
};

const QMetaObject modbus_ascii::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_modbus_ascii,
      qt_meta_data_modbus_ascii, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &modbus_ascii::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *modbus_ascii::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *modbus_ascii::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_modbus_ascii))
        return static_cast<void*>(const_cast< modbus_ascii*>(this));
    return QObject::qt_metacast(_clname);
}

int modbus_ascii::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CRC_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: FRAME_RECIEVED(); break;
        case 2: WRITE_REG_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: READ_REG_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: SET_INFO_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: GET_INFO_OK((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: UNCNOWN_COMMAND(); break;
        case 7: NOT_IMPLEMENTED(); break;
        case 8: DEVICE_NOT_CONNECTED(); break;
        case 9: CALIBRATE_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: SET_ADDR_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: SET_ADC_SETTINGS_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: SET_DAC_SETTINGS_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: GET_DEV_SETTINGS_OK((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 14: IsRead((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 15: IsRead((*reinterpret_cast< MB_Register(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 16: WriteToOut_Thread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: ResponseHandling((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void modbus_ascii::CRC_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void modbus_ascii::FRAME_RECIEVED()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void modbus_ascii::WRITE_REG_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void modbus_ascii::READ_REG_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void modbus_ascii::SET_INFO_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void modbus_ascii::GET_INFO_OK(bool _t1, quint16 _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void modbus_ascii::UNCNOWN_COMMAND()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void modbus_ascii::NOT_IMPLEMENTED()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void modbus_ascii::DEVICE_NOT_CONNECTED()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void modbus_ascii::CALIBRATE_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void modbus_ascii::SET_ADDR_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void modbus_ascii::SET_ADC_SETTINGS_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void modbus_ascii::SET_DAC_SETTINGS_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void modbus_ascii::GET_DEV_SETTINGS_OK(bool _t1, QByteArray _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void modbus_ascii::IsRead(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void modbus_ascii::IsRead(MB_Register _t1, QByteArray _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void modbus_ascii::WriteToOut_Thread(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE
