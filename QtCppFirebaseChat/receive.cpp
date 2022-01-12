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
    //netMngCheck->deleteLater();
}

void receive::checkUpdates()
{
    netRepCheck = netMngCheck->get(QNetworkRequest(QUrl("https://qfirenotes-default-rtdb.firebaseio.com/users/hasiru/notes.json")));
    connect(netRepCheck, &QNetworkReply::readyRead, this, &receive::readMCount );
     qDebug() << "checking for updates";
     //getMsgs();
}

void receive::getMsgs()
{
    //netRepCheck = netMngCheck->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1.json")));
    //connect(netRepCheck, &QNetworkReply::readyRead, this, &receive::readMCount );
//    connect(netMngCheck, &QNetworkAccessManager::finished, [=](QNetworkReply *reply) {
//        qDebug() << reply->readAll(); // You don't need QTextCodec!
//        //reply->deleteLater();
//        Sleep(1);
//        netMngCheck->get(QNetworkRequest(QUrl("https://qtfirebasechat-default-rtdb.firebaseio.com/messages/1.json")));
//    });
    //Sleep(2000);
    //checkUpdates();
}

void receive::readMCount()
{
    qDebug() << netRepCheck->readAll();
    //checkUpdates();
    //QByteArray netRepStr = netRepCheck->readAll();
    //qDebug() << netRepStr;
    //QString qstr = QString(netRepStr);
    //qDebug() << qstr;
}
