#include "sketcher.h"

Sketcher::Sketcher()
{

}

Quantity_Color Sketcher::QColorToQuantityColor(QColor color) {
    Quantity_Color ocColor(
                color.redF(),   // Red component (normalized)
                color.greenF(), // Green component (normalized)
                color.blueF(),  // Blue component (normalized)
                Quantity_TOC_RGB // Color model: RGB
                );
    return ocColor;
}

// Construct, scetch a line.
Handle(AIS_Line) Sketcher::sketch_3d_line_set_startpoint_rubberline(gp_Pnt p){

    myFirstPoint=new Geom_CartesianPoint(p);
    mySecondPoint=new Geom_CartesianPoint(p.X()+0.01,p.Y(),p.Z());
    rubberline = new AIS_Line(myFirstPoint,mySecondPoint);
    rubberline->SetColor(color);
    return rubberline;
}

Handle(AIS_Line) Sketcher::sketch_3d_line_show_endpoint_rubberline(gp_Pnt p){

    mySecondPoint->SetPnt(p);
    if(mySecondPoint->Distance(myFirstPoint)==0){
        mySecondPoint->SetX(myFirstPoint->X()+0.01);
    }
    rubberline->SetPoints(myFirstPoint,mySecondPoint);
    return rubberline;
}

gp_Pnt Sketcher::to_ortho(gp_Pnt p1, gp_Pnt p2){

    //gp_Pnt projected_point_on_plane= draw_primitives().projectPointOnPlane(p2, planeorigin, planevec);

    gp_Pnt pr=p1;
    double dx,dy,dz;

    dx=abs(p2.X()-p1.X());
    dy=abs(p2.Y()-p1.Y());
    dz=abs(p2.Z()-p1.Z());

    if(dx>dy && dx>dz){
        pr.SetX(p2.X());
    }
    if(dy>dx && dy>dz){
        pr.SetY(p2.Y());
    }
    if(dz>dx && dz>dy){
        pr.SetZ(p2.Z());
    }
    return pr;
}






















