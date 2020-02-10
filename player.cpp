#include "player.h"
#include <QLabel>
Player::Player(QWidget *parent)
    : QWidget(parent){
    pos_x =5;
    pos_y = 5;
    setFocusPolicy(Qt::ClickFocus);

}

void Player:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    QRectF pff(0,0,10,10);
    painter.drawEllipse(pff);
    return;
}
void Player::keyPressEvent(QKeyEvent *e){
}
void Player::set_position(int x,int y){
    pos_x = x;
    pos_y = y;
}
int Player:: get_pos_x(){
    return pos_x;
}
int Player::get_pos_y(){
    return pos_y;
}
void Player::add_food(Food* next_food){
    sandwhich.push_back(next_food);
    //next_food->print();
}
void Player::print_sandwhich(){
    QWidget* w3 = new QWidget;
   // QLabel* test = new QLabel("Test");
    //test->show();
    QVBoxLayout* layout = new QVBoxLayout;
    for (int i =0; i<sandwhich.size();i++){
        QLabel* new_one = new QLabel();
       QString a= sandwhich[i]->get_food_type();
        new_one->setText(a);
        //new_one->show();
        layout->addWidget(new_one);
    }
    w3->setLayout(layout);
    w3->show();

}
int Player::get_vector_size(){
    return sandwhich.size();
}
