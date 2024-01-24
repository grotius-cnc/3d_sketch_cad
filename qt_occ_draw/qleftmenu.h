#ifndef QLEFTMENU_H
#define QLEFTMENU_H

#include <QFrame>

class QLeftMenu : public QFrame
{
    Q_OBJECT
public:
    explicit QLeftMenu(QWidget *parent = nullptr);

public slots:
    bool is_hovered();
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
private:

    double myHovered=0;
};

#endif // QLEFTMENU_H
