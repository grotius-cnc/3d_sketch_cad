#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "gp_Pnt.hxx"
#include "gp_Pln.hxx"
#include "AIS_InteractiveContext.hxx"
#include "AIS_Shape.hxx"

#include "qleftmenu.h"
#include "draw_primitives.h"
#include "vector"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    QLeftMenu *lmenu;

signals:

    void lineEdit_input_returnPressed(QString text);
    void lineEdit_plane_pos_x_returnPressed(double value);
    void lineEdit_plane_pos_y_returnPressed(double value);
    void lineEdit_plane_pos_z_returnPressed(double value);
    void lineEdit_plane_rot_x_returnPressed(double value);
    void lineEdit_plane_rot_y_returnPressed(double value);
    void lineEdit_plane_rot_z_returnPressed(double value);
    void lineEdit_snap_returnPressed(double value);
    void checkBox_axis_toggled(bool checked);
    void checkBox_grid_toggled(bool checked);
    void checkBox_plane_toggled(bool checked);
    void checkBox_lock_toggled(bool checked);
    void toolButton_set_shape_values_pressed(int shapevecnr);
    void toolButton_ortho_pressed();
    void toolButton_snap_pressed();
    void toolButton_draw_line_pressed();
    void toolButton_draw_arc_pressed();
    void toolButton_draw_circle_pressed();
    void toolButton_view_3d_pressed();
    void toolButton_view_top_pressed();
    void toolButton_view_bottom_pressed();
    void toolButton_view_left_pressed();
    void toolButton_view_right_pressed();
    void toolButton_view_front_pressed();
    void toolButton_view_back_pressed();
    void toolButton_document_save_pressed();
    void toolButton_document_save_as_pressed();
    void toolButton_document_open_pressed();
    void toolButton_delete_selected_shapes_pressed();
    void toolButton_offset_pressed();
    void toolButton_copy_pressed();
    void toolButton_rotate_pressed();
    void toolButton_mirror_pressed();
    void toolButton_move_pressed();
    void toolButton_set_plane_origin_pressed();
    void toolButton_draw_point_pressed();

public slots:

    void set_text(QString text);
    void set_mousepos(gp_Pnt mouse);
    void set_planepos(gp_Pln plane);
    void set_planepos(gp_Pnt pos);
    void set_planeangle(double angle_x, double angle_y, double angle_z);
    void set_ortho_state(bool state);
    void set_color(QString stylesheet_text);
    void set_snap_state(bool state);
    void set_linetype(QString type);
    void set_linewidth(double value);
    void set_property_widget(std::vector<Handle(AIS_Shape)> shapevec, int shapenr);
    bool is_hovered();
    double snap_size();
    Handle(AIS_Shape) get_property_widget();

private slots:

    void on_lineEdit_input_returnPressed();

    void on_lineEdit_plane_pos_x_returnPressed();

    void on_lineEdit_plane_pos_y_returnPressed();

    void on_lineEdit_plane_pos_z_returnPressed();

    void on_lineEdit_plane_rot_x_returnPressed();

    void on_lineEdit_plane_rot_y_returnPressed();

    void on_lineEdit_plane_rot_z_returnPressed();

    void on_lineEdit_snap_returnPressed();

    void on_checkBox_axis_toggled(bool checked);

    void on_checkBox_grid_toggled(bool checked);

    void on_checkBox_plane_toggled(bool checked);

    void on_toolButton_set_shape_values_pressed();

    void on_doubleSpinBox_color_red_valueChanged(double arg1);

    void on_doubleSpinBox_color_green_valueChanged(double arg1);

    void on_doubleSpinBox_color_blue_valueChanged(double arg1);

    void on_toolButton_choose_color_pressed();

    void on_doubleSpinBox_transparancy_valueChanged(double arg1);

    void on_toolButton_ortho_pressed();

    void on_toolButton_snap_pressed();

    void on_toolButton_draw_line_pressed();

    void on_toolButton_draw_arc_pressed();

    void on_toolButton_draw_circle_pressed();

    void on_toolButton_view_3d_pressed();

    void on_toolButton_view_top_pressed();

    void on_toolButton_view_bottom_pressed();

    void on_toolButton_view_front_pressed();

    void on_toolButton_view_back_pressed();

    void on_toolButton_view_left_pressed();

    void on_toolButton_view_right_pressed();

    void on_toolButton_document_open_pressed();

    void on_toolButton_document_save_pressed();

    void on_toolButton_document_save_as_pressed();

    void on_toolButton_delete_selected_shapes_pressed();

    void on_toolButton_offset_pressed();

    void on_toolButton_copy_pressed();

    void on_toolButton_rotate_pressed();

    void on_toolButton_mirror_pressed();

    void on_toolButton_move_pressed();

    void on_toolButton_set_plane_origin_pressed();

    void on_toolButton_draw_point_pressed();

private:
    Ui::Form *ui;
    draw_primitives *draw=new draw_primitives();

};

#endif // FORM_H
