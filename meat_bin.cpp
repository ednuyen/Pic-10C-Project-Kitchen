#include "meat_bin.h"
Meat_Bin::Meat_Bin(QWidget *parent)
    : QWidget(parent){
    meat_bin_pos_x = 4;
    meat_bin_pos_y = 4;
}


void Meat_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
int Meat_Bin:: get_meat_bin_pos_x(){
    return meat_bin_pos_x;
}

int Meat_Bin:: get_meat_bin_pos_y(){
    return meat_bin_pos_y;
}
