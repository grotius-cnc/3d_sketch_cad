#include "draw_workflow.h"

draw_workflow::draw_workflow()
{

}

void draw_workflow::set_style(Aspect_TypeOfLine linetype, Quantity_Color color, double linewidth, double transparancy){
    myLinetype=linetype;
    myColor=color;
    myLinewidth=linewidth;
    myTransparancy=transparancy;
}

void draw_workflow::set_ortho(bool state){
    myOrtho=state;
}

void draw_workflow::set_plane_trsf(gp_Trsf trsf){
    double x,y,z;

    trsf.Transforms(x,y,z);
    // std::cout<<"plane trsf x:"<<x<<" y:"<<y<<" z:"<<z<<std::endl;
    myPlaneTrsf=trsf;
}

void draw_workflow::set_plane_point_on_z_axis(gp_Pnt p){
    myPlanePointOnZAxis=p;
}

//! Set ortho on-off.
//! This ortho works in 3d space and aligns with the plane axis.
//! If you use a ais_plane shape as a plane, use the ais_shape->Transformation().
void draw_workflow::set_ortho(bool state, gp_Trsf trsf){
    myOrtho=state;
    myPlaneTrsf=trsf;
}

bool draw_workflow::ortho(){
    return myOrtho;
}

void draw_workflow::ortho_toggle(){
    myOrtho=!myOrtho;
}

//! The eye-line is the line from user (mid screen pos) to mousepos. The eye-line is a 3d ray.
//! We use this 3d ray to find close shapes.
void draw_workflow::set_snap(bool state, bool endpoint, bool midpoint, bool perpendicular, bool center, bool tangent, bool nearest, gp_Lin eye_line, double snap_dist){
    mySnap=state;
    mySnapEnd=endpoint;
    mySnapMid=midpoint;
    mySnapPerpendicular=perpendicular;
    mySnapCenter=center;
    mySnapTangent=tangent;
    mySnapNearest=nearest;
    myEyeLine=eye_line;
    mySnapSize=snap_dist;
}

void draw_workflow::set_snap(bool state){
    mySnap=state;
}

void draw_workflow::set_snap_mid(bool state){
    mySnapMid=state;
}

void draw_workflow::set_snap_end(bool state){
    mySnapEnd=state;
}

void draw_workflow::set_snap_perpendicular(bool state){
    mySnapPerpendicular=state;
}

void draw_workflow::set_snap_center(bool state){
    mySnapCenter=state;
}

void draw_workflow::set_snap_tangent(bool state){
    mySnapTangent=state;
}

void draw_workflow::set_snap_nearest(bool state){
    mySnapNearest=state;
}

void draw_workflow::set_snap_size(double size){
    mySnapSize=size;
}

void draw_workflow::set_eye_line(gp_Lin eye_line){
    myEyeLine=eye_line;
}

bool draw_workflow::snap(){
    return mySnap;
}

bool draw_workflow::snap_mid(){
    return mySnapMid;
}

bool draw_workflow::snap_end(){
    return mySnapEnd;
}

bool draw_workflow::snap_perpendicular(){
    return mySnapPerpendicular;
}

bool draw_workflow::snap_center(){
    return mySnapCenter;
}

bool draw_workflow::snap_nearest(){
    return mySnapNearest;
}

bool draw_workflow::snap_tangent(){
    return mySnapTangent;
}

double draw_workflow::snap_size(){
    return mySnapSize;
}

gp_Trsf draw_workflow::plane_trsf(){
    return myPlaneTrsf;
}

bool draw_workflow::snap(Handle(AIS_InteractiveContext) &context,
                         std::vector<Handle(AIS_Shape)> shapevec,
                         gp_Pnt &pos,
                         gp_Pnt leavingpos,
                         uint shape_nr_excl){

    bool snap_ok=0;

    if(mySnap){
        gp_Pnt p;

        if(draw->intersect_3d_line_point(myEyeLine,shapevec,mySnapSize,p,shape_nr_excl)){
            pos=p;
            snap_ok=1;

            //! Logic to display a sphere.
            if(context->IsDisplayed(mySnapSphere)){
                mySnapSphere->SetShape(draw->draw_3d_sphere(mySnapSize,pos)->Shape());
                context->Redisplay(mySnapSphere,true);
            } else {
                mySnapSphere=draw->draw_3d_sphere(mySnapSize,pos);
                context->Display(mySnapSphere,AIS_Shaded,-1,true,AIS_DS_Displayed);
            }
            return 1;
        }


        if(draw->intersect_3d_line_line_shortest_route_line(myEyeLine,shapevec,leavingpos,p,mySnapSize,
                                                            mySnapEnd,
                                                            mySnapMid,
                                                            mySnapPerpendicular,
                                                            mySnapNearest,
                                                            shape_nr_excl)){
            pos=p;
            snap_ok=1;

            //! Logic to display a sphere.
            if(context->IsDisplayed(mySnapSphere)){
                mySnapSphere->SetShape(draw->draw_3d_sphere(mySnapSize,pos)->Shape());
                context->Redisplay(mySnapSphere,true);
            } else {
                mySnapSphere=draw->draw_3d_sphere(mySnapSize,pos);
                context->Display(mySnapSphere,AIS_Shaded,-1,true,AIS_DS_Displayed);
            }
            return 1;
        }

        if(draw->intersect_3d_line_arc_shortest_route_line(myEyeLine,shapevec,p,mySnapSize,
                                                           mySnapEnd,
                                                           mySnapMid,
                                                           mySnapCenter,
                                                           mySnapNearest,
                                                           shape_nr_excl)){
            pos=p;
            snap_ok=1;

            //! Logic to display a sphere.
            if(context->IsDisplayed(mySnapSphere)){
                mySnapSphere->SetShape(draw->draw_3d_sphere(mySnapSize,pos)->Shape());
                context->Redisplay(mySnapSphere,true);
            } else {
                mySnapSphere=draw->draw_3d_sphere(mySnapSize,pos);
                context->Display(mySnapSphere,AIS_Shaded,-1,true,AIS_DS_Displayed);
            }
            return 1;
        }
    }

    context->Remove(mySnapSphere,true);
    return 0;
}

