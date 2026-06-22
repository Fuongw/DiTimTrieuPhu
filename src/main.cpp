#include "mainwindow.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    // MỚI: Bắt lấy tên người chơi do Shell Script truyền vào
    QString playerName = "Khách"; 
    if (argc > 1) {
        playerName = QString::fromUtf8(argv[1]); // Lấy đối số thứ 2 (là cái tên)
    }

    MainWindow w;
    w.setPlayerName(playerName); // MỚI: Gửi tên này vào trong Giao diện chính
    w.show();
    
    return a.exec();
}
