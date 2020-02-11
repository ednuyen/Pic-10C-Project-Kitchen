#include "player.h"
#include "bread.h"
#include "cheese.h"
#include "meat.h"
#include <QLabel>
Player::Player(QWidget *parent)
    : QWidget(parent){
    pos_x =5;
    pos_y = 5;
    setFocusPolicy(Qt::ClickFocus);

}

Player::Player(int x,int y){
    pos_x =x;
    pos_y= y;
}


bool Player:: check_order(Player *other){
    if(this->get_vector_size() == other->get_vector_size()){
        for(int i= 0; i<get_vector_size(); i++){
            if (this->sandwhich[i]->get_food_type()!=other->sandwhich[i]->get_food_type()){
                QLabel* why = new QLabel("Your fired!");
                why->show();
                return false;}
        }
    }
    else{
        QLabel* w4 = new QLabel("You fired!");
        w4->show();
       return false;
    }
    QLabel* w4 = new QLabel("You got a raise!");
    w4->show();
    return true;
}
void Player::set_customer_sandwhich(){
    Food* a = new Bread("White Bread");
    Food* b = new Cheese("American Cheese");
    Food* c = new Meat("Turkey Meat");
    Food* d = new Bread("White Bread");
    this->add_food(a);
    this->add_food(b);
    this->add_food(c);
    this->add_food(d);
}




void Player:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    QRectF pff(0,0,10,10);
    painter.drawEllipse(pff);
    return;
}

//void Player::keyPressEvent(QKeyEvent *e){
//}
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

    QVBoxLayout* layout = new QVBoxLayout;
    for (int i =0; i<sandwhich.size();i++){
        QLabel* new_one = new QLabel();
       QString a= sandwhich[i]->get_food_type();
        new_one->setText(a);

        layout->addWidget(new_one);
    }
    w3->setLayout(layout);
    w3->show();

}
int Player::get_vector_size(){
    return sandwhich.size();
}


void Player::move_up(){pos_y--;}
void Player::move_down(){pos_y++;}
void Player::move_right(){pos_x++;}
void Player::move_left(){pos_x--;}
