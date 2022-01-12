#include "chat.h"
#include "receive.h"

#include <QApplication>
#include <windows.h>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Chat window;
    //window.show();

    receive test;
    test.checkUpdates();

//    QFuture<void> future = QtConcurrent::run([=]() {
//        receive updates;
//        updates.checkUpdates();
//    });

    return a.exec();
}
