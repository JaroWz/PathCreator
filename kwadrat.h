#ifndef KWADRAT_H
#define KWADRAT_H

#include <QWidget>

class kwadrat : public QWidget
{
    Q_OBJECT
public:
    explicit kwadrat(QWidget *parent = 0);
    int xpos;
    int ypos;
    int size;
    bool free_status;
    int xplanszy;
    int yplanszy;

signals:

public slots:
};

#endif // KWADRAT_H
