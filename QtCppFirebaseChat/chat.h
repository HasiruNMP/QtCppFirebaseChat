#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private:
    Ui::Chat *ui;
    void sendMsg();
    void getNewMsg();
    void refresh();
};

#endif // CHAT_H
