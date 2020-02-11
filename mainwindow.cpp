#include "mainwindow.h"
#include "secondwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)   
{

//    QPixmap pm(":/menu/pic10c-menu-#3-pixilart.png");
//    this->title->setPixmap(pm);
//    this->title->setScaledContents(true);

    QPixmap bkgnd(":/menu/pic10c-menu-#3-pixilart.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    layout = new QVBoxLayout();
    mainscreen = new QVBoxLayout();
    buttons = new QHBoxLayout();

  //title = new QLabel("HECK'S KITCHEN");
  //challenge_level = new QLabel("Pick the Spice level you want to play!!");
  challenge = new QSlider();
  challenge->setRange(1,3);
  start = new QPushButton("Start the game!!");
  leave = new QPushButton(" Quit!");
  connect(start, &QPushButton::pressed, this,&MainWindow::buttonpressed);
   connect(leave,&QPushButton::pressed, this, &MainWindow::buttonclose);

  //layout->addWidget(title);
 // layout->addWidget(challenge_level);
  layout->addWidget(challenge);

this->setFixedSize(700,700);
  buttons->addWidget(start);
  buttons->addWidget(leave);
  mainscreen->addLayout(layout);
  mainscreen->addLayout(buttons);
  QWidget* central = new QWidget();
      central->setLayout(mainscreen);
      this->setCentralWidget(central);
}

MainWindow::~MainWindow(){}

void MainWindow::buttonpressed(){

  w2.show();
}

void MainWindow::buttonclose(){
MainWindow::close();
w2.close();
}

