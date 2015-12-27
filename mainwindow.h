#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pole.h"
#include "kwadrat.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:





    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;

    pole *p;
    int size,size_horizontal,size_vertical;


};

#endif // MAINWINDOW_H
    
