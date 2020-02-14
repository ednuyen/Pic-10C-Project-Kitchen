#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QStackedWidget>
#include "secondwindow.h"
#include "instructionswindow.h"

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pressedPlay();
    void pressedExit();
    void pressedHelp();

    QHBoxLayout *getButtons() const;
    void setButtons(QHBoxLayout *value);

private:
    QLabel* blank;
    QLabel* challenge_level;
    QSlider* challenge;
    QPushButton* start;
    QPushButton* leave;
    QVBoxLayout* mainscreen;
    QVBoxLayout* layout;
    QHBoxLayout* buttons;
    SecondWindow w2;
    InstructionsWindow i;
};
#endif // MAINWINDOW_H
