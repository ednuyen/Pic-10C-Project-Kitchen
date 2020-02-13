#include "mainwindow.h"
#include "secondwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)   
{
    QPixmap bkgnd(":/menu/pic10c-menu-#3-pixilart.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    layout = new QVBoxLayout();
    mainscreen = new QVBoxLayout();
    buttons = new QHBoxLayout();

    challenge = new QSlider();
    challenge->setRange(1,3); // choose difficulty of game
    start = new QPushButton("PLAY");
    start->setStyleSheet("QPushButton { color : black; }");
    leave = new QPushButton("EXIT");
    leave->setStyleSheet("QPushButton { color : black; }");
    QPushButton* help = new QPushButton("INSTRUCTIONS");
    help->setStyleSheet("QPushButton { color : black; }");
    connect(start,&QPushButton::pressed, this, &MainWindow::pressedPlay);
    connect(leave,&QPushButton::pressed, this, &MainWindow::pressedExit);
    connect(help,&QPushButton::pressed, this, &MainWindow::pressedHelp);

    layout->addWidget(challenge);
    buttons->addWidget(leave);
    buttons->addWidget(help);
    buttons->addWidget(start);
    mainscreen->addLayout(layout);
    mainscreen->addLayout(buttons);

    QWidget* central = new QWidget();
    central->setLayout(mainscreen);
    this->setCentralWidget(central);
}

MainWindow::~MainWindow() {}

void MainWindow::pressedPlay(){
    w2.show();
}

void MainWindow::pressedExit(){
    MainWindow::close();
    w2.close();
}

void MainWindow::pressedHelp() {
//    stackedWidget->setCurrentIndex(1);
    i.show();
}

QHBoxLayout *MainWindow::getButtons() const
{
    return buttons;
}

void MainWindow::setButtons(QHBoxLayout *value)
{
    buttons = value;
}


