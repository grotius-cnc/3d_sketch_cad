#include "libdxfrw_functions.h"
#include "draw_primitives.h"
#include "examplewriter.h"

libdxfrw_functions::libdxfrw_functions()
{

}

std::vector<Handle(AIS_Shape)> libdxfrw_functions::open_dxf_file(std::string filename){

    // dx_iface().clear(&fData);           // Clear previous loaded dxf data.
    std::vector<Handle(AIS_Shape)> Ais_shapevec;

    bool ok = iface->fileImport( filename, &fData, 0 );

    if (!ok) {
        std::cout << "Error reading file " << filename << std::endl;
    } else {
        Ais_shapevec=convert_dxf_into_opencascade_shapes();
    }
    return Ais_shapevec;
}

// Function to convert Quantity_Color to a 24-bit color value (combined integer value)
int convertQuantityColorTo24Bit(const Quantity_Color& color) {
    // Convert floating-point color components to the 0-255 range
    int red = static_cast<int>(color.Red() * 255.0);
    int green = static_cast<int>(color.Green() * 255.0);
    int blue = static_cast<int>(color.Blue() * 255.0);

    // Combine red, green, and blue components into a 24-bit color value
    return (red << 16) | (green << 8) | blue;
}

//! A example how to write and save dxf file.
bool libdxfrw_functions::save_dxf_file(std::string filename, std::vector<Handle(AIS_Shape)> shapevec){

    dxfRW dxf(filename.c_str());
    ExampleWriter writer(dxf);

    for(uint i=0; i<shapevec.size(); i++){

        Handle(AIS_Shape) shape=shapevec.at(i);
        TopoDS_Edge edge = TopoDS::Edge(shape->Shape());
        Standard_Real first, last;
        Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, first, last);
        gp_Pnt p1= curve->Value(first);
        gp_Pnt p2= curve->Value(last);
        gp_Pnt p3= curve->Value((first+last)/2);
        std::cout<<"    first:"<<first<<std::endl;
        std::cout<<"    way:"<<last<<std::endl;
        std::cout<<"    last:"<<last<<std::endl;

        TopExp_Explorer explorer(shapevec.at(i)->Shape(), TopAbs_VERTEX);
        if (explorer.More()) {
            explorer.Next();
            if (!explorer.More()) {

                TopoDS_Vertex aVertex = TopoDS::Vertex(explorer.Current());
                gp_Pnt p1 = BRep_Tool::Pnt(aVertex);

                std::cout << "The shape is a point." << std::endl;

                DRW_Point point;
                point.basePoint.x = p1.X();
                point.basePoint.y = p1.Y();
                point.basePoint.z = p1.Z();

                Quantity_Color col;
                shape->Color(col);
                point.color24=convertQuantityColorTo24Bit(col);

                // point.layer="0";
                // point.visible=1;
                // point.lineType

                writer.pointvec.push_back(point);

            } else {
                // std::cout << "The shape does not represent a single point." << std::endl;

                if (curve->IsKind(STANDARD_TYPE(Geom_Line))) {
                    std::cout << "The shape is a line." << std::endl;

                    DRW_Line line;
                    line.basePoint.x = p1.X();
                    line.basePoint.y = p1.Y();
                    line.basePoint.z = p1.Z();
                    line.secPoint.x = p2.X();
                    line.secPoint.y = p2.Y();
                    line.secPoint.z = p2.Z();

                    Quantity_Color col;
                    shape->Color(col);
                    line.color24=convertQuantityColorTo24Bit(col);

                    writer.linevec.push_back(line);
                }

                if (curve->IsKind(STANDARD_TYPE(Geom_Circle))) {

                    Handle(Geom_Circle) circle = Handle(Geom_Circle)::DownCast(curve);

                    std::cout<<"writing arc."<<std::endl;
                    std::cout<<"    center x:"<<circle->Location().X()<<" y:"<<circle->Location().Y()<<" z:"<<circle->Location().Z()<<std::endl;
                    std::cout<<"    radius:"<<circle->Radius()<<std::endl;
                    std::cout<<"    start angle:"<<first<<std::endl;
                    std::cout<<"    end angle:"<<last<<std::endl;
                    std::cout<<"    start point x:"<<p1.X()<<" y:"<<p1.Y()<<" z:"<<p1.Z()<<std::endl;
                    std::cout<<"    way point x:"<<p3.X()<<" y:"<<p3.Y()<<" z:"<<p3.Z()<<std::endl;
                    std::cout<<"    end point:"<<p2.X()<<" y:"<<p2.Y()<<" z:"<<p2.Z()<<std::endl;

                    DRW_Arc arc;
                    arc.isccw=0; // only used in hatch,
                    arc.staangle=first;
                    arc.endangle=last;

                    arc.radious=circle->Radius();

                    arc.basePoint.x=circle->Location().X(); // Arc center.
                    arc.basePoint.y=circle->Location().Y();
                    arc.basePoint.z=circle->Location().Z();

                    arc.arcstartPoint.x=p1.X();
                    arc.arcstartPoint.y=p1.Y();
                    arc.arcstartPoint.z=p1.Z();

                    arc.arcwayPoint.x=p3.X();
                    arc.arcwayPoint.y=p3.Y();
                    arc.arcwayPoint.z=p3.Z();

                    arc.arcendPoint.x=p2.X();
                    arc.arcendPoint.y=p2.Y();
                    arc.arcendPoint.z=p2.Z();

                    Quantity_Color col;
                    shape->Color(col);
                    arc.color24=convertQuantityColorTo24Bit(col);

                    writer.arcvec.push_back(arc);
                }
            }
        }
    }

    //! Here it will write all data at once to the dxf file.
    dxf.write(&writer, DRW::Version::AC1027, false);
    return 1;
}

