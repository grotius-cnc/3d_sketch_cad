/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../qt_occ_draw/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[84];
    char stringdata0[1807];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "zoom_plus"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "zoom_min"
QT_MOC_LITERAL(4, 31, 8), // "zoom_all"
QT_MOC_LITERAL(5, 40, 10), // "view_front"
QT_MOC_LITERAL(6, 51, 9), // "view_back"
QT_MOC_LITERAL(7, 61, 8), // "view_top"
QT_MOC_LITERAL(8, 70, 11), // "view_bottom"
QT_MOC_LITERAL(9, 82, 9), // "view_left"
QT_MOC_LITERAL(10, 92, 10), // "view_right"
QT_MOC_LITERAL(11, 103, 7), // "view_3d"
QT_MOC_LITERAL(12, 111, 15), // "draw_3d_2p_line"
QT_MOC_LITERAL(13, 127, 14), // "draw_3d_3p_arc"
QT_MOC_LITERAL(14, 142, 11), // "draw_fillet"
QT_MOC_LITERAL(15, 154, 9), // "set_color"
QT_MOC_LITERAL(16, 164, 15), // "set_input_value"
QT_MOC_LITERAL(17, 180, 4), // "text"
QT_MOC_LITERAL(18, 185, 15), // "set_plane_pos_x"
QT_MOC_LITERAL(19, 201, 5), // "value"
QT_MOC_LITERAL(20, 207, 15), // "set_plane_pos_y"
QT_MOC_LITERAL(21, 223, 15), // "set_plane_pos_z"
QT_MOC_LITERAL(22, 239, 15), // "set_plane_rot_x"
QT_MOC_LITERAL(23, 255, 15), // "set_plane_rot_y"
QT_MOC_LITERAL(24, 271, 15), // "set_plane_rot_z"
QT_MOC_LITERAL(25, 287, 14), // "set_user_plane"
QT_MOC_LITERAL(26, 302, 8), // "set_snap"
QT_MOC_LITERAL(27, 311, 8), // "set_axis"
QT_MOC_LITERAL(28, 320, 5), // "state"
QT_MOC_LITERAL(29, 326, 8), // "set_grid"
QT_MOC_LITERAL(30, 335, 9), // "set_plane"
QT_MOC_LITERAL(31, 345, 9), // "set_shape"
QT_MOC_LITERAL(32, 355, 10), // "shapevecnr"
QT_MOC_LITERAL(33, 366, 11), // "toggle_snap"
QT_MOC_LITERAL(34, 378, 12), // "toggle_ortho"
QT_MOC_LITERAL(35, 391, 31), // "on_actionorthographic_triggered"
QT_MOC_LITERAL(36, 423, 30), // "on_actionperspective_triggered"
QT_MOC_LITERAL(37, 454, 24), // "on_action_open_triggered"
QT_MOC_LITERAL(38, 479, 24), // "on_action_save_triggered"
QT_MOC_LITERAL(39, 504, 32), // "on_actionset_plane_top_triggered"
QT_MOC_LITERAL(40, 537, 33), // "on_actionset_plane_left_trigg..."
QT_MOC_LITERAL(41, 571, 34), // "on_actionset_plane_front_trig..."
QT_MOC_LITERAL(42, 606, 30), // "on_action_2p_3d_line_triggered"
QT_MOC_LITERAL(43, 637, 22), // "on_actionEsc_triggered"
QT_MOC_LITERAL(44, 660, 23), // "on_action_top_triggered"
QT_MOC_LITERAL(45, 684, 26), // "on_action_bottom_triggered"
QT_MOC_LITERAL(46, 711, 25), // "on_action_front_triggered"
QT_MOC_LITERAL(47, 737, 24), // "on_action_back_triggered"
QT_MOC_LITERAL(48, 762, 24), // "on_action_left_triggered"
QT_MOC_LITERAL(49, 787, 25), // "on_action_right_triggered"
QT_MOC_LITERAL(50, 813, 29), // "on_action_zoom_plus_triggered"
QT_MOC_LITERAL(51, 843, 28), // "on_action_zoom_min_triggered"
QT_MOC_LITERAL(52, 872, 28), // "on_action_zoom_all_triggered"
QT_MOC_LITERAL(53, 901, 27), // "on_action_view_3d_triggered"
QT_MOC_LITERAL(54, 929, 37), // "on_actionclick_plane_origin_t..."
QT_MOC_LITERAL(55, 967, 28), // "on_action3p_3d_arc_triggered"
QT_MOC_LITERAL(56, 996, 29), // "on_action_snap_center_toggled"
QT_MOC_LITERAL(57, 1026, 4), // "arg1"
QT_MOC_LITERAL(58, 1031, 26), // "on_action_snap_end_toggled"
QT_MOC_LITERAL(59, 1058, 26), // "on_action_snap_mid_toggled"
QT_MOC_LITERAL(60, 1085, 36), // "on_action_snap_perpendicular_..."
QT_MOC_LITERAL(61, 1122, 30), // "on_action_snap_nearest_toggled"
QT_MOC_LITERAL(62, 1153, 23), // "on_actionfuse_triggered"
QT_MOC_LITERAL(63, 1177, 25), // "on_actionoffset_triggered"
QT_MOC_LITERAL(64, 1203, 23), // "on_actioncopy_triggered"
QT_MOC_LITERAL(65, 1227, 25), // "on_actionmirror_triggered"
QT_MOC_LITERAL(66, 1253, 23), // "on_action_ortho_toggled"
QT_MOC_LITERAL(67, 1277, 22), // "on_action_snap_toggled"
QT_MOC_LITERAL(68, 1300, 29), // "on_action_set_color_triggered"
QT_MOC_LITERAL(69, 1330, 49), // "on_actionset_origin_plane_top..."
QT_MOC_LITERAL(70, 1380, 49), // "on_actionset_origin_plane_lef..."
QT_MOC_LITERAL(71, 1430, 49), // "on_actionset_origin_plane_fro..."
QT_MOC_LITERAL(72, 1480, 33), // "on_actionset_user_plane_trigg..."
QT_MOC_LITERAL(73, 1514, 29), // "on_action_continous_triggered"
QT_MOC_LITERAL(74, 1544, 26), // "on_action_dashed_triggered"
QT_MOC_LITERAL(75, 1571, 26), // "on_action_dottet_triggered"
QT_MOC_LITERAL(76, 1598, 25), // "on_action_mixed_triggered"
QT_MOC_LITERAL(77, 1624, 24), // "on_action_user_triggered"
QT_MOC_LITERAL(78, 1649, 26), // "on_action_hidden_triggered"
QT_MOC_LITERAL(79, 1676, 23), // "on_action_1mm_triggered"
QT_MOC_LITERAL(80, 1700, 23), // "on_action_2mm_triggered"
QT_MOC_LITERAL(81, 1724, 23), // "on_action_3mm_triggered"
QT_MOC_LITERAL(82, 1748, 27), // "on_action_save_as_triggered"
QT_MOC_LITERAL(83, 1776, 30) // "on_action_snap_tangent_toggled"

    },
    "MainWindow\0zoom_plus\0\0zoom_min\0zoom_all\0"
    "view_front\0view_back\0view_top\0view_bottom\0"
    "view_left\0view_right\0view_3d\0"
    "draw_3d_2p_line\0draw_3d_3p_arc\0"
    "draw_fillet\0set_color\0set_input_value\0"
    "text\0set_plane_pos_x\0value\0set_plane_pos_y\0"
    "set_plane_pos_z\0set_plane_rot_x\0"
    "set_plane_rot_y\0set_plane_rot_z\0"
    "set_user_plane\0set_snap\0set_axis\0state\0"
    "set_grid\0set_plane\0set_shape\0shapevecnr\0"
    "toggle_snap\0toggle_ortho\0"
    "on_actionorthographic_triggered\0"
    "on_actionperspective_triggered\0"
    "on_action_open_triggered\0"
    "on_action_save_triggered\0"
    "on_actionset_plane_top_triggered\0"
    "on_actionset_plane_left_triggered\0"
    "on_actionset_plane_front_triggered\0"
    "on_action_2p_3d_line_triggered\0"
    "on_actionEsc_triggered\0on_action_top_triggered\0"
    "on_action_bottom_triggered\0"
    "on_action_front_triggered\0"
    "on_action_back_triggered\0"
    "on_action_left_triggered\0"
    "on_action_right_triggered\0"
    "on_action_zoom_plus_triggered\0"
    "on_action_zoom_min_triggered\0"
    "on_action_zoom_all_triggered\0"
    "on_action_view_3d_triggered\0"
    "on_actionclick_plane_origin_triggered\0"
    "on_action3p_3d_arc_triggered\0"
    "on_action_snap_center_toggled\0arg1\0"
    "on_action_snap_end_toggled\0"
    "on_action_snap_mid_toggled\0"
    "on_action_snap_perpendicular_toggled\0"
    "on_action_snap_nearest_toggled\0"
    "on_actionfuse_triggered\0"
    "on_actionoffset_triggered\0"
    "on_actioncopy_triggered\0"
    "on_actionmirror_triggered\0"
    "on_action_ortho_toggled\0on_action_snap_toggled\0"
    "on_action_set_color_triggered\0"
    "on_actionset_origin_plane_top_bottom_XY_triggered\0"
    "on_actionset_origin_plane_left_right_YZ_triggered\0"
    "on_actionset_origin_plane_front_back_XZ_triggered\0"
    "on_actionset_user_plane_triggered\0"
    "on_action_continous_triggered\0"
    "on_action_dashed_triggered\0"
    "on_action_dottet_triggered\0"
    "on_action_mixed_triggered\0"
    "on_action_user_triggered\0"
    "on_action_hidden_triggered\0"
    "on_action_1mm_triggered\0on_action_2mm_triggered\0"
    "on_action_3mm_triggered\0"
    "on_action_save_as_triggered\0"
    "on_action_snap_tangent_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      77,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  399,    2, 0x08 /* Private */,
       3,    0,  400,    2, 0x08 /* Private */,
       4,    0,  401,    2, 0x08 /* Private */,
       5,    0,  402,    2, 0x08 /* Private */,
       6,    0,  403,    2, 0x08 /* Private */,
       7,    0,  404,    2, 0x08 /* Private */,
       8,    0,  405,    2, 0x08 /* Private */,
       9,    0,  406,    2, 0x08 /* Private */,
      10,    0,  407,    2, 0x08 /* Private */,
      11,    0,  408,    2, 0x08 /* Private */,
      12,    0,  409,    2, 0x08 /* Private */,
      13,    0,  410,    2, 0x08 /* Private */,
      14,    0,  411,    2, 0x08 /* Private */,
      15,    0,  412,    2, 0x08 /* Private */,
      16,    1,  413,    2, 0x08 /* Private */,
      18,    1,  416,    2, 0x08 /* Private */,
      20,    1,  419,    2, 0x08 /* Private */,
      21,    1,  422,    2, 0x08 /* Private */,
      22,    1,  425,    2, 0x08 /* Private */,
      23,    1,  428,    2, 0x08 /* Private */,
      24,    1,  431,    2, 0x08 /* Private */,
      25,    0,  434,    2, 0x08 /* Private */,
      26,    1,  435,    2, 0x08 /* Private */,
      27,    1,  438,    2, 0x08 /* Private */,
      29,    1,  441,    2, 0x08 /* Private */,
      30,    1,  444,    2, 0x08 /* Private */,
      31,    1,  447,    2, 0x08 /* Private */,
      33,    0,  450,    2, 0x08 /* Private */,
      34,    0,  451,    2, 0x08 /* Private */,
      35,    0,  452,    2, 0x08 /* Private */,
      36,    0,  453,    2, 0x08 /* Private */,
      37,    0,  454,    2, 0x08 /* Private */,
      38,    0,  455,    2, 0x08 /* Private */,
      39,    0,  456,    2, 0x08 /* Private */,
      40,    0,  457,    2, 0x08 /* Private */,
      41,    0,  458,    2, 0x08 /* Private */,
      42,    0,  459,    2, 0x08 /* Private */,
      43,    0,  460,    2, 0x08 /* Private */,
      44,    0,  461,    2, 0x08 /* Private */,
      45,    0,  462,    2, 0x08 /* Private */,
      46,    0,  463,    2, 0x08 /* Private */,
      47,    0,  464,    2, 0x08 /* Private */,
      48,    0,  465,    2, 0x08 /* Private */,
      49,    0,  466,    2, 0x08 /* Private */,
      50,    0,  467,    2, 0x08 /* Private */,
      51,    0,  468,    2, 0x08 /* Private */,
      52,    0,  469,    2, 0x08 /* Private */,
      53,    0,  470,    2, 0x08 /* Private */,
      54,    0,  471,    2, 0x08 /* Private */,
      55,    0,  472,    2, 0x08 /* Private */,
      56,    1,  473,    2, 0x08 /* Private */,
      58,    1,  476,    2, 0x08 /* Private */,
      59,    1,  479,    2, 0x08 /* Private */,
      60,    1,  482,    2, 0x08 /* Private */,
      61,    1,  485,    2, 0x08 /* Private */,
      62,    0,  488,    2, 0x08 /* Private */,
      63,    0,  489,    2, 0x08 /* Private */,
      64,    0,  490,    2, 0x08 /* Private */,
      65,    0,  491,    2, 0x08 /* Private */,
      66,    1,  492,    2, 0x08 /* Private */,
      67,    1,  495,    2, 0x08 /* Private */,
      68,    0,  498,    2, 0x08 /* Private */,
      69,    0,  499,    2, 0x08 /* Private */,
      70,    0,  500,    2, 0x08 /* Private */,
      71,    0,  501,    2, 0x08 /* Private */,
      72,    0,  502,    2, 0x08 /* Private */,
      73,    0,  503,    2, 0x08 /* Private */,
      74,    0,  504,    2, 0x08 /* Private */,
      75,    0,  505,    2, 0x08 /* Private */,
      76,    0,  506,    2, 0x08 /* Private */,
      77,    0,  507,    2, 0x08 /* Private */,
      78,    0,  508,    2, 0x08 /* Private */,
      79,    0,  509,    2, 0x08 /* Private */,
      80,    0,  510,    2, 0x08 /* Private */,
      81,    0,  511,    2, 0x08 /* Private */,
      82,    0,  512,    2, 0x08 /* Private */,
      83,    1,  513,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   57,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->zoom_plus(); break;
        case 1: _t->zoom_min(); break;
        case 2: _t->zoom_all(); break;
        case 3: _t->view_front(); break;
        case 4: _t->view_back(); break;
        case 5: _t->view_top(); break;
        case 6: _t->view_bottom(); break;
        case 7: _t->view_left(); break;
        case 8: _t->view_right(); break;
        case 9: _t->view_3d(); break;
        case 10: _t->draw_3d_2p_line(); break;
        case 11: _t->draw_3d_3p_arc(); break;
        case 12: _t->draw_fillet(); break;
        case 13: _t->set_color(); break;
        case 14: _t->set_input_value((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->set_plane_pos_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->set_plane_pos_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->set_plane_pos_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->set_plane_rot_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->set_plane_rot_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->set_plane_rot_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->set_user_plane(); break;
        case 22: _t->set_snap((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->set_axis((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->set_grid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->set_plane((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->set_shape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->toggle_snap(); break;
        case 28: _t->toggle_ortho(); break;
        case 29: _t->on_actionorthographic_triggered(); break;
        case 30: _t->on_actionperspective_triggered(); break;
        case 31: _t->on_action_open_triggered(); break;
        case 32: _t->on_action_save_triggered(); break;
        case 33: _t->on_actionset_plane_top_triggered(); break;
        case 34: _t->on_actionset_plane_left_triggered(); break;
        case 35: _t->on_actionset_plane_front_triggered(); break;
        case 36: _t->on_action_2p_3d_line_triggered(); break;
        case 37: _t->on_actionEsc_triggered(); break;
        case 38: _t->on_action_top_triggered(); break;
        case 39: _t->on_action_bottom_triggered(); break;
        case 40: _t->on_action_front_triggered(); break;
        case 41: _t->on_action_back_triggered(); break;
        case 42: _t->on_action_left_triggered(); break;
        case 43: _t->on_action_right_triggered(); break;
        case 44: _t->on_action_zoom_plus_triggered(); break;
        case 45: _t->on_action_zoom_min_triggered(); break;
        case 46: _t->on_action_zoom_all_triggered(); break;
        case 47: _t->on_action_view_3d_triggered(); break;
        case 48: _t->on_actionclick_plane_origin_triggered(); break;
        case 49: _t->on_action3p_3d_arc_triggered(); break;
        case 50: _t->on_action_snap_center_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->on_action_snap_end_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: _t->on_action_snap_mid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->on_action_snap_perpendicular_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_action_snap_nearest_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_actionfuse_triggered(); break;
        case 56: _t->on_actionoffset_triggered(); break;
        case 57: _t->on_actioncopy_triggered(); break;
        case 58: _t->on_actionmirror_triggered(); break;
        case 59: _t->on_action_ortho_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 60: _t->on_action_snap_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 61: _t->on_action_set_color_triggered(); break;
        case 62: _t->on_actionset_origin_plane_top_bottom_XY_triggered(); break;
        case 63: _t->on_actionset_origin_plane_left_right_YZ_triggered(); break;
        case 64: _t->on_actionset_origin_plane_front_back_XZ_triggered(); break;
        case 65: _t->on_actionset_user_plane_triggered(); break;
        case 66: _t->on_action_continous_triggered(); break;
        case 67: _t->on_action_dashed_triggered(); break;
        case 68: _t->on_action_dottet_triggered(); break;
        case 69: _t->on_action_mixed_triggered(); break;
        case 70: _t->on_action_user_triggered(); break;
        case 71: _t->on_action_hidden_triggered(); break;
        case 72: _t->on_action_1mm_triggered(); break;
        case 73: _t->on_action_2mm_triggered(); break;
        case 74: _t->on_action_3mm_triggered(); break;
        case 75: _t->on_action_save_as_triggered(); break;
        case 76: _t->on_action_snap_tangent_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 77)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 77;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 77)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 77;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
