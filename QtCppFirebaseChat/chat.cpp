#include "chat.h"
#include "ui_chat.h"
#include <windows.h>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QVariantMap>

using std::string;

Chat::Chat(QWidget *parent) : QMainWindow(parent), ui(new Ui::Chat)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    networkMng = new QNetworkAccessManager();
}

Chat::~Chat()
{
    delete ui;
    networkMng->deleteLater();
}

void Chat::sendMsg()
{
    QString urlP1{"https://qtfirebasechat-default-rtdb.firebaseio.com/messages/"};
    QString urlP2{"2"};
    QString urlP3{".json"};
    QString url = urlP1+urlP2+urlP3;

    QString newMsgText = ui->msgLineEdit->text();
    QVariantMap newMsgVM;
    newMsgVM["text"] = newMsgText;
    newMsgVM["user"] = "Hasiru";
    QJsonDocument newMsgJson = QJsonDocument::fromVariant(newMsgVM);

    QNetworkRequest newMsgReq((QUrl(url)));
    newMsgReq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    networkMng->put(newMsgReq, newMsgJson.toJson());

    ui->msgLineEdit->setText("");
    getMsg();
}

void Chat::getMsg()
{
    networkReply = networkMng->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/2.json")));
    connect(networkReply, &QNetworkReply::readyRead, this, &Chat::read );

    ui->listWidget->addItem("test123");
    ui->listWidget->scrollToBottom();
}

void Chat::checkUpdates()
{
    QFuture<void> future = QtConcurrent::run([=]() {
        networkMng = new QNetworkAccessManager();
        networkReply = networkMng->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1/text.json")));
        connect(networkReply, &QNetworkReply::readyRead, this, &Chat::read );
    });
    //qDebug() << "Stopped checking for updates";
}

void Chat::on_btnOpenChat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    chatOn = true;
    //checkUpdates();
}


void Chat::on_btnSendMsg_clicked()
{
    sendMsg();
}


void Chat::on_btnLogout_clicked()
{
    chatOn = false;
    ui->stackedWidget->setCurrentIndex(0);
}

void Chat::read()
{
    QByteArray netRepStr = networkReply->readAll();
    qDebug() << netRepStr;
    QString qstr = QString(netRepStr);
    qDebug() << qstr;
}

