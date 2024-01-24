#include "mainwindow.h"
#include "./ui_mainwindow.h"

//! Todo:
//! Compound logic.
//! Draw circle.
//! Trim.
//! Extend.
//! Circle selection.

enum MODE {
    selection,
    aborting,
    point,
    line,
    arc,
    circle,
    edit_point,
    edit_line_start,
    edit_line_end,
    edit_arc_start,
    edit_arc_way,
    edit_arc_end,
    edit_arc_center,
    plane_origin,
    fillet,
    offset,
    copy,
    mirror,
    move_,
    rotate,
    set_plane_origin,
    mode_set_user_plane,
    trim
} mode;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    occ = new OcctQtViewer();

    //! Add gridlayout on top of the occ widget.
    QGridLayout *layout=new QGridLayout(occ);
    layout->setMargin(0);

    //! Add the controls into the occ gridlayout..
    layout->addWidget(form);

    ui->gridLayout_occ->addWidget(occ);

    //! This activates a screen update when robot is moving and screen needs to be updated automaticly.
    connect(timer, &QTimer::timeout, this, &MainWindow::update);
    timer->start(20);

    connect(form, &Form::lineEdit_input_returnPressed, this, &MainWindow::set_input_value);
    connect(form, &Form::lineEdit_plane_pos_x_returnPressed, this, &MainWindow::set_plane_pos_x);
    connect(form, &Form::lineEdit_plane_pos_y_returnPressed, this, &MainWindow::set_plane_pos_y);
    connect(form, &Form::lineEdit_plane_pos_z_returnPressed, this, &MainWindow::set_plane_pos_z);
    connect(form, &Form::lineEdit_plane_rot_x_returnPressed, this, &MainWindow::set_plane_rot_x);
    connect(form, &Form::lineEdit_plane_rot_y_returnPressed, this, &MainWindow::set_plane_rot_y);
    connect(form, &Form::lineEdit_plane_rot_z_returnPressed, this, &MainWindow::set_plane_rot_z);
    connect(form, &Form::lineEdit_snap_returnPressed, this, &MainWindow::set_snap);
    connect(form, &Form::checkBox_axis_toggled, this, &MainWindow::set_axis);
    connect(form, &Form::checkBox_grid_toggled, this, &MainWindow::set_grid);
    connect(form, &Form::checkBox_plane_toggled, this, &MainWindow::set_plane);
    connect(form, &Form::toolButton_set_shape_values_pressed, this, &MainWindow::set_shape);
    connect(form, &Form::toolButton_snap_pressed, this, &MainWindow::toggle_snap);
    connect(form, &Form::toolButton_ortho_pressed, this, &MainWindow::toggle_ortho);

    connect(form, &Form::toolButton_draw_point_pressed, this, &MainWindow::on_action_1p_point_triggered);
    connect(form, &Form::toolButton_draw_line_pressed, this, &MainWindow::on_action_2p_3d_line_triggered);
    connect(form, &Form::toolButton_draw_arc_pressed, this, &MainWindow::draw_3d_3p_arc);
    connect(form, &Form::toolButton_draw_circle_pressed, this, &MainWindow::on_action_3d_1p_pc_circle_triggered);

    connect(form, &Form::toolButton_view_3d_pressed, this, &MainWindow::on_action_view_3d_triggered);
    connect(form, &Form::toolButton_view_front_pressed, this, &MainWindow::on_action_front_triggered);
    connect(form, &Form::toolButton_view_back_pressed, this, &MainWindow::on_action_back_triggered);
    connect(form, &Form::toolButton_view_left_pressed, this, &MainWindow::on_action_left_triggered);
    connect(form, &Form::toolButton_view_right_pressed, this, &MainWindow::on_action_right_triggered);
    connect(form, &Form::toolButton_view_top_pressed, this, &MainWindow::on_action_top_triggered);
    connect(form, &Form::toolButton_view_bottom_pressed, this, &MainWindow::on_action_bottom_triggered);
    connect(form, &Form::toolButton_document_open_pressed, this, &MainWindow::on_action_open_triggered);
    connect(form, &Form::toolButton_document_save_pressed, this, &MainWindow::on_action_save_triggered);
    connect(form, &Form::toolButton_document_save_as_pressed, this, &MainWindow::on_action_save_as_triggered);
    connect(form, &Form::toolButton_delete_selected_shapes_pressed, this, &MainWindow::on_action_delete_triggered);

    connect(form, &Form::toolButton_offset_pressed, this, &MainWindow::on_action_offset_triggered);
    connect(form, &Form::toolButton_move_pressed, this, &MainWindow::on_action_move_triggered);
    connect(form, &Form::toolButton_mirror_pressed, this, &MainWindow::on_action_mirror_triggered);
    connect(form, &Form::toolButton_copy_pressed, this, &MainWindow::on_action_copy_triggered);
    connect(form, &Form::toolButton_rotate_pressed, this, &MainWindow::on_action_rotate_triggered);

    connect(form, &Form::toolButton_set_plane_origin_pressed, this, &MainWindow::on_action_set_plane_origin_triggered);

    //! Draw point at origin.
    Handle(AIS_Shape) shape=draw->draw_3d_point({0,0,0});
    shape=draw->colorize(shape,Quantity_NOC_GRAY,0.9);
    occ->add_shapevec(shape);

    occ->create_snap_sphere(form->snap_size());
    occ->hide_snap_sphere();

    occ->set_view_top();
    on_actionset_plane_top_triggered(); //! Activate top plane.
    occ->set_orthographic();

    set_user_plane(); //! Updates to view the user plane.
}

