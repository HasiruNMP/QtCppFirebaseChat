#include "send.h"
#include "chat.h"
#include "ui_chat.h"
#include "receive.h"
#include <windows.h>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QVariantMap>
#include <QThread>

send::send(QObject *parent) : QObject(parent)
{
    netMngSend = new QNetworkAccessManager();
}

void send::sendMsg()
{
    QString urlP1{"https://qtfirebasechat-default-rtdb.firebaseio.com/messages/"};
    QString urlP2{"2"};
    QString urlP3{".json"};
    QString url = urlP1+urlP2+urlP3;

    //QString newMsgText = ui->msgLineEdit->text();
    QVariantMap newMsgVM;
    newMsgVM["text"] = "fnksjfnkjsfn";
    newMsgVM["user"] = "Hasiru";
    QJsonDocument newMsgJson = QJsonDocument::fromVariant(newMsgVM);

    QNetworkRequest newMsgReq((QUrl(url)));
    newMsgReq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    netMngSend->put(newMsgReq, newMsgJson.toJson());

    //ui->msgLineEdit->setText("");
    //getMsg();
}
