#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTimer>
#include <QKeyEvent>
#include <QColorDialog>
#include <QDebug>
#include <QMessageBox>
#include <iostream>

#ifdef Success
#undef Success
#endif

//! Draw lib.
#include "draw_primitives.h"

//! Opencascade.
#include "OcctQtViewer.h"

//! Gui overlay.
#include "form.h"

//! Dxf.
#include "libdxfrw_functions.h"

//! Draw workflow.
#include "draw_workflow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update();

private slots:

    void zoom_plus();
    void zoom_min();
    void zoom_all();
    void view_front();
    void view_back();
    void view_top();
    void view_bottom();
    void view_left();
    void view_right();
    void view_3d();
    void draw_3d_2p_line();
    void draw_3d_3p_arc();
    void draw_fillet();
    void set_color();
    void set_input_value(QString text);
    void set_plane_pos_x(double value);
    void set_plane_pos_y(double value);
    void set_plane_pos_z(double value);
    void set_plane_rot_x(double value);
    void set_plane_rot_y(double value);
    void set_plane_rot_z(double value);

    void set_user_plane();
    void set_snap(double value);
    void set_axis(bool state);
    void set_grid(bool state);
    void set_plane(bool state);
    void set_shape(int shapevecnr);

    void toggle_snap();
    void toggle_ortho();

    void on_actionorthographic_triggered();

    void on_actionperspective_triggered();

    void on_action_open_triggered();

    void on_action_save_triggered();

    void on_actionset_plane_top_triggered();

    void on_actionset_plane_left_triggered();

    void on_actionset_plane_front_triggered();

    void on_action_2p_3d_line_triggered();

    void on_actionEsc_triggered();

    void on_action_top_triggered();

    void on_action_bottom_triggered();

    void on_action_front_triggered();

    void on_action_back_triggered();

    void on_action_left_triggered();

    void on_action_right_triggered();

    void on_action_zoom_plus_triggered();

    void on_action_zoom_min_triggered();

    void on_action_zoom_all_triggered();

    void on_action_view_3d_triggered();

    void on_actionclick_plane_origin_triggered();

    void on_action_snap_center_toggled(bool arg1);

    void on_action_snap_end_toggled(bool arg1);

    void on_action_snap_mid_toggled(bool arg1);

    void on_action_snap_perpendicular_toggled(bool arg1);

    void on_action_snap_nearest_toggled(bool arg1);

    void on_action_ortho_toggled(bool arg1);

    void on_action_snap_toggled(bool arg1);

    void on_action_set_color_triggered();

    void on_actionset_user_plane_triggered();

    void on_action_continous_triggered();

    void on_action_dashed_triggered();

    void on_action_dottet_triggered();

    void on_action_mixed_triggered();

    void on_action_user_triggered();

    void on_action_hidden_triggered();

    void on_action_1mm_triggered();

    void on_action_2mm_triggered();

    void on_action_3mm_triggered();

    void on_action_save_as_triggered();

    void on_action_snap_tangent_toggled(bool arg1);

    void on_action_delete_triggered();

    void on_action_3d_1p_pc_circle_triggered();

    void on_action_offset_triggered();

    void on_action_copy_triggered();

    void on_action_mirror_triggered();

    void on_action_move_triggered();

    void on_action_rotate_triggered();

    void on_action_set_plane_origin_triggered();

    void on_action_1p_point_triggered();

    void on_action_trim_triggered();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDragEventUpdate();
    void mousePostPressEvent(); //! Mouse event that is updated next cycle. For example get selection.
private:
    Ui::MainWindow *ui;

    QTimer *timer = new QTimer(this);

    OcctQtViewer *occ;

    Form *form = new Form();

    draw_primitives *draw=new draw_primitives();
    draw_workflow *work=new draw_workflow();

    int left_mouse_click_counter=0;
    int right_mouse_click_counter=0;
    bool left_mouse_pressed=0;
    bool left_mouse_dragged=0;
    gp_Pnt left_mouse_press_pos;
    int oldkey;
    double snap_size=5;
    double keyboard_input=0;
    QString filename, keyboard_text;
    double keyboard_value=0;
    gp_Pnt p;
    bool show_axis=0, show_grid=0, show_plane=0;
    int next=0;

    int mySelectedShape=0;
    bool myMousePostCycle=0;

    QString myFilePath;
};
#endif