void draw_workflow::ortho(gp_Pnt leavingpos, gp_Pnt &mousepos){
    if(myOrtho){
        draw->to_ortho_plane(leavingpos,mousepos,myPlaneTrsf,p2);
        mousepos=p2;
    }
}

void draw_workflow::edit_point(Handle(AIS_InteractiveContext) &context,
                               std::vector<Handle(AIS_Shape)> &shapevec,
                               int shape_nr, gp_Pnt pos){
    gp_Pnt p;
    draw->get_point(shapevec.at(shape_nr),p);
    snap(context,shapevec,pos,p,shape_nr);
    draw->edit_3d_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}

void draw_workflow::edit_line_start_point(Handle(AIS_InteractiveContext) &context,
                                          std::vector<Handle(AIS_Shape)> &shapevec,
                                          int shape_nr, gp_Pnt pos){
    gp_Pnt p1,p2;
    draw->get_line_points(shapevec.at(shape_nr),p1,p2);

    snap(context,shapevec,pos,p2,shape_nr);
    draw->edit_3d_line_start_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}

void draw_workflow::edit_line_end_point(Handle(AIS_InteractiveContext) &context,
                                        std::vector<Handle(AIS_Shape)> &shapevec,
                                        int shape_nr, gp_Pnt pos){


    gp_Pnt p1,p2;
    draw->get_line_points(shapevec.at(shape_nr),p1,p2);

    snap(context,shapevec,pos,p1,shape_nr);
    draw->edit_3d_line_end_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}

void draw_workflow::edit_arc_start_point(Handle(AIS_InteractiveContext) &context,
                                         std::vector<Handle(AIS_Shape)> &shapevec,
                                         int shape_nr, gp_Pnt pos){

    gp_Pnt p1,p2,pw,pc;
    draw->get_arc_points(shapevec.at(shape_nr),p1,p2,pw,pc);

    snap(context,shapevec,pos,pos,shape_nr);
    draw->edit_3d_arc_start_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}

void draw_workflow::edit_arc_way_point(Handle(AIS_InteractiveContext) &context,
                                       std::vector<Handle(AIS_Shape)> &shapevec,
                                       int shape_nr, gp_Pnt pos){

    gp_Pnt p1,p2,pw,pc;
    draw->get_arc_points(shapevec.at(shape_nr),p1,p2,pw,pc);

    snap(context,shapevec,pos,pos,shape_nr);
    draw->edit_3d_arc_way_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}


void draw_workflow::edit_arc_end_point(Handle(AIS_InteractiveContext) &context,
                                       std::vector<Handle(AIS_Shape)> &shapevec,
                                       int shape_nr, gp_Pnt pos){

    gp_Pnt p1,p2,pw,pc;
    draw->get_arc_points(shapevec.at(shape_nr),p1,p2,pw,pc);

    snap(context,shapevec,pos,pos,shape_nr);
    draw->edit_3d_arc_end_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}

void draw_workflow::edit_arc_center_point(Handle(AIS_InteractiveContext) &context,
                                          std::vector<Handle(AIS_Shape)> &shapevec,
                                          int shape_nr, gp_Pnt pos){

    gp_Pnt p1,p2,pw,pc;
    draw->get_arc_points(shapevec.at(shape_nr),p1,p2,pw,pc);

    snap(context,shapevec,pos,pc,shape_nr);
    draw->edit_3d_arc_center_point(shapevec.at(shape_nr),pos);
    context->Redisplay(shapevec.at(shape_nr),true);
}

