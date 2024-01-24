#include "form.h"
#include "ui_form.h"

#include "mainwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setMouseTracking(true);
    lmenu=new QLeftMenu();

    ui->comboBox_shape_type->setEnabled(false); //! No selection.
    ui->lineEdit_arc_x_dir->setEnabled(false);
    ui->lineEdit_arc_y_dir->setEnabled(false);
    ui->lineEdit_arc_z_dir->setEnabled(false);
}

Form::~Form()
{
    delete ui;
}


bool Form::is_hovered(){
    return lmenu->is_hovered();
}

double Form::snap_size(){
    return ui->lineEdit_snap->text().toDouble();
}

Handle(AIS_Shape) Form::get_property_widget(){

    Handle(AIS_Shape) shape;
    gp_Pnt p1,pw,p2;
    Quantity_Color col(
                float(ui->doubleSpinBox_color_red->value()/255),
                float(ui->doubleSpinBox_color_green->value()/255),
                float(ui->doubleSpinBox_color_blue->value()/255),
                Quantity_TOC_RGB // Color model: RGB
                );
    double transparancy=1-(ui->doubleSpinBox_transparancy->value()/255);

    Aspect_TypeOfLine linetype=Aspect_TOL_SOLID;
    if(ui->comboBox_line_type->currentIndex()==0){
        linetype=Aspect_TOL_SOLID;
    }
    if(ui->comboBox_line_type->currentIndex()==1){
        linetype=Aspect_TOL_DASH;
    }
    if(ui->comboBox_line_type->currentIndex()==2){
        linetype=Aspect_TOL_DOT;
    }
    if(ui->comboBox_line_type->currentIndex()==3){
        linetype=Aspect_TOL_DOTDASH;
    }
    if(ui->comboBox_line_type->currentIndex()==4){
        linetype=Aspect_TOL_USERDEFINED;
    }
    if(ui->comboBox_line_type->currentIndex()==5){
        linetype=Aspect_TOL_EMPTY;
    }

    double linewidth=ui->doubleSpinBox_line_width->value();

    //! Shape = point.
    if(ui->comboBox_shape_type->currentIndex()==0){
        p1={ui->lineEdit_point_x->text().toDouble(), ui->lineEdit_point_y->text().toDouble(),ui->lineEdit_point_z->text().toDouble()} ;
        shape=draw->draw_3d_point(p1);
        shape=draw->set_colorize_linetype(shape,col,transparancy,linetype,linewidth);
    }
    //! Shape = line.
    if(ui->comboBox_shape_type->currentIndex()==1){
        p1={ui->lineEdit_line_x_start->text().toDouble(), ui->lineEdit_line_y_start->text().toDouble(),ui->lineEdit_line_z_start->text().toDouble()} ;
        p2={ui->lineEdit_line_x_end->text().toDouble(), ui->lineEdit_line_y_end->text().toDouble(),ui->lineEdit_line_z_end->text().toDouble()} ;
        shape=draw->draw_3d_line(p1,p2);
        shape=draw->set_colorize_linetype(shape,col,transparancy,linetype,linewidth);
    }
    //! Shape = arc.
    if(ui->comboBox_shape_type->currentIndex()==2){
        p1={ui->lineEdit_arc_x_start->text().toDouble(), ui->lineEdit_arc_y_start->text().toDouble(),ui->lineEdit_arc_z_start->text().toDouble()} ;
        pw={ui->lineEdit_arc_x_way->text().toDouble(), ui->lineEdit_arc_y_way->text().toDouble(),ui->lineEdit_arc_z_way->text().toDouble()} ;
        p2={ui->lineEdit_arc_x_end->text().toDouble(), ui->lineEdit_arc_y_end->text().toDouble(),ui->lineEdit_arc_z_end->text().toDouble()} ;
        shape=draw->draw_3p_3d_arc(p1,pw,p2);
        shape=draw->set_colorize_linetype(shape,col,transparancy,linetype,linewidth);
    }
    return shape;
}

