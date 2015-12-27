#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "pole.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p = new pole;

    ui->gridLayout->addWidget(p,0,0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{

}
