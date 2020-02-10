#include "Food.h"
Food::Food(QWidget *parent)
    : QWidget(parent){

}

QString Food::get_food_type(){
    return type_of_food;
}
void Food::store_type(QString name){
    type_of_food = name;
}
