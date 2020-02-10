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
text1 = new QLabel("Welcome to Heck's Kitchen!");
health_text= new QLabel("Health: "+ QString::number(health) );
main_character = new Player;
 binb = new Bread_Bin;
 binc = new Cheese_Bin;
 binm = new Meat_Bin;


 draw_walls();
 draw_targets();

title_space->addWidget(text1);
title_space->addWidget(health_text);
play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
play_space->addWidget(binb,binb->get_beard_bin_pos_x(),binb->get_beard_bin_pos_y());
play_space->addWidget(binc,binc->get_cheese_bin_pos_x(),binc->get_cheese_bin_pos_y());
play_space->addWidget(binm,binm->get_meat_bin_pos_x(),binm->get_meat_bin_pos_y());

fullwindow->addLayout(title_space);
fullwindow->addLayout(play_space);
fullwindow->addLayout(sandwhich_layout);
setLayout(fullwindow);



}

void SecondWindow:: draw_walls(){
    for (int i= 0; i<11; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,i,0);
    }
    for (int i= 0; i<11; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,i,10);
    }
    for (int i= 0; i<10; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,0,i);
    }
    for (int i= 0; i<10; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,10,i);
    }
}


void SecondWindow:: draw_targets(){
    for (int i =1; i<10; i++){
        Target* a= new Target;
        play_space->addWidget(a,i, 2);
    }
}


void SecondWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_G){
        main_character->print_sandwhich();

    }
    if(event->key() == Qt::Key_A||event->key() == Qt::Key_Left){
    if(main_character->get_pos_y()>2){
    main_character->set_position(main_character->get_pos_x(), main_character->get_pos_y()-1);
    play_space->addWidget(main_character, main_character->get_pos_x(),main_character->get_pos_y());
    }

    }
    else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right){
        if(main_character->get_pos_y()<10){
    main_character->set_position(main_character->get_pos_x(), main_character->get_pos_y()+1);
    play_space->addWidget(main_character, main_character->get_pos_x(),main_character->get_pos_y());
        }
    }

    else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up){
        if(main_character->get_pos_x()>0){
    main_character->set_position(main_character->get_pos_x()-1, main_character->get_pos_y());
    play_space->addWidget(main_character, main_character->get_pos_x(),main_character->get_pos_y());
        }
    }

    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down){
        if(main_character->get_pos_x()<10){
    main_character->set_position(main_character->get_pos_x()+1, main_character->get_pos_y());
    play_space->addWidget(main_character, main_character->get_pos_x(),main_character->get_pos_y());
        }
    }
    if(event->key() == Qt::Key_Space){
        if(main_character->get_pos_x() == binc->get_cheese_bin_pos_x()&&main_character->get_pos_y() == binc->get_cheese_bin_pos_y() ){
            Food* a = new Cheese();
            main_character->add_food(a);
            Cheese_Bin* b = new Cheese_Bin;
            sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binb->get_beard_bin_pos_x() && main_character->get_pos_y() == binb->get_beard_bin_pos_y() ){
            Food* a = new Bread();
            main_character->add_food(a);
            Bread_Bin* b = new Bread_Bin;
            sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
        if(main_character->get_pos_x() == binm->get_meat_bin_pos_x() && main_character->get_pos_y() == binm->get_meat_bin_pos_y() ){
            Food* a = new Meat();
            main_character->add_food(a);
            Meat_Bin* b = new Meat_Bin;
            sandwhich_layout->addWidget(b, 12,main_character->get_vector_size());
        }
    }

    return;
}


SecondWindow::~SecondWindow()
{

}
