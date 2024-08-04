#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeTrafficLight();

private:
    Ui::MainWindow *ui;
    QLabel *redLight;
    QLabel *yellowLight;
    QLabel *greenLight;
    QTimer *timer;
    int changeLight;
};

#endif // MAINWINDOW_H
