#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <ball.h>
#include <playerbar.h>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    Ball *b;
    PlayerBar *p1;
    PlayerBar *p2;
    QLabel *score1;
    QLabel *score2;
};

#endif // MAINWINDOW_H