bool draw_workflow::draw_point(int &clicks,                                  //! Mouse click counter.
                               gp_Pnt &pos,                                  //! Mouse position.
                               QString &keyboard_text,                       //! Keyboard input.
                               Handle(AIS_InteractiveContext) &context,      //! Update opencascade context.
                               std::vector<Handle(AIS_Shape)> &shapevec,     //! Update shapevec with new final shape.
                               QString &message){                            //! Sent message to user.

    switch (clicks) {

    case 0: //! Init.
        context->ClearSelected(true);
        clicks++;
        break;

    case 1: //! Move to startpos, wait for mouse click. Snap is active.
        message="Mode point, click startpoint, or use keyboard input. \n0,0,0";

        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks++;
        }

        if(myRubberShape.IsNull()){
            myRubberShape=draw->draw_3d_point(pos);
            myRubberShape=draw->set_colorize_linetype(myRubberShape,myColor,myTransparancy,myLinetype,myLinewidth);
        } else {
            myRubberShape->SetShape(draw->draw_3d_point(pos)->Shape());
        }
        draw->draw(context,myRubberShape,0);

        break;

    case 2: //! Return final shape and hide rubber shape from context.
        message="Mode point, done.";

        //! Remove temponary line and sphere.
        context->Remove(myRubberShape,true);
        context->Remove(mySnapSphere,true);

        //! Add final shape to shapevec and update display.
        shapevec.push_back(draw->draw_3d_point(pos));
        shapevec.back()=draw->set_colorize_linetype(shapevec.back(),myColor,myTransparancy,myLinetype,myLinewidth);
        context->Display(shapevec.back(),true);

        clicks=0;
        return 1;
    }

    return 0;
}

//! This function automate's the draw of a line in 3d space, using mouse and or keyboard input.
//! It has snap F3 & ortho F8 integrated. It sends info message's back.
//! It display's a preview line while constructing the final shape, the rubberline.
//! When the final shape is created, it updates the display context, and it add's the new shape to the shapevec.
bool draw_workflow::draw_line(int &clicks,                                  //! Mouse click counter.
                              gp_Pnt &pos,                                  //! Mouse position.
                              QString &keyboard_text,                       //! Keyboard input.
                              Handle(AIS_InteractiveContext) &context,      //! Update opencascade context.
                              std::vector<Handle(AIS_Shape)> &shapevec,     //! Update shapevec with new final shape.
                              QString &message){                            //! Sent message to user.

    switch (clicks) {

    case 0: //! Init.
        context->ClearSelected(true);
        clicks++;
        break;

    case 1: //! Move to startpos, wait for mouse click. Snap is active.
        message="Mode line, click startpoint, or use keyboard input. \n0,0,0 or relative @0,0,0 or lenght l0.";

        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks++;
        }

        break;

    case 2: //! Set startpos, set the rubber shape start values.
        p1=p2=pos;
        myRubberShape=draw->draw_3d_line(p1,p2);
        myRubberShape=draw->set_colorize_linetype(myRubberShape,myColor,myTransparancy,myLinetype,myLinewidth);
        context->Display(myRubberShape,AIS_WireFrame,-1,true,AIS_DS_None);
        context->Remove(mySnapSphere,true);
        clicks++;
        break;

    case 3: //! Snap to endpos, show preview rubber shape.
        message="Mode line, click endpoint, or use keyboard input. \n0,0,0 or relative @0,0,0 or lenght l0.";

        snap(context,shapevec,pos,p1,-1);
        ortho(p1,pos);
        p2=pos;

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,p2,p1,p2);
            keyboard_text="";
            clicks++;
        }

        myRubberShape->SetShape(draw->draw_3d_line(p1,p2)->Shape());
        context->Redisplay(myRubberShape,true);
        break;

    case 4: //! Return final shape and hide rubber shape from context.
        message="Mode line, done.";

        //! Remove temponary line and sphere.
        context->Remove(myRubberShape,true);
        context->Remove(mySnapSphere,true);

        //! Add final shape to shapevec and update display.
        shapevec.push_back(draw->draw_3d_line(p1,p2));
        shapevec.back()=draw->set_colorize_linetype(shapevec.back(),myColor,myTransparancy,myLinetype,myLinewidth);
        context->Display(shapevec.back(),true);

        clicks=0;
        return 1;
    }

    return 0;
}

//! Draw a arc in 3d space. Given arc start-, way-, endpoint.
bool draw_workflow::draw_3p_arc(int &clicks,
                                gp_Pnt &pos,
                                QString &keyboard_text,
                                Handle(AIS_InteractiveContext) &context,
                                std::vector<Handle(AIS_Shape)> &shapevec,
                                QString &message){

    switch (clicks) {

    case 0:
        draw_line(clicks,pos,keyboard_text,context,shapevec,message);
        break;

    case 1: //! Move to startpos, wait for mouse click. Snap is active.
        draw_line(clicks,pos,keyboard_text,context,shapevec,message);
        message="Mode arc, click startpoint, or use keyboard input. \n0,0,0 or relative @0,0,0 or lenght l0.";
        break;

    case 2: //! Construct rubbershape as line.
        draw_line(clicks,pos,keyboard_text,context,shapevec,message);
        break;

    case 3: //! Preview rubbershape as line.
        draw_line(clicks,pos,keyboard_text,context,shapevec,message);
        message="Mode line, click waypoint, or use keyboard input. \n0,0,0 or relative @0,0,0 or lenght l0.";
        break;

    case 4: //! Preview arc.
        message="Mode arc, click endpoint, or use keyboard input. \n0,0,0 or relative @0,0,0 or lenght l0.";

        snap(context,shapevec,pos,p1,-1);
        p3=pos;

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,p3,p2,p3);
            keyboard_text="";
            clicks++;
        }

        myRubberShape->SetShape(draw->draw_3p_3d_arc(p1,p2,p3)->Shape());
        draw->draw(context,myRubberShape,0);

        break;
    case 5:
        message="Mode arc, done.";

        //! Remove temponary line and sphere.
        context->Remove(myRubberShape,true);
        context->Remove(mySnapSphere,true);

        //! Add final shape to shapevec and update display.
        shapevec.push_back(draw->draw_3p_3d_arc(p1,p2,p3));
        shapevec.back()=draw->set_colorize_linetype(shapevec.back(),myColor,myTransparancy,myLinetype,myLinewidth);
        shapevec.back()->AddChild(draw->draw_3d_point(draw->get_arc_centerpoint(shapevec.back())));
        context->Display(shapevec.back(),true);

        clicks=0;
        return 1;
    }
    return 0;
}

