#ifndef RECEIVE_H
#define RECEIVE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QThread>
#include <QThreadPool>

class receive : public QObject
{
    Q_OBJECT
public:
    explicit receive(QObject *parent = nullptr);
    ~receive();

    void checkUpdates();
    void getMsgs();

    bool chatOn;

private:
    QNetworkAccessManager * netMngCheck;
    QNetworkReply * netRepCheck;

public slots:
    void readMCount();

signals:

private slots:



};

#endif // RECEIVE_H
