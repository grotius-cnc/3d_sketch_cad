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

//! Edited by Skynet Cyberdyne 01-2021.

#include <QApplication>
#include <QMessageBox>
#include <QMouseEvent>

#ifdef _WIN32
#include <windows.h>
#endif
#include <OpenGl_Context.hxx>

#include "OcctQtViewer.h"

#include <Standard_WarningsDisable.hxx>

#include <Standard_WarningsRestore.hxx>

#include <AIS_Shape.hxx>
#include <AIS_ViewCube.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Aspect_NeutralWindow.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <Message.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <OpenGl_FrameBuffer.hxx>

namespace
{
//! Map Qt buttons bitmask to virtual keys.
Aspect_VKeyMouse qtMouseButtons2VKeys (Qt::MouseButtons theButtons)
{
    Aspect_VKeyMouse aButtons = Aspect_VKeyMouse_NONE;
    if ((theButtons & Qt::LeftButton) != 0)
    {
        aButtons |= Aspect_VKeyMouse_LeftButton;
    }
    if ((theButtons & Qt::MiddleButton) != 0)
    {
        aButtons |= Aspect_VKeyMouse_MiddleButton;
    }
    if ((theButtons & Qt::RightButton) != 0)
    {
        aButtons |= Aspect_VKeyMouse_RightButton;
    }
    return aButtons;
}

//! Map Qt mouse modifiers bitmask to virtual keys.
Aspect_VKeyFlags qtMouseModifiers2VKeys (Qt::KeyboardModifiers theModifiers)
{
    Aspect_VKeyFlags aFlags = Aspect_VKeyFlags_NONE;
    if ((theModifiers & Qt::ShiftModifier) != 0)
    {
        aFlags |= Aspect_VKeyFlags_SHIFT;
    }
    if ((theModifiers & Qt::ControlModifier) != 0)
    {
        aFlags |= Aspect_VKeyFlags_CTRL;
    }
    if ((theModifiers & Qt::AltModifier) != 0)
    {
        aFlags |= Aspect_VKeyFlags_ALT;
    }
    return aFlags;
}

//! Map Qt key to virtual key.
Aspect_VKey qtKey2VKey (int theKey)
{
    switch (theKey)
    {
    case 1060: // ru
    case Qt::Key_A: return Aspect_VKey_A;
    case 1048: // ru
    case Qt::Key_B: return Aspect_VKey_B;
    case 1057: // ru
    case Qt::Key_C: return Aspect_VKey_C;
    case 1042: // ru
    case Qt::Key_D: return Aspect_VKey_D;
    case 1059: // ru
    case Qt::Key_E: return Aspect_VKey_E;
    case 1040: // ru
    case Qt::Key_F: return Aspect_VKey_F;
    case Qt::Key_G: return Aspect_VKey_G;
    case Qt::Key_H: return Aspect_VKey_H;
    case Qt::Key_I: return Aspect_VKey_I;
    case Qt::Key_J: return Aspect_VKey_J;
    case Qt::Key_K: return Aspect_VKey_K;
    case 1044: // ru
    case Qt::Key_L: return Aspect_VKey_L;
    case Qt::Key_M: return Aspect_VKey_M;
    case Qt::Key_N: return Aspect_VKey_N;
    case Qt::Key_O: return Aspect_VKey_O;
    case Qt::Key_P: return Aspect_VKey_P;
    case 1049: // ru
    case Qt::Key_Q: return Aspect_VKey_Q;
    case 1050: // ru
    case Qt::Key_R: return Aspect_VKey_R;
    case 1067: // ru
    case Qt::Key_S: return Aspect_VKey_S;
    case 1045: // ru
    case Qt::Key_T: return Aspect_VKey_T;
    case Qt::Key_U: return Aspect_VKey_U;
    case 1052: // ru
    case Qt::Key_V: return Aspect_VKey_V;
    case 1062: // ru
    case Qt::Key_W: return Aspect_VKey_W;
    case 1063: // ru
    case Qt::Key_X: return Aspect_VKey_X;
    case Qt::Key_Y: return Aspect_VKey_Y;
    case 1071: // ru
    case Qt::Key_Z: return Aspect_VKey_Z;
        //
    case Qt::Key_0: return Aspect_VKey_0;
    case Qt::Key_1: return Aspect_VKey_1;
    case Qt::Key_2: return Aspect_VKey_2;
    case Qt::Key_3: return Aspect_VKey_3;
    case Qt::Key_4: return Aspect_VKey_4;
    case Qt::Key_5: return Aspect_VKey_5;
    case Qt::Key_6: return Aspect_VKey_6;
    case Qt::Key_7: return Aspect_VKey_7;
    case Qt::Key_8: return Aspect_VKey_8;
    case Qt::Key_9: return Aspect_VKey_9;
        //
    case Qt::Key_F1:        return Aspect_VKey_F1;
    case Qt::Key_F2:        return Aspect_VKey_F2;
    case Qt::Key_F3:        return Aspect_VKey_F3;
    case Qt::Key_F4:        return Aspect_VKey_F4;
    case Qt::Key_F5:        return Aspect_VKey_F5;
    case Qt::Key_F6:        return Aspect_VKey_F6;
    case Qt::Key_F7:        return Aspect_VKey_F7;
    case Qt::Key_F8:        return Aspect_VKey_F8;
    case Qt::Key_F9:        return Aspect_VKey_F9;
    case Qt::Key_F10:       return Aspect_VKey_F10;
    case Qt::Key_F11:       return Aspect_VKey_F11;
    case Qt::Key_F12:       return Aspect_VKey_F12;
        //
    case Qt::Key_Up:        return Aspect_VKey_Up;
    case Qt::Key_Left:      return Aspect_VKey_Left;
    case Qt::Key_Right:     return Aspect_VKey_Right;
    case Qt::Key_Down:      return Aspect_VKey_Down;
    case Qt::Key_Plus:      return Aspect_VKey_Plus;
    case Qt::Key_Minus:     return Aspect_VKey_Minus;
    case Qt::Key_Equal:     return Aspect_VKey_Equal;
    case Qt::Key_PageDown:  return Aspect_VKey_PageDown;
    case Qt::Key_PageUp:    return Aspect_VKey_PageUp;
    case Qt::Key_Home:      return Aspect_VKey_Home;
    case Qt::Key_End:       return Aspect_VKey_End;
    case Qt::Key_Escape:    return Aspect_VKey_Escape;
    case Qt::Key_Back:      return Aspect_VKey_Back;
    case Qt::Key_Enter:     return Aspect_VKey_Enter;
    case Qt::Key_Backspace: return Aspect_VKey_Backspace;
    case Qt::Key_Space:     return Aspect_VKey_Space;
    case Qt::Key_Delete:    return Aspect_VKey_Delete;
    case Qt::Key_Tab:       return Aspect_VKey_Tab;
    case 1025:
    case Qt::Key_QuoteLeft: return Aspect_VKey_Tilde;
        //
    case Qt::Key_Shift:     return Aspect_VKey_Shift;
    case Qt::Key_Control:   return Aspect_VKey_Control;
    case Qt::Key_Alt:       return Aspect_VKey_Alt;
    case Qt::Key_Menu:      return Aspect_VKey_Menu;
    case Qt::Key_Meta:      return Aspect_VKey_Meta;
    default:                return Aspect_VKey_UNKNOWN;
    }
}
}

