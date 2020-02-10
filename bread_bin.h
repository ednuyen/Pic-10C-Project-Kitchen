#ifndef BREAD_BIN_H
#define BREAD_BIN_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>

class Bread_Bin:public QWidget{
    public:
       Bread_Bin(QWidget *parent= nullptr);
        void paintEvent(QPaintEvent* e);
        int get_beard_bin_pos_x();
        int get_beard_bin_pos_y();
private:
       int bread_bin_pos_x;
       int bread_bin_pos_y;
};



#endif // BREAD_BIN_H
