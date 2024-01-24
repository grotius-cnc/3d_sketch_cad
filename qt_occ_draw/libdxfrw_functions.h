#ifndef LIBDXFRW_FUNCTIONS_H
#define LIBDXFRW_FUNCTIONS_H

#include <iostream>
#include <string>

// libocct
#include <AIS_Shape.hxx>

// libdxfrw
#include "dx_data.h"
#include "dx_iface.h"

class libdxfrw_functions
{
public:
    libdxfrw_functions();

    std::vector<Handle(AIS_Shape)> open_dxf_file(std::string filename);
    bool save_dxf_file(std::string filename, std::vector<Handle(AIS_Shape)> shapevec);
    bool write_entity();
    std::vector<opencascade::handle<AIS_Shape>> convert_dxf_into_opencascade_shapes();

private:
    // Dxf data
    dx_data fData;
    dx_data fCleanData; // To clean the fData.
    dx_iface *iface = new dx_iface;

};

#endif // LIBDXFRW_FUNCTIONS_H