//! OcctQtViewer
OcctQtViewer::OcctQtViewer (QWidget* theParent)
    : QOpenGLWidget (theParent),
      myIsCoreProfile (true)

{
    Handle(Aspect_DisplayConnection) aDisp = new Aspect_DisplayConnection();
    Handle(OpenGl_GraphicDriver) aDriver = new OpenGl_GraphicDriver (aDisp, false);
    aDriver->ChangeOptions().ffpEnable = Standard_False;
    aDriver->ChangeOptions().glslWarnings = Standard_False;
    aDriver->ChangeOptions().buffersNoSwap = Standard_False;

    //! lets QOpenGLWidget to manage buffer swap
    aDriver->ChangeOptions().buffersNoSwap = true;
    //! don't write into alpha channel
    //! aDriver->ChangeOptions().buffersOpaqueAlpha = true;
    //! offscreen FBOs should be always used
    aDriver->ChangeOptions().useSystemBuffer = false;

    //! create viewer
    myViewer = new V3d_Viewer (aDriver);
    myViewer->SetDefaultBackgroundColor (Quantity_NOC_BLACK);
    myViewer->SetDefaultLights();
    myViewer->SetLightOn();
    // myViewer->ActivateGrid (Aspect_GT_Rectangular, Aspect_GDM_Points);

    //! create AIS context
    myContext = new AIS_InteractiveContext (myViewer);

    //! 3D navigation cube.
    /*
    myViewCube = new AIS_ViewCube();
    myViewCube->SetViewAnimation (myViewAnimation);
    myViewCube->SetBoxColor(Quantity_NOC_GRAY75); //
    myViewCube->SetDrawAxes(false); //
    myViewCube->SetFixedAnimationLoop (false);
    myViewCube->SetAutoStartAnimation (true);
    myViewCube->SetSize(40);
    myViewCube->SetFontHeight(10);
    myViewCube->SetTransformPersistence(
                new Graphic3d_TransformPers(
                    Graphic3d_TMF_TriedronPers,
                    Aspect_TOTP_LEFT_UPPER, //! Position.
                    Graphic3d_Vec2i(85, 85)));
    */

    //! note - window will be created later within initializeGL() callback!
    myView = myViewer->CreateView();
    myView->SetImmediateUpdate (false);

    //! Print the actual opencascade performance.
    bool show_specs=0;
    if(show_specs){
        myView->ChangeRenderingParams().NbMsaaSamples = 4; // warning - affects performance
        myView->ChangeRenderingParams().ToShowStats = true;
        myView->ChangeRenderingParams().CollectedStats = (Graphic3d_RenderingParams::PerfCounters )
                (Graphic3d_RenderingParams::PerfCounters_FrameRate
                 | Graphic3d_RenderingParams::PerfCounters_Triangles);
    }

    //! Set model view as perspective.
    myView->Camera()->SetProjectionType (Graphic3d_Camera::Projection_Perspective);

    /// Show triedron. This is the 3d axis cross at the lower left of the screen.
    myView->TriedronDisplay(Aspect_TOTP_LEFT_UPPER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);

    //! Qt widget setup
    setMouseTracking (true);
    setBackgroundRole (QPalette::NoRole);   //! or NoBackground
    setFocusPolicy (Qt::StrongFocus);       //! set focus policy to threat QContextMenuEvent from keyboard
    setUpdatesEnabled (true);
    setUpdateBehavior (QOpenGLWidget::NoPartialUpdate);

    //! OpenGL setup managed by Qt
    QSurfaceFormat aGlFormat;
    aGlFormat.setDepthBufferSize   (24);
    aGlFormat.setStencilBufferSize (8);
    //! aGlFormat.setOption (QSurfaceFormat::DebugContext, true);
    //! aGlFormat.setOption (QSurfaceFormat::DeprecatedFunctions, true);

    aGlFormat.setProfile(QSurfaceFormat::NoProfile);

    if (myIsCoreProfile)
    {
        aGlFormat.setVersion (4, 5);

    }
    //! QSurfaceFormat::CoreProfile limits linewidth to 1.
    aGlFormat.setProfile (myIsCoreProfile ? QSurfaceFormat::CoreProfile : QSurfaceFormat::CompatibilityProfile);
#if (QT_VERSION_MAJOR > 5) || (QT_VERSION_MAJOR == 5 && QT_VERSION_MINOR >= 10)
    aGlFormat.setColorSpace (QSurfaceFormat::sRGBColorSpace);

    setTextureFormat (GL_SRGB8_ALPHA8);
#else
    Message::SendWarning ("Warning! Qt 5.10+ is required for sRGB setup.\n"
                          "Colors in 3D Viewer might look incorrect (Qt " QT_VERSION_STR " is used).\n");
    aDriver->ChangeOptions().sRGBDisable = true;
#endif
    setFormat (aGlFormat);

#if defined(_WIN32)
    // never use ANGLE on Windows, since OCCT 3D Viewer does not expect this
    QCoreApplication::setAttribute (Qt::AA_UseDesktopOpenGL);
    //QCoreApplication::setAttribute (Qt::AA_UseOpenGLES);
#endif

}

