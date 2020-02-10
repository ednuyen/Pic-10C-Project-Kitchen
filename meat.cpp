#include "meat.h"
Meat::Meat():Food()
 {
 store_type("Meat");
}


void Meat::print(){
    QLabel* testing = new QLabel ("This is testing if meat was added to the vector");
    testing->show();
}
