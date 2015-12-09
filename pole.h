#ifndef POLE_H
#define POLE_H

#include <QObject>
#include <QWidget>
#include "kwadrat.h"

class pole : public QWidget
{
    Q_OBJECT
public:
    explicit pole(QWidget *parent = 0);
    bool game_status;
    bool move_status;
    bool game_pause;

    kwadrat *g;
    kwadrat **siatka;
    int iks,igrek;

    QKeyEvent *w;

    double ruchy;
    int teleport_bar;
    int czas;
    int wykonane;



signals:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:

     void paintEvent(QPaintEvent *);
     void rysuj_Siatka(QPainter *d);
     void inicjalizacja();
     void generate_obstacle(QPainter *d);
};

#endif // POLE_H
