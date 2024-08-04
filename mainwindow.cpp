#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , changeLight(0)
{
    ui->setupUi(this);
    redLight = new QLabel(this);
    yellowLight = new QLabel(this);
    greenLight = new QLabel(this);
    redLight->setFixedSize(100, 100);
    yellowLight->setFixedSize(100, 100);
    greenLight->setFixedSize(100, 100);
    redLight->setStyleSheet("background-color: grey; border: 1px solid black; border-radius: 50px;");
    yellowLight->setStyleSheet("background-color: grey; border: 1px solid black; border-radius: 50px;");
    greenLight->setStyleSheet("background-color: grey; border: 1px solid black; border-radius: 50px;");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(redLight);
    layout->addWidget(yellowLight);
    layout->addWidget(greenLight);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::changeTrafficLight);
    timer->start(1000); 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTrafficLight()
{
    redLight->setStyleSheet("background-color: grey; border: 1px solid black; border-radius: 50px;");
    yellowLight->setStyleSheet("background-color: grey; border: 1px solid black; border-radius: 50px;");
    greenLight->setStyleSheet("background-color: grey; border: 1px solid black; border-radius: 50px;");

    switch (changeLight)
    {
    case 0:
        redLight->setStyleSheet("background-color: red; border: 1px solid black; border-radius: 50px;");
        timer->setInterval(5000);
        break;
    case 1:
        yellowLight->setStyleSheet("background-color: yellow; border: 1px solid black; border-radius: 50px;");
        timer->setInterval(2500);
        break;
    case 2:
        greenLight->setStyleSheet("background-color: LightGreen; border: 1px solid black; border-radius: 50px;");
        timer->setInterval(5000);
        break;
    case 3:
        yellowLight->setStyleSheet("background-color: yellow; border: 1px solid black; border-radius: 50px;");
        timer->setInterval(3500);
        break;
    }
    changeLight = (changeLight + 1) % 4;
}

