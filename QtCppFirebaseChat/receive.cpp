#include "receive.h"
#include <windows.h>

receive::receive(QObject *parent) : QObject(parent)
{
    netMngCheck = new QNetworkAccessManager(this);
    //netRepCheck = netMngCheck->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/counts.json")));
    //connect(netRepCheck, &QNetworkReply::readyRead, this, &receive::readMCount );
    qDebug() << "receive object initiated";
    //checkUpdates();
}

receive::~receive()
{
    netMngCheck->deleteLater();
}

void receive::checkUpdates()
{
     qDebug() << "checking for updates";
     getMsgs();
}

void receive::getMsgs()
{
    netRepCheck = netMngCheck->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1.json")));
    connect(netRepCheck, &QNetworkReply::readyRead, this, &receive::readMCount );
    Sleep(5000);
}

void receive::readMCount()
{
    qDebug() << netRepCheck->readAll();
    checkUpdates();
    //QByteArray netRepStr = netRepCheck->readAll();
    //qDebug() << netRepStr;
    //QString qstr = QString(netRepStr);
    //qDebug() << qstr;
}
