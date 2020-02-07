#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b = new Ball();
    p1 = new PlayerBar(1050, 500);
    p2 = new PlayerBar(150, 500);
    score1 = new QLabel(this);
    QFont font = score1->font();
    font.setPointSize(50);
    font.setBold(true);
    score1->setFont(font);
    score1->setGeometry(1080, 20, 100, 100);
    score1->setStyleSheet("QLabel { background-color : black; color : yellow; }");
    score1->setText("0");
    score2 = new QLabel(this);
    score2->setFont(font);
    score2->setGeometry(40, 20, 100, 100);
    score2->setStyleSheet("QLabel { background-color : black; color : blue; }");
    score2->setText("0");
    score1->show();
    score2->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setColor(Qt::white);
    p.setBrush(Qt::white);
    p.setPen(pen);
    p.drawRect(150, 25, 900, 5);
    p.drawRect(150, 25+900, 900, 5);
    //p.fillRect(50, 50, 100, 100, QBrush(Qt::white));
    pen.setWidth(5);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(Qt::red);
    p.setPen(pen);
    p.setBrush(Qt::red);
    p.drawEllipse(b->getX(),b->getY(),20,20);
    pen.setColor(Qt::yellow);
    pen.setJoinStyle(Qt::MiterJoin);
    p.setPen(pen);
    p.setBrush(Qt::yellow);
    p.drawRect(p1->getX(), p1->getY(), 10, 150);
    pen.setColor(Qt::blue);
    p.setPen(pen);
    p.setBrush(Qt::blue);
    p.drawRect(p2->getX(), p2->getY(), 10, 150);
    b->detectCollision(p1->getX(), p1->getY());
    b->detectCollision(p2->getX(), p2->getY());
    if (!b->isMoving() && b->getX() >= 600)
    {
        b->setY(p1->getY() + 70);
    }
    else if (!b->isMoving() && b->getX() < 600)
    {
        b->setY(p2->getY() + 70);
    }
    score1->setText(QString::number(b->getS1()));
    score2->setText(QString::number(b->getS2()));
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        p1->setY(p1->getY() - 100);
    }
    else if (event->key() == Qt::Key_Down)
    {
        p1->setY(p1->getY() + 100);
    }
    else if (event->key() == Qt::Key_W)
    {
        p2->setY(p2->getY() - 100);
    }
    else if (event->key() == Qt::Key_S)
    {
        p2->setY(p2->getY() + 100);
    }
    else if (event->key() == Qt::Key_Space)
    {
        b->startMotion();
    }
}