void MainWindow::toggle_snap(){

    if(work->snap()){
        work->set_snap(0);
        work->set_snap_end(0);
        work->set_snap_mid(0);
        work->set_snap_perpendicular(0);
        work->set_snap_center(0);
        work->set_snap_tangent(0);
        work->set_snap_size(form->snap_size());
        form->set_snap_state(0);

        ui->action_snap->setChecked(0);
        ui->action_snap_center->setChecked(0);
        ui->action_snap_mid->setChecked(0);
        ui->action_snap_end->setChecked(0);
        ui->action_snap_perpendicular->setChecked(0);
        ui->action_snap_tangent->setChecked(0);
    } else {
        work->set_snap(1);
        work->set_snap(1);
        work->set_snap_end(1);
        work->set_snap_mid(1);
        work->set_snap_perpendicular(1);
        work->set_snap_center(1);
        work->set_snap_tangent(1);
        work->set_snap_size(form->snap_size());
        form->set_snap_state(1);

        ui->action_snap->setChecked(1);
        ui->action_snap_center->setChecked(1);
        ui->action_snap_mid->setChecked(1);
        ui->action_snap_end->setChecked(1);
        ui->action_snap_perpendicular->setChecked(1);
        ui->action_snap_tangent->setChecked(1);
    }
}

void MainWindow::toggle_ortho(){

    if(work->ortho()){
        work->set_ortho(0);
        ui->action_ortho->setChecked(0);
        form->set_ortho_state(0);
    } else {
        work->set_ortho(1);
        ui->action_ortho->setChecked(1);
        form->set_ortho_state(1);
    }
}

void MainWindow::set_shape(int shapevecnr){
    //! std::cout<<"set shape nr:"<<shapevecnr<<std::endl;
    if(shapevecnr<int(occ->shapevec.size())){
        Handle(AIS_Shape) shape=form->get_property_widget();
        occ->myContext->Remove(occ->shapevec.at(shapevecnr),true);
        occ->shapevec.at(shapevecnr)->SetShape(shape->Shape());
        occ->shapevec.at(shapevecnr)->SetAttributes(shape->Attributes());
        occ->myContext->Display(occ->shapevec.at(shapevecnr),true);
    }
}

void MainWindow::set_axis(bool state){
    show_axis=state;
    set_user_plane(); //! Updates this state.
}

void MainWindow::set_grid(bool state){
    show_grid=state;
    set_user_plane(); //! Updates this state.
}

void MainWindow::set_plane(bool state){
    show_plane=state;
    set_user_plane(); //! Updates this state.
}

void MainWindow::set_snap(double value){
    //! std::cout<<"snap size set to:"<<value<<std::endl;
    work->set_snap_size(value);

    //! Update sphere with new snap size.
    if(occ->Context()->IsDisplayed(occ->snap_sphere)){
        occ->Context()->Erase(occ->snap_sphere,true);
        occ->snap_sphere.Nullify();
    }
    occ->create_snap_sphere(work->snap_size());
}

void MainWindow::set_plane_pos_x(double value){
    //! std::cout<<"posx:"<<value<<std::endl;
    gp_Pnt p=occ->plane.Location();
    occ->plane.SetLocation({value,p.Y(),p.Z()});
    set_user_plane();
}
void MainWindow::set_plane_pos_y(double value){
    //! std::cout<<"posy:"<<value<<std::endl;
    gp_Pnt p=occ->plane.Location();
    occ->plane.SetLocation({p.X(),value,p.Z()});
    set_user_plane();
}
void MainWindow::set_plane_pos_z(double value){
    //! std::cout<<"posz:"<<value<<std::endl;
    gp_Pnt p=occ->plane.Location();
    occ->plane.SetLocation({p.X(),p.Y(),value});
    set_user_plane();
}

void MainWindow::set_plane_rot_x(double value){
    //! std::cout<<"rotx:"<<value<<std::endl;
    occ->plane_rot_x=value;
    set_user_plane();
}
void MainWindow::set_plane_rot_y(double value){
    //! std::cout<<"roty:"<<value<<std::endl;
    occ->plane_rot_y=value;
    set_user_plane();
}
void MainWindow::set_plane_rot_z(double value){
    //! std::cout<<"rotz:"<<value<<std::endl;
    occ->plane_rot_z=value;
    set_user_plane();
}

void MainWindow::set_input_value(QString text){
    keyboard_text=text;
}

void MainWindow::mouseDragEventUpdate(){
    if(left_mouse_pressed && occ->mousepos.Distance(left_mouse_press_pos)>0){
        left_mouse_dragged=1;
    } else {
        left_mouse_dragged=0;
    }
    //! std::cout<<"dragged:"<<left_mouse_dragged<<std::endl;
}

int res=0;
int nr=0;
QString message;

