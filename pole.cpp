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


void pole::mousePressEvent(QMouseEvent *event)
{
    //generate_obstacle();
   if (this->rect().contains(event->pos()))
    {
       this->currentX=event->pos().x();
               this->currentY=event->pos().y();
    if(event->buttons() & Qt::LeftButton){this->isClickedLeft=1;}//
    if(event->buttons() & Qt::RightButton){ this->isClickedRight=1;}
    }
    }


void pole::mouseMoveEvent(QMouseEvent *event)
{

        this->currentX=event->pos().x();
                this->currentY=event->pos().y();

}

void pole::mouseReleaseEvent(QMouseEvent *event)
{
     this->currentX=event->pos().x();
     this->currentY=event->pos().y();
     this->isClickedLeft=0;
     this->isClickedRight=0;

}

void pole::generate_obstacle()
{


        QRect checkRect(this->currentX-g->size/2,
                        this->currentY-g->size/2,
                        g->size,g->size);
        for(int i=0;i<this->iks;i++)
        {
            for(int j=0;j<this->igrek;j++)
            {
                if(checkRect.contains(this->siatka[i][j].xpos,this->siatka[i][j].ypos))
                {
                        if(this->isClickedLeft)
                {
                        this->siatka[i][j].free_status=true;

            }
                        if(this->isClickedRight)
                {
                        this->siatka[i][j].free_status=false;

            }
            }
            }
            }

            }



void pole:: rysuj_Siatka(QPainter *d)//pomocnicza siatka na planszy
{

    for(int i=0;i<this->iks;i++)
        for(int j=0 ; j<this->igrek;j++)
        {   if(this->siatka[i][j].free_status==false){
                d->setBrush(Qt::white);
                d->drawRect(this->siatka[i][j].xpos-g->size/2,this->siatka[i][j].ypos-g->size/2,g->size,g->size);
            }

        }
}


void pole:: draw_obstacle(QPainter *d)//pomocnicza siatka na planszy
{

    for(int i=0;i<this->iks;i++)
        for(int j=0 ; j<this->igrek;j++)
        {
            if(this->siatka[i][j].free_status==true){
                d->setBrush(Qt::black);
                d->drawRect(this->siatka[i][j].xpos-g->size/2,this->siatka[i][j].ypos-g->size/2,g->size,g->size);
}
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
    //generate_obstacle();
     generate_obstacle();
    draw_obstacle(&d);

   // rysuj_Plansza(&d);

   // this->update(0,0,this->maximumWidth(),this->maximumHeight());

}
