#include "qleftmenu.h"
#include "iostream"

QLeftMenu::QLeftMenu(QWidget *parent) : QFrame(parent)
{

}

bool QLeftMenu::is_hovered() {
    return myHovered;
}

void QLeftMenu::enterEvent(QEvent *event) {

    std::cout<<"mouse entered"<<std::endl;
    QLeftMenu::setCursor(Qt::CursorShape::ArrowCursor);
    myHovered=1;
}

void QLeftMenu::leaveEvent(QEvent *event) {

    std::cout<<"mouse leaved"<<std::endl;
    myHovered=0;
}
