/****************************************************************************
** Meta object code from reading C++ file 'QtPropertyEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../qt_occ_draw/QtPropertyEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtPropertyEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtPropertyEditor__QtAbstractPropertyModel_t {
    QByteArrayData data[1];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtPropertyEditor__QtAbstractPropertyModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtPropertyEditor__QtAbstractPropertyModel_t qt_meta_stringdata_QtPropertyEditor__QtAbstractPropertyModel = {
    {
QT_MOC_LITERAL(0, 0, 41) // "QtPropertyEditor::QtAbstractP..."

    },
    "QtPropertyEditor::QtAbstractPropertyModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtPropertyEditor__QtAbstractPropertyModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QtPropertyEditor::QtAbstractPropertyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QtPropertyEditor::QtAbstractPropertyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_QtPropertyEditor__QtAbstractPropertyModel.data,
    qt_meta_data_QtPropertyEditor__QtAbstractPropertyModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtPropertyEditor::QtAbstractPropertyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPropertyEditor::QtAbstractPropertyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtPropertyEditor__QtAbstractPropertyModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int QtPropertyEditor::QtAbstractPropertyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeModel_t {
    QByteArrayData data[3];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeModel_t qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeModel = {
    {
QT_MOC_LITERAL(0, 0, 37), // "QtPropertyEditor::QtPropertyT..."
QT_MOC_LITERAL(1, 38, 5), // "reset"
QT_MOC_LITERAL(2, 44, 0) // ""

    },
    "QtPropertyEditor::QtPropertyTreeModel\0"
    "reset\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtPropertyEditor__QtPropertyTreeModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QtPropertyEditor::QtPropertyTreeModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtPropertyTreeModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reset(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QtPropertyEditor::QtPropertyTreeModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyModel::staticMetaObject>(),
    qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeModel.data,
    qt_meta_data_QtPropertyEditor__QtPropertyTreeModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtPropertyEditor::QtPropertyTreeModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPropertyEditor::QtPropertyTreeModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeModel.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyModel::qt_metacast(_clname);
}

int QtPropertyEditor::QtPropertyTreeModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_QtPropertyEditor__QtPropertyTableModel_t {
    QByteArrayData data[4];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtPropertyEditor__QtPropertyTableModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtPropertyEditor__QtPropertyTableModel_t qt_meta_stringdata_QtPropertyEditor__QtPropertyTableModel = {
    {
QT_MOC_LITERAL(0, 0, 38), // "QtPropertyEditor::QtPropertyT..."
QT_MOC_LITERAL(1, 39, 15), // "rowCountChanged"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 15) // "rowOrderChanged"

    },
    "QtPropertyEditor::QtPropertyTableModel\0"
    "rowCountChanged\0\0rowOrderChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtPropertyEditor__QtPropertyTableModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtPropertyEditor::QtPropertyTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtPropertyTableModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rowCountChanged(); break;
        case 1: _t->rowOrderChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtPropertyTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtPropertyTableModel::rowCountChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtPropertyTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtPropertyTableModel::rowOrderChanged)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QtPropertyEditor::QtPropertyTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QtAbstractPropertyModel::staticMetaObject>(),
    qt_meta_stringdata_QtPropertyEditor__QtPropertyTableModel.data,
    qt_meta_data_QtPropertyEditor__QtPropertyTableModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtPropertyEditor::QtPropertyTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPropertyEditor::QtPropertyTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtPropertyEditor__QtPropertyTableModel.stringdata0))
        return static_cast<void*>(this);
    return QtAbstractPropertyModel::qt_metacast(_clname);
}

int QtPropertyEditor::QtPropertyTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractPropertyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QtPropertyEditor::QtPropertyTableModel::rowCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtPropertyEditor::QtPropertyTableModel::rowOrderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeEditor_t {
    QByteArrayData data[3];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeEditor_t qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeEditor = {
    {
QT_MOC_LITERAL(0, 0, 38), // "QtPropertyEditor::QtPropertyT..."
QT_MOC_LITERAL(1, 39, 23), // "resizeColumnsToContents"
QT_MOC_LITERAL(2, 63, 0) // ""

    },
    "QtPropertyEditor::QtPropertyTreeEditor\0"
    "resizeColumnsToContents\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtPropertyEditor__QtPropertyTreeEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QtPropertyEditor::QtPropertyTreeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtPropertyTreeEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resizeColumnsToContents(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QtPropertyEditor::QtPropertyTreeEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeEditor.data,
    qt_meta_data_QtPropertyEditor__QtPropertyTreeEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtPropertyEditor::QtPropertyTreeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPropertyEditor::QtPropertyTreeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtPropertyEditor__QtPropertyTreeEditor.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int QtPropertyEditor::QtPropertyTreeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_QtPropertyEditor__QtPropertyTableEditor_t {
    QByteArrayData data[12];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtPropertyEditor__QtPropertyTableEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtPropertyEditor__QtPropertyTableEditor_t qt_meta_stringdata_QtPropertyEditor__QtPropertyTableEditor = {
    {
QT_MOC_LITERAL(0, 0, 39), // "QtPropertyEditor::QtPropertyT..."
QT_MOC_LITERAL(1, 40, 27), // "horizontalHeaderContextMenu"
QT_MOC_LITERAL(2, 68, 0), // ""
QT_MOC_LITERAL(3, 69, 3), // "pos"
QT_MOC_LITERAL(4, 73, 25), // "verticalHeaderContextMenu"
QT_MOC_LITERAL(5, 99, 9), // "appendRow"
QT_MOC_LITERAL(6, 109, 18), // "insertSelectedRows"
QT_MOC_LITERAL(7, 128, 18), // "removeSelectedRows"
QT_MOC_LITERAL(8, 147, 17), // "handleSectionMove"
QT_MOC_LITERAL(9, 165, 12), // "logicalIndex"
QT_MOC_LITERAL(10, 178, 14), // "oldVisualIndex"
QT_MOC_LITERAL(11, 193, 14) // "newVisualIndex"

    },
    "QtPropertyEditor::QtPropertyTableEditor\0"
    "horizontalHeaderContextMenu\0\0pos\0"
    "verticalHeaderContextMenu\0appendRow\0"
    "insertSelectedRows\0removeSelectedRows\0"
    "handleSectionMove\0logicalIndex\0"
    "oldVisualIndex\0newVisualIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtPropertyEditor__QtPropertyTableEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       5,    0,   50,    2, 0x0a /* Public */,
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x0a /* Public */,
       8,    3,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,

       0        // eod
};

void QtPropertyEditor::QtPropertyTableEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtPropertyTableEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->horizontalHeaderContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->verticalHeaderContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->appendRow(); break;
        case 3: _t->insertSelectedRows(); break;
        case 4: _t->removeSelectedRows(); break;
        case 5: _t->handleSectionMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtPropertyEditor::QtPropertyTableEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableView::staticMetaObject>(),
    qt_meta_stringdata_QtPropertyEditor__QtPropertyTableEditor.data,
    qt_meta_data_QtPropertyEditor__QtPropertyTableEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtPropertyEditor::QtPropertyTableEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPropertyEditor::QtPropertyTableEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtPropertyEditor__QtPropertyTableEditor.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int QtPropertyEditor::QtPropertyTableEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
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
