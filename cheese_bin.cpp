#include "cheese_bin.h"
Cheese_Bin::Cheese_Bin(QWidget *parent)
    : QWidget(parent){
    cheese_bin_pos_x = 4;
    cheese_bin_pos_y = 7;
}


void Cheese_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::yellow));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
int Cheese_Bin::get_cheese_bin_pos_x(){
    return cheese_bin_pos_x;
}

int Cheese_Bin::get_cheese_bin_pos_y(){
    return cheese_bin_pos_y;
}
