#ifndef CHEESE_BIN_H
#define CHEESE_BIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>

class Cheese_Bin:public QWidget{
    public:
       Cheese_Bin(QWidget *parent= nullptr);
        void paintEvent(QPaintEvent* e);
        int get_cheese_bin_pos_x();
        int get_cheese_bin_pos_y();
private:
       int cheese_bin_pos_x;
       int cheese_bin_pos_y;
};




#endif // CHEESE_BIN_H