void MainWindow::update(){

    mouseDragEventUpdate();

    work->set_style(occ->linetype,occ->color,occ->linewidth,occ->transparancy);
    work->set_plane_trsf(occ->plane_user->Transformation());
    work->set_eye_line(occ->eyeline);
    work->set_snap(work->snap(),
                   work->snap_end(),
                   work->snap_mid(),
                   work->snap_perpendicular(),
                   work->snap_center(),
                   work->snap_tangent(),
                   work->snap_nearest(),
                   occ->eyeline,
                   work->snap_size());

    switch (mode) {

    case aborting:
        form->set_text("Mode aborting.");
        left_mouse_click_counter=0;
        right_mouse_click_counter=0;
        keyboard_text="";

        mode=selection;
        break;

    case selection:

        //! Todo, edit multiple selected shapes at the same time, like common points.
        res=work->draw_selection(left_mouse_click_counter,occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message,nr);
        form->set_text(message);

        if(res==1){
            mode=edit_line_start;
        }
        if(res==2){
            mode=edit_line_end;
        }
        if(res==3){
            mode=edit_arc_start;
        }
        if(res==4){
            mode=edit_arc_way;
        }
        if(res==5){
            mode=edit_arc_end;
        }
        if(res==6){
            mode=edit_arc_center;
        }
        if(res==7){
            mode=edit_point;
        }
        break;

    case trim:
        work->trim(left_mouse_click_counter,right_mouse_click_counter,occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case point:
        work->draw_point(left_mouse_click_counter,occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case edit_point:
        //! std::cout<<"mode edit point"<<std::endl;
        if(left_mouse_dragged){
            work->edit_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case line:
        work->draw_line(left_mouse_click_counter,occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case edit_line_start:
        //! std::cout<<"mode edit line start"<<std::endl;
        if(left_mouse_dragged){
            work->edit_line_start_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case edit_line_end:
        //! std::cout<<"mode edit line end"<<std::endl;
        if(left_mouse_dragged){
            work->edit_line_end_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case arc:
        work->draw_3p_arc(left_mouse_click_counter,occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case circle:
        work->draw_1p_pc_circle(left_mouse_click_counter,occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case edit_arc_start:
        //! std::cout<<"mode edit arc start"<<std::endl;
        if(left_mouse_dragged){
            work->edit_arc_start_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case edit_arc_way:
        //! std::cout<<"mode edit arc way"<<std::endl;
        if(left_mouse_dragged){
            work->edit_arc_way_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case edit_arc_end:
        //! std::cout<<"mode edit arc end"<<std::endl;
        if(left_mouse_dragged){
            work->edit_arc_end_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case edit_arc_center:
        //! std::cout<<"mode edit arc center"<<std::endl;
        if(left_mouse_dragged){
            work->edit_arc_center_point(occ->myContext,occ->shapevec,nr,occ->mousepos);
        }
        if(!left_mouse_dragged){
            mode=aborting;
        }
        break;

    case mode_set_user_plane:
        switch (left_mouse_click_counter) {
        case 0:
            occ->deselected_all();
            left_mouse_click_counter++;
            break;
        case 1:
            form->set_text("Mode set user plane.");
            break;
        }
        break;

    case mirror:
        work->mirror(left_mouse_click_counter,
                     right_mouse_click_counter,
                     occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case copy:
        work->copy(left_mouse_click_counter,
                   right_mouse_click_counter,
                   occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case offset:
        work->offset(left_mouse_click_counter,
                     right_mouse_click_counter,
                     occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,occ->plane,message);
        form->set_text(message);
        break;

    case move_:
        work->move(left_mouse_click_counter,
                   right_mouse_click_counter,
                   occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case rotate:
        work->rotate(left_mouse_click_counter,
                     right_mouse_click_counter,
                     occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message);
        form->set_text(message);
        break;

    case set_plane_origin:
        if(work->get_point(left_mouse_click_counter,
                                  right_mouse_click_counter,
                                  occ->mousepos,keyboard_text,occ->myContext,occ->shapevec,message)){
            mode=aborting;
        }
        form->set_text(message);

        occ->plane.SetLocation(occ->mousepos);
        set_user_plane(); //! Reconstruct the user plane.

        break;

    default:
        break;
    }

    //! Update mouse position.
    QString x=QString::number(occ->mousepos.X(),'f',3);
    QString y=QString::number(occ->mousepos.Y(),'f',3);
    QString z=QString::number(occ->mousepos.Z(),'f',3);
    QString plane_x=QString::number(occ->plane.Location().X(),'f',3);
    QString plane_y=QString::number(occ->plane.Location().Y(),'f',3);
    QString plane_z=QString::number(occ->plane.Location().Z(),'f',3);
    QString plane_dir_x=QString::number(occ->plane.Position().Direction().X(),'f',3);
    QString plane_dir_y=QString::number(occ->plane.Position().Direction().Y(),'f',3);
    QString plane_dir_z=QString::number(occ->plane.Position().Direction().Z(),'f',3);

    form->set_mousepos(occ->mousepos);

    //! To update mouse moves.
    occ->redraw();

    //! Update gui property frame.
    if(draw->get_highlighted_shape(occ->myContext,occ->shapevec,mySelectedShape) && myMousePostCycle){
        form->set_property_widget(occ->shapevec,mySelectedShape);
        myMousePostCycle=0;
    }

    work->set_snap_size(draw->get_consistent_snap_size(occ->myView,form->snap_size()));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    //! std::cout<<"keyevent key:"<<event->key()<<std::endl;

    if (event->key()==16777220) { //! Key enter.
        //! std::cout<<"enter"<<std::endl;
    }
    if (event->key()==16777216) { //! Esc enter.
        mode=aborting;
        //! std::cout<<"escape"<<std::endl;
    }
    if (event->key()==16777223) { //! Del delete.
        on_action_delete_triggered();
        //! std::cout<<"delete"<<std::endl;
    }
    if (event->key()==65 && oldkey==16777249) { //! Control+a
        occ->select_all();
        //! std::cout<<"control+a"<<std::endl;
    }
    if (event->key()==90 && oldkey==16777249) { //! Control+z
        occ->undo();
        //! std::cout<<"control+z"<<std::endl;
    }
    if (event->key()==32) { //! Space
        next++;
        occ->redraw(); // Update screen to show new snap position.
        //! std::cout<<"space key, next:"<<next<<std::endl;
    }
    if (event->key()==16777271) { //! F8 Ortho
        toggle_ortho();
        //! std::cout<<"F8"<<std::endl;
    }
    if (event->key()==16777266) { //! F3 Snap
        toggle_snap();
        if(work->snap()){ //! Update gui menu.

            work->set_snap_end(1);
            work->set_snap_mid(1);
            work->set_snap_perpendicular(1);
            work->set_snap_center(1);
            work->set_snap_tangent(1);

            ui->action_snap->setChecked(1);
            ui->action_snap_center->setChecked(1);
            ui->action_snap_mid->setChecked(1);
            ui->action_snap_end->setChecked(1);
            ui->action_snap_perpendicular->setChecked(1);
        } else{

            work->set_snap_end(0);
            work->set_snap_mid(0);
            work->set_snap_perpendicular(0);
            work->set_snap_center(0);
            work->set_snap_tangent(0);

            ui->action_snap->setChecked(0);
            ui->action_snap_center->setChecked(0);
            ui->action_snap_mid->setChecked(0);
            ui->action_snap_end->setChecked(0);
            ui->action_snap_perpendicular->setChecked(0);
        }
        //! std::cout<<"F3"<<std::endl;
    }
    if (event->key()==79) { //! o

    }
    if (event->key()==83) { //! s

    }

    oldkey=event->key();
    occ->redraw();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton) {
        left_mouse_pressed=0;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){

    //! std::cout<<"mousepressevent"<<std::endl;
    if (event->button() == Qt::LeftButton) {
        //! Left mouse button pressed
        left_mouse_click_counter++;

        myMousePostCycle=1;
        left_mouse_pressed=1;

        left_mouse_press_pos=occ->mousepos;

    } else if (event->button() == Qt::RightButton) {
        //! std::cout<<"right mouse pressed"<<std::endl;
        right_mouse_click_counter++;
    }
    if (event->modifiers() & Qt::ShiftModifier) {
        //! Shift key is held down
    }
}

void MainWindow::set_color(){

    //! Open the color chooser dialog
    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Choose a color");

    //! Check if a color was selected
    if (color.isValid()) {
        occ->color=draw->QColorToQuantityColor(color);

        //! Update form color.
        QString stylesheet_text; //! Example of stylesheet text : "background-color: rgba(170, 0, 0, 100);"
        stylesheet_text.append("background-color: rgba(");
        stylesheet_text.append(QString::number(color.red()));
        stylesheet_text.append(", ");
        stylesheet_text.append(QString::number(color.green()));
        stylesheet_text.append(", ");
        stylesheet_text.append(QString::number(color.blue()));
        stylesheet_text.append(", ");
        stylesheet_text.append(QString::number(255)); //! Transparancy 0-255 in qt.
        stylesheet_text.append(");");
        form->set_color(stylesheet_text);
    }
}

void MainWindow::on_action_set_color_triggered()
{
    set_color();
}

void MainWindow::on_actionset_user_plane_triggered()
{
    mode=mode_set_user_plane;
    left_mouse_click_counter=0;
}

void MainWindow::draw_3d_2p_line(){
    mode=line;
    left_mouse_click_counter=0;
}

void MainWindow::on_action_2p_3d_line_triggered()
{
    mode=line;
    left_mouse_click_counter=0;
}

void MainWindow::draw_3d_3p_arc(){
    // mode=arc_3p;
    mode=arc;
    left_mouse_click_counter=0;
}

void MainWindow::on_action_3d_1p_pc_circle_triggered()
{
    mode=circle;
    left_mouse_click_counter=0;
}

void MainWindow::draw_fillet(){
    mode=fillet;
    left_mouse_click_counter=0;
}

void MainWindow::on_actionEsc_triggered()
{
    mode=aborting;
}

void MainWindow::zoom_plus(){
    occ->zoom_plus();
}

void MainWindow::zoom_min(){
    occ->zoom_min();
}

void MainWindow::zoom_all(){
    occ->fit_all();
}

void MainWindow::view_front(){
    occ->set_view_front();
}

void MainWindow::view_back(){
    occ->set_view_back();
}

void MainWindow::view_top(){
    occ->set_view_top();
}

void MainWindow::view_bottom(){
    occ->set_view_bottom();
}

void MainWindow::view_left(){
    occ->set_view_left();
}

void MainWindow::view_right(){
    occ->set_view_right();
}

void MainWindow::view_3d(){
    occ->set_view_3d();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionorthographic_triggered()
{
    occ->set_orthographic();
}

void MainWindow::on_actionperspective_triggered()
{
    occ->set_perspective();
}

void MainWindow::on_action_open_triggered()
{
    std::vector<Handle(AIS_Shape)> shapevec;

    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/", tr("Cad Files (*.dxf *.step)"));

    QFileInfo fileInfo(filename);
    QString extension = fileInfo.suffix();

    if (!extension.isEmpty()) {
        //! std::cout << "File extension: " << extension.toStdString() << std::endl;
    } else {
        //! std::cout << "No file extension found." << std::endl;
    }

    if(extension.toStdString()=="dxf"){
        shapevec=libdxfrw_functions().open_dxf_file(filename.toStdString());
    }

    if(extension.toStdString()=="step"){
        shapevec=draw_primitives().load_stepfile(filename.toStdString());
    }

    if(extension.toStdString()=="ngc"){
        //! Todo. Use a nice interpreter for it.
    }

    for(uint i=0; i<shapevec.size(); i++){
        occ->add_shapevec(shapevec.at(i));
    }
}

void MainWindow::on_action_save_triggered()
{
    if (!myFilePath.isEmpty()) {
        //! std::cout<<"filepath:"<<myFilePath.toStdString()<<std::endl;
        //! The user selected a file, 'filePath' contains the selected file path
        //! You can perform actions like saving to this file
        libdxfrw_functions().save_dxf_file(myFilePath.toStdString(),occ->shapevec);
    } else { //! Open filedialog to set the file path.
        on_action_save_as_triggered();
    }
}

void MainWindow::on_action_save_as_triggered()
{
    myFilePath = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), tr("Cad Files (*.dxf)"));
    if (!myFilePath.isEmpty()) {
        //! std::cout<<"filepath:"<<myFilePath.toStdString()<<std::endl;
        //! The user selected a file, 'filePath' contains the selected file path
        //! You can perform actions like saving to this file
        libdxfrw_functions().save_dxf_file(myFilePath.toStdString(),occ->shapevec);
    }
}

void MainWindow::on_actionset_plane_top_triggered()
{
    occ->plane_rot_x=0;
    occ->plane_rot_y=0;
    occ->plane_rot_z=0;
    form->set_planeangle(0,0,0);

    //! Define the axis for the plane (center and normal direction using predefined direction)
    gp_Pnt centerPoint(occ->plane.Location()); //! Current centerpoint.
    gp_Dir xAxisDirection = gp::DZ();
    gp_Ax3 planeAxis(centerPoint, xAxisDirection); //! Axis for the plane
    gp_Pln myPlane(planeAxis);
    occ->plane=myPlane;

    gp_Pnt origin = planeAxis.Location();
    gp_Dir xDir = planeAxis.XDirection();
    gp_Dir yDir = planeAxis.YDirection();

    //! Calculate points on the plane based on the origin and directions
    gp_Pnt point1 = origin.Translated(xDir.XYZ() * 50).Translated(yDir.XYZ() * 50);     //! Offset by 5 units in X and Y directions
    gp_Pnt point2 = origin.Translated(xDir.XYZ() * -50).Translated(yDir.XYZ() * 50);    //! Offset by -5 units in X and 5 units in Y
    gp_Pnt point3 = origin.Translated(xDir.XYZ() * -50).Translated(yDir.XYZ() * -50);   //! Offset by -5 units in X and Y
    gp_Pnt point4 = origin.Translated(xDir.XYZ() * 50).Translated(yDir.XYZ() * -50);    //! Offset by 5 units in X and -5 units in Y

    if(occ->Context()->IsDisplayed(occ->plane_top)){
        occ->Context()->Erase(occ->plane_top,true);
        occ->plane_top.Nullify();
    }

    occ->plane_top=draw_primitives().draw_3d_surface(point1,point2,point3,point4);

    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge({origin.X()-50,origin.Y(),origin.Z()},{origin.X()+50,origin.Y(),origin.Z()});
    occ->aisbody_tcp_xaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_xaxis->SetColor(Quantity_NOC_RED);

    edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y()-50,origin.Z()},{origin.X(),origin.Y()+50,origin.Z()});
    occ->aisbody_tcp_yaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_yaxis->SetColor(Quantity_NOC_GREEN);

    edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y(),origin.Z()-50},{origin.X(),origin.Y(),origin.Z()+50});
    occ->aisbody_tcp_zaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_zaxis->SetColor(Quantity_NOC_BLUE);

    occ->plane_top->AddChild(occ->aisbody_tcp_xaxis);
    occ->plane_top->AddChild(occ->aisbody_tcp_yaxis);
    occ->plane_top->AddChild(occ->aisbody_tcp_zaxis);

    occ->plane_top=draw->colorize(occ->plane_top,Quantity_NOC_GRAY50,0.95);
    occ->Context()->Display(occ->plane_top,AIS_Shaded,-1,true,AIS_DS_Displayed); //! non selectable shape.

    if(occ->Context()->IsDisplayed(occ->plane_user)){
        occ->Context()->Remove(occ->plane_user,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_left)){
        occ->Context()->Remove(occ->plane_left,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_front)){
        occ->Context()->Remove(occ->plane_front,true);
    }

    form->set_planepos(occ->plane);
}

void MainWindow::on_actionset_plane_left_triggered()
{
    occ->plane_rot_x=0;
    occ->plane_rot_y=90;
    occ->plane_rot_z=0;
    form->set_planeangle(0,90,0);

    //! Define the axis for the plane (center and normal direction using predefined direction)
    gp_Pnt centerPoint(occ->plane.Location()); //! Current centerpoint.
    gp_Dir xAxisDirection = gp::DX();
    gp_Ax3 planeAxis(centerPoint, xAxisDirection); //! Axis for the plane
    gp_Pln myPlane(planeAxis);
    occ->plane=myPlane;

    gp_Pnt origin = planeAxis.Location();
    gp_Dir xDir = planeAxis.XDirection();
    gp_Dir yDir = planeAxis.YDirection();

    //! Calculate points on the plane based on the origin and directions
    gp_Pnt point1 = origin.Translated(xDir.XYZ() * 50).Translated(yDir.XYZ() * 50);     //! Offset by 5 units in X and Y directions
    gp_Pnt point2 = origin.Translated(xDir.XYZ() * -50).Translated(yDir.XYZ() * 50);    //! Offset by -5 units in X and 5 units in Y
    gp_Pnt point3 = origin.Translated(xDir.XYZ() * -50).Translated(yDir.XYZ() * -50);   //! Offset by -5 units in X and Y
    gp_Pnt point4 = origin.Translated(xDir.XYZ() * 50).Translated(yDir.XYZ() * -50);    //! Offset by 5 units in X and -5 units in Y

    if(occ->Context()->IsDisplayed(occ->plane_left)){
        occ->Context()->Erase(occ->plane_left,true);
        occ->plane_left.Nullify();
    }

    occ->plane_left=draw_primitives().draw_3d_surface(point1,point2,point3,point4);

    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge({origin.X()-50,origin.Y(),origin.Z()},{origin.X()+50,origin.Y(),origin.Z()});
    occ->aisbody_tcp_xaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_xaxis->SetColor(Quantity_NOC_RED);

    edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y()-50,origin.Z()},{origin.X(),origin.Y()+50,origin.Z()});
    occ->aisbody_tcp_yaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_yaxis->SetColor(Quantity_NOC_GREEN);

    edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y(),origin.Z()-50},{origin.X(),origin.Y(),origin.Z()+50});
    occ->aisbody_tcp_zaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_zaxis->SetColor(Quantity_NOC_BLUE);

    occ->plane_left->AddChild(occ->aisbody_tcp_xaxis);
    occ->plane_left->AddChild(occ->aisbody_tcp_yaxis);
    occ->plane_left->AddChild(occ->aisbody_tcp_zaxis);

    occ->plane_left=draw->colorize(occ->plane_left,Quantity_NOC_GRAY50,0.95);
    occ->Context()->Display(occ->plane_left,AIS_Shaded,-1,true,AIS_DS_Displayed); //! non selectable shape.

    if(occ->Context()->IsDisplayed(occ->plane_user)){
        occ->Context()->Remove(occ->plane_user,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_top)){
        occ->Context()->Remove(occ->plane_top,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_front)){
        occ->Context()->Remove(occ->plane_front,true);
    }

    form->set_planepos(occ->plane);
}

void MainWindow::on_actionset_plane_front_triggered()
{
    occ->plane_rot_x=90;
    occ->plane_rot_y=0;
    occ->plane_rot_z=0;
    form->set_planeangle(90,0,0);

    //! Define the axis for the plane (center and normal direction using predefined direction)
    gp_Pnt centerPoint(occ->plane.Location()); //! Current centerpoint.
    gp_Dir xAxisDirection = gp::DY();
    gp_Ax3 planeAxis(centerPoint, xAxisDirection); //! Axis for the plane
    gp_Pln myPlane(planeAxis);
    occ->plane=myPlane;

    gp_Pnt origin = planeAxis.Location();
    gp_Dir xDir = planeAxis.XDirection();
    gp_Dir yDir = planeAxis.YDirection();

    //! Calculate points on the plane based on the origin and directions
    gp_Pnt point1 = origin.Translated(xDir.XYZ() * 50).Translated(yDir.XYZ() * 50);     //! Offset by 5 units in X and Y directions
    gp_Pnt point2 = origin.Translated(xDir.XYZ() * -50).Translated(yDir.XYZ() * 50);    //! Offset by -5 units in X and 5 units in Y
    gp_Pnt point3 = origin.Translated(xDir.XYZ() * -50).Translated(yDir.XYZ() * -50);   //! Offset by -5 units in X and Y
    gp_Pnt point4 = origin.Translated(xDir.XYZ() * 50).Translated(yDir.XYZ() * -50);    //! Offset by 5 units in X and -5 units in Y

    if(occ->Context()->IsDisplayed(occ->plane_front)){
        occ->Context()->Erase(occ->plane_front,true);
        occ->plane_front.Nullify();
    }

    occ->plane_front=draw_primitives().draw_3d_surface(point1,point2,point3,point4);

    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge({origin.X()-50,origin.Y(),origin.Z()},{origin.X()+50,origin.Y(),origin.Z()});
    occ->aisbody_tcp_xaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_xaxis->SetColor(Quantity_NOC_RED);

    edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y()-50,origin.Z()},{origin.X(),origin.Y()+50,origin.Z()});
    occ->aisbody_tcp_yaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_yaxis->SetColor(Quantity_NOC_GREEN);

    edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y(),origin.Z()-50},{origin.X(),origin.Y(),origin.Z()+50});
    occ->aisbody_tcp_zaxis = new AIS_Shape(edge);
    occ->aisbody_tcp_zaxis->SetColor(Quantity_NOC_BLUE);

    occ->plane_front->AddChild(occ->aisbody_tcp_xaxis);
    occ->plane_front->AddChild(occ->aisbody_tcp_yaxis);
    occ->plane_front->AddChild(occ->aisbody_tcp_zaxis);

    occ->plane_front=draw->colorize(occ->plane_front,Quantity_NOC_GRAY50,0.95);
    occ->Context()->Display(occ->plane_front,AIS_Shaded,-1,true,AIS_DS_Displayed); //! non selectable shape.

    if(occ->Context()->IsDisplayed(occ->plane_user)){
        occ->Context()->Remove(occ->plane_user,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_left)){
        occ->Context()->Remove(occ->plane_left,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_top)){
        occ->Context()->Remove(occ->plane_top,true);
    }
    form->set_planepos(occ->plane);
}

void MainWindow::set_user_plane()
{
    gp_Pnt origin={0,0,0};
    // draw->print_gp_Pnt("plane origin:",origin);

    //! Calculate points on the plane based on the origin and directions
    gp_Pnt point1(origin.X()-50,origin.Y()-50,origin.Z()+0);
    gp_Pnt point2(origin.X()-50,origin.Y()+50,origin.Z()+0);
    gp_Pnt point3(origin.X()+50,origin.Y()+50,origin.Z()+0);
    gp_Pnt point4(origin.X()+50,origin.Y()-50,origin.Z()+0);

    if(occ->Context()->IsDisplayed(occ->plane_user)){
        occ->Context()->Erase(occ->plane_user,true);
        occ->plane_user.Nullify();
    }

    occ->plane_user=draw_primitives().draw_3d_surface(point1,point2,point3,point4);
    occ->plane_user=draw->rotate_translate_3d_quaternion(occ->plane_user,origin,occ->plane.Location(),occ->plane_rot_z*DegtoRad, occ->plane_rot_y*DegtoRad, occ->plane_rot_x*DegtoRad);

    if(show_axis){
        TopoDS_Edge edge = BRepBuilderAPI_MakeEdge({origin.X(),origin.Y(),origin.Z()},{origin.X()+50,origin.Y(),origin.Z()});
        occ->aisbody_tcp_xaxis = new AIS_Shape(edge);
        occ->aisbody_tcp_xaxis->SetColor(Quantity_NOC_RED);

        edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y(),origin.Z()},{origin.X(),origin.Y()+50,origin.Z()});
        occ->aisbody_tcp_yaxis = new AIS_Shape(edge);
        occ->aisbody_tcp_yaxis->SetColor(Quantity_NOC_GREEN);

        edge= BRepBuilderAPI_MakeEdge({origin.X(),origin.Y(),origin.Z()},{origin.X(),origin.Y(),origin.Z()+50});
        occ->aisbody_tcp_zaxis = new AIS_Shape(edge);
        occ->aisbody_tcp_zaxis->SetColor(Quantity_NOC_BLUE);

        occ->plane_user->AddChild(occ->aisbody_tcp_xaxis);
        occ->plane_user->AddChild(occ->aisbody_tcp_yaxis);
        occ->plane_user->AddChild(occ->aisbody_tcp_zaxis);
    }

    if(show_grid){
        //! Add pointcloud here.
        for(float x=-50.0; x<=50.0; x+=10.0){
            for(float y=-50.0; y<=50.0; y+=10.0){
                Handle(AIS_Shape) shape=draw->draw_3d_point({x,y,0});
                shape=draw->colorize(shape,Quantity_NOC_GRAY,0.9);
                occ->plane_user->AddChild(shape);
                //! occ->add_helpervec(shape); sketcher->rubberline,AIS_WireFrame,-1,true,AIS_DS_None
            }
        }
    }

    if(show_plane){
        occ->plane_user=draw->colorize(occ->plane_user,Quantity_NOC_GRAY50,0.95);
        occ->plane_user->Attributes()->SetDisplayMode(AIS_Shaded);
        occ->plane_user->SelectionType(-1);
        occ->Context()->Display(occ->plane_user,AIS_WireFrame,-1,true,AIS_DS_Displayed); //! non selectable shape.
    }

    if(occ->Context()->IsDisplayed(occ->plane_front)){
        occ->Context()->Remove(occ->plane_front,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_left)){
        occ->Context()->Remove(occ->plane_left,true);
    }
    if(occ->Context()->IsDisplayed(occ->plane_top)){
        occ->Context()->Remove(occ->plane_top,true);
    }

    occ->plane=occ->plane_reset;
    occ->plane.Transform(occ->plane_user->Transformation());

    form->set_planepos(occ->plane);
}

