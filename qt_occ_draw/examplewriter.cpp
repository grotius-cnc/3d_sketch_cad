#include "examplewriter.h"
#include "iostream"

ExampleWriter::ExampleWriter(dxfRW &dxfW) : dxfW(dxfW) {
}

void ExampleWriter::writeEntities() {

    for(unsigned int i=0; i<linevec.size(); i++){
        dxfW.writeLine(&linevec[i]);
    }
    for(unsigned int i=0; i<arcvec.size(); i++){
        dxfW.writeArc(&arcvec[i]);
    }
    for(unsigned int i=0; i<circlevec.size(); i++){
        dxfW.writeCircle(&circlevec[i]);
    }
    for(unsigned int i=0; i<pointvec.size(); i++){
        dxfW.writePoint(&pointvec[i]);
    }
    for(unsigned int i=0; i<layervec.size(); i++){
        dxfW.writeLayer(&layervec[i]);
    }


    //! Etc.

    //! Example :
    //!
    //!    DRW_Line line;
    //!    line.basePoint.x = 10.20;
    //!    line.basePoint.y = 20.10;
    //!    line.secPoint.x = 30.25;
    //!    line.secPoint.y = 30;
    //!    dxfW.writeLine(&line);
}
