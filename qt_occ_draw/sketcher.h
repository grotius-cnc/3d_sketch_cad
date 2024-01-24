#ifndef SKETCHER_H
#define SKETCHER_H

#include <QColor>
#include "AIS_Line.hxx"
#include "AIS_Shape.hxx"
#include "Geom_CartesianPoint.hxx"
#include <gp_Pnt.hxx>
#include <gp_Pln.hxx>
#include <draw_primitives.h>

class Sketcher
{
public:
    Sketcher();

    // Scetch a line.
    Handle(AIS_Line) sketch_3d_line_set_startpoint_rubberline(gp_Pnt p);
    Handle(AIS_Line) sketch_3d_line_show_endpoint_rubberline(gp_Pnt p);

    Handle(AIS_Line) rubberline;
    Handle(AIS_Shape) rubberarc;
    Handle(AIS_Shape) rubbershape_1;
    Handle(AIS_Shape) rubbershape_2;
    Handle(AIS_Shape) fillet_shape;
    std::vector<Handle(AIS_Shape)> rubbershapevec;
    std::vector<Handle(AIS_Shape)> copyshapevec;

    Quantity_Color QColorToQuantityColor(QColor color);
    Quantity_Color color=Quantity_NOC_GRAY50;

    Handle(Geom_CartesianPoint) myFirstPoint;
    Handle(Geom_CartesianPoint)	mySecondPoint;

    //! Given a line startpoint p1, given a current mousepos p2. Calculate orhto pos.
    gp_Pnt to_ortho(gp_Pnt p1, gp_Pnt p2);

    std::vector<int> copy_list;
    gp_Pnt copy_ref_1;
    gp_Pnt copy_ref_2;

    bool ortho=0; //! F8 toggle on-off.
    bool snap=0; //! F3 toggle on-off.
    bool snap_center=0;
    bool snap_mid=0;
    bool snap_nearest=0;
    bool snap_end=0;
    bool snap_perpendicular=0;

    //gp_Pnt planeorigin={0,0,0};
    //gp_Vec planevec=gp::DZ();
};

#endif // SKETCHER_H
