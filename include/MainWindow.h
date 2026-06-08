#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "GameController.h"

// Dòng này giúp C++ nhận diện được file giao diện .ui mà bạn sẽ kéo thả trong Qt Designer
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT // Bắt buộc phải có macro này để dùng cơ chế Signals & Slots (Click nút bấm)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 1. Các hàm xử lý luồng màn hình
    void showLoginScreen();       // Hàm tự động gọi khi đếm hết 10 giây Intro Logo
    void on_btnStart_clicked();   // Xử lý khi người chơi nhập tên xong và bấm "Bắt đầu"

    // 2. Các hàm xử lý click 4 đáp án
    // Tên hàm đặt theo cú pháp on_[Tên_Nút]_clicked để Qt tự động kết nối
    void on_btnAnswerA_clicked();
    void on_btnAnswerB_clicked();
    void on_btnAnswerC_clicked();
    void on_btnAnswerD_clicked();

    // 3. Các hàm xử lý 3 quyền trợ giúp
    void on_btn5050_clicked();
    void on_btnSwap_clicked();
    void on_btnCallFriend_clicked();

    // 4. Xử lý chơi lại ở màn hình kết thúc
    void on_btnPlayAgain_clicked();

private:
    Ui::MainWindow *ui;           // Con trỏ ui: Dùng để gọi các nút bấm đã thiết kế (VD: ui->btnStart)
    GameController controller;    // Lõi logic game đã chốt với bạn cùng nhóm
    QTimer *introTimer;           // Bộ đồng hồ đếm ngược 10s cho màn hình Intro

    // Các hàm nội bộ hỗ trợ cập nhật giao diện (không dính tới sự kiện click)
    void updateUI();                    // Tải câu hỏi mới, làm mới màu nút bấm, cập nhật mốc tiền
    void handleAnswer(int choiceIndex); // Hàm gộp chung để kiểm tra đúng/sai cho gọn code
    void showResultScreen(bool isWin);  // Lật sang trang tổng kết tiền thưởng
};

#endif // MAINWINDOW_H
