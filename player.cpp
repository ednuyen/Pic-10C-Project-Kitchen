#include "player.h"
#include "bread.h"
#include "cheese.h"
#include "veggies.h"
#include "meat.h"
#include <QLabel>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
                return false;}
        }
    }
    else{  
       return false;
    } 
    return true;
}

void Player::set_basic_sandwhich(){
    srand(time(NULL));
    int rand_num = rand() % 4 +1;
        if (rand_num == 1){
            //House Special
            Food* a = new Bread("White Bread");
            Food* b = new Cheese("American Cheese");
            Food* c = new Meat("Turkey Meat");
            Food* d = new Bread("White Bread");
            this->add_food(a);
            this->add_food(b);
            this->add_food(c);
            this->add_food(d);
            type_of_sandwhich = "House Special";
    }
        if (rand_num == 2){
            //Vegan Sandwhich
            Food* a = new Veggies("Lettuce");
            Food* b = new Cheese("Vegan Cheese");
            Food* c = new Meat("Impossible Meat");
            Food* d = new Veggies("Lettuce");
            this->add_food(a);
            this->add_food(b);
            this->add_food(c);
            this->add_food(d);
            type_of_sandwhich = "Vegan Sandwhich";
    }
        if (rand_num == 3){
            //Swiss Burger
            Food* a = new Bread("Whole Wheat Bread");
            Food* b = new Cheese("Swiss Cheese");
            Food* c = new Meat("Steak");
            Food* d = new Bread("Whole Wheat Bread");
            this->add_food(a);
            this->add_food(b);
            this->add_food(c);
            this->add_food(d);
            type_of_sandwhich = "Swiss Burger";
    }
        if (rand_num == 4){
            //The Salad Sandwhich
            Food* a = new Veggies("Lettuce");
            Food* b = new Veggies("Peppers");
            Food* c = new Veggies("Spinage");
            Food* d = new Veggies("Lettuce");
            this->add_food(a);
            this->add_food(b);
            this->add_food(c);
            this->add_food(d);
            type_of_sandwhich = "The Salad Sandwhich";
    }
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

QVBoxLayout* Player::print_sandwhich(){


    QVBoxLayout* layout = new QVBoxLayout;
        QLabel * title = new QLabel(type_of_sandwhich);
        layout->addWidget(title);
    for (int i =0; i<sandwhich.size();i++){
        QLabel* new_one = new QLabel();
       QString a= sandwhich[i]->get_food_type();
        new_one->setText(a);

        layout->addWidget(new_one);
    }
    return layout;

}

int Player::get_vector_size(){
    return sandwhich.size();
}

void Player:: delete_sandwhich(){
    for (int i = 0; i<this->get_vector_size();i++){
        delete sandwhich[i];
        sandwhich[i] = nullptr;
        sandwhich.pop_back();
    }
}

void Player::move_up(){pos_y--;}
void Player::move_down(){pos_y++;}
void Player::move_right(){pos_x++;}
void Player::move_left(){pos_x--;}
