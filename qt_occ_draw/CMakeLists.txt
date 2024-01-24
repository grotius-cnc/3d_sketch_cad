cmake_minimum_required(VERSION 3.5)
set(PROJECT "cad") # The name of the file excluding .c or .h
project(${PROJECT} C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths for header files etc.
include_directories(${SRC_DIR}/)
include_directories(${SRC_DIR}/../oce-upstream-V7_5_0beta/inc)
include_directories(${SRC_DIR}/../oce-upstream-V7_5_0beta/src)
include_directories(${SRC_DIR}/../libdxfrw)
include_directories(${SRC_DIR}/../libdxfrw/src)
include_directories(${SRC_DIR}/../libdxfrw/dwg2dxf)
include_directories(${SRC_DIR}/../libdxfrw/src/intern)
include_directories("usr/include")
include_directories("usr/local/lib")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Set path to eigen3, for install $ sudo apt-get install libeigen3-dev
include_directories("/usr/include/eigen3/Eigen")

# Opencascade
find_package (OpenCASCADE REQUIRED)

SET(OpenCASCADE_LIBS
    TKGeomAlgo TKMesh TKHLR TKBO TKShHealing
    TKPrim
    TKernel TKMath TKTopAlgo TKService
    TKG2d TKG3d TKV3d TKOpenGl
    TKBRep TKXSBase TKGeomBase TKGeomAlgo
    TKXSDRAW
    TKLCAF TKXCAF TKCAF TKVCAF
    TKCDF TKBin TKBinL TKBinXCAF TKXml TKXmlL TKXmlXCAF
    # -- IGES support
    TKIGES
    # -- STEP support
    TKSTEP TKXDESTEP TKXDEIGES TKSTEPAttr TKSTEPBase TKSTEP209
    # -- STL support
    TKSTL
    # -- OBJ/glTF support
    TKRWMesh TKMeshVS
    # -- VRML support
    TKVRML
    # -- ViewerTest
    TKViewerTest
    )

# Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/opt/qt-creator/5.15.1/gcc_64/lib/cmake")
include_directories("/opt/qt-creator/5.15.1/gcc_64/include/QtWidgets")
include_directories("/opt/qt-creator/5.15.1/gcc_64/include/QtGui")
include_directories("/opt/qt-creator/5.15.1/gcc_64/include")
include_directories("/opt/qt-creator/5.15.1/gcc_64/include/QtCore")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets OpenGL REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets OpenGL REQUIRED)

set(PROJECT_SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/mainwindow.cpp
    ${SRC_DIR}/mainwindow.h
    ${SRC_DIR}/mainwindow.ui
    ${SRC_DIR}/form.cpp
    ${SRC_DIR}/form.h
    ${SRC_DIR}/form.ui
    ${SRC_DIR}/OcctQtViewer.h
    ${SRC_DIR}/OcctQtViewer.cpp
    ${SRC_DIR}/icons.qrc
    ${SRC_DIR}/draw_primitives.h
    ${SRC_DIR}/draw_primitives.cpp
    #${SRC_DIR}/sketcher.h
    #${SRC_DIR}/sketcher.cpp
    ${SRC_DIR}/libdxfrw_functions.h
    ${SRC_DIR}/libdxfrw_functions.cpp
    ${SRC_DIR}/examplewriter.h
    ${SRC_DIR}/examplewriter.cpp
    ${SRC_DIR}/draw_workflow.h
    ${SRC_DIR}/draw_workflow.cpp
    ${SRC_DIR}/qleftmenu.h
    ${SRC_DIR}/qleftmenu.cpp

    # Dxf library.
    ${SRC_DIR}/../libdxfrw/src/intern/drw_dbg.h
    ${SRC_DIR}/../libdxfrw/src/intern/drw_dbg.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/drw_textcodec.h
    ${SRC_DIR}/../libdxfrw/src/intern/drw_textcodec.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgbuffer.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgbuffer.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader15.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader15.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader18.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader18.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader21.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader21.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader24.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader24.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader27.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgreader27.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dwgutil.h
    ${SRC_DIR}/../libdxfrw/src/intern/dwgutil.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dxfreader.h
    ${SRC_DIR}/../libdxfrw/src/intern/dxfreader.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/dxfwriter.h
    ${SRC_DIR}/../libdxfrw/src/intern/dxfwriter.cpp
    ${SRC_DIR}/../libdxfrw/src/intern/rscodec.h
    ${SRC_DIR}/../libdxfrw/src/intern/rscodec.cpp
    ${SRC_DIR}/../libdxfrw/src/drw_base.h
    ${SRC_DIR}/../libdxfrw/src/drw_base.cpp
    ${SRC_DIR}/../libdxfrw/src/drw_classes.h
    ${SRC_DIR}/../libdxfrw/src/drw_classes.cpp
    ${SRC_DIR}/../libdxfrw/src/drw_entities.h
    ${SRC_DIR}/../libdxfrw/src/drw_entities.cpp
    ${SRC_DIR}/../libdxfrw/src/drw_header.h
    ${SRC_DIR}/../libdxfrw/src/drw_header.cpp
    ${SRC_DIR}/../libdxfrw/src/drw_objects.h
    ${SRC_DIR}/../libdxfrw/src/drw_objects.cpp
    ${SRC_DIR}/../libdxfrw/src/libdwgr.h
    ${SRC_DIR}/../libdxfrw/src/libdwgr.cpp
    ${SRC_DIR}/../libdxfrw/src/libdxfrw.h
    ${SRC_DIR}/../libdxfrw/src/libdxfrw.cpp
    ${SRC_DIR}/../libdxfrw/dwg2dxf/dx_data.h
    ${SRC_DIR}/../libdxfrw/dwg2dxf/dx_iface.h
    ${SRC_DIR}/../libdxfrw/dwg2dxf/dx_iface.cpp
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT}
        ${PROJECT_SOURCES}
        )
else()
    if(ANDROID)
        add_library(${PROJECT} SHARED
            ${PROJECT_SOURCES}
            )
    else()
        add_executable(${PROJECT}
            ${PROJECT_SOURCES}
            )
    endif()
endif()

if (BUILD_USPACE)
    add_definitions(-DULAPI)
else ()
    add_definitions(-DRTAPI)
endif ()

# Link.
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${OpenCASCADE_LIBS} Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}
    )

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../../bin)
