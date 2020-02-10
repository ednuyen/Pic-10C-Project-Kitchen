#ifndef CHEESE_H
#define CHEESE_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include "Food.h"
class Cheese: public QWidget,public Food{
public:
   Cheese();
    void print();

private:
    int pos_x;
    int pos_y;

};




#endif // CHEESE_H