void MainWindow::on_action_top_triggered()
{
    occ->set_view_top();
}

void MainWindow::on_action_bottom_triggered()
{
    occ->set_view_bottom();
}

void MainWindow::on_action_front_triggered()
{
    occ->set_view_front();
}

void MainWindow::on_action_back_triggered()
{
    occ->set_view_back();
}

void MainWindow::on_action_left_triggered()
{
    occ->set_view_left();
}

void MainWindow::on_action_right_triggered()
{
    occ->set_view_right();
}

void MainWindow::on_action_zoom_plus_triggered()
{
    occ->zoom_plus();
}

void MainWindow::on_action_zoom_min_triggered()
{
    occ->zoom_min();
}

void MainWindow::on_action_zoom_all_triggered()
{
    occ->fit_all();
}

void MainWindow::on_action_view_3d_triggered()
{
    occ->set_view_3d();
}

void MainWindow::on_actionclick_plane_origin_triggered()
{
    mode=plane_origin;
    left_mouse_click_counter=0;
}

void MainWindow::on_action_snap_center_toggled(bool arg1)
{
    if(arg1){
        work->set_snap_center(1);
    } else {
        work->set_snap_center(0);
    }
}

void MainWindow::on_action_snap_end_toggled(bool arg1)
{
    if(arg1){
        work->set_snap_end(1);
    } else {
        work->set_snap_end(0);
    }
}