bool draw_workflow::draw_1p_pc_circle(int &clicks,
                                      gp_Pnt &pos,
                                      QString &keyboard_text,
                                      Handle(AIS_InteractiveContext) &context,
                                      std::vector<Handle(AIS_Shape)> &shapevec,
                                      QString &message){

    double radius=0;
    gp_Quaternion quad;
    gp_Mat rotationMatrix;

    switch (clicks) {

    case 0:
        context->ClearSelected(true);
        clicks++;
        break;

    case 1:
        message="Mode circle, click centerpoint, or use keyboard input. \n0,0,0 or relative @0,0,0 or lenght l0.";

        snap(context,shapevec,pos,pos,-1);
        p1=pos;

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos,pos,p1);
            keyboard_text="";
            clicks++;
        }

        break;
    case 2:
        message="Mode circle, click waypoint.";

        snap(context,shapevec,pos,p1,-1);
        p2=pos;

        if(p1.Distance(p2)==0){
            p2.SetXYZ({p1.X()+0.01,p1.Y(),p1.Z()});
        }

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos,p1,p2);
            keyboard_text="";
            clicks++;
        }

        radius=p1.Distance(p2);
        quad=myPlaneTrsf.GetRotation();
        rotationMatrix=quad.GetMatrix();

        if(myRubberShape.IsNull()){
            myRubberShape=draw->draw_3d_pc_circle(p1,gp_Dir(rotationMatrix.Value(1, 3), rotationMatrix.Value(2, 3), rotationMatrix.Value(3, 3)),radius);
            myRubberShape=draw->set_colorize_linetype(myRubberShape,myColor,myTransparancy,myLinetype,myLinewidth);
        } else {
            myRubberShape->SetShape(draw->draw_3d_pc_circle(p1,gp_Dir(rotationMatrix.Value(1, 3), rotationMatrix.Value(2, 3), rotationMatrix.Value(3, 3)),radius)->Shape());
        }
        draw->draw(context,myRubberShape,0);

        break;

    case 3:
        message="Mode circle, done.";

        //! Remove temponary line and sphere.
        context->Remove(myRubberShape,true);
        context->Remove(mySnapSphere,true);

        radius=p1.Distance(p2);
        quad=myPlaneTrsf.GetRotation();
        rotationMatrix=quad.GetMatrix();

        //! Add final shape to shapevec and update display.
        shapevec.push_back(draw->draw_3d_pc_circle(p1,gp_Dir(rotationMatrix.Value(1, 3), rotationMatrix.Value(2, 3), rotationMatrix.Value(3, 3)),radius));
        shapevec.back()=draw->set_colorize_linetype(shapevec.back(),myColor,myTransparancy,myLinetype,myLinewidth);
        shapevec.back()->AddChild(draw->draw_3d_point(draw->get_arc_centerpoint(shapevec.back())));
        draw->draw(context,shapevec.back(),1);

        clicks=0;

        std::cout<<"shapevecsize:"<<shapevec.size()<<std::endl;

        return 1;
    }

    return 0;

}

bool draw_workflow::trim(int &clicks_left,
                         int &clicks_right,
                         gp_Pnt &pos,
                         QString &keyboard_text,
                         Handle(AIS_InteractiveContext) &context,
                         std::vector<Handle(AIS_Shape)> &shapevec,
                         QString &message){

    switch (clicks_left) {

    case 0:
        context->ClearSelected(true);
        clicks_left++;
        break;
    case 1:

        draw->get_highlighted_shapeveclist(context,shapevec,myList);
        message="mode trim, click on the object piece to be removed.";

        if(myList.size()>0){
            context->ClearSelected(true);
            clicks_left++;
        }

        if(myList.size()==0){
            clicks_left=0;
        }


        break;
    case 2:
        message="Mode trim, select boundary object.";
              draw->get_highlighted_shapeveclist(context,shapevec,mySecondList);
        //        if(mySecondList.size()>0){
        //            draw->trim_3d_line_line_one_boundary(shapevec.at(myList.front()),shapevec.at(mySecondList.front()),pos);
        //            draw->draw(context,shapevec.at(myList.front()),1);
        //            clicks_left=0;
        //            clicks_right=0;
        //            return 1;
        //        }
        std::cout<<"myListSize:"<<myList.size()<<std::endl;
        std::cout<<"mySecondListSize:"<<mySecondList.size()<<std::endl;

        clicks_left=2;
        break;
    }
    return 0;
}