void Form::set_property_widget(std::vector<Handle(AIS_Shape)> shapevec, int shapenr){

    ui->spinBox_shapenr->setValue(shapenr);

    Handle(AIS_Shape) shape=shapevec.at(shapenr);
    opencascade::handle<Standard_Type> type= draw->get_shapetype(shape);

    gp_Pnt p1,pw,p2,pc;
    double r;
    gp_Dir dir;

    //! Set gui shape type.
    if(type==STANDARD_TYPE(Geom_Point)){
        // std::cout<<"point selected"<<std::endl;
        ui->comboBox_shape_type->setCurrentIndex(0);
        ui->stackedWidget_points->setCurrentIndex(0);

        draw->get_point(shape,p1);
        ui->lineEdit_point_x->setText(QString::number(p1.X(),'f',3));
        ui->lineEdit_point_y->setText(QString::number(p1.Y(),'f',3));
        ui->lineEdit_point_z->setText(QString::number(p1.Z(),'f',3));
    }
    if(type==STANDARD_TYPE(Geom_Line)){
        // std::cout<<"line selected"<<std::endl;
        ui->comboBox_shape_type->setCurrentIndex(1);
        ui->stackedWidget_points->setCurrentIndex(1);

        draw->get_line_points(shape,p1,p2);
        ui->lineEdit_line_x_start->setText(QString::number(p1.X(),'f',3));
        ui->lineEdit_line_y_start->setText(QString::number(p1.Y(),'f',3));
        ui->lineEdit_line_z_start->setText(QString::number(p1.Z(),'f',3));

        ui->lineEdit_line_x_end->setText(QString::number(p2.X(),'f',3));
        ui->lineEdit_line_y_end->setText(QString::number(p2.Y(),'f',3));
        ui->lineEdit_line_z_end->setText(QString::number(p2.Z(),'f',3));
    }
    if(type==STANDARD_TYPE(Geom_Circle)){
        // std::cout<<"arc selected"<<std::endl;
        ui->comboBox_shape_type->setCurrentIndex(2);
        ui->stackedWidget_points->setCurrentIndex(2);

        draw->get_arc_points(shape,p1,p2,pw,pc,dir,r);
        ui->lineEdit_arc_x_start->setText(QString::number(p1.X(),'f',3));
        ui->lineEdit_arc_y_start->setText(QString::number(p1.Y(),'f',3));
        ui->lineEdit_arc_z_start->setText(QString::number(p1.Z(),'f',3));

        ui->lineEdit_arc_x_way->setText(QString::number(pw.X(),'f',3));
        ui->lineEdit_arc_y_way->setText(QString::number(pw.Y(),'f',3));
        ui->lineEdit_arc_z_way->setText(QString::number(pw.Z(),'f',3));

        ui->lineEdit_arc_x_end->setText(QString::number(p2.X(),'f',3));
        ui->lineEdit_arc_y_end->setText(QString::number(p2.Y(),'f',3));
        ui->lineEdit_arc_z_end->setText(QString::number(p2.Z(),'f',3));

        ui->lineEdit_arc_x_center->setText(QString::number(pc.X(),'f',3));
        ui->lineEdit_arc_y_center->setText(QString::number(pc.Y(),'f',3));
        ui->lineEdit_arc_z_center->setText(QString::number(pc.Z(),'f',3));

        ui->lineEdit_arc_x_dir->setText(QString::number(dir.X(),'f',3));
        ui->lineEdit_arc_y_dir->setText(QString::number(dir.Y(),'f',3));
        ui->lineEdit_arc_z_dir->setText(QString::number(dir.Z(),'f',3));
    }

    //! Set gui color.
    Quantity_Color col;
    shape->Color(col);
    ui->doubleSpinBox_color_red->setValue(col.Red()*255);
    ui->doubleSpinBox_color_green->setValue(col.Green()*255);
    ui->doubleSpinBox_color_blue->setValue(col.Blue()*255);
    ui->doubleSpinBox_transparancy->setValue((1-shape->Attributes()->Transparency())*255);

    //! Update form color.
    QString stylesheet_text;
    stylesheet_text.append("background-color: rgba(");
    stylesheet_text.append(QString::number(col.Red()*255));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(col.Green()*255));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(col.Blue()*255));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number((1-shape->Attributes()->Transparency())*255));
    stylesheet_text.append(");");
    ui->label_color_preview->setStyleSheet(stylesheet_text);

    //! Set gui linetype.
    Aspect_TypeOfLine linetype=draw->get_linetype(shape);

    if(linetype==Aspect_TOL_SOLID){
        // std::cout<<"linetype solid"<<std::endl;
        ui->comboBox_line_type->setCurrentIndex(0);
    }
    if(linetype==Aspect_TOL_DASH){
        // std::cout<<"linetype dash"<<std::endl;
        ui->comboBox_line_type->setCurrentIndex(1);
    }
    if(linetype==Aspect_TOL_DOT){
        // std::cout<<"linetype dot"<<std::endl;
        ui->comboBox_line_type->setCurrentIndex(2);
    }
    if(linetype==Aspect_TOL_DOTDASH){
        // std::cout<<"linetype dotdash"<<std::endl;
        ui->comboBox_line_type->setCurrentIndex(3);
    }
    if(linetype==Aspect_TOL_USERDEFINED){
        // std::cout<<"linetype user"<<std::endl;
        ui->comboBox_line_type->setCurrentIndex(4);
    }
    if(linetype==Aspect_TOL_EMPTY){
        // std::cout<<"linetype empty"<<std::endl;
    }

    ui->doubleSpinBox_line_width->setValue(1);

}

