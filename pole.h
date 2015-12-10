#ifndef POLE_H
#define POLE_H

#include <QObject>
#include <QWidget>
#include "kwadrat.h"
#include <QKeyEvent>
//#include <QImage>
#include <QRadioButton>

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


    bool isClickedLeft=0;
    bool isClickedRight=0;
    bool isPosChanged=0;
  //  bool isPaintChanged=0;


     int currentX=0;
     int currentY=0;



signals:

public slots:

     void paintEvent(QPaintEvent *);
     void rysuj_Siatka(QPainter *d);
     void inicjalizacja();
     void generate_obstacle();
     void mousePressEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void draw_obstacle(QPainter *d);

};


#endif // POLE_H
