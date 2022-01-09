#include "chat.h"
#include "ui_chat.h"
#include <windows.h>
#include <QNetworkRequest>
#include <QDebug>

Chat::Chat(QWidget *parent) : QMainWindow(parent), ui(new Ui::Chat)
{
    networkMng = new QNetworkAccessManager(this);
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QFuture<void> future = QtConcurrent::run([=]() {
        checkUpdates();
    });
}

Chat::~Chat()
{
    delete ui;
    networkMng->deleteLater();
}

void Chat::sendMsg()
{
    ui->listWidget->addItem("test");
    getMsg();
}

void Chat::getMsg()
{
    ui->listWidget->scrollToBottom();
}

void Chat::checkUpdates()
{
    while (chatOn == true) {
        Sleep(2000);
        qDebug() << "checked for updates";
        ui->listWidget->addItem("test123");
    }
}

void Chat::on_btnOpenChat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    //checkUpdates();
}


void Chat::on_btnSendMsg_clicked()
{
    sendMsg();
}

