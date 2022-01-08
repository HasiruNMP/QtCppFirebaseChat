#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnOpenChat_clicked()
{
    static Chat newchat;
    newchat.show();
}

