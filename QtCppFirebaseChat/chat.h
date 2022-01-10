#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QThread>
#include <QThreadPool>

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();
    bool chatOn;

private slots:
    void on_btnOpenChat_clicked();
    void on_btnSendMsg_clicked();
    void on_btnLogout_clicked();
    void read();

private:
    Ui::Chat *ui;

    QNetworkAccessManager * networkMng;
    QNetworkReply * networkReply;

    void sendMsg();
    void getMsg();
    void checkUpdates();


};

#endif // CHAT_H
