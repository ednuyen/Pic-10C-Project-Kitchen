#include "bread.h"
#include <QLabel>
Bread::Bread():Food()
 {
 store_type("Bread");
}


void Bread::print(){
    QLabel* testing = new QLabel ("This is testing if bread was added to the vector");
    testing->show();
}
