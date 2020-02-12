#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>

#include "Food.h"
#include <vector>
class Player:public QWidget{
public:
  // void keyPressEvent(QKeyEvent* e);
  // void keyReleaseEvent(QKeyEvent *event);
   void set_position(int,int);
    Player(QWidget *parent= nullptr);
    Player(int,int);

    void paintEvent(QPaintEvent* e);
    int get_pos_x();
    int get_pos_y();
    void add_food(Food*);
    QVBoxLayout* print_sandwhich();
    int get_vector_size();
    void set_basic_sandwhich();
    Player& operator = (Player*);
    bool check_order(Player*);
    void delete_sandwhich();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
private:
    std::vector<Food*> sandwhich;
    int pos_x;
    int pos_y;
    QString type_of_sandwhich;



};
#endif // PLAYER_H

