/****************************************************************************
** Meta object code from reading C++ file 'w_menudejeu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "w_menudejeu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_menudejeu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_W_MenuDeJeu_t {
    QByteArrayData data[9];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_W_MenuDeJeu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_W_MenuDeJeu_t qt_meta_stringdata_W_MenuDeJeu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "W_MenuDeJeu"
QT_MOC_LITERAL(1, 12, 20), // "on_pbQuitter_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "on_bpJ1Pret_clicked"
QT_MOC_LITERAL(4, 54, 19), // "on_bpJ2Pret_clicked"
QT_MOC_LITERAL(5, 74, 10), // "tankTouche"
QT_MOC_LITERAL(6, 85, 10), // "peerAdress"
QT_MOC_LITERAL(7, 96, 13), // "newConnection"
QT_MOC_LITERAL(8, 110, 20) // "on_pbPrintIP_clicked"

    },
    "W_MenuDeJeu\0on_pbQuitter_clicked\0\0"
    "on_bpJ1Pret_clicked\0on_bpJ2Pret_clicked\0"
    "tankTouche\0peerAdress\0newConnection\0"
    "on_pbPrintIP_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_W_MenuDeJeu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void W_MenuDeJeu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        W_MenuDeJeu *_t = static_cast<W_MenuDeJeu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pbQuitter_clicked(); break;
        case 1: _t->on_bpJ1Pret_clicked(); break;
        case 2: _t->on_bpJ2Pret_clicked(); break;
        case 3: _t->tankTouche((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->newConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_pbPrintIP_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject W_MenuDeJeu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_W_MenuDeJeu.data,
      qt_meta_data_W_MenuDeJeu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *W_MenuDeJeu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *W_MenuDeJeu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_W_MenuDeJeu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int W_MenuDeJeu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
