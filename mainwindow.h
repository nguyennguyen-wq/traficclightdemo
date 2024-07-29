#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include "circlelabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRedCircle();
    void showYellowCircle();
    void showGreenCircle();
    void hideCircles();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int step;
    CircleLabel *labelRed;
    CircleLabel *labelYellow;
    CircleLabel *labelGreen;
    void setupTimers();
};

#endif // MAINWINDOW_H

