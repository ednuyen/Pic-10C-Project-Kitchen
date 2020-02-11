#include "bread_bin.h"
Bread_Bin::Bread_Bin(QWidget *parent)
    : QWidget(parent){
    bread_bin_pos_x = 9;
    bread_bin_pos_y = 1;
}


void Bread_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::gray));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
int Bread_Bin:: get_beard_bin_pos_x(){
    return bread_bin_pos_x;
}
int Bread_Bin:: get_beard_bin_pos_y(){
    return bread_bin_pos_y;
}