//! Destructor ~OcctQtViewer
OcctQtViewer::~OcctQtViewer()
{
    // hold on X11 display connection till making another connection active by glXMakeCurrent()
    // to workaround sudden crash in QOpenGLWidget destructor
    Handle(Aspect_DisplayConnection) aDisp = myViewer->Driver()->GetDisplayConnection();

    // release OCCT viewer
    myContext->RemoveAll (false);
    myContext.Nullify();
    myView->Remove();
    myView.Nullify();
    myViewer.Nullify();

    //! make active OpenGL context created by Qt
    makeCurrent();
    aDisp.Nullify();
}

//! dumpGlInfo
void OcctQtViewer::dumpGlInfo (bool theIsBasic)
{
    TColStd_IndexedDataMapOfStringString aGlCapsDict;
    myView->DiagnosticInformation (aGlCapsDict, theIsBasic ? Graphic3d_DiagnosticInfo_Basic : Graphic3d_DiagnosticInfo_Complete);
    TCollection_AsciiString anInfo;
    for (TColStd_IndexedDataMapOfStringString::Iterator aValueIter (aGlCapsDict); aValueIter.More(); aValueIter.Next())
    {
        if (!aValueIter.Value().IsEmpty())
        {
            if (!anInfo.IsEmpty())
            {
                anInfo += "\n";
            }
            anInfo += aValueIter.Key() + ": " + aValueIter.Value();
        }
    }

    Message::SendInfo (anInfo);
    myGlInfo = QString::fromUtf8 (anInfo.ToCString());
}

//! initializeGL
#include <OpenGl_VertexBuffer.hxx>
#include <AIS_Trihedron.hxx>
void OcctQtViewer::initializeGL()
{
    const QRect aRect = rect();
    const Graphic3d_Vec2i aViewSize (aRect.right() - aRect.left(), aRect.bottom() - aRect.top());

    Handle(OpenGl_Context) aGlCtx = new OpenGl_Context();
    if (!aGlCtx->Init (myIsCoreProfile))
    {
        Message::SendFail() << "Error: OpenGl_Context is unable to wrap OpenGL context";
        QMessageBox::critical (0, "Failure", "OpenGl_Context is unable to wrap OpenGL context");
        QApplication::exit (1);
        return;
    }

    Handle(Aspect_NeutralWindow) aWindow = Handle(Aspect_NeutralWindow)::DownCast (myView->Window());
    if (!aWindow.IsNull())
    {
        aWindow->SetSize (aViewSize.x(), aViewSize.y());
        myView->SetWindow (aWindow, (Aspect_RenderingContext) glXGetCurrentContext());

        dumpGlInfo (true);
    }
    else
    {
        aWindow = new Aspect_NeutralWindow();

        Aspect_Drawable aNativeWin = (Aspect_Drawable )winId();
#ifdef _WIN32
        //HGLRC aWglCtx    = wglGetCurrentContext();
        HDC   aWglDevCtx = wglGetCurrentDC();
        HWND  aWglWin    = WindowFromDC (aWglDevCtx);
        aNativeWin = (Aspect_Drawable )aWglWin;
#endif
        aWindow->SetNativeHandle (aNativeWin);
        aWindow->SetSize (aViewSize.x(), aViewSize.y());
        myView->SetWindow (aWindow, (Aspect_RenderingContext) glXGetCurrentContext());
        dumpGlInfo (true);

        myContext->Display (myViewCube, 0, 0, false);
    }

    {
        //! dummy shape for testing
        /*
        TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox (100.0, 50.0, 90.0).Shape();
        objvec.push_back(new AIS_Shape (aTopoBox));
        //! Set shape boundary line enable.
        objvec.back()->Attributes()->SetFaceBoundaryDraw(true);
        objvec.back()->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        objvec.back()->Attributes()->SetIsoOnTriangulation(true);
        objvec.back()->Attributes()->SetDisplayMode(AIS_Shaded);
        myContext->Display (objvec.back(),Standard_False);
        */

        /*
        gp_Ax2 anAxis(gp::Origin(), gp::DZ()); // Origin at (0, 0, 0), X-axis as main direction, Y-axis as secondary direction
        Handle(Geom_Axis2Placement) anAxisPlacement = new Geom_Axis2Placement(anAxis);
        trihedron = new AIS_Trihedron(anAxisPlacement);
        myContext->Display(trihedron, Standard_True); // Display the triedron
        */
    }
}

