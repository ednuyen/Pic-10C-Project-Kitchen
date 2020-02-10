#include "wall.h"
Wall::Wall(QWidget *parent)
    : QWidget(parent){

}


void Wall:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    QRectF pff(0,0,5,5);
    painter.drawRect(pff);


    return;
}