void MainWindow::on_action_snap_mid_toggled(bool arg1)
{
    if(arg1){
        work->set_snap_mid(1);
    } else {
        work->set_snap_mid(0);
    }
}

void MainWindow::on_action_snap_perpendicular_toggled(bool arg1)
{
    if(arg1){
        work->set_snap_perpendicular(1);
    } else {
        work->set_snap_perpendicular(0);
    }
}

void MainWindow::on_action_snap_tangent_toggled(bool arg1)
{
    if(arg1){
        work->set_snap_tangent(1);
    } else {
        work->set_snap_tangent(0);
    }
}

void MainWindow::on_action_snap_nearest_toggled(bool arg1)
{
    if(arg1){
        work->set_snap_nearest(1);
    } else {
        work->set_snap_nearest(0);
    }
}

void MainWindow::on_action_ortho_toggled(bool arg1)
{
    work->set_ortho(arg1);
}

void MainWindow::on_action_snap_toggled(bool arg1)
{
    form->set_snap_state(arg1);

    if(arg1){
        work->set_snap(1);
        work->set_snap_center(1);
        work->set_snap_mid(1);
        work->set_snap_end(1);
        work->set_snap_perpendicular(1);
        work->set_snap_tangent(1);

        ui->action_snap->setChecked(1);
        ui->action_snap_center->setChecked(1);
        ui->action_snap_mid->setChecked(1);
        ui->action_snap_end->setChecked(1);
        ui->action_snap_perpendicular->setChecked(1);
        ui->action_snap_tangent->setChecked(1);
    } else {
        work->set_snap(0);
        work->set_snap_center(0);
        work->set_snap_mid(0);
        work->set_snap_end(0);
        work->set_snap_perpendicular(0);
        work->set_snap_tangent(0);

        ui->action_snap->setChecked(0);
        ui->action_snap_center->setChecked(0);
        ui->action_snap_mid->setChecked(0);
        ui->action_snap_end->setChecked(0);
        ui->action_snap_perpendicular->setChecked(0);
        ui->action_snap_tangent->setChecked(0);
    }
}