//! closeEvent
void OcctQtViewer::closeEvent (QCloseEvent* theEvent)
{
    theEvent->accept();
}

//! keyPressEvent
void OcctQtViewer::keyPressEvent (QKeyEvent* theEvent)
{
    Aspect_VKey aKey = qtKey2VKey (theEvent->key());
    switch (aKey)
    {
    case Aspect_VKey_F:
    {
        myView->FitAll (0.01, false);
        break;
    }
    case Aspect_VKey_Space:
    {
        // std::cout<<"space key pressed"<<std::endl;
    }
    default:
        break;
    }

    QOpenGLWidget::keyPressEvent (theEvent);
    if (!myView.IsNull()){
        updateView();
    }
}


//! mousePressEvent
void OcctQtViewer::mousePressEvent (QMouseEvent* theEvent)
{
    QOpenGLWidget::mousePressEvent (theEvent);
    const Graphic3d_Vec2i aPnt (theEvent->pos().x(), theEvent->pos().y());
    const Aspect_VKeyFlags aFlags = qtMouseModifiers2VKeys (theEvent->modifiers());
    if (!myView.IsNull()
            && UpdateMouseButtons (aPnt,
                                   qtMouseButtons2VKeys (theEvent->buttons()),
                                   aFlags,
                                   false))
    {
        updateView();
    }
}
#include "IntAna_IntConicQuad.hxx"
#include "IntCurvesFace_ShapeIntersector.hxx"

//! mouseReleaseEvent
void OcctQtViewer::mouseReleaseEvent (QMouseEvent* theEvent)
{
    QOpenGLWidget::mouseReleaseEvent (theEvent);
    const Graphic3d_Vec2i aPnt (theEvent->pos().x(), theEvent->pos().y());
    const Aspect_VKeyFlags aFlags = qtMouseModifiers2VKeys (theEvent->modifiers());
    if (!myView.IsNull()
            && UpdateMouseButtons (aPnt,
                                   qtMouseButtons2VKeys (theEvent->buttons()),
                                   aFlags,
                                   false))
    {
        updateView();
    }
}

gp_Lin createLineFromViewEye(Standard_Real x, Standard_Real y, Handle(V3d_View) view)
{
    Standard_Real Xp = x, Yp = y;
    Standard_Real Xv, Yv, Zv;
    Standard_Real Vx, Vy, Vz;

    view->Convert( Xp, Yp, Xv, Yv, Zv );
    view->Proj( Vx, Vy, Vz );

    // std::cout<<"x:"<<Xv<<" y:"<<Yv<<" z:"<<Zv<<std::endl;

    return gp_Lin(gp_Pnt(Xv, Yv, Zv), gp_Dir(Vx, Vy, Vz));
}

gp_Pnt intersectLineThroughShape(const TopoDS_Shape shapeToIntersect, const gp_Lin lineForIntersecting)
{
    IntCurvesFace_ShapeIntersector shapeIntersector;
    shapeIntersector.Load(shapeToIntersect, Precision::Confusion());
    shapeIntersector.Perform(lineForIntersecting, -RealLast(), RealLast());

    return shapeIntersector.Pnt(1);
}

