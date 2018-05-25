/****************************************************************************
** Meta object code from reading C++ file 'BasicMotion.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/BasicMotion.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BasicMotion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BasicMotion_t {
    QByteArrayData data[23];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasicMotion_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasicMotion_t qt_meta_stringdata_BasicMotion = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BasicMotion"
QT_MOC_LITERAL(1, 12, 9), // "wheelMove"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "stop"
QT_MOC_LITERAL(4, 28, 9), // "robotMove"
QT_MOC_LITERAL(5, 38, 10), // "robotMove2"
QT_MOC_LITERAL(6, 49, 10), // "controller"
QT_MOC_LITERAL(7, 60, 15), // "PCCheckBoxState"
QT_MOC_LITERAL(8, 76, 5), // "state"
QT_MOC_LITERAL(9, 82, 21), // "WirelessCheckBoxState"
QT_MOC_LITERAL(10, 104, 20), // "clickedConnectButton"
QT_MOC_LITERAL(11, 125, 11), // "SynchButton"
QT_MOC_LITERAL(12, 137, 14), // "processStarted"
QT_MOC_LITERAL(13, 152, 24), // "readyReadStandardOutput1"
QT_MOC_LITERAL(14, 177, 18), // "startJoystickSlot1"
QT_MOC_LITERAL(15, 196, 18), // "startJoystickSlot2"
QT_MOC_LITERAL(16, 215, 24), // "updateControllerCommands"
QT_MOC_LITERAL(17, 240, 12), // "controllerId"
QT_MOC_LITERAL(18, 253, 4), // "int*"
QT_MOC_LITERAL(19, 258, 14), // "controllerAxes"
QT_MOC_LITERAL(20, 273, 23), // "sendControllerCommands1"
QT_MOC_LITERAL(21, 297, 23), // "sendControllerCommands2"
QT_MOC_LITERAL(22, 321, 19) // "clickedClosedButton"

    },
    "BasicMotion\0wheelMove\0\0stop\0robotMove\0"
    "robotMove2\0controller\0PCCheckBoxState\0"
    "state\0WirelessCheckBoxState\0"
    "clickedConnectButton\0SynchButton\0"
    "processStarted\0readyReadStandardOutput1\0"
    "startJoystickSlot1\0startJoystickSlot2\0"
    "updateControllerCommands\0controllerId\0"
    "int*\0controllerAxes\0sendControllerCommands1\0"
    "sendControllerCommands2\0clickedClosedButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasicMotion[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    1,   97,    2, 0x0a /* Public */,
       7,    1,  100,    2, 0x0a /* Public */,
       9,    1,  103,    2, 0x0a /* Public */,
      10,    0,  106,    2, 0x0a /* Public */,
      11,    0,  107,    2, 0x0a /* Public */,
      12,    0,  108,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x0a /* Public */,
      14,    0,  110,    2, 0x0a /* Public */,
      15,    0,  111,    2, 0x0a /* Public */,
      16,    2,  112,    2, 0x0a /* Public */,
      20,    0,  117,    2, 0x0a /* Public */,
      21,    0,  118,    2, 0x0a /* Public */,
      22,    0,  119,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 18,   17,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BasicMotion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BasicMotion *_t = static_cast<BasicMotion *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wheelMove(); break;
        case 1: _t->stop(); break;
        case 2: _t->robotMove(); break;
        case 3: _t->robotMove2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->PCCheckBoxState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->WirelessCheckBoxState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->clickedConnectButton(); break;
        case 7: _t->SynchButton(); break;
        case 8: _t->processStarted(); break;
        case 9: _t->readyReadStandardOutput1(); break;
        case 10: _t->startJoystickSlot1(); break;
        case 11: _t->startJoystickSlot2(); break;
        case 12: _t->updateControllerCommands((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2]))); break;
        case 13: _t->sendControllerCommands1(); break;
        case 14: _t->sendControllerCommands2(); break;
        case 15: _t->clickedClosedButton(); break;
        default: ;
        }
    }
}

const QMetaObject BasicMotion::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BasicMotion.data,
      qt_meta_data_BasicMotion,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BasicMotion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasicMotion::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BasicMotion.stringdata0))
        return static_cast<void*>(const_cast< BasicMotion*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BasicMotion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
