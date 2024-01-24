// Copyright (c) 2021 OPEN CASCADE SAS
//
// This file is part of the examples of the Open CASCADE Technology software library.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE

//! Edited by Skynet Cyberdyne 01-2022.

#ifndef _OcctQtViewer_HeaderFile
#define _OcctQtViewer_HeaderFile

#include <Standard_WarningsDisable.hxx>
#include <QOpenGLWidget>
#include <Standard_WarningsRestore.hxx>

#include <AIS_InteractiveContext.hxx>
#include <AIS_ViewController.hxx>
#include <V3d_View.hxx>
#include <AIS_ViewCube.hxx>
#include "gp.hxx"

#include "draw_primitives.h"

//! OCCT 3D View.
class OcctQtViewer : public QOpenGLWidget, public AIS_ViewController
{
    Q_OBJECT
public:

    //! Main constructor.
    OcctQtViewer (QWidget* theParent = nullptr);

    //! Destructor.
    virtual ~OcctQtViewer();

    //! Return Viewer.
    const Handle(V3d_Viewer)& Viewer() const { return myViewer; }

    //! Return View.
    const Handle(V3d_View)& View() const { return myView; }

    //! Return AIS context.
    const Handle(AIS_InteractiveContext)& Context() const { return myContext; }

    //! Return OpenGL info.
    const QString& getGlInfo() const { return myGlInfo; }

    //! Minial widget size.
    virtual QSize minimumSizeHint() const override { return QSize(200, 200); }

    //! Default widget size.
    virtual QSize sizeHint()        const override { return QSize(720, 480); }

    //! Set the tranceparancy level of the shapevec.
    void set_tranceparancy(double value);

    //! Set the background color. Red,green,blue. 0-255.
    void set_backgroundcolor(double r, double g, double b);

    //! Enable the shape contours lines to be viewed.
    void show_boundary();
    void hide_boundary();

    //! Show or hide the navigation cube.
    void show_cube();
    void hide_cube();

    //! Shape preview mode.
    void show_as_wireframe();
    void show_as_shaded();

    //! Triedron axis origin.
    void show_triedron();
    void hide_triedron();

    //! Display mode.
    void set_orthographic();
    void set_perspective();

    void set_view_front();
    void set_view_back();
    void set_view_left();
    void set_view_right();
    void set_view_top();
    void set_view_bottom();
    void set_view_3d();

    void zoom_plus();
    void zoom_min();

    void redraw();
    void fit_all();
    bool ready();
    void show_shape(Handle(AIS_Shape) shape);
    void hide_shape(Handle(AIS_Shape) shape);
    void add_shapevec(Handle(AIS_Shape) shape);

    void add_shapevec(std::vector<Handle(AIS_Shape)> another_shapevec); //! Add user drawed shapes.
    void redraw_shapevec(std::vector<Handle(AIS_Shape)> shapevec);

    void add_helpervec(Handle(AIS_Shape) shape); //! Add shapes that are program used.

    void clear_objvec();

    void select_all();
    void remove_all();

    void undo();
    void remove_selected_shape();

    gp_Pnt mousepos;

    gp_Lin eyeline; //! Line from eye to mouse point. Use for ray intersect.

    bool project_mouse_to_plane=1;
    gp_Pln plane_reset={gp::Origin(), gp::DZ()};
    gp_Pln plane={gp::Origin(), gp::DZ()}; //! Drawing plane.

    Handle(AIS_Shape) plane_top;
    Handle(AIS_Shape) plane_left;
    Handle(AIS_Shape) plane_front;
    Handle(AIS_Shape) plane_user;

    double plane_rot_x=0, plane_rot_y=0, plane_rot_z=0;

    Handle(AIS_Shape) aisbody_tcp_xaxis; //! Red line.
    Handle(AIS_Shape) aisbody_tcp_yaxis; //! Green line.
    Handle(AIS_Shape) aisbody_tcp_zaxis; //! Blue line.

    // Handle(AIS_Trihedron) trihedron; //! Follows the plane.

    Handle(AIS_Shape) snap_sphere;
    void create_snap_sphere(double radius);
    void show_snap_sphere(gp_Pnt point);
    void hide_snap_sphere();

    bool selected_shape(Handle(AIS_Shape) &shape);
    bool selected_shapevec(int &nr);
    bool selected_shapevec(std::vector<int> &nrvec);
    Handle(AIS_Shape) selected_shape();

    bool detected_shape(Handle(AIS_Shape) &shape); //! Highlight during hovering.
    bool detected_shapevec(int &nr);
    Handle(AIS_Shape) detected_shape();
    void deselected_all();
    bool highlighted_shape(Handle(AIS_Shape) &shape);

    bool highlighted_interactive_shape(Handle(AIS_Shape) &shape);

    std::vector<Handle(AIS_Shape)> shapevec; //! Contains all user drawed shapes.
    std::vector<Handle(AIS_Shape)> helpervec; //! Contains grid's, plane's etc.
    std::vector<Handle(AIS_Shape)> recyclebin_shapevec; //! Stores removed shapes for cntr+z.
    //! Interactive objects.
    // std::vector<Handle(AIS_InteractiveObject)> objectvec;

    Aspect_TypeOfLine linetype=Aspect_TOL_SOLID;
    double linewidth=1;
    Quantity_Color color=Quantity_NOC_WHITE;
    double transparancy=0;

    Handle(AIS_InteractiveContext) myContext;
    Handle(V3d_View)               myView;

protected: // OpenGL events

    virtual void initializeGL() override;
    virtual void paintGL() override;
    //virtual void resizeGL(int , int ) override;

protected: // user input events

    virtual void closeEvent       (QCloseEvent*  theEvent) override;
    virtual void keyPressEvent    (QKeyEvent*    theEvent) override;
    virtual void mousePressEvent  (QMouseEvent*  theEvent) override;
    virtual void mouseReleaseEvent(QMouseEvent*  theEvent) override;
    virtual void mouseMoveEvent   (QMouseEvent*  theEvent) override;
    virtual void wheelEvent       (QWheelEvent*  theEvent) override;

private:

    //! Dump OpenGL info.
    void dumpGlInfo (bool theIsBasic);

    //! Request widget paintGL() event.
    void updateView();

    //! Handle view redraw.
    virtual void handleViewRedraw (const Handle(AIS_InteractiveContext)& theCtx,
                                   const Handle(V3d_View)& theView) override;



private:
    Handle(V3d_Viewer)             myViewer;
    Handle(AIS_ViewCube)           myViewCube;

    GLint m_vaoHandle;
    QString myGlInfo;
    bool myIsCoreProfile;


};

#endif // _OcctQtViewer_HeaderFile