//! mouseMoveEvent
void OcctQtViewer::mouseMoveEvent (QMouseEvent* theEvent)
{
    /* This is when left mouse is pressed and object is selected. It will g
    for(myContext->InitSelected(); myContext->MoreSelected(); myContext->NextSelected()){
        if(myContext->MainSelector()->NbPicked()>0){
            aMousePnt=myContext->MainSelector()->PickedPoint(1).XYZ();
        }
    } */


    // Mouse simple section:
    if(!project_mouse_to_plane){
        double aVx,aVy,aVz,aPx,aPy,aPz;
        myView->Convert(theEvent->pos().x(), theEvent->pos().y(), aVx, aVy, aVz);
        myView->Proj(aPx, aPy, aPz);
        //mySketcher->OnMouseMoveEvent(aVx, aVy, aVz, aPx, aPy, aPz);
        mousepos={aVx,aVy,aVz};

        QOpenGLWidget::mouseMoveEvent (theEvent);
        const Graphic3d_Vec2i aNewPos (theEvent->pos().x(), theEvent->pos().y());

        Aspect_VKeyMouse aMouseKey=qtMouseButtons2VKeys (theEvent->buttons());
        // std::cout<<"key amouse:"<<aMouseKey<<std::endl;
        //32786
        if(!(aMouseKey==8192)){ // Skip left mouse.

            if(aMouseKey==32768){ // Swap left, right
                aMouseKey=8192;
            }


            if (!myView.IsNull()
                    && UpdateMousePosition (aNewPos,
                                            aMouseKey,
                                            qtMouseModifiers2VKeys (theEvent->modifiers()), //! Control, shift etc buttons.
                                            false))
            {
                updateView();
            }
        }
    }


    if(project_mouse_to_plane){
    // Mouse to plane section:
    //! If view is plane top, plane has to be the same.
    double vx,vy,vz;
    myView->Proj(vx,vy,vz);

    QOpenGLWidget::mouseMoveEvent (theEvent);
    const Graphic3d_Vec2i aNewPos (theEvent->pos().x(), theEvent->pos().y());

    Aspect_VKeyMouse aMouseKey=qtMouseButtons2VKeys (theEvent->buttons());
    // std::cout<<"key amouse:"<<aMouseKey<<std::endl;
    //32786
    if(!(aMouseKey==8192)){ // Skip left mouse.

        if(aMouseKey==32768){ // Swap left, right
            aMouseKey=8192;
        }


        if (!myView.IsNull()
                && UpdateMousePosition (aNewPos,
                                        aMouseKey,
                                        qtMouseModifiers2VKeys (theEvent->modifiers()), //! Control, shift etc buttons.
                                        false))
        {
            updateView();
        }
    }

    eyeline = createLineFromViewEye(theEvent->pos().x(), theEvent->pos().y(), myView);
    mousepos=eyeline.Location();

    IntAna_IntConicQuad intersection_xx(eyeline, plane, 1e-6);
    if(intersection_xx.IsParallel()){
        // std::cout<<"intersection is parallel, plane is set equal to view."<<std::endl;
        plane.SetPosition(gp_Ax3({plane.Location()},gp_Dir(vx,vy,vz)));
    }

    //! Control line.
    // gp_Pnt startPoint = myLine.Location();
    // gp_Pnt endPoint = startPoint.Translated(gp_Vec(myLine.Direction()));
    // draw_primitives().offset_3d_point_on_line(startPoint,endPoint,-1000000000,endPoint);
    // add_shapevec(draw_primitives().draw_3d_line(startPoint,endPoint));
    // std::cout<<"linelenght:"<<startPoint.Distance(endPoint)<<std::endl;

    // Find the intersection point between the line of sight and the plane
    IntAna_IntConicQuad intersection(eyeline, plane, 1e-6);
    if (intersection.IsDone() && intersection.NbPoints() > 0) {
        gp_Pnt intersectionPoint = intersection.Point(1);
        // std::cout<<"intersection x:"<<intersectionPoint.X()<<" y:"<<intersectionPoint.Y()<<" z:"<<intersectionPoint.Z()<<std::endl;
        mousepos=intersectionPoint;
    }

    // std::cout<<"has detected:" << myContext->HasDetected()<<std::endl; // Hovering detection.
    // if(myContext->HasDetected()){ // Mouse hovering detection.
    //    Handle(AIS_InteractiveObject) detected_object= myContext->DetectedInteractive();
    //   detected_shape=draw_primitives().downcast(detected_object);

    /*
        int shapetype=draw_primitives().get_shapetype( detected_shape);
        if(shapetype==1){ //! A point.
            std::cout<<"point shape found"<<std::endl;
            mousepos=(draw_primitives().get_point( detected_shape));
        }
        if(shapetype==2){ //! A line.
            std::cout<<"line shape found"<<std::endl;
            //draw_primitives().get_closest_point_to_line(mousepos,shape,mousepos);
            gp_Pnt p1,p2;
            draw_primitives().get_line_points( detected_shape,p1,p2);
            if(mousepos.Distance(p1)<5){
                mousepos=p1;
            } else
                if(mousepos.Distance(p2)<5){
                    mousepos=p2;
                } else {

                }
        }*/

    //        IntAna_IntConicQuad intersection(myLine, plane, 1e-6); // Tolerance = 1e-6
    //        if (intersection.IsDone() && intersection.NbPoints() > 0) {
    //            gp_Pnt intersectionPoint = intersection.Point(1);
    //            // 'intersectionPoint' now contains the intersection point between the line and the plane
    //            // Use this point for further operations

    //             draw_primitives().print_gp_Pnt("intersectionpoint",intersectionPoint);
    //        }
    //}

    }
}

//! wheelEvent
void OcctQtViewer::wheelEvent (QWheelEvent* theEvent)
{
    QOpenGLWidget::wheelEvent (theEvent);
    const Graphic3d_Vec2i aPos (theEvent->position().x(), theEvent->position().y());
    if (!myView.IsNull()
            && UpdateZoom (Aspect_ScrollDelta (aPos, theEvent->delta() / 8)))
    {
        updateView();
    }
}

//! updateView
void OcctQtViewer::updateView()
{
    update();
    //! if (window() != NULL) { window()->update(); }
}