void MainWindow::on_action_continous_triggered()
{
    occ->linetype=Aspect_TOL_SOLID;
    form->set_linetype("solid");
}

void MainWindow::on_action_dashed_triggered()
{
    occ->linetype=Aspect_TOL_DASH;
    form->set_linetype("dash");
}

void MainWindow::on_action_dottet_triggered()
{
    occ->linetype=Aspect_TOL_DOT;
    form->set_linetype("dot");
}

void MainWindow::on_action_mixed_triggered()
{
    occ->linetype=Aspect_TOL_DOTDASH;
    form->set_linetype("dotdash");
}

void MainWindow::on_action_user_triggered()
{
    occ->linetype=Aspect_TOL_USERDEFINED;
    form->set_linetype("user");
}

void MainWindow::on_action_hidden_triggered()
{
    occ->linetype=Aspect_TOL_EMPTY;
    form->set_linetype("empty");
}

void MainWindow::on_action_1mm_triggered()
{
    occ->linewidth=1;
    form->set_linewidth(1);
}

void MainWindow::on_action_2mm_triggered()
{
    occ->linewidth=2;
    form->set_linewidth(2);
}

void MainWindow::on_action_3mm_triggered()
{
    occ->linewidth=3;
    form->set_linewidth(3);
}

void MainWindow::on_action_delete_triggered()
{
    occ->remove_selected_shape();
}

void MainWindow::on_action_offset_triggered()
{
    mode=offset;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_copy_triggered()
{
    mode=copy;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_mirror_triggered()
{
    mode=mirror;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_move_triggered()
{
    mode=move_;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_rotate_triggered()
{
    mode=rotate;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_set_plane_origin_triggered()
{
    mode=set_plane_origin;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_1p_point_triggered()
{
    mode=point;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}

void MainWindow::on_action_trim_triggered()
{
    mode=trim;
    left_mouse_click_counter=0;
    right_mouse_click_counter=0;
}
