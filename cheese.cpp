#include "cheese.h"
Cheese::Cheese():Food()
 {
    store_type("Cheese");
}

void Cheese::print(){
    QLabel* testing = new QLabel ("This is testing if cheese was added to the vector");
    testing->show();
}


