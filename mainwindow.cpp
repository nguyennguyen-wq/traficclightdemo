#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    step(0)
{
    ui->setupUi(this);
    labelRed = new CircleLabel(this, Qt::red);
    labelYellow = new CircleLabel(this, Qt::yellow);
    labelGreen = new CircleLabel(this, Qt::green);
    labelRed->setGeometry(10, 10, 100, 100);
    labelYellow->setGeometry(120, 10, 100, 100);
    labelGreen->setGeometry(230, 10, 100, 100);
    labelRed->setVisible(false);
    labelYellow->setVisible(false);
    labelGreen->setVisible(false);
    setupTimers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTimers()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        switch (step) {
		case 0:
            showRedCircle();
            break;
        case 1:
            hideCircles();
            break;
        case 2:
            showYellowCircle();
            break;
        case 3:
            hideCircles();
            break;
        case 4:
            showGreenCircle();
            break;
		case 5:
            hideCircles();
            break;
		case 6:
            showYellowCircle();
            break;
		case 7:
            hideCircles();
            break;
		}
        step = (step + 1) % 8;
    });
    timer->start(3500); 
}

void MainWindow::showRedCircle()
{
    labelRed->setVisible(true);
    labelYellow->setVisible(false);
    labelGreen->setVisible(false);
    timer->setInterval(3500); 
}

void MainWindow::showYellowCircle()
{
    labelRed->setVisible(false);
    labelYellow->setVisible(true);
    labelGreen->setVisible(false);
    timer->setInterval(1500); 
}

void MainWindow::showGreenCircle()
{
    labelRed->setVisible(false);
    labelYellow->setVisible(false);
    labelGreen->setVisible(true);
    timer->setInterval(3500); 
}

void MainWindow::hideCircles()
{
    labelRed->setVisible(false);
    labelYellow->setVisible(false);
    labelGreen->setVisible(false);
    timer->setInterval(100); 
}

