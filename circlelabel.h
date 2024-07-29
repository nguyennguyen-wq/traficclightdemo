#ifndef CIRCLELABEL_H
#define CIRCLELABEL_H
#include <QLabel>
#include <QPainter>

class CircleLabel : public QLabel
{
    Q_OBJECT

public:
    explicit CircleLabel(QWidget *parent = nullptr, const QColor &color = Qt::red)
        : QLabel(parent), circleColor(color) {}

    void setColor(const QColor &color) {
        circleColor = color;
        update();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QLabel::paintEvent(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(circleColor);
        painter.drawEllipse(0, 0, width(), height());
    }

private:
    QColor circleColor;
};

#endif // CIRCLELABEL_H