//! paintGL
void OcctQtViewer::paintGL()
{
    if (myView->Window().IsNull())
    {
        return;
    }

    //! wrap FBO created by QOpenGLWidget
    Handle(OpenGl_GraphicDriver) aDriver = Handle(OpenGl_GraphicDriver)::DownCast (myContext->CurrentViewer()->Driver());
    const Handle(OpenGl_Context)& aGlCtx = aDriver->GetSharedContext();
    Handle(OpenGl_FrameBuffer) aDefaultFbo = aGlCtx->DefaultFrameBuffer();
    if (aDefaultFbo.IsNull())
    {
        aDefaultFbo = new OpenGl_FrameBuffer();
        aGlCtx->SetDefaultFrameBuffer (aDefaultFbo);
    }
    if (!aDefaultFbo->InitWrapper (aGlCtx))
    {
        aDefaultFbo.Nullify();
        Message::DefaultMessenger()->Send ("Default FBO wrapper creation failed", Message_Fail);
        QMessageBox::critical (0, "Failure", "Default FBO wrapper creation failed");
        QApplication::exit (1);
        return;
    }

    Graphic3d_Vec2i aViewSizeOld;
    //! const QRect aRect = rect(); Graphic3d_Vec2i aViewSizeNew(aRect.right() - aRect.left(), aRect.bottom() - aRect.top());
    Graphic3d_Vec2i aViewSizeNew(aDefaultFbo->GetVPSizeX(),aDefaultFbo->GetVPSizeY());
    Handle(Aspect_NeutralWindow) aWindow = Handle(Aspect_NeutralWindow)::DownCast (myView->Window());
    aWindow->Size (aViewSizeOld.x(), aViewSizeOld.y());
    if (aViewSizeNew != aViewSizeOld)
    {
        aWindow->SetSize (aViewSizeNew.x(), aViewSizeNew.y());
        myView->MustBeResized();
        myView->Invalidate();
    }

    //! flush pending input events and redraw the viewer
    myView->InvalidateImmediate();
    FlushViewEvents (myContext, myView, true);
}

//! handleViewRedraw
void OcctQtViewer::handleViewRedraw (const Handle(AIS_InteractiveContext)& theCtx,
                                     const Handle(V3d_View)& theView)
{
    AIS_ViewController::handleViewRedraw (theCtx, theView);
    if (myToAskNextFrame)
    {
        //! ask more frames for animation
        updateView();
    }
}

//! Set the tranceparancy between 0 & 1.
void OcctQtViewer::set_tranceparancy(double value){
    for(unsigned int i=0; i<shapevec.size(); i++){
        shapevec.at(i)->SetTransparency(value);
    }
}

//! Set background color.
void OcctQtViewer::set_backgroundcolor(double r, double g, double b){
    Quantity_Color cola,colb;
    cola.SetValues(r/255,g/255,b/255,Quantity_TOC_RGB);
    colb.SetValues(r/255,g/255,b/255,Quantity_TOC_RGB);
    myView->SetBgGradientColors(cola,colb,Aspect_GFM_DIAG2 , false);
}

//! Show the boundary line of the shapes.
void OcctQtViewer::show_boundary(){
    for(unsigned int i=0; i<shapevec.size(); i++){
        shapevec[i]->Attributes()->SetFaceBoundaryDraw(true);
        shapevec[i]->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        shapevec[i]->Attributes()->SetIsoOnTriangulation(true);
        myContext->Redisplay(shapevec[i],Standard_False);
    }
    myView->Update();
}

//! Hide the boundary lines of the shapes.
void OcctQtViewer::hide_boundary(){
    for(unsigned int i=0; i<shapevec.size(); i++){
        shapevec[i]->Attributes()->SetFaceBoundaryDraw(false);
        //! objvec[i]->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        shapevec[i]->Attributes()->SetIsoOnTriangulation(false);
        myContext->Redisplay(shapevec[i],Standard_False);
    }
    myView->Update();
}

//! Hide the navigation cube.
void OcctQtViewer::hide_cube(){
    myContext->Erase(myViewCube, false);
    myView->Update();
}

//! Hide the navigation cube.
void OcctQtViewer::show_cube(){
    myContext->Display(myViewCube, false);
    myView->Update();
}

//! Show the trihedron
void OcctQtViewer::show_triedron(){
    myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
    myView->Update();
}

//! Hide the trihedron
void OcctQtViewer::hide_triedron(){
    myView->TriedronErase();
    myView->Update();
}

//! Show as wireframe
void OcctQtViewer::show_as_wireframe(){
    for(unsigned int i=0; i<shapevec.size(); i++){
        shapevec[i]->SetDisplayMode(AIS_WireFrame);
        myContext->Remove(shapevec[i],Standard_False);
        myContext->Display(shapevec[i],Standard_False);
    }
    myView->Redraw();
    myView->Update();
}

//! Show as shaded
void OcctQtViewer::show_as_shaded(){
    for(unsigned int i=0; i<shapevec.size(); i++){
        shapevec[i]->SetDisplayMode(AIS_Shaded);
        myContext->Remove(shapevec[i],Standard_False);
        myContext->Display(shapevec[i],Standard_True);
    }
    myView->Redraw();
    myView->Update();
}

//! Display mode orthographic.
void OcctQtViewer::set_orthographic(){
    myView->Camera()->SetProjectionType (Graphic3d_Camera::Projection_Orthographic);
    myView->Redraw();
    myView->Update();
}

//! Display mode perspective.
void OcctQtViewer::set_perspective(){
    myView->Camera()->SetProjectionType (Graphic3d_Camera::Projection_Perspective);
    myView->Redraw();
    myView->Update();
}

void OcctQtViewer::add_shapevec(Handle(AIS_Shape) shape){
    shape->Attributes()->SetFaceBoundaryDraw(true);
    shape->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
    shape->Attributes()->SetIsoOnTriangulation(true);
    shape->Attributes()->SetDisplayMode(AIS_Shaded);
    shapevec.push_back(shape);
    myContext->Display(shape,true);
}

//! Seems not to work always. Maybe use remove and then display.
void OcctQtViewer::redraw_shapevec(std::vector<Handle(AIS_Shape)> shapevec){
    for(uint i=0; i<shapevec.size(); i++){
        myContext->Redisplay(shapevec.at(i),true);
    }
}

