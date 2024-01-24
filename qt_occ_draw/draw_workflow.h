#ifndef DRAW_WORKFLOW_H
#define DRAW_WORKFLOW_H

#include "draw_primitives.h"
#include "QString"


class draw_workflow
{
public:
    draw_workflow();

    void set_style(Aspect_TypeOfLine linetype, Quantity_Color color, double linewidth, double transparancy);

    void set_plane_trsf(gp_Trsf trsf);
    void set_plane_point_on_z_axis(gp_Pnt p);
    void set_ortho(bool state);
    void set_ortho(bool state, gp_Trsf trsf);
    gp_Trsf plane_trsf();

    bool ortho();
    void ortho_toggle();

    void set_snap(bool state);
    void set_snap_mid(bool state);
    void set_snap_end(bool state);
    void set_snap_perpendicular(bool state);
    void set_snap_center(bool state);
    void set_snap_nearest(bool state);
    void set_snap_tangent(bool state);
    void set_snap_size(double size);
    void set_eye_line(gp_Lin eye_line);

    bool snap();
    bool snap_mid();
    bool snap_end();
    bool snap_perpendicular();
    bool snap_center();
    bool snap_nearest();
    bool snap_tangent();
    double snap_size();

    void set_snap(bool state, bool endpoint, bool midpoint, bool perpendicular, bool center, bool tangent, bool nearest, gp_Lin eye_line, double snap_dist);

    bool snap(Handle(AIS_InteractiveContext) &context,
              std::vector<Handle(AIS_Shape)> shapevec,
              gp_Pnt &pos,
              gp_Pnt leavingpos,
              uint shape_nr_excl);

    void ortho(gp_Pnt leavingpos, gp_Pnt &mousepos);

    int draw_selection(int &clicks,
                       gp_Pnt &pos,
                       QString &keyboard_text,
                       Handle(AIS_InteractiveContext) &context,
                       std::vector<opencascade::handle<AIS_Shape> > &shapevec,
                       QString &message, int &nr);

    bool draw_point(int &clicks, gp_Pnt &pos, QString &keyboard_text, Handle(AIS_InteractiveContext) &context, std::vector<Handle(AIS_Shape)> &shapevec, QString &message);
    bool draw_line(int &clicks, gp_Pnt &pos, QString &keyboard_text, Handle(AIS_InteractiveContext) &context, std::vector<Handle(AIS_Shape)> &shapevec, QString &message);
    bool draw_3p_arc(int &clicks, gp_Pnt &pos, QString &keyboard_text, Handle(AIS_InteractiveContext) &context, std::vector<Handle(AIS_Shape)> &shapevec, QString &message);
    bool draw_1p_pc_circle(int &clicks, gp_Pnt &pos, QString &keyboard_text, Handle(AIS_InteractiveContext) &context, std::vector<Handle(AIS_Shape)> &shapevec, QString &message);

    bool trim(int &clicks_left,
              int &clicks_right,
              gp_Pnt &pos, QString &keyboard_text,
              Handle(AIS_InteractiveContext) &context,
              std::vector<Handle(AIS_Shape)> &shapevec,
              QString &message);

    void edit_point(Handle(AIS_InteractiveContext) &context,
                               std::vector<Handle(AIS_Shape)> &shapevec,
                               int shape_nr, gp_Pnt pos);
    void edit_line_start_point(Handle(AIS_InteractiveContext) &context,
                               std::vector<Handle(AIS_Shape)> &shapevec,
                               int shape_nr, gp_Pnt pos);
    void edit_line_end_point(Handle(AIS_InteractiveContext) &context,
                             std::vector<Handle(AIS_Shape)> &shapevec,
                             int shape_nr, gp_Pnt pos);
    void edit_arc_start_point(Handle(AIS_InteractiveContext) &context,
                              std::vector<Handle(AIS_Shape)> &shapevec,
                              int shape_nr, gp_Pnt pos);
    void edit_arc_way_point(Handle(AIS_InteractiveContext) &context,
                            std::vector<Handle(AIS_Shape)> &shapevec,
                            int shape_nr, gp_Pnt pos);
    void edit_arc_end_point(Handle(AIS_InteractiveContext) &context,
                            std::vector<Handle(AIS_Shape)> &shapevec,
                            int shape_nr, gp_Pnt pos);
    void edit_arc_center_point(Handle(AIS_InteractiveContext) &context,
                               std::vector<Handle(AIS_Shape)> &shapevec,
                               int shape_nr, gp_Pnt pos);

    bool move(int &clicks_left,
              int &clicks_right,
              gp_Pnt &pos, QString &keyboard_text,
              Handle(AIS_InteractiveContext) &context,
              std::vector<Handle(AIS_Shape)> &shapevec,
              QString &message);

    bool offset(int &clicks_left,
                int &clicks_right,
                gp_Pnt &pos, QString &keyboard_text,
                Handle(AIS_InteractiveContext) &context,
                std::vector<Handle(AIS_Shape)> &shapevec,
                gp_Pln plane,
                QString &message);


    bool copy(int &clicks_left,
              int &clicks_right,
              gp_Pnt &pos, QString &keyboard_text,
              Handle(AIS_InteractiveContext) &context,
              std::vector<Handle(AIS_Shape)> &shapevec,
              QString &message);

    bool rotate(int &clicks_left,
                int &clicks_right,
                gp_Pnt &pos, QString &keyboard_text,
                Handle(AIS_InteractiveContext) &context,
                std::vector<Handle(AIS_Shape)> &shapevec,
                QString &message);

    bool mirror(int &clicks_left,
                int &clicks_right,
                gp_Pnt &pos, QString &keyboard_text,
                Handle(AIS_InteractiveContext) &context,
                std::vector<Handle(AIS_Shape)> &shapevec,
                QString &message);

    bool get_point(int &clicks_left,
                          int &clicks_right,
                          gp_Pnt &pos, QString &keyboard_text,
                          Handle(AIS_InteractiveContext) &context,
                          std::vector<Handle(AIS_Shape)> &shapevec,
                          QString &message);

private:
    draw_primitives *draw=new draw_primitives();

    gp_Pnt p1,p2,p3;
    Handle(AIS_Shape) myRubberShape;
    Handle(AIS_Shape) mySnapSphere;

    Handle(AIS_Shape) mySelectionSphereStart;
    Handle(AIS_Shape) mySelectionSphereWay;
    Handle(AIS_Shape) mySelectionSphereEnd;
    Handle(AIS_Shape) mySelectionSphereCenter;

    Aspect_TypeOfLine myLinetype=Aspect_TOL_SOLID;
    double myLinewidth=1;
    Quantity_Color myColor=Quantity_NOC_WHITE;
    double myTransparancy=0;

    bool myOrtho=0;

    bool mySnap=0;
    bool mySnapEnd=0;
    bool mySnapMid=0;
    bool mySnapPerpendicular=0;
    bool mySnapNearest=0;
    bool mySnapCenter=0;
    bool mySnapTangent=0; //! Touching a circle with a line at the edge.
    double mySnapSize=0;
    gp_Lin myEyeLine;

    gp_Pnt myPlaneOrigin={0,0,0};
    gp_Pnt myPlanePointOnZAxis={0,0,0};
    gp_Trsf myPlaneTrsf;

    std::vector<int> myList={},mySecondList={};
    std::vector<Handle(AIS_Shape)> myTempShapeVec;


};

#endif // DRAW_WORKFLOW_H
