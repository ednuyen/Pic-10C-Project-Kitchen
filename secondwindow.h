#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include "wall.h"
#include "target.h"
#include "health.h"
#include "player.h"
#include "meat.h"
#include "cheese.h"
#include "bread.h"
#include "bread_bin.h"
#include "cheese_bin.h"
#include "meat_bin.h"
#include "veggie_bin.h"
#include "veggies.h"

//Desgins a Second Window that will say Welcome to Particle board and then print the grid of particles

class SecondWindow: public QWidget
{
    Q_OBJECT

public:
    //Secondary window declaration
    SecondWindow(QWidget *parent = nullptr);

    //void printgrid(int, int);
    ~SecondWindow();
        //virtual void paintEvent(QPaintEvent* e);
    void draw_walls();
    void draw_targets();
    void change_health();
    void keyPressEvent(QKeyEvent *event);

private:
    //The different text that will appear on the window
    QLabel* text1;
   // Health* player_health;
    QLabel* health_text;
    qreal health =10;
    QGridLayout* play_space;
    QHBoxLayout* title_space;
    QGridLayout* sandwhich_layout;
    QVBoxLayout* fullwindow;
    Player* main_character;
    Bread_Bin* binb1;
    Bread_Bin* binb2;
    Bread_Bin* binb3;

    Cheese_Bin* binc1;
    Cheese_Bin* binc2;
    Cheese_Bin* binc3;

    Meat_Bin* binm1;
    Meat_Bin* binm2;
    Meat_Bin* binm3;

    Veggie_Bin* binv1;
    Veggie_Bin* binv2;
    Veggie_Bin* binv3;

    Player* customer1;
    Player* customer2;
    Player* customer3;
    Player* customer4;



public slots:



signals:
};

#endif // SECONDWINDOW_H