//! Draw blue and red dot's if a shape is selected by mouse click.
int draw_workflow::draw_selection(int &clicks, gp_Pnt &pos, QString &keyboard_text,
                                  Handle(AIS_InteractiveContext) &context,
                                  std::vector<Handle(AIS_Shape)> &shapevec,
                                  QString &message, int &nr){

    message="Mode selection";

    context->Remove(myRubberShape,1);

    std::vector<int> list;
    draw->get_highlighted_shapeveclist(context,shapevec,list);

    if(list.size()>0){

        nr=list.front();

        Handle(Standard_Type) type=draw->get_shapetype(shapevec.at(nr));
        clicks=0;

        if(type==STANDARD_TYPE(Geom_Point)){

            message+=", point selected.";

            gp_Pnt p1;
            draw->get_point(shapevec.at(nr),p1);

            if(context->IsDisplayed(mySelectionSphereStart)){
                mySelectionSphereStart->SetShape(draw->draw_3d_sphere(mySnapSize,p1)->Shape());
                gp_Pnt pi;
                bool inSnapRange=draw->intersect_3d_line_point(myEyeLine,p1,mySnapSize,pi);
                //! std::cout<<"point in range:"<<inSnapRange<<std::endl;
                if(inSnapRange){
                    if(!context->IsDisplayed(mySnapSphere)){
                        mySnapSphere=draw->draw_3d_sphere(mySnapSize,p1);
                    }
                    draw->draw(context,mySnapSphere,false,Quantity_NOC_RED);
                    return 7;
                } else {
                    draw->draw(context,mySelectionSphereStart,false,Quantity_NOC_BLUE);
                    context->Remove(mySnapSphere,true);
                }
            } else {
                mySelectionSphereStart=draw->draw_3d_sphere(mySnapSize,p1);
                draw->draw(context,mySelectionSphereStart,false,Quantity_NOC_BLUE);
                context->Remove(mySnapSphere,true);
            }
        }

        if(type==STANDARD_TYPE(Geom_Line)){

            message+=", line selected.";

            gp_Pnt p1,p2;
            draw->get_line_points(shapevec.at(nr),p1,p2);

            if(context->IsDisplayed(mySelectionSphereStart)){
                mySelectionSphereStart->SetShape(draw->draw_3d_sphere(mySnapSize,p1)->Shape());
                mySelectionSphereEnd->SetShape(draw->draw_3d_sphere(mySnapSize,p2)->Shape());

                gp_Pnt p;
                if(draw->intersect_3d_line_line_shortest_route_line(myEyeLine,{shapevec.at(nr)},pos,p,mySnapSize,1,0,0,0)){

                    if(!context->IsDisplayed(mySnapSphere)){
                        mySnapSphere=draw->draw_3d_sphere(mySnapSize,p);
                    }
                    draw->draw(context,mySnapSphere,false,Quantity_NOC_RED);

                    if(p.Distance(p1)<1e-6){
                        return 1;
                    } else {
                        return 2;
                    }

                } else {
                    draw->draw(context,mySelectionSphereStart,false,Quantity_NOC_BLUE);
                    draw->draw(context,mySelectionSphereEnd,false,Quantity_NOC_BLUE);
                    context->Remove(mySnapSphere,true);
                }
            } else {
                mySelectionSphereStart=draw->draw_3d_sphere(mySnapSize,p1);
                mySelectionSphereEnd=draw->draw_3d_sphere(mySnapSize,p2);
                draw->draw(context,mySelectionSphereStart,false,Quantity_NOC_BLUE);
                draw->draw(context,mySelectionSphereEnd,false,Quantity_NOC_BLUE);
                context->Remove(mySnapSphere,true);
            }
        }
        if(type==STANDARD_TYPE(Geom_Circle)){

            message+=", arc selected.";

            gp_Pnt p1,p2,pw,pc;
            draw->get_arc_points(shapevec.at(nr),p1,p2,pw,pc);

            // bool isCircle=draw->get_closed_arc(shapevec.at(nr));

            if(context->IsDisplayed(mySelectionSphereWay)){
                mySelectionSphereStart->SetShape(draw->draw_3d_sphere(mySnapSize,p1)->Shape());
                mySelectionSphereEnd->SetShape(draw->draw_3d_sphere(mySnapSize,p2)->Shape());
                mySelectionSphereWay->SetShape(draw->draw_3d_sphere(mySnapSize,pw)->Shape());
                mySelectionSphereCenter->SetShape(draw->draw_3d_sphere(mySnapSize,pc)->Shape());

                gp_Pnt p=pos;
                if(draw->intersect_3d_line_arc_shortest_route_line(myEyeLine,{shapevec.at(nr)},p,mySnapSize,1,1,1,0)){

                    if(!context->IsDisplayed(mySnapSphere)){
                        mySnapSphere=draw->draw_3d_sphere(mySnapSize,p);
                    }
                    draw->draw(context,mySnapSphere,false,Quantity_NOC_RED);

                    if(p.Distance(p1)<1e-6){
                        return 3;
                    }
                    if(p.Distance(pw)<1e-6){
                        return 4;
                    }
                    if(p.Distance(p2)<1e-6){
                        return 5;
                    }
                    if(p.Distance(pc)<1e-6){
                        return 6;
                    }

                } else {
                    draw->draw(context,mySelectionSphereStart,false,Quantity_NOC_BLUE);
                    draw->draw(context,mySelectionSphereEnd,false,Quantity_NOC_BLUE);
                    draw->draw(context,mySelectionSphereWay,false,Quantity_NOC_BLUE);
                    draw->draw(context,mySelectionSphereCenter,false,Quantity_NOC_BLUE);
                    context->Remove(mySnapSphere,true);
                }
            } else {
                mySelectionSphereStart=draw->draw_3d_sphere(mySnapSize,p1);
                mySelectionSphereEnd=draw->draw_3d_sphere(mySnapSize,p2);
                draw->draw(context,mySelectionSphereStart,false,Quantity_NOC_BLUE);
                draw->draw(context,mySelectionSphereEnd,false,Quantity_NOC_BLUE);

                mySelectionSphereWay=draw->draw_3d_sphere(mySnapSize,pw);
                mySelectionSphereCenter=draw->draw_3d_sphere(mySnapSize,pc);
                draw->draw(context,mySelectionSphereWay,false,Quantity_NOC_BLUE);
                draw->draw(context,mySelectionSphereCenter,false,Quantity_NOC_BLUE);
                context->Remove(mySnapSphere,true);
            }
        }

    } else {
        context->Remove(mySelectionSphereStart,true);
        context->Remove(mySelectionSphereWay,true);
        context->Remove(mySelectionSphereEnd,true);
        context->Remove(mySelectionSphereCenter,true);
        context->Remove(mySnapSphere,true);
    }

    message+="\nTotal selected:";
    message+=QString::number(list.size());
    return 0;
}

