#ifndef SEND_H
#define SEND_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QThread>
#include <QThreadPool>

class send : public QObject
{
    Q_OBJECT
public:
    explicit send(QObject *parent = nullptr);

    void sendMsg();

signals:

private:
    QNetworkAccessManager * netMngSend;
    QNetworkReply * netRepSend;
};

#endif // SEND_H