void Form::set_linewidth(double value){
    ui->label_linewidth->setText(QString::number(value,'f',0)+" mm");
}

void Form::set_linetype(QString type){
    ui->label_linetype->setText(type);
}

void Form::set_text(QString text){
    ui->plainTextEdit_message->setPlainText(text);
}

void Form::set_color(QString stylesheet_text){
    ui->label_color->setStyleSheet(stylesheet_text);
}

void Form::set_ortho_state(bool state){
    if(state){
        ui->label_ortho->setStyleSheet("background-color: rgba(85, 170, 0, 100);"); // green
    } else {
        ui->label_ortho->setStyleSheet("background-color: rgba(170, 0, 0, 100);"); // red
    }
}

void Form::set_snap_state(bool state){
    if(state){
        ui->label_snap->setStyleSheet("background-color: rgba(85, 170, 0, 100);"); // green
    } else {
        ui->label_snap->setStyleSheet("background-color: rgba(170, 0, 0, 100);"); // red
    }
}

void Form::set_planeangle(double angle_x, double angle_y, double angle_z){
    ui->lineEdit_plane_rot_x->setText(QString::number(angle_x,'f',3));
    ui->lineEdit_plane_rot_y->setText(QString::number(angle_y,'f',3));
    ui->lineEdit_plane_rot_z->setText(QString::number(angle_z,'f',3));
}

void Form::set_mousepos(gp_Pnt mouse){
    ui->label_mouse_x->setText(QString::number(mouse.X(),'f',3));
    ui->label_mouse_y->setText(QString::number(mouse.Y(),'f',3));
    ui->label_mouse_z->setText(QString::number(mouse.Z(),'f',3));
}

void Form::set_planepos(gp_Pln plane){
    ui->lineEdit_plane_pos_x->setText(QString::number(plane.Location().X(),'f',3));
    ui->lineEdit_plane_pos_y->setText(QString::number(plane.Location().Y(),'f',3));
    ui->lineEdit_plane_pos_z->setText(QString::number(plane.Location().Z(),'f',3));
}

void Form::set_planepos(gp_Pnt pos){
    ui->lineEdit_plane_pos_x->setText(QString::number(pos.X(),'f',3));
    ui->lineEdit_plane_pos_y->setText(QString::number(pos.Y(),'f',3));
    ui->lineEdit_plane_pos_z->setText(QString::number(pos.Z(),'f',3));
}

void Form::on_lineEdit_input_returnPressed()
{
    emit lineEdit_input_returnPressed(ui->lineEdit_input->text());
}

void Form::on_lineEdit_plane_pos_x_returnPressed()
{
    emit lineEdit_plane_pos_x_returnPressed(ui->lineEdit_plane_pos_x->text().toDouble());
}

void Form::on_lineEdit_plane_pos_y_returnPressed()
{
    emit lineEdit_plane_pos_y_returnPressed(ui->lineEdit_plane_pos_y->text().toDouble());
}

void Form::on_lineEdit_plane_pos_z_returnPressed()
{
    emit lineEdit_plane_pos_z_returnPressed(ui->lineEdit_plane_pos_z->text().toDouble());
}

void Form::on_lineEdit_plane_rot_x_returnPressed()
{
    emit lineEdit_plane_rot_x_returnPressed(ui->lineEdit_plane_rot_x->text().toDouble());
}

void Form::on_lineEdit_plane_rot_y_returnPressed()
{
    emit lineEdit_plane_rot_y_returnPressed(ui->lineEdit_plane_rot_y->text().toDouble());
}

void Form::on_lineEdit_plane_rot_z_returnPressed()
{
    emit lineEdit_plane_rot_z_returnPressed(ui->lineEdit_plane_rot_z->text().toDouble());
}

void Form::on_lineEdit_snap_returnPressed()
{
    emit lineEdit_snap_returnPressed(ui->lineEdit_snap->text().toDouble());
}

void Form::on_checkBox_axis_toggled(bool checked)
{
    emit checkBox_axis_toggled(checked);
}

void Form::on_checkBox_grid_toggled(bool checked)
{
    emit checkBox_grid_toggled(checked);
}

void Form::on_checkBox_plane_toggled(bool checked)
{
    emit checkBox_plane_toggled(checked);
}

void Form::on_toolButton_set_shape_values_pressed()
{
    emit toolButton_set_shape_values_pressed(ui->spinBox_shapenr->value());
}

void Form::on_doubleSpinBox_color_red_valueChanged(double arg1)
{
    //! Update form color.
    QString stylesheet_text;
    stylesheet_text.append("background-color: rgba(");
    stylesheet_text.append(QString::number(arg1));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_green->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_blue->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_transparancy->value()));
    stylesheet_text.append(");");
    ui->label_color_preview->setStyleSheet(stylesheet_text);
}