bool draw_workflow::move(int &clicks_left,
                         int &clicks_right,
                         gp_Pnt &pos, QString &keyboard_text,
                         Handle(AIS_InteractiveContext) &context,
                         std::vector<Handle(AIS_Shape)> &shapevec,
                         QString &message){


    switch (clicks_left) {

    case 0:
        context->ClearSelected(true);
        clicks_left++;
        break;
    case 1:
        draw->get_highlighted_shapeveclist(context,shapevec,myList);

        message="mode move, select objects, shift+click to add more objects. "
                "Right click to specify base point. Selections:"+QString::number(myList.size());

        switch (clicks_right) {
        case 1:

            if(myList.size()>0){
                clicks_left=3;
            } else {
                clicks_right=0;
            }
            break;
        }
    case 2:
        if(clicks_right==0){
            clicks_left=1;
        }

        break;
    case 3:
        message="Left click move base point. \n0,0,0";

        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;
    case 4:
        p1=pos;
        clicks_left++;

        //! Static preview:
        myTempShapeVec.clear();
        draw->copy_shapes(myList,shapevec,{0,0,0},{0,0,0},myTempShapeVec);
        draw->draw(context,myTempShapeVec,0);

        break;
    case 5:
        message="Left click move target point. \n0,0,0 or relative @0,0,0";

        snap(context,shapevec,pos,p1,-1);
        snap(context,myTempShapeVec,pos,pos,-1); //! Snap also to the static duplicates.

        draw->move_shape_preview_3d(myList,shapevec,p1,pos,context);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos,p1,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;
    case 6:
        p2=pos;
        clicks_left++;
        break;
    case 7:
        //! Set shape coordinates.
        draw->move_shape_permanent_3d(myList,shapevec,p1,p2);

        draw->draw(context,shapevec,1);

        clicks_left=0;
        clicks_right=0;

        //! Remove static preview.
        draw->erase(context,myTempShapeVec);

        //! Remove if displayed.
        context->Remove(mySnapSphere,true);

        return 1;
    }
    return 0;
}

