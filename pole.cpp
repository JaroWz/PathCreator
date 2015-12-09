#include "pole.h"
#include <Qpainter>

pole::pole(QWidget *parent) : QWidget(parent)
{


            g=new kwadrat;
            g->size=10;

            game_status=false;
            move_status=false;
            game_pause=false;

            this->setMaximumHeight(201);
            this->setMaximumWidth(201);

            this->igrek= this->maximumHeight()/g->size;
            this->iks= this->maximumWidth()/g->size;

           // this->iks=this->maximumWidth()/g->size/2;
           // this->igrek=this->maximumHeight()/2/g->size;


            this->siatka=new kwadrat *[this->iks];
            for(int i=0;i<this->igrek;i++)
            {
                this->siatka[i]=new kwadrat [igrek];

            }


            this->inicjalizacja();


       }

void Ekran::mousePressEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
    if(event->buttons() & Qt::LeftButton) this->isClickedLeft=1;
    if(event->buttons() & Qt::RightButton) this->isClickedRight=1;

    }
}

void Ekran::mouseMoveEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
    this->isPosChanged=1;
        this->currentX=event->pos().x();
                this->currentY=event->pos().y();
    }
}

void Ekran::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
       this->isClickedLeft=0;
         this->isClickedRight=0;
        this->isPosChanged=0;
    }
}


void pole:: rysuj_Siatka(QPainter *d)//pomocnicza siatka na planszy
{
    for(int i=0;i<this->iks;i++)
        for(int j=0 ; j<this->igrek;j++)
        {
                d->setBrush(Qt::white);
                d->drawRect(this->siatka[i][j].xpos-g->size/2,this->siatka[i][j].ypos-g->size/2,10,10);

        }
}

void pole:: inicjalizacja()
{
    for(int i=0;i<this->iks;i++)
        for(int j=0 ; j<this->igrek;j++)
    {
        this->siatka[i][j].xpos=i*g->size+g->size/2;
        this->siatka[i][j].ypos=j*g->size+g->size/2;
        this->siatka[i][j].size=g->size;
        this->siatka[i][j].free_status=true;
        //if(i==this->iks-2 && j==this->igrek ) this->siatka[i][j].finish=true;


    }
this->game_pause=false;
}

void pole::paintEvent(QPaintEvent *)
{

    QPainter d(this);



    //d.setBrush(Qt::green);
    //d.drawRect(10,10,100,100);//this->maximumWidth(),this->maximumHeight());

    this->update(0,0,this->maximumWidth(),this->maximumHeight());

    //QPainter d(this);
    rysuj_Siatka(&d);


   // rysuj_Plansza(&d);

   // this->update(0,0,this->maximumWidth(),this->maximumHeight());

}
