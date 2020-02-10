#ifndef MEAT_BIN_H
#define MEAT_BIN_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>

class Meat_Bin:public QWidget{
    public:
       Meat_Bin(QWidget *parent= nullptr);
        void paintEvent(QPaintEvent* e);
        int get_meat_bin_pos_x();
        int get_meat_bin_pos_y();
private:
       int meat_bin_pos_x;
       int meat_bin_pos_y;
};



#endif // MEAT_BIN_H