// Function to convert a 24-bit color value (0-255 for each component) to Quantity_Color
Quantity_Color convert24BitToQuantityColor(int color24bit) {
    int red = (color24bit >> 16) & 0xFF;        // Extract red component (bits 16-23)
    int green = (color24bit >> 8) & 0xFF;       // Extract green component (bits 8-15)
    int blue = color24bit & 0xFF;               // Extract blue component (bits 0-7)

    // Normalize 24-bit color components to Quantity_Color range (0.0-1.0)
    double normalizedRed = static_cast<double>(red) / 255.0;
    double normalizedGreen = static_cast<double>(green) / 255.0;
    double normalizedBlue = static_cast<double>(blue) / 255.0;

    // Create and return a Quantity_Color object using normalized values
    return Quantity_Color(normalizedRed, normalizedGreen, normalizedBlue, Quantity_TOC_RGB);
}

std::vector<Handle(AIS_Shape)> libdxfrw_functions::convert_dxf_into_opencascade_shapes(){

    std::cout<<"inside convert dxf function"<<std::endl;
    std::vector<Handle(AIS_Shape)> Ais_shapevec;
    Ais_shapevec.reserve(10000);

    auto blocks = fData.mBlock->ent;
    for (auto iter = blocks.begin(); iter != blocks.end(); iter++){
        if(DRW::POINT == (*iter)->eType){
            std::cout<<"loading point"<<std::endl;
            DRW_Point *point = dynamic_cast<DRW_Point*>(*iter);

            Handle(AIS_Shape) shape=draw_primitives().draw_3d_point({point->basePoint.x,point->basePoint.y,point->basePoint.z});
            draw_primitives().colorize(shape,convert24BitToQuantityColor(point->color24),0);

            Ais_shapevec.push_back(shape);
        }
        if(DRW::LINE == (*iter)->eType){
            DRW_Line *line = dynamic_cast<DRW_Line*>(*iter);
            std::cout<<"loading line"<<std::endl;
            // Check if linelenght>0.
            double l=sqrt(pow(line->basePoint.x-line->secPoint.x,2)+pow(line->basePoint.y-line->secPoint.y,2)+pow(line->basePoint.z-line->secPoint.z,2));
            if(l>0){

                Handle(AIS_Shape) shape=draw_primitives().draw_3d_line({line->basePoint.x,line->basePoint.y,line->basePoint.z},{line->secPoint.x,line->secPoint.y,line->secPoint.z});
                draw_primitives().colorize(shape,convert24BitToQuantityColor(line->color24),0);
                Ais_shapevec.push_back(shape);
            } else {
                std::cout<<"line is too short to be a line"<<std::endl;
            }
        }
        if(DRW::LWPOLYLINE == (*iter)->eType){
            DRW_LWPolyline *lwpolyline = dynamic_cast<DRW_LWPolyline*>(*iter);
            std::cout<<"loading wire"<<std::endl;
            std::vector<gp_Pnt> pvec;
            for(unsigned int i=0; i<lwpolyline->vertlist.size(); i++){
                pvec.push_back({lwpolyline->vertlist.at(i)->x,lwpolyline->vertlist.at(i)->y,0});
            }
            pvec.push_back({lwpolyline->vertlist.at(0)->x,lwpolyline->vertlist.at(0)->y,0});
            Ais_shapevec.push_back(draw_primitives().draw_3d_line_wire(pvec));
        }
        if(DRW::SPLINE == (*iter)->eType){
            std::cout<<"loading spline"<<std::endl;
            DRW_Spline *spline = dynamic_cast<DRW_Spline*>(*iter);
            std::vector<gp_Pnt> pvec;

            //for(unsigned int i=0; i<spline->controllist.size(); i++){
            //    pvec.push_back({spline->controllist.at(i)->x,spline->controllist.at(i)->y,spline->controllist.at(i)->z});
            //}
            //Ais_shapevec.push_back(draw_primitives().draw_3d_spline(pvec,5));
        }
        if(DRW::ARC == (*iter)->eType){
            std::cout<<"loading arc"<<std::endl;
            DRW_Arc *arc = dynamic_cast<DRW_Arc*>(*iter);

            gp_Pnt center={arc->center().x,arc->center().y,arc->center().z};
            gp_Pnt point_on_normal={arc->extPoint.x,arc->extPoint.y,arc->extPoint.z};
            gp_Dir directionVector(point_on_normal.X()-center.X(), point_on_normal.Y()-center.Y(), point_on_normal.Z()-center.Z()); // Not normalized.

            /*
            std::cout<<"    center x:"<<center.X()<<" y:"<<center.Y()<<" z:"<<center.Z()<<std::endl;
            std::cout<<"    point on normal x:"<<point_on_normal.X()<<" y:"<<point_on_normal.Y()<<" z:"<<point_on_normal.Z()<<std::endl;
            std::cout<<"    radius:"<<arc->radius() <<std::endl;
            std::cout<<"    start angle:"<<arc->startAngle()<<std::endl;
            std::cout<<"    end angle:"<<arc->endAngle()<<std::endl;
            std::cout<<"    startpoint x:"<<arc->arcstartPoint.x<<" y:"<<arc->arcstartPoint.y<<" z:"<<arc->arcstartPoint.z<<std::endl;
            std::cout<<"    waypoint x:"<<arc->arcwayPoint.x<<" y:"<<arc->arcwayPoint.y<<" z:"<<arc->arcwayPoint.z<<std::endl;
            std::cout<<"    endpoint x:"<<arc->arcendPoint.x<<" y:"<<arc->arcendPoint.y<<" z:"<<arc->arcendPoint.z<<std::endl;*/

            Handle(AIS_Shape) shape=draw_primitives().draw_3p_3d_arc({arc->arcstartPoint.x,arc->arcstartPoint.y,arc->arcstartPoint.z},
                                                                     {arc->arcwayPoint.x,arc->arcwayPoint.y,arc->arcwayPoint.z},
                                                                     {arc->arcendPoint.x,arc->arcendPoint.y,arc->arcendPoint.z});
            draw_primitives().colorize(shape,convert24BitToQuantityColor(arc->color24),0);
            Ais_shapevec.push_back(shape);
        }
        if(DRW::CIRCLE == (*iter)->eType){
            std::cout<<"loading circle"<<std::endl;
            DRW_Circle *circle = dynamic_cast<DRW_Circle*>(*iter);
            Ais_shapevec.push_back(draw_primitives().draw_2d_circle({circle->basePoint.x,circle->basePoint.y,circle->basePoint.z},circle->radious));

        }
    }
    return Ais_shapevec;
}


