bool draw_workflow::copy(int &clicks_left,
                         int &clicks_right,
                         gp_Pnt &pos, QString &keyboard_text,
                         Handle(AIS_InteractiveContext) &context,
                         std::vector<Handle(AIS_Shape)> &shapevec,
                         QString &message){

    switch (clicks_left) {

    case 0:
        context->ClearSelected(true);
        clicks_left++;
        break;
    case 1:
        draw->get_highlighted_shapeveclist(context,shapevec,myList);

        message="mode move, select objects, shift+click to add more objects. "
                "Right click to specify base point. Selections:"+QString::number(myList.size());

        switch (clicks_right) {
        case 1:

            if(myList.size()>0){
                clicks_left=3;
            } else {
                clicks_right=0;
            }
            break;
        }
    case 2:
        if(clicks_right==0){
            clicks_left=1;
        }

        break;
    case 3:
        message="Left click move base point. \n0,0,0";

        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;
    case 4:
        p1=pos;
        clicks_left++;

        //! Static preview:
        myTempShapeVec.clear();
        draw->copy_shapes(myList,shapevec,{0,0,0},{0,0,0},myTempShapeVec);
        draw->copy_shapevec_to_shapevec(shapevec,myTempShapeVec);
        draw->draw(context,shapevec,1);

        break;
    case 5:
        message="Left click move target point. \n0,0,0 or relative @0,0,0";

        snap(context,shapevec,pos,p1,-1);
        snap(context,myTempShapeVec,pos,pos,-1); //! Snap also to the static duplicates.

        draw->move_shape_preview_3d(myList,shapevec,p1,pos,context);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos,p1,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;
    case 6:
        p2=pos;
        clicks_left++;
        break;
    case 7:
        //! Set shape coordinates.
        draw->move_shape_permanent_3d(myList,shapevec,p1,p2);
        draw->draw(context,shapevec,1);

        clicks_left=0;
        clicks_right=0;

        //! Remove if displayed.
        context->Remove(mySnapSphere,true);

        return 1;
    }
    return 0;
}

bool draw_workflow::rotate(int &clicks_left,
                           int &clicks_right,
                           gp_Pnt &pos, QString &keyboard_text,
                           Handle(AIS_InteractiveContext) &context,
                           std::vector<Handle(AIS_Shape)> &shapevec,
                           QString &message){

    switch (clicks_left) {

    case 0: // Init.
        context->ClearSelected(true);
        clicks_left++;
        break;
    case 1:
        draw->get_highlighted_shapeveclist(context,shapevec,myList);

        message="mode rotate, select objects, shift+click to add more objects. "
                "Right click to specify mirror line first point. Selections:"+QString::number(myList.size());

        switch (clicks_right) {
        case 1:

            if(myList.size()>0){
                clicks_left=3;
            } else {
                clicks_right=0;
            }
            break;
        }
    case 2:
        if(clicks_right==0){
            clicks_left=1;
        }

        break;
    case 3:
        message="Left click rotate base point. \nOr input keyboard input value : 0,0,0";
        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks_left++;
        }

        break;
    case 4:
        p1=pos;
        clicks_left++;

        break;
    case 5:
        message="Left click rotate target point, \nOr input keyboard input value : 0,0,0";

        snap(context,shapevec,pos,p1,-1);
        ortho(p1,pos);

        if(p1.Distance(pos)>0){

            draw->erase(context,myTempShapeVec); //! Remove from display.
            myTempShapeVec.clear(); //! Clear temp vec.
            draw->copy_shapes(myList,shapevec,{0,0,0},{0,0,0},myTempShapeVec); //! Fill the temp vec with shapes to be mirrored.

            //! Rotation line, start at p1. Then p1 translated along myPlane z axis.
            gp_Pnt origin=myPlaneTrsf.TranslationPart();
            gp_Pnt point_along_x = origin.Translated(gp_Vec(1.0, 0.0, 0.0)).Transformed(myPlaneTrsf);
            gp_Pnt point_along_z = origin.Translated(gp_Vec(0.0, 0.0, 1.0)).Transformed(myPlaneTrsf);
            gp_Vec vec_z(origin,point_along_z);
            gp_Vec vec_x(origin,point_along_x);

            gp_Pnt p11=p1.Translated(vec_z);

            double angle;
            draw->get_angle_3p(point_along_x,origin,pos,vec_z,angle);

            //! Check for keyboard input.
            if(!keyboard_text.isEmpty()){
                angle=keyboard_text.toDouble();
            }

            draw->rotate_3d_shapevec_around_line(myTempShapeVec,angle*DegtoRad,p1,p11);

            draw->draw(context,myTempShapeVec,0); //! Preview.
        }

        break;
    case 6:
        draw->erase(context,myTempShapeVec); //! Remove from display.
        draw->copy_shapevec_to_shapevec(shapevec,myTempShapeVec); //! Add mirrored shapes to shapevec.
        draw->draw(context,shapevec,1); //! Display all.
        myTempShapeVec.clear(); //! Clear tempvec, optional.

        clicks_left=0;
        clicks_right=0;

        //! Remove if displayed.
        context->Remove(mySnapSphere,true);

        return 1;
    }
    return 0;
}

