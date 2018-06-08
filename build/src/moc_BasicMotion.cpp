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
    QByteArrayData data[25];
    char stringdata0[362];
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
QT_MOC_LITERAL(6, 49, 15), // "PCCheckBoxState"
QT_MOC_LITERAL(7, 65, 5), // "state"
QT_MOC_LITERAL(8, 71, 21), // "WirelessCheckBoxState"
QT_MOC_LITERAL(9, 93, 20), // "clickedConnectButton"
QT_MOC_LITERAL(10, 114, 11), // "SynchButton"
QT_MOC_LITERAL(11, 126, 14), // "processStarted"
QT_MOC_LITERAL(12, 141, 23), // "readyReadStandardOutput"
QT_MOC_LITERAL(13, 165, 17), // "startJoystickSlot"
QT_MOC_LITERAL(14, 183, 24), // "updateControllerCommands"
QT_MOC_LITERAL(15, 208, 12), // "controllerId"
QT_MOC_LITERAL(16, 221, 4), // "int*"
QT_MOC_LITERAL(17, 226, 14), // "controllerAxes"
QT_MOC_LITERAL(18, 241, 22), // "sendControllerCommands"
QT_MOC_LITERAL(19, 264, 22), // "showControllerCommands"
QT_MOC_LITERAL(20, 287, 19), // "clickedClosedButton"
QT_MOC_LITERAL(21, 307, 12), // "processEnded"
QT_MOC_LITERAL(22, 320, 8), // "exitCode"
QT_MOC_LITERAL(23, 329, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(24, 350, 11) // "existStatus"

    },
    "BasicMotion\0wheelMove\0\0stop\0robotMove\0"
    "robotMove2\0PCCheckBoxState\0state\0"
    "WirelessCheckBoxState\0clickedConnectButton\0"
    "SynchButton\0processStarted\0"
    "readyReadStandardOutput\0startJoystickSlot\0"
    "updateControllerCommands\0controllerId\0"
    "int*\0controllerAxes\0sendControllerCommands\0"
    "showControllerCommands\0clickedClosedButton\0"
    "processEnded\0exitCode\0QProcess::ExitStatus\0"
    "existStatus"
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
       5,    0,   97,    2, 0x0a /* Public */,
       6,    1,   98,    2, 0x0a /* Public */,
       8,    1,  101,    2, 0x0a /* Public */,
       9,    0,  104,    2, 0x0a /* Public */,
      10,    0,  105,    2, 0x0a /* Public */,
      11,    0,  106,    2, 0x0a /* Public */,
      12,    0,  107,    2, 0x0a /* Public */,
      13,    0,  108,    2, 0x0a /* Public */,
      14,    2,  109,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    0,  115,    2, 0x0a /* Public */,
      20,    0,  116,    2, 0x0a /* Public */,
      21,    2,  117,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 16,   15,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 23,   22,   24,

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
        case 3: _t->robotMove2(); break;
        case 4: _t->PCCheckBoxState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->WirelessCheckBoxState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->clickedConnectButton(); break;
        case 7: _t->SynchButton(); break;
        case 8: _t->processStarted(); break;
        case 9: _t->readyReadStandardOutput(); break;
        case 10: _t->startJoystickSlot(); break;
        case 11: _t->updateControllerCommands((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2]))); break;
        case 12: _t->sendControllerCommands(); break;
        case 13: _t->showControllerCommands(); break;
        case 14: _t->clickedClosedButton(); break;
        case 15: _t->processEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
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