void OcctQtViewer::add_shapevec(std::vector<Handle(AIS_Shape)> another_shapevec){
    for(uint i=0; i<another_shapevec.size(); i++){
        add_shapevec(another_shapevec.at(i));
    }
}

void OcctQtViewer::add_helpervec(Handle(AIS_Shape) shape){
    shape->Attributes()->SetFaceBoundaryDraw(true);
    shape->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
    shape->Attributes()->SetIsoOnTriangulation(true);
    shape->Attributes()->SetDisplayMode(AIS_Shaded);
    helpervec.push_back(shape);
    myContext->Display(shape,AIS_Shaded,-1,true,AIS_DS_Displayed); // non selectable shape.
}

void OcctQtViewer::show_shape(Handle(AIS_Shape) shape){
    shape->Attributes()->SetFaceBoundaryDraw(true);
    shape->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
    shape->Attributes()->SetIsoOnTriangulation(true);
    shape->Attributes()->SetDisplayMode(AIS_Shaded);
    myContext->Display(shape,true);
}

void OcctQtViewer::hide_shape(Handle(AIS_Shape) shape){
    myContext->Remove(shape,true);
}

void OcctQtViewer::create_snap_sphere(double radius){
    snap_sphere=draw_primitives().draw_3d_sphere(radius,{0,0,0});
    snap_sphere->Attributes()->SetFaceBoundaryDraw(true);
    snap_sphere->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
    snap_sphere->Attributes()->SetIsoOnTriangulation(true);
    snap_sphere->Attributes()->SetDisplayMode(AIS_Shaded);
    snap_sphere->SetTransparency(0.5);
    myContext->Display(snap_sphere,false);
}

void OcctQtViewer::show_snap_sphere(gp_Pnt point){
    snap_sphere=draw_primitives().translate_3d(snap_sphere,{0,0,0},point);
    myContext->Display(snap_sphere,false);
}

void OcctQtViewer::hide_snap_sphere(){
    myContext->Remove(snap_sphere,true);
}

void OcctQtViewer::redraw(){
    myView->Redraw();
    // updateView(); //! Updates like a thread.
}

bool OcctQtViewer::ready(){
    if(myView.IsNull()){
        return 0;
    }
    return 1;
}

void OcctQtViewer::fit_all(){
    myView->FitAll (0.01, false);
}

void OcctQtViewer::remove_selected_shape(){

    //! Use:
    // myContext->EraseSelected(Standard_False);
    //! Or prevent memory leaks:

    // Get all displayed interactive objects
    AIS_ListOfInteractive displayedObjects;
    myContext->DisplayedObjects(displayedObjects);

    // Remove selected shapes from the context
    recyclebin_shapevec.clear();
    for (AIS_ListIteratorOfListOfInteractive it(displayedObjects); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject) obj = it.Value();
        if (myContext->IsSelected(obj)) {
            recyclebin_shapevec.push_back(Handle(AIS_Shape)::DownCast(obj));
            myContext->Erase(obj, Standard_True); // Erase selected object from context
            obj.Nullify();
        }
    }
}

void OcctQtViewer::remove_all(){
    AIS_ListOfInteractive list;
    myContext->DisplayedObjects(list); // Get the displayed objects

    // Remove all displayed objects from the context
    recyclebin_shapevec.clear();
    for (AIS_ListIteratorOfListOfInteractive it(list); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject) obj = it.Value();
        recyclebin_shapevec.push_back(Handle(AIS_Shape)::DownCast(obj));
        myContext->Remove(obj, Standard_True); // Remove object from context
        obj.Nullify();
    }
}


void OcctQtViewer::select_all(){
    // Get all displayed interactive objects (shapes)
    TopTools_ListOfShape displayedShapes;
    AIS_ListOfInteractive list;
    myContext->DisplayedObjects(list);

    // Set all shapes in the list as selected
    for (AIS_ListIteratorOfListOfInteractive it(list); it.More(); it.Next()) {
        const Handle(AIS_InteractiveObject)& obj = it.Value();
        if (obj->IsKind(STANDARD_TYPE(AIS_InteractiveObject))) {
            myContext->AddOrRemoveSelected(obj, Standard_True);
        }
    }
}

void OcctQtViewer::deselected_all(){
    myContext->ClearSelected(true);
}

Handle(AIS_Shape) OcctQtViewer::selected_shape(){
    // Get all displayed interactive objects
    AIS_ListOfInteractive displayedObjects;
    myContext->DisplayedObjects(displayedObjects);
    Handle(AIS_Shape) shape;

    for (AIS_ListIteratorOfListOfInteractive it(displayedObjects); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject)& obj = it.Value();
        if (myContext->IsSelected(obj)) {
            shape=(Handle(AIS_Shape)::DownCast(obj));
            break;
        }
    }
    return shape;
}

bool OcctQtViewer::selected_shape(Handle(AIS_Shape) &shape){

    // Get all displayed interactive objects
    AIS_ListOfInteractive displayedObjects;
    myContext->DisplayedObjects(displayedObjects);

    for (AIS_ListIteratorOfListOfInteractive it(displayedObjects); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject)& obj = it.Value();
        if (myContext->IsSelected(obj)) {
            shape=(Handle(AIS_Shape)::DownCast(obj));
            std::cout<<"shape selected"<<std::endl;
            return 1;
        }
    }
    return 0;
}