bool draw_workflow::mirror(int &clicks_left,
                           int &clicks_right,
                           gp_Pnt &pos, QString &keyboard_text,
                           Handle(AIS_InteractiveContext) &context,
                           std::vector<Handle(AIS_Shape)> &shapevec,
                           QString &message){

    switch (clicks_left) {

    case 0:
        context->ClearSelected(true);
        clicks_left++;
        break;
    case 1:
        draw->get_highlighted_shapeveclist(context,shapevec,myList);

        message="mode mirror, select objects, shift+click to add more objects. "
                "Right click to specify mirror line first point. Selections:"+QString::number(myList.size());

        switch (clicks_right) {
        case 1:

            if(myList.size()>0){
                clicks_left=3;
            } else {
                clicks_right=0;
            }
            break;
        }
    case 2:
        if(clicks_right==0){
            clicks_left=1;
        }

        break;
    case 3:
        message="Left click mirror line start point.";

        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;
    case 4:
        p1=pos;
        clicks_left++;

        break;
    case 5:
        message="Left click mirror line end point.";

        snap(context,shapevec,pos,p1,-1);

        if(p1.Distance(pos)>0){

            draw->erase(context,myTempShapeVec); //! Remove from display.
            myTempShapeVec.clear(); //! Clear temp vec.
            draw->copy_shapes(myList,shapevec,{0,0,0},{0,0,0},myTempShapeVec); //! Fill the temp vec with shapes to be mirrored.
            draw->mirror_3d_shape_on_line(myTempShapeVec,p1,pos); //! Mirror shapes.

            myTempShapeVec.push_back(draw->colorize(draw->draw_3d_line(p1,pos),Quantity_NOC_BLUE,0)); //! Mirror line.
            draw->draw(context,myTempShapeVec,0); //! Preview.
        }

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos,p1,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;
    case 6:
        p2=pos;
        clicks_left++;
        break;
    case 7:
        draw->erase(context,myTempShapeVec); //! Remove from display.
        draw->copy_shapevec_to_shapevec(shapevec,myTempShapeVec); //! Add mirrored shapes to shapevec.
        shapevec.pop_back(); //! Remove the mirror line.
        draw->draw(context,shapevec,1); //! Display all.
        myTempShapeVec.clear(); //! Clear tempvec, optional.

        clicks_left=0;
        clicks_right=0;

        //! Remove if displayed.
        context->Remove(mySnapSphere,true);

        return 1;
    }
    return 0;
}

bool draw_workflow::get_point(int &clicks_left,
                              int &clicks_right,
                              gp_Pnt &pos, QString &keyboard_text,
                              Handle(AIS_InteractiveContext) &context,
                              std::vector<Handle(AIS_Shape)> &shapevec,
                              QString &message){

    switch (clicks_left) {

    case 0: // Init.
        context->ClearSelected(true);
        clicks_left++;
        break;

    case 1:

        message="mode set_plane_origin, mouse left click for new plane origin position, or keyboard input : 0,0,0 + enter.";

        snap(context,shapevec,pos,pos,-1);

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;

    case 2:
        //! Ready.
        return 1;
    }

    return 0;
}

bool draw_workflow::offset(int &clicks_left,
                           int &clicks_right,
                           gp_Pnt &pos, QString &keyboard_text,
                           Handle(AIS_InteractiveContext) &context,
                           std::vector<Handle(AIS_Shape)> &shapevec,
                           gp_Pln plane,
                           QString &message){


    switch (clicks_left) {

    case 0:
        context->ClearSelected(true);
        clicks_left++;
        break;
    case 1:
        draw->get_highlighted_shapeveclist(context,shapevec,myList);

        message="mode offset, select objects, shift+click to add more objects. "
                "Right click to specify mirror line first point. Selections:"+QString::number(myList.size());

        switch (clicks_right) {
        case 1:

            if(myList.size()>0){
                clicks_left=3;
            } else {
                clicks_right=0;
            }
            break;
        }
    case 2:
        if(clicks_right==0){
            clicks_left=1;
        }

        break;
    case 3:
        message="Input keyboard offset value.";

        //! Check for keyboard input.
        if(!keyboard_text.isEmpty()){
            draw->text_input_to_point(keyboard_text,pos);
            keyboard_text="";
            clicks_left++;
        }
        break;

    case 4:
        message="Move mouse to offset side.";

        //! Copy selected shapes.
        draw->erase(context,myTempShapeVec); //! Remove from display.
        myTempShapeVec.clear(); //! Clear temp vec.
        draw->copy_shapes({myList.front()},shapevec,{0,0,0},{0,0,0},myTempShapeVec); //! Fill the temp vec with shapes to be mirrored.

        myTempShapeVec.back()=draw->draw_3d_offset(myList.front(),shapevec,pos,keyboard_text.toDouble(),plane);

        //! Set the color.
        myTempShapeVec.back()=draw->colorize(myTempShapeVec.back(),draw->get_color(shapevec.at(myList.front())),0);
        //! Set the type of line.
        myTempShapeVec.back()->Attributes()->SetWireAspect(shapevec.at(myList.front())->Attributes()->WireAspect());

        draw->draw(context,myTempShapeVec,0); //! Preview.

        break;
    case 5:
        //! Finish function.

        draw->erase(context,myTempShapeVec); //! Remove from display.
        draw->copy_shapevec_to_shapevec(shapevec,myTempShapeVec); //! Add mirrored shapes to shapevec.
        draw->draw(context,shapevec,1); //! Display all.
        myTempShapeVec.clear(); //! Clear tempvec, optional.

        clicks_left=0;
        clicks_right=0;

        //! Remove if displayed.
        context->Remove(mySnapSphere,true);
        break;
    }

    return 0;
}















