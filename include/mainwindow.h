
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
    void setPlayerName(QString name);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void showLoginScreen();
    void on_btn_Start_clicked(); // (Nếu nút Start bên UI không có gạch dưới thì giữ nguyên)

    // SỬA Ở ĐÂY: Thêm dấu gạch dưới sau chữ btn
    void on_btn_AnswerA_clicked();
    void on_btn_AnswerB_clicked();
    void on_btn_AnswerC_clicked();
    void on_btn_AnswerD_clicked();

    void on_btn_5050_clicked();
    void on_btn_Swap_clicked();
    void on_btn_CallFriend_clicked();

    void on_btn_PlayAgain_clicked();

private:
    QString currentPlayerName;
    Ui::MainWindow *ui;           // Con trỏ ui: Dùng để gọi các nút bấm đã thiết kế (VD: ui->btnStart)
    GameController controller;    // Lõi logic game đã chốt với bạn cùng nhóm
    QTimer *introTimer;           // Bộ đồng hồ đếm ngược 10s cho màn hình Intro

    // Các hàm nội bộ hỗ trợ cập nhật giao diện (không dính tới sự kiện click)
    void updateUI();                    // Tải câu hỏi mới, làm mới màu nút bấm, cập nhật mốc tiền
    void handleAnswer(int choiceIndex); // Hàm gộp chung để kiểm tra đúng/sai cho gọn code
    void showResultScreen(bool isWin);  // Lật sang trang tổng kết tiền thưởng
};

#endif // MAINWINDOW_H