bool OcctQtViewer::selected_shapevec(int &nr){
    // Get all displayed interactive objects
    AIS_ListOfInteractive displayedObjects;
    myContext->DisplayedObjects(displayedObjects);

    for (AIS_ListIteratorOfListOfInteractive it(displayedObjects); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject)& obj = it.Value();
        if (myContext->IsSelected(obj)) {
            Handle(AIS_Shape) shape=(Handle(AIS_Shape)::DownCast(obj));

            for(uint i=0; i<shapevec.size(); i++){
                if(shapevec.at(i)==shape){
                    nr=i;
                    std::cout<<"selected shape is at shapvec nr:"<<i<<std::endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool OcctQtViewer::selected_shapevec(std::vector<int> &nrvec){
    // Get all displayed interactive objects
    AIS_ListOfInteractive displayedObjects;
    myContext->DisplayedObjects(displayedObjects);

    for (AIS_ListIteratorOfListOfInteractive it(displayedObjects); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject)& obj = it.Value();
        if (myContext->IsSelected(obj)) {
            Handle(AIS_Shape) shape=(Handle(AIS_Shape)::DownCast(obj));

            for(uint i=0; i<shapevec.size(); i++){
                if(shapevec.at(i)==shape){

                    if( !(std::find(nrvec.begin(), nrvec.end(), i) != nrvec.end()) ){ // Avoid duplicates.
                        nrvec.push_back(i);
                        std::cout<<"selected shape is at shapvec nr:"<<i<<std::endl;
                    }
                }
            }
        }
    }

    if(nrvec.size()>0){
        return 1;
    }
    return 0;
}

bool OcctQtViewer::detected_shapevec(int &nr){
    // std::cout<<"has detected:" << myContext->HasDetected()<<std::endl; // Hovering detection.
    if(myContext->HasDetected()){ // Mouse hovering detection.
        Handle(AIS_InteractiveObject) detected_object= myContext->DetectedInteractive();
        Handle(AIS_Shape) shape=draw_primitives().downcast(detected_object);

        for(uint i=0; i<shapevec.size(); i++){
            if(shapevec.at(i)==shape){
                shape=shapevec.at(i);
                nr=i;
                std::cout<<"detected shape is at shapvec nr:"<<i<<std::endl;
                return 1;
            }
        }
    }
    return 0;
}

bool OcctQtViewer::highlighted_shape(Handle(AIS_Shape) &shape){

    // Get all displayed interactive objects
    AIS_ListOfInteractive displayedObjects;
    myContext->DisplayedObjects(displayedObjects);

    for (AIS_ListIteratorOfListOfInteractive it(displayedObjects); it.More(); it.Next()) {
        Handle(AIS_InteractiveObject)& obj = it.Value();
        if (myContext->IsHilighted(obj)) {


            shape=(Handle(AIS_Shape)::DownCast(obj));
            std::cout<<"shape highlighted"<<std::endl;
            return 1;
        }
    }
    return 0;
}

bool OcctQtViewer::detected_shape(Handle(AIS_Shape) &shape){
    // std::cout<<"has detected:" << myContext->HasDetected()<<std::endl; // Hovering detection.
    if(myContext->HasDetected()){ // Mouse hovering detection.
        Handle(AIS_InteractiveObject) detected_object= myContext->DetectedInteractive();
        shape=draw_primitives().downcast(detected_object);
        return 1;
    }
    return 0;
}

Handle(AIS_Shape) OcctQtViewer::detected_shape(){
    Handle(AIS_Shape) shape;
    // std::cout<<"has detected:" << myContext->HasDetected()<<std::endl; // Hovering detection.
    if(myContext->HasDetected()){ // Mouse hovering detection.
        Handle(AIS_InteractiveObject) detected_object= myContext->DetectedInteractive();
        shape=draw_primitives().downcast(detected_object);
    }
    return shape;
}

bool OcctQtViewer::highlighted_interactive_shape(Handle(AIS_Shape) &shape){

    // Get all displayed interactive objects
    Handle(AIS_InteractiveObject) obj =myContext->SelectedInteractive();


    shape=(Handle(AIS_Shape)::DownCast(obj));
    //std::cout<<"interactive shape highlighted."<<std::endl;

    if (myContext->IsHilighted(obj)) {


        shape=(Handle(AIS_Shape)::DownCast(obj));
        std::cout<<"interactive shape highlighted."<<std::endl;
        return 1;
    }

    return 0;
}

void OcctQtViewer::undo(){

    for(uint i=0; i<recyclebin_shapevec.size(); i++){
        add_shapevec(recyclebin_shapevec.at(i));
    }
    recyclebin_shapevec.clear();
}


void OcctQtViewer::set_view_front()
{
    myView->SetProj( V3d_Yneg );
}

void OcctQtViewer::set_view_back()
{
    myView->SetProj( V3d_Ypos );
}

void OcctQtViewer::set_view_top()
{
    myView->SetProj( V3d_Zpos );
}

void OcctQtViewer::set_view_bottom()
{
    myView->SetProj( V3d_Zneg );
}

void OcctQtViewer::set_view_left()
{
    myView->SetProj( V3d_Xneg );
}
void OcctQtViewer::set_view_right()
{
    myView->SetProj( V3d_Xpos );
}

void OcctQtViewer::set_view_3d()
{
    myView->SetProj( V3d_XnegYnegZpos );
}

void OcctQtViewer::zoom_plus(){
    UpdateZoom(10);
    updateView();
}

void OcctQtViewer::zoom_min(){
    UpdateZoom(-10);
    updateView();
}