void Form::on_doubleSpinBox_color_green_valueChanged(double arg1)
{
    //! Update form color.
    QString stylesheet_text;
    stylesheet_text.append("background-color: rgba(");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_red->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(arg1));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_blue->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_transparancy->value()));
    stylesheet_text.append(");");
    ui->label_color_preview->setStyleSheet(stylesheet_text);
}

void Form::on_doubleSpinBox_color_blue_valueChanged(double arg1)
{
    //! Update form color.
    QString stylesheet_text;
    stylesheet_text.append("background-color: rgba(");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_red->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_green->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(arg1));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_transparancy->value()));
    stylesheet_text.append(");");
    ui->label_color_preview->setStyleSheet(stylesheet_text);
}

void Form::on_doubleSpinBox_transparancy_valueChanged(double arg1)
{
    //! Update form color.
    QString stylesheet_text;
    stylesheet_text.append("background-color: rgba(");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_red->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_green->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(ui->doubleSpinBox_color_blue->value()));
    stylesheet_text.append(", ");
    stylesheet_text.append(QString::number(arg1));
    stylesheet_text.append(");");
    ui->label_color_preview->setStyleSheet(stylesheet_text);
}

void Form::on_toolButton_choose_color_pressed()
{
    //! Open the color chooser dialog
    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Choose a color", QColorDialog::ShowAlphaChannel);

    // Check if a color was selected
    if (color.isValid()) {

        ui->doubleSpinBox_color_red->setValue(color.red());
        ui->doubleSpinBox_color_green->setValue(color.green());
        ui->doubleSpinBox_color_blue->setValue(color.blue());
        ui->doubleSpinBox_transparancy->setValue(color.alpha());

        //! Update form color.
        QString stylesheet_text;
        stylesheet_text.append("background-color: rgba(");
        stylesheet_text.append(QString::number(ui->doubleSpinBox_color_red->value()));
        stylesheet_text.append(", ");
        stylesheet_text.append(QString::number(ui->doubleSpinBox_color_green->value()));
        stylesheet_text.append(", ");
        stylesheet_text.append(QString::number(ui->doubleSpinBox_color_blue->value()));
        stylesheet_text.append(", ");
        stylesheet_text.append(QString::number(ui->doubleSpinBox_transparancy->value()));
        stylesheet_text.append(");");
        ui->label_color_preview->setStyleSheet(stylesheet_text);
    }
}

void Form::on_toolButton_ortho_pressed()
{
    emit toolButton_ortho_pressed();
}

void Form::on_toolButton_snap_pressed()
{
    emit toolButton_snap_pressed();
}



void Form::on_toolButton_draw_line_pressed()
{
    emit toolButton_draw_line_pressed();
}

void Form::on_toolButton_draw_arc_pressed()
{
    emit toolButton_draw_arc_pressed();
}

void Form::on_toolButton_view_3d_pressed()
{
    emit toolButton_view_3d_pressed();
}

void Form::on_toolButton_view_top_pressed()
{
    emit toolButton_view_top_pressed();
}

void Form::on_toolButton_view_bottom_pressed()
{
    emit toolButton_view_bottom_pressed();
}

void Form::on_toolButton_view_front_pressed()
{
    emit toolButton_view_front_pressed();
}

void Form::on_toolButton_view_back_pressed()
{
    emit toolButton_view_back_pressed();
}

void Form::on_toolButton_view_left_pressed()
{
    emit toolButton_view_left_pressed();
}

void Form::on_toolButton_view_right_pressed()
{
    emit toolButton_view_right_pressed();
}

void Form::on_toolButton_document_open_pressed()
{
    emit toolButton_document_open_pressed();
}

void Form::on_toolButton_document_save_pressed()
{
    emit toolButton_document_save_pressed();
}

void Form::on_toolButton_document_save_as_pressed()
{
    emit toolButton_document_save_as_pressed();
}

void Form::on_toolButton_delete_selected_shapes_pressed()
{
    emit toolButton_delete_selected_shapes_pressed();
}

void Form::on_toolButton_draw_circle_pressed()
{
    emit toolButton_draw_circle_pressed();
}

void Form::on_toolButton_offset_pressed()
{
    emit toolButton_offset_pressed();
}

void Form::on_toolButton_copy_pressed()
{
    emit toolButton_copy_pressed();
}

void Form::on_toolButton_rotate_pressed()
{
    emit toolButton_rotate_pressed();
}

void Form::on_toolButton_mirror_pressed()
{
    emit toolButton_mirror_pressed();
}

void Form::on_toolButton_move_pressed()
{
    emit toolButton_move_pressed();
}

void Form::on_toolButton_set_plane_origin_pressed()
{
    emit toolButton_set_plane_origin_pressed();
}

void Form::on_toolButton_draw_point_pressed()
{
    emit toolButton_draw_point_pressed();
}
