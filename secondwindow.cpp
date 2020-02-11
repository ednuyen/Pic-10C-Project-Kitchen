#include "secondwindow.h"
#include "player.h"
#include "wall.h"
#include "target.h"


#include <QGridLayout>

//Makes the second window which will be able to recieve the signal from MainWindow
SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
{
setFocusPolicy(Qt::ClickFocus);

fullwindow = new QVBoxLayout();
title_space = new QHBoxLayout();
play_space = new QGridLayout();
sandwhich_layout = new QGridLayout();

//player_health
this->setFixedSize(700,700);
text1 = new QLabel("Welcome to Heck's Kitchen!");
health_text= new QLabel("Health: "+ QString::number(health) );
main_character = new Player;
 binb1 = new Bread_Bin(12,1);
 binb2 = new Bread_Bin(13,1);
 binb3 = new Bread_Bin(14,1);

 binc1 = new Cheese_Bin(12,3);
 binc2 = new Cheese_Bin(13,3);
 binc3 = new Cheese_Bin(14,3);

 binm1 = new Meat_Bin(12,5);
 binm2 = new Meat_Bin(13,5);
 binm3 = new Meat_Bin(14,5);

 binv1 = new Veggie_Bin(12,7);
 binv2 = new Veggie_Bin(13,7);
 binv3 = new Veggie_Bin(14,7);

 customer1 = new Player(1,1);
customer1->set_customer_sandwhich();
customer1->print_sandwhich();
 draw_walls();
 draw_targets();

title_space->addWidget(text1);
title_space->addWidget(health_text);
play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());

play_space->addWidget(binb1,binb1->get_bin_pos_y(),binb1->get_bin_pos_x());
play_space->addWidget(binb2,binb2->get_bin_pos_y(),binb2->get_bin_pos_x());
play_space->addWidget(binb3,binb3->get_bin_pos_y(),binb3->get_bin_pos_x());

play_space->addWidget(binc1,binc1->get_bin_pos_y(),binc1->get_bin_pos_x());
play_space->addWidget(binc2,binc2->get_bin_pos_y(),binc2->get_bin_pos_x());
play_space->addWidget(binc3,binc3->get_bin_pos_y(),binc3->get_bin_pos_x());

play_space->addWidget(binm1,binm1->get_bin_pos_y(),binm1->get_bin_pos_x());
play_space->addWidget(binm2,binm2->get_bin_pos_y(),binm2->get_bin_pos_x());
play_space->addWidget(binm3,binm3->get_bin_pos_y(),binm3->get_bin_pos_x());

play_space->addWidget(binv1,binv1->get_bin_pos_y(),binv1->get_bin_pos_x());
play_space->addWidget(binv2,binv2->get_bin_pos_y(),binv2->get_bin_pos_x());
play_space->addWidget(binv3,binv3->get_bin_pos_y(),binv3->get_bin_pos_x());

fullwindow->addLayout(title_space);
fullwindow->addLayout(play_space);
fullwindow->addLayout(sandwhich_layout);
setLayout(fullwindow);



}

void SecondWindow:: draw_walls(){
    for (int i= 0; i<8; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,i,0);
    }
    for (int i= 0; i<8; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,i,16);
    }
    for (int i= 0; i<16; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,0,i);
    }
    for (int i= 0; i<16; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,8,i);
    }
}


void SecondWindow:: draw_targets(){
    for (int i =1; i<8; i++){
        Target* a= new Target;
        play_space->addWidget(a,i, 2);
    }
}


void SecondWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer1->get_pos_x() &&main_character->get_pos_y()==customer1->get_pos_y()){
        main_character->print_sandwhich();
        main_character->check_order(customer1);

    }

    if(event->key() == Qt::Key_A||event->key() == Qt::Key_Left){
    if(main_character->get_pos_x()>2){
    main_character->move_left();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
    }

    }
    else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right){
        if(main_character->get_pos_x()<16){
    main_character->move_right();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }

    else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up){
        if(main_character->get_pos_y()>0){
    main_character->move_up();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }

    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down){
        if(main_character->get_pos_y()<8){
    main_character->move_down();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }

   if(event->key() == Qt::Key_Space){
        if(main_character->get_pos_x() == binc1->get_bin_pos_x()&&main_character->get_pos_y() == binc1->get_bin_pos_y() ){
            Food* a = new Cheese("American Cheese");
            main_character->add_food(a);
            //Cheese_Bin* b = new Cheese_Bin;
            //sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binc2->get_bin_pos_x()&&main_character->get_pos_y() == binc2->get_bin_pos_y() ){
                 Food* a = new Cheese("Swiss Cheese");
                 main_character->add_food(a);
                 //Cheese_Bin* b = new Cheese_Bin;
                 //sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
       if(main_character->get_pos_x() == binc3->get_bin_pos_x()&&main_character->get_pos_y() == binc3->get_bin_pos_y() ){
               Food* a = new Cheese("Vegan Cheese");
               main_character->add_food(a);
                //Cheese_Bin* b = new Cheese_Bin;
                  //sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
                  }



        if(main_character->get_pos_x() == binb1->get_bin_pos_x() && main_character->get_pos_y() == binb1->get_bin_pos_y() ){
            Food* a = new Bread("White Bread");
            main_character->add_food(a);
           // Bread_Bin* b = new Bread_Bin;
           // sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binb2->get_bin_pos_x() && main_character->get_pos_y() == binb2->get_bin_pos_y() ){
            Food* a = new Bread("Whole Wheat Bread");
            main_character->add_food(a);
           // Bread_Bin* b = new Bread_Bin;
           // sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binb3->get_bin_pos_x() && main_character->get_pos_y() == binb3->get_bin_pos_y() ){
            Food* a = new Bread("Prezel Bun");
            main_character->add_food(a);
           // Bread_Bin* b = new Bread_Bin;
           // sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }



        if(main_character->get_pos_x() == binm1->get_bin_pos_x() && main_character->get_pos_y() == binm1->get_bin_pos_y() ){
            Food* a = new Meat("Turkey Meat");
            main_character->add_food(a);
           // Meat_Bin* b = new Meat_Bin;
            //sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binm2->get_bin_pos_x() && main_character->get_pos_y() == binm2->get_bin_pos_y() ){
            Food* a = new Meat("Steak");
            main_character->add_food(a);
           // Meat_Bin* b = new Meat_Bin;
            //sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binm3->get_bin_pos_x() && main_character->get_pos_y() == binm3->get_bin_pos_y() ){
            Food* a = new Meat("Impossible Meat");
            main_character->add_food(a);
           // Meat_Bin* b = new Meat_Bin;
            //sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }





        if(main_character->get_pos_x() == binv1->get_bin_pos_x() && main_character->get_pos_y() == binv1->get_bin_pos_y() ){
            Food* a = new Veggies("Lettuce");
            main_character->add_food(a);
           // Veggie_Bin* b = new Veggie_Bin;
           // sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binv2->get_bin_pos_x() && main_character->get_pos_y() == binv2->get_bin_pos_y() ){
            Food* a = new Veggies("Peppers");
            main_character->add_food(a);
           // Veggie_Bin* b = new Veggie_Bin;
           // sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binv3->get_bin_pos_x() && main_character->get_pos_y() == binv3->get_bin_pos_y() ){
            Food* a = new Veggies("Spinage");
            main_character->add_food(a);
           // Veggie_Bin* b = new Veggie_Bin;
           // sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }



    }

    return;
}


SecondWindow::~SecondWindow(){
    delete main_character;
    delete customer1;
    delete customer2;
    delete customer3;
    delete customer4;
}
