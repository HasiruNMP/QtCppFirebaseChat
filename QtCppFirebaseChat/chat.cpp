#include "chat.h"
#include "ui_chat.h"
//#include "send.h"
//#include "receive.h"
#include <windows.h>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QVariantMap>
#include <QThread>

using std::string;

Chat::Chat(QWidget *parent) : QMainWindow(parent), ui(new Ui::Chat)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //netMngMain = new QNetworkAccessManager();
    //netRepMain = netMngMain->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1.json")));
    //connect(netRepMain, &QNetworkReply::readyRead, this, &Chat::read );

    chatOn = true;
    syncMethod = 1;

}

Chat::~Chat()
{
    delete ui;
    netMngMain->deleteLater();
}

void Chat::sync()
{
    if(chatOn==true){

        if(syncMethod==1){
            getMsg();
        }
        else{
            sendMsg2();
        }
    }
}

void Chat::showMsg(string msg, string user)
{
    Sleep(2000);
    sync();
    //QString newMsg = QString::fromStdString(msg+user);
    //ui->listMsgs->addItem(newMsg);
}

void Chat::getMsg()
{
    ui->listMsgs->addItem("recieved a new message");
    ui->listMsgs->scrollToBottom();
    syncMethod=1;
    //netRepMain = netMngMain->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1.json")));
    //connect(netRepMain, &QNetworkReply::readyRead, this, &Chat::read );
    //Sleep(3000);
    showMsg("","");

}

void Chat::sendMsg2()
{
    ui->listMsgs->addItem("sent a new message");
    ui->listMsgs->scrollToBottom();
    syncMethod=1;
    //netRepMain = netMngMain->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1.json")));
    //connect(netRepMain, &QNetworkReply::readyRead, this, &Chat::read );
    //Sleep(3000);

}

void Chat::on_btnOpenChat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    //chatOn = true;
    //Sleep(5000);

}

void Chat::on_btnSendMsg_clicked()
{
    QFuture<void> future = QtConcurrent::run([=]() {
        syncMethod=2;
    });
}

void Chat::on_btnLogout_clicked()
{
    //chatOn = false;
    //ui->stackedWidget->setCurrentIndex(0);
    chatOn = true;
    //syncMethod = 1;
    //netMngMain = new QNetworkAccessManager();
    sync();
}


void Chat::read()
{
    QByteArray netRepStr = netRepGet->readAll();
    qDebug() << netRepStr;
    QString qstr = QString(netRepStr);
    qDebug() << qstr;
    sync();
}



