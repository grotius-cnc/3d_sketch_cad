/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionorthographic;
    QAction *actionperspective;
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionset_plane_top;
    QAction *actionset_plane_left;
    QAction *actionset_plane_front;
    QAction *action_ortho;
    QAction *action_snap_center;
    QAction *action_snap_end;
    QAction *action2p_3d_line;
    QAction *action3p_3d_arc;
    QAction *action1p_point;
    QAction *action2p_pc_arc;
    QAction *action1p_pc_circe;
    QAction *actiontop;
    QAction *actionbottom;
    QAction *actionfront;
    QAction *actionback;
    QAction *actionleft;
    QAction *actionright;
    QAction *actionzoom_plus;
    QAction *actionzoom_min;
    QAction *actionzoom_all;
    QAction *actionview_3d;
    QAction *actionellipse;
    QAction *actionpolygon;
    QAction *actionlinestrip;
    QAction *actionspline;
    QAction *actionbezier;
    QAction *action3p_circle;
    QAction *action_snap_mid;
    QAction *action_snap_perpendicular;
    QAction *action_snap_nearest;
    QAction *actionfuse;
    QAction *actionoffset;
    QAction *actioncopy;
    QAction *actionmirror;
    QAction *action_snap;
    QAction *action_set_color;
    QAction *actionset_origin_plane_top_bottom_XY;
    QAction *actionset_origin_plane_left_right_YZ;
    QAction *actionset_origin_plane_front_back_XZ;
    QAction *actionset_user_plane;
    QAction *action_continous;
    QAction *action_dashed;
    QAction *action_dottet;
    QAction *action_mixed;
    QAction *action_user;
    QAction *action_hidden;
    QAction *action_1mm;
    QAction *action_2mm;
    QAction *action_3mm;
    QAction *actiontestaction;
    QAction *action_left_menu;
    QAction *action_save_as;
    QAction *action_snap_tangent;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_occ;
    QMenuBar *menubar;
    QMenu *menuview;
    QMenu *menuviewmode;
    QMenu *menufile;
    QMenu *menuplane;
    QMenu *menuortho;
    QMenu *menusnap;
    QMenu *menudraw;
    QMenu *menuset_linetype;
    QMenu *menuset_linewidth;
    QMenu *menumodify;
    QMenu *menuhelp;
    QMenu *menumenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 800);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        MainWindow->setIconSize(QSize(30, 30));
        actionorthographic = new QAction(MainWindow);
        actionorthographic->setObjectName(QString::fromUtf8("actionorthographic"));
        actionperspective = new QAction(MainWindow);
        actionperspective->setObjectName(QString::fromUtf8("actionperspective"));
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionset_plane_top = new QAction(MainWindow);
        actionset_plane_top->setObjectName(QString::fromUtf8("actionset_plane_top"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/vendor/icons/view-top.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionset_plane_top->setIcon(icon);
        actionset_plane_left = new QAction(MainWindow);
        actionset_plane_left->setObjectName(QString::fromUtf8("actionset_plane_left"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/vendor/icons/view-left.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionset_plane_left->setIcon(icon1);
        actionset_plane_front = new QAction(MainWindow);
        actionset_plane_front->setObjectName(QString::fromUtf8("actionset_plane_front"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/vendor/icons/view-front.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionset_plane_front->setIcon(icon2);
        action_ortho = new QAction(MainWindow);
        action_ortho->setObjectName(QString::fromUtf8("action_ortho"));
        action_ortho->setCheckable(true);
        action_ortho->setChecked(false);
        action_snap_center = new QAction(MainWindow);
        action_snap_center->setObjectName(QString::fromUtf8("action_snap_center"));
        action_snap_center->setCheckable(true);
        action_snap_center->setChecked(false);
        action_snap_end = new QAction(MainWindow);
        action_snap_end->setObjectName(QString::fromUtf8("action_snap_end"));
        action_snap_end->setCheckable(true);
        action_snap_end->setChecked(false);
        action2p_3d_line = new QAction(MainWindow);
        action2p_3d_line->setObjectName(QString::fromUtf8("action2p_3d_line"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/line.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action2p_3d_line->setIcon(icon3);
        action3p_3d_arc = new QAction(MainWindow);
        action3p_3d_arc->setObjectName(QString::fromUtf8("action3p_3d_arc"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/arc.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action3p_3d_arc->setIcon(icon4);
        action1p_point = new QAction(MainWindow);
        action1p_point->setObjectName(QString::fromUtf8("action1p_point"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/point.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action1p_point->setIcon(icon5);
        action2p_pc_arc = new QAction(MainWindow);
        action2p_pc_arc->setObjectName(QString::fromUtf8("action2p_pc_arc"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action2p_pc_arc->setIcon(icon6);
        action1p_pc_circe = new QAction(MainWindow);
        action1p_pc_circe->setObjectName(QString::fromUtf8("action1p_pc_circe"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/rectangle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action1p_pc_circe->setIcon(icon7);
        actiontop = new QAction(MainWindow);
        actiontop->setObjectName(QString::fromUtf8("actiontop"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/view-top.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actiontop->setIcon(icon8);
        actionbottom = new QAction(MainWindow);
        actionbottom->setObjectName(QString::fromUtf8("actionbottom"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/view-bottom.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionbottom->setIcon(icon9);
        actionfront = new QAction(MainWindow);
        actionfront->setObjectName(QString::fromUtf8("actionfront"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/view-front.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionfront->setIcon(icon10);
        actionback = new QAction(MainWindow);
        actionback->setObjectName(QString::fromUtf8("actionback"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/view-back.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionback->setIcon(icon11);
        actionleft = new QAction(MainWindow);
        actionleft->setObjectName(QString::fromUtf8("actionleft"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/view-left.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionleft->setIcon(icon12);
        actionright = new QAction(MainWindow);
        actionright->setObjectName(QString::fromUtf8("actionright"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/view-right.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionright->setIcon(icon13);
        actionzoom_plus = new QAction(MainWindow);
        actionzoom_plus->setObjectName(QString::fromUtf8("actionzoom_plus"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/zoom_plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionzoom_plus->setIcon(icon14);
        actionzoom_min = new QAction(MainWindow);
        actionzoom_min->setObjectName(QString::fromUtf8("actionzoom_min"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/zoom_min.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionzoom_min->setIcon(icon15);
        actionzoom_all = new QAction(MainWindow);
        actionzoom_all->setObjectName(QString::fromUtf8("actionzoom_all"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/zoom_extend.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionzoom_all->setIcon(icon16);
        actionview_3d = new QAction(MainWindow);
        actionview_3d->setObjectName(QString::fromUtf8("actionview_3d"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/view-iso.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionview_3d->setIcon(icon17);
        actionellipse = new QAction(MainWindow);
        actionellipse->setObjectName(QString::fromUtf8("actionellipse"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/ellipse.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionellipse->setIcon(icon18);
        actionpolygon = new QAction(MainWindow);
        actionpolygon->setObjectName(QString::fromUtf8("actionpolygon"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons/polygon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionpolygon->setIcon(icon19);
        actionlinestrip = new QAction(MainWindow);
        actionlinestrip->setObjectName(QString::fromUtf8("actionlinestrip"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons/linestrip.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionlinestrip->setIcon(icon20);
        actionspline = new QAction(MainWindow);
        actionspline->setObjectName(QString::fromUtf8("actionspline"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons/spline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionspline->setIcon(icon21);
        actionbezier = new QAction(MainWindow);
        actionbezier->setObjectName(QString::fromUtf8("actionbezier"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons/cubicbezcurve.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionbezier->setIcon(icon22);
        action3p_circle = new QAction(MainWindow);
        action3p_circle->setObjectName(QString::fromUtf8("action3p_circle"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons/circle_3p.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action3p_circle->setIcon(icon23);
        action_snap_mid = new QAction(MainWindow);
        action_snap_mid->setObjectName(QString::fromUtf8("action_snap_mid"));
        action_snap_mid->setCheckable(true);
        action_snap_mid->setChecked(false);
        action_snap_perpendicular = new QAction(MainWindow);
        action_snap_perpendicular->setObjectName(QString::fromUtf8("action_snap_perpendicular"));
        action_snap_perpendicular->setCheckable(true);
        action_snap_perpendicular->setChecked(false);
        action_snap_nearest = new QAction(MainWindow);
        action_snap_nearest->setObjectName(QString::fromUtf8("action_snap_nearest"));
        action_snap_nearest->setCheckable(true);
        actionfuse = new QAction(MainWindow);
        actionfuse->setObjectName(QString::fromUtf8("actionfuse"));
        actionoffset = new QAction(MainWindow);
        actionoffset->setObjectName(QString::fromUtf8("actionoffset"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons/offset.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionoffset->setIcon(icon24);
        actioncopy = new QAction(MainWindow);
        actioncopy->setObjectName(QString::fromUtf8("actioncopy"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/icons/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actioncopy->setIcon(icon25);
        actionmirror = new QAction(MainWindow);
        actionmirror->setObjectName(QString::fromUtf8("actionmirror"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/icons/mirror.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionmirror->setIcon(icon26);
        action_snap = new QAction(MainWindow);
        action_snap->setObjectName(QString::fromUtf8("action_snap"));
        action_snap->setCheckable(true);
        action_set_color = new QAction(MainWindow);
        action_set_color->setObjectName(QString::fromUtf8("action_set_color"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/icons/format-stroke-color.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_set_color->setIcon(icon27);
        actionset_origin_plane_top_bottom_XY = new QAction(MainWindow);
        actionset_origin_plane_top_bottom_XY->setObjectName(QString::fromUtf8("actionset_origin_plane_top_bottom_XY"));
        actionset_origin_plane_left_right_YZ = new QAction(MainWindow);
        actionset_origin_plane_left_right_YZ->setObjectName(QString::fromUtf8("actionset_origin_plane_left_right_YZ"));
        actionset_origin_plane_front_back_XZ = new QAction(MainWindow);
        actionset_origin_plane_front_back_XZ->setObjectName(QString::fromUtf8("actionset_origin_plane_front_back_XZ"));
        actionset_user_plane = new QAction(MainWindow);
        actionset_user_plane->setObjectName(QString::fromUtf8("actionset_user_plane"));
        action_continous = new QAction(MainWindow);
        action_continous->setObjectName(QString::fromUtf8("action_continous"));
        action_dashed = new QAction(MainWindow);
        action_dashed->setObjectName(QString::fromUtf8("action_dashed"));
        action_dottet = new QAction(MainWindow);
        action_dottet->setObjectName(QString::fromUtf8("action_dottet"));
        action_mixed = new QAction(MainWindow);
        action_mixed->setObjectName(QString::fromUtf8("action_mixed"));
        action_user = new QAction(MainWindow);
        action_user->setObjectName(QString::fromUtf8("action_user"));
        action_hidden = new QAction(MainWindow);
        action_hidden->setObjectName(QString::fromUtf8("action_hidden"));
        action_1mm = new QAction(MainWindow);
        action_1mm->setObjectName(QString::fromUtf8("action_1mm"));
        action_2mm = new QAction(MainWindow);
        action_2mm->setObjectName(QString::fromUtf8("action_2mm"));
        action_3mm = new QAction(MainWindow);
        action_3mm->setObjectName(QString::fromUtf8("action_3mm"));
        actiontestaction = new QAction(MainWindow);
        actiontestaction->setObjectName(QString::fromUtf8("actiontestaction"));
        action_left_menu = new QAction(MainWindow);
        action_left_menu->setObjectName(QString::fromUtf8("action_left_menu"));
        action_left_menu->setCheckable(true);
        action_save_as = new QAction(MainWindow);
        action_save_as->setObjectName(QString::fromUtf8("action_save_as"));
        action_snap_tangent = new QAction(MainWindow);
        action_snap_tangent->setObjectName(QString::fromUtf8("action_snap_tangent"));
        action_snap_tangent->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setCursor(QCursor(Qt::ArrowCursor));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_occ = new QGridLayout();
        gridLayout_occ->setSpacing(0);
        gridLayout_occ->setObjectName(QString::fromUtf8("gridLayout_occ"));

        gridLayout->addLayout(gridLayout_occ, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuview = new QMenu(menubar);
        menuview->setObjectName(QString::fromUtf8("menuview"));
        menuviewmode = new QMenu(menuview);
        menuviewmode->setObjectName(QString::fromUtf8("menuviewmode"));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuplane = new QMenu(menubar);
        menuplane->setObjectName(QString::fromUtf8("menuplane"));
        menuortho = new QMenu(menubar);
        menuortho->setObjectName(QString::fromUtf8("menuortho"));
        menusnap = new QMenu(menubar);
        menusnap->setObjectName(QString::fromUtf8("menusnap"));
        menudraw = new QMenu(menubar);
        menudraw->setObjectName(QString::fromUtf8("menudraw"));
        menuset_linetype = new QMenu(menudraw);
        menuset_linetype->setObjectName(QString::fromUtf8("menuset_linetype"));
        menuset_linewidth = new QMenu(menudraw);
        menuset_linewidth->setObjectName(QString::fromUtf8("menuset_linewidth"));
        menumodify = new QMenu(menubar);
        menumodify->setObjectName(QString::fromUtf8("menumodify"));
        menuhelp = new QMenu(menubar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        menumenu = new QMenu(menubar);
        menumenu->setObjectName(QString::fromUtf8("menumenu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menufile->menuAction());
        menubar->addAction(menuview->menuAction());
        menubar->addAction(menuplane->menuAction());
        menubar->addAction(menuortho->menuAction());
        menubar->addAction(menusnap->menuAction());
        menubar->addAction(menudraw->menuAction());
        menubar->addAction(menumodify->menuAction());
        menubar->addAction(menuhelp->menuAction());
        menubar->addAction(menumenu->menuAction());
        menuview->addAction(menuviewmode->menuAction());
        menuview->addAction(actionview_3d);
        menuview->addAction(actiontop);
        menuview->addAction(actionbottom);
        menuview->addAction(actionfront);
        menuview->addAction(actionback);
        menuview->addAction(actionleft);
        menuview->addAction(actionright);
        menuview->addAction(actionzoom_plus);
        menuview->addAction(actionzoom_min);
        menuview->addAction(actionzoom_all);
        menuviewmode->addAction(actionorthographic);
        menuviewmode->addAction(actionperspective);
        menufile->addAction(actionopen);
        menufile->addAction(actionsave);
        menufile->addAction(action_save_as);
        menuplane->addAction(actionset_plane_top);
        menuplane->addAction(actionset_plane_left);
        menuplane->addAction(actionset_plane_front);
        menuplane->addAction(actionset_origin_plane_top_bottom_XY);
        menuplane->addAction(actionset_origin_plane_left_right_YZ);
        menuplane->addAction(actionset_origin_plane_front_back_XZ);
        menuplane->addAction(actionset_user_plane);
        menuortho->addAction(action_ortho);
        menusnap->addAction(action_snap);
        menusnap->addAction(action_snap_center);
        menusnap->addAction(action_snap_end);
        menusnap->addAction(action_snap_mid);
        menusnap->addAction(action_snap_perpendicular);
        menusnap->addAction(action_snap_tangent);
        menusnap->addAction(action_snap_nearest);
        menudraw->addAction(menuset_linetype->menuAction());
        menudraw->addAction(menuset_linewidth->menuAction());
        menudraw->addAction(action_set_color);
        menudraw->addAction(action1p_point);
        menudraw->addAction(action2p_3d_line);
        menudraw->addAction(actionlinestrip);
        menudraw->addAction(action3p_3d_arc);
        menudraw->addAction(action2p_pc_arc);
        menudraw->addAction(action3p_circle);
        menudraw->addAction(action1p_pc_circe);
        menudraw->addAction(actionellipse);
        menudraw->addAction(actionpolygon);
        menudraw->addAction(actionspline);
        menudraw->addAction(actionbezier);
        menuset_linetype->addAction(action_hidden);
        menuset_linetype->addAction(action_continous);
        menuset_linetype->addAction(action_dashed);
        menuset_linetype->addAction(action_dottet);
        menuset_linetype->addAction(action_mixed);
        menuset_linetype->addAction(action_user);
        menuset_linewidth->addAction(action_1mm);
        menuset_linewidth->addAction(action_2mm);
        menuset_linewidth->addAction(action_3mm);
        menumodify->addAction(actionfuse);
        menumodify->addAction(actionoffset);
        menumodify->addAction(actioncopy);
        menumodify->addAction(actionmirror);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3d draw", nullptr));
        actionorthographic->setText(QCoreApplication::translate("MainWindow", "orthographic", nullptr));
        actionperspective->setText(QCoreApplication::translate("MainWindow", "perspective", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        actionset_plane_top->setText(QCoreApplication::translate("MainWindow", "set plane top-bottom XY", nullptr));
        actionset_plane_left->setText(QCoreApplication::translate("MainWindow", "set plane left-right YZ", nullptr));
        actionset_plane_front->setText(QCoreApplication::translate("MainWindow", "set plane front-back XZ", nullptr));
        action_ortho->setText(QCoreApplication::translate("MainWindow", "ortho F8", nullptr));
#if QT_CONFIG(tooltip)
        action_ortho->setToolTip(QCoreApplication::translate("MainWindow", "ortho ", nullptr));
#endif // QT_CONFIG(tooltip)
        action_snap_center->setText(QCoreApplication::translate("MainWindow", "snap center", nullptr));
        action_snap_end->setText(QCoreApplication::translate("MainWindow", "snap end", nullptr));
        action2p_3d_line->setText(QCoreApplication::translate("MainWindow", "2p_line", nullptr));
        action3p_3d_arc->setText(QCoreApplication::translate("MainWindow", "3p_arc", nullptr));
        action1p_point->setText(QCoreApplication::translate("MainWindow", "1p_point", nullptr));
        action2p_pc_arc->setText(QCoreApplication::translate("MainWindow", "1p_pc_circle", nullptr));
        action1p_pc_circe->setText(QCoreApplication::translate("MainWindow", "2p_rectangular", nullptr));
        actiontop->setText(QCoreApplication::translate("MainWindow", "top", nullptr));
        actionbottom->setText(QCoreApplication::translate("MainWindow", "bottom", nullptr));
        actionfront->setText(QCoreApplication::translate("MainWindow", "front", nullptr));
        actionback->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        actionleft->setText(QCoreApplication::translate("MainWindow", "left", nullptr));
        actionright->setText(QCoreApplication::translate("MainWindow", "right", nullptr));
        actionzoom_plus->setText(QCoreApplication::translate("MainWindow", "zoom plus", nullptr));
        actionzoom_min->setText(QCoreApplication::translate("MainWindow", "zoom min", nullptr));
        actionzoom_all->setText(QCoreApplication::translate("MainWindow", "zoom all", nullptr));
        actionview_3d->setText(QCoreApplication::translate("MainWindow", "view 3d", nullptr));
        actionellipse->setText(QCoreApplication::translate("MainWindow", "3p_pc_ellipse", nullptr));
        actionpolygon->setText(QCoreApplication::translate("MainWindow", "2p_polygon", nullptr));
        actionlinestrip->setText(QCoreApplication::translate("MainWindow", "linestrip", nullptr));
        actionspline->setText(QCoreApplication::translate("MainWindow", "xp_spline", nullptr));
        actionbezier->setText(QCoreApplication::translate("MainWindow", "4p_bezier", nullptr));
        action3p_circle->setText(QCoreApplication::translate("MainWindow", "3p_circle", nullptr));
        action_snap_mid->setText(QCoreApplication::translate("MainWindow", "snap mid", nullptr));
        action_snap_perpendicular->setText(QCoreApplication::translate("MainWindow", "snap perpendicular", nullptr));
        action_snap_nearest->setText(QCoreApplication::translate("MainWindow", "snap nearest", nullptr));
        actionfuse->setText(QCoreApplication::translate("MainWindow", "fuse", nullptr));
        actionoffset->setText(QCoreApplication::translate("MainWindow", "offset", nullptr));
        actioncopy->setText(QCoreApplication::translate("MainWindow", "copy", nullptr));
        actionmirror->setText(QCoreApplication::translate("MainWindow", "mirror", nullptr));
        action_snap->setText(QCoreApplication::translate("MainWindow", "snap F3", nullptr));
        action_set_color->setText(QCoreApplication::translate("MainWindow", "set color", nullptr));
        actionset_origin_plane_top_bottom_XY->setText(QCoreApplication::translate("MainWindow", "set origin plane top_bottom XY", nullptr));
        actionset_origin_plane_left_right_YZ->setText(QCoreApplication::translate("MainWindow", "set origin plane left_right YZ", nullptr));
        actionset_origin_plane_front_back_XZ->setText(QCoreApplication::translate("MainWindow", "set origin plane front_back XZ", nullptr));
        actionset_user_plane->setText(QCoreApplication::translate("MainWindow", "set user plane", nullptr));
        action_continous->setText(QCoreApplication::translate("MainWindow", "continuous", nullptr));
        action_dashed->setText(QCoreApplication::translate("MainWindow", "dashed 2.0,1.0 (MM)", nullptr));
        action_dottet->setText(QCoreApplication::translate("MainWindow", "dotted 0.2,0.5 (MM)", nullptr));
        action_mixed->setText(QCoreApplication::translate("MainWindow", "mixed  10.0,1.0,2.0,1.0 (MM)", nullptr));
        action_user->setText(QCoreApplication::translate("MainWindow", "user defined", nullptr));
        action_hidden->setText(QCoreApplication::translate("MainWindow", "hidden", nullptr));
        action_1mm->setText(QCoreApplication::translate("MainWindow", "1mm", nullptr));
        action_2mm->setText(QCoreApplication::translate("MainWindow", "2mm", nullptr));
        action_3mm->setText(QCoreApplication::translate("MainWindow", "3mm", nullptr));
        actiontestaction->setText(QCoreApplication::translate("MainWindow", "testaction", nullptr));
        action_left_menu->setText(QCoreApplication::translate("MainWindow", "left menu no animation", nullptr));
        action_save_as->setText(QCoreApplication::translate("MainWindow", "save as", nullptr));
        action_snap_tangent->setText(QCoreApplication::translate("MainWindow", "snap tangent", nullptr));
        menuview->setTitle(QCoreApplication::translate("MainWindow", "view", nullptr));
        menuviewmode->setTitle(QCoreApplication::translate("MainWindow", "viewmode", nullptr));
        menufile->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
        menuplane->setTitle(QCoreApplication::translate("MainWindow", "plane", nullptr));
        menuortho->setTitle(QCoreApplication::translate("MainWindow", "ortho", nullptr));
        menusnap->setTitle(QCoreApplication::translate("MainWindow", "snap", nullptr));
        menudraw->setTitle(QCoreApplication::translate("MainWindow", "draw", nullptr));
        menuset_linetype->setTitle(QCoreApplication::translate("MainWindow", "set linetype", nullptr));
        menuset_linewidth->setTitle(QCoreApplication::translate("MainWindow", "set linewidth", nullptr));
        menumodify->setTitle(QCoreApplication::translate("MainWindow", "modify", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("MainWindow", "help", nullptr));
        menumenu->setTitle(QCoreApplication::translate("MainWindow", "menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
