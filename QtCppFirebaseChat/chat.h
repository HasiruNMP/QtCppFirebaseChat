#ifndef CHAT_H
#define CHAT_H

#include "receive.h"
#include "send.h"
#include <QMainWindow>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QThread>
#include <QThreadPool>

using std::string;

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

    void sync();

    bool chatOn;
    int syncMethod;

    QNetworkAccessManager * netMngGet;
    QNetworkReply * netRepGet;

    void showMsg(string msg, string user);

private slots:
    void on_btnOpenChat_clicked();
    void on_btnSendMsg_clicked();
    void on_btnLogout_clicked();
    void read();


private:
    Ui::Chat *ui;

    QNetworkAccessManager * netMngMain;
    QNetworkReply * netRepMain;

    void getMsg();
    void sendMsg2();
    void loadPrevMsgs();
    void checkUpdates();

    //receive updates;
    //send newMsgs;

};

#endif // CHAT_H
