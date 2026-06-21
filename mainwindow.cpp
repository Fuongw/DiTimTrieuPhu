#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QFontDatabase>
#include <QMessageBox>
#include <QInputDialog>

// Biến đếm xem người chơi đang ở câu số mấy (Bắt đầu từ câu 1)
int currentQuestionIndex = 1;

// Mảng lưu trữ mức tiền thưởng của 15 câu
QString prizeMoney[15] = {"200", "400", "600", "1.000", "2.000",
                          "3.000", "6.000", "10.000", "14.000", "22.000",
                          "30.000", "40.000", "60.000", "80.000", "150.000"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // NẠP FONT PIXEL
    int fontId = QFontDatabase::addApplicationFont("data/pixel_font.ttf");

    if (fontId != -1) { // Nếu load font thành công
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont customFont(fontFamily);
        customFont.setPointSize(17);

        // Áp dụng font này cho các khung chữ
        ui->lbl_Question->setFont(customFont);
        ui->btn_AnswerA->setFont(customFont);
        ui->btn_AnswerB->setFont(customFont);
        ui->btn_AnswerC->setFont(customFont);
        ui->btn_AnswerD->setFont(customFont);
        ui->lbl_Money->setFont(customFont);
    }

    // Kích hoạt GIF chú mèo
    QMovie *movie = new QMovie("images/cat_hoi.gif");
    ui->cat_hoi->setMovie(movie);
    movie->start();

    // Gọi lệnh load file câu hỏi
    controller.loadEasyQuestions("data/questions_easy.txt");
    controller.loadHardQuestions("data/questions_hard.txt");

    // Ẩn 3 nút quyền trợ giúp khi game mới bắt đầu (Chưa qua câu 5)
    ui->btn_5050->setVisible(false);
    ui->btn_Swap->setVisible(false);
    ui->btn_CallFriend->setVisible(false);

    // Khởi tạo một ván game mới
    controller.startNewGame();

    // Đổ dữ liệu câu hỏi đầu tiên lên giao diện
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Hàm cập nhật giao diện
void MainWindow::updateUI() {
    Question currentQ = controller.getCurrentQuestion(currentQuestionIndex);

    ui->lbl_Question->setText(QString::fromStdString(currentQ.text));

    ui->btn_AnswerA->setText(QString::fromStdString("A. " + currentQ.options[0]));
    ui->btn_AnswerB->setText(QString::fromStdString("B. " + currentQ.options[1]));
    ui->btn_AnswerC->setText(QString::fromStdString("C. " + currentQ.options[2]));
    ui->btn_AnswerD->setText(QString::fromStdString("D. " + currentQ.options[3]));

    QString defaultStyle = "QPushButton { background-color: transparent; border: none; color: white; text-align: left; padding-left: 20px; }"
                           "QPushButton:hover { color: #FFD700; background-color: rgba(255, 255, 255, 0.1); border-radius: 20px; }";

    ui->btn_AnswerA->setStyleSheet(defaultStyle);
    ui->btn_AnswerB->setStyleSheet(defaultStyle);
    ui->btn_AnswerC->setStyleSheet(defaultStyle);
    ui->btn_AnswerD->setStyleSheet(defaultStyle);

    ui->btn_AnswerA->setEnabled(true);
    ui->btn_AnswerB->setEnabled(true);
    ui->btn_AnswerC->setEnabled(true);
    ui->btn_AnswerD->setEnabled(true);

    if (ui->btn_5050->isVisible()) {
        if (controller.canUse5050()) {
            ui->btn_5050->setEnabled(true);
            ui->btn_5050->setStyleSheet("QPushButton { color: white; }");
        } else {
            ui->btn_5050->setEnabled(false);
            ui->btn_5050->setStyleSheet("QPushButton { color: gray; background-color: rgba(100, 100, 100, 0.5); }");
        }
    }
    if (ui->btn_Swap->isVisible()) {
        if (controller.canUseSwapQuestion()) {
            ui->btn_Swap->setEnabled(true);
            ui->btn_Swap->setStyleSheet("QPushButton { color: white; }");
        } else {
            ui->btn_Swap->setEnabled(false);
            ui->btn_Swap->setStyleSheet("QPushButton { color: gray; background-color: rgba(100, 100, 100, 0.5); }");
        }
    }
    if (ui->btn_CallFriend->isVisible()) {
        if (controller.canUseCallFriend()) {
            ui->btn_CallFriend->setEnabled(true);
            ui->btn_CallFriend->setStyleSheet("QPushButton { color: white; }");
        } else {
            ui->btn_CallFriend->setEnabled(false);
            ui->btn_CallFriend->setStyleSheet("QPushButton { color: gray; background-color: rgba(100, 100, 100, 0.5); }");
        }
    }

    QString accumulatedMoney = "0";
    if (currentQuestionIndex > 1) {
        accumulatedMoney = prizeMoney[currentQuestionIndex - 2];
    }

    ui->lbl_Money->setText("Câu " + QString::number(currentQuestionIndex) + ": " + accumulatedMoney);
}

void MainWindow::showLoginScreen() {}

void MainWindow::on_btn_AnswerA_clicked() { handleAnswer(0); }
void MainWindow::on_btn_AnswerB_clicked() { handleAnswer(1); }
void MainWindow::on_btn_AnswerC_clicked() { handleAnswer(2); }
void MainWindow::on_btn_AnswerD_clicked() { handleAnswer(3); }

void MainWindow::handleAnswer(int choiceIndex) {
    Question currentQ = controller.getCurrentQuestion(currentQuestionIndex);
    char choiceChar = '0' + choiceIndex;

    if (choiceChar == currentQ.correctAnswer) {
        if (currentQuestionIndex == 15) {
            QMessageBox::information(this, "CHIẾN THẮNG VĨ ĐẠI",
                                     "CHÚC MỪNG! Bạn đã xuất sắc vượt qua toàn bộ 15 câu hỏi.\nBạn chính thức trở thành TRIỆU MEOWWWWWWWW!!!!!");
            currentQuestionIndex = 1;
            controller.startNewGame();
            ui->btn_5050->setVisible(false);
            ui->btn_Swap->setVisible(false);
            ui->btn_CallFriend->setVisible(false);
            updateUI();
        } else if (currentQuestionIndex == 5) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Mốc Quan Trọng",
                                          "Chúc mừng! Bạn đã vượt qua 5 câu đầu tiên và chắc chắn nhận được 2.000 cá.\nBạn có muốn đi tiếp để chinh phục các mốc cao hơn không?",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                ui->btn_5050->setVisible(true);
                ui->btn_Swap->setVisible(true);
                ui->btn_CallFriend->setVisible(true);
                currentQuestionIndex++;
                QMessageBox::information(this, "Tiếp tục", "Các quyền trợ giúp đã được mở khóa!");
                updateUI();
            } else {
                QMessageBox::information(this, "Kết thúc", "Bạn đã quyết định dừng cuộc chơi và mang về 2.000.000 VNĐ!");
            }
        } else {
            QMessageBox::information(this, "Kết quả", "CHÍNH XÁC! Bạn nhận được " + prizeMoney[currentQuestionIndex - 1] + " VNĐ.");
            currentQuestionIndex++;
            updateUI();
        }
    } else {
        QString correctStyle = "background-color: transparent; border: none; color: #00FF00; font-size: 20px; font-weight: bold; text-align: left; padding-left: 20px;";

        if (currentQ.correctAnswer == '0') ui->btn_AnswerA->setStyleSheet(correctStyle);
        else if (currentQ.correctAnswer == '1') ui->btn_AnswerB->setStyleSheet(correctStyle);
        else if (currentQ.correctAnswer == '2') ui->btn_AnswerC->setStyleSheet(correctStyle);
        else if (currentQ.correctAnswer == '3') ui->btn_AnswerD->setStyleSheet(correctStyle);

        ui->btn_AnswerA->setEnabled(false);
        ui->btn_AnswerB->setEnabled(false);
        ui->btn_AnswerC->setEnabled(false);
        ui->btn_AnswerD->setEnabled(false);

        if (currentQuestionIndex <= 5) {
            QMessageBox::critical(this, "Sai rồi", "Rất tiếc, bạn đã trả lời sai ở 5 câu đầu.\nBạn phải ra về với mức thưởng 0 VNĐ.");
        } else {
            QMessageBox::critical(this, "Sai rồi", "Rất tiếc! Bạn đã trả lời sai. Trò chơi kết thúc.\nBạn ra về với 2.000.000 VNĐ.");
        }

        currentQuestionIndex = 1;
        controller.startNewGame();
        ui->btn_5050->setVisible(false);
        ui->btn_Swap->setVisible(false);
        ui->btn_CallFriend->setVisible(false);
        updateUI();
    }
}

void MainWindow::on_btn_5050_clicked() {
    if (!controller.canUse5050()) {
        QMessageBox::warning(this, "Thông báo", "Bạn đã dùng quyền trợ giúp 50/50 rồi!");
        return;
    }

    std::vector<int> hiddenAnswers = controller.use5050();

    if (hiddenAnswers.size() >= 2) {
        std::vector<QPushButton*> answerButtons = {ui->btn_AnswerA, ui->btn_AnswerB, ui->btn_AnswerC, ui->btn_AnswerD};

        for (int hiddenIndex : hiddenAnswers) {
            if (hiddenIndex >= 0 && hiddenIndex < 4) {
                answerButtons[hiddenIndex]->setEnabled(false);
                answerButtons[hiddenIndex]->setText("");
                answerButtons[hiddenIndex]->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
            }
        }

        ui->btn_5050->setEnabled(false);
        ui->btn_5050->setStyleSheet("QPushButton { color: gray; background-color: rgba(100, 100, 100, 0.5); }");
        QMessageBox::information(this, "50/50", "2 đáp án sai đã bị loại bỏ!\nBạn còn 2 lựa chọn.");
    }
}

void MainWindow::on_btn_Swap_clicked() {
    if (!controller.canUseSwapQuestion()) {
        QMessageBox::warning(this, "Thông báo", "Bạn đã dùng quyền đổi câu hỏi rồi!");
        return;
    }

    // 1. ĐỒNG BỘ CHỈ SỐ: Gán vị trí câu hỏi hiện tại trên UI vào Controller
    // Vì currentQuestionIndex chạy từ 1-15, còn currentIndex chạy từ 0-14
    controller.setCurrentIndex(currentQuestionIndex - 1);

    // 2. Gọi controller thực hiện đổi câu hỏi (xóa câu cũ, nạp câu mới vào mảng)
    controller.useSwapQuestion();

    // 3. Làm mờ và khóa nút đổi câu hỏi
    ui->btn_Swap->setEnabled(false);
    ui->btn_Swap->setStyleSheet("QPushButton { color: gray; background-color: rgba(100, 100, 100, 0.5); }");

    QMessageBox::information(this, "Đổi câu hỏi", "Đã hủy bỏ câu hỏi cũ và đổi câu hỏi mới thành công!");

    // 4. CẬP NHẬT GIAO DIỆN: Ép UI phải đọc lại câu hỏi mới vừa được đổi
    // Trong code hiện tại của bạn, hàm nạp dữ liệu lên UI là loadQuestion()
    updateUI();
}

void MainWindow::on_btn_CallFriend_clicked() {
    if (!controller.canUseCallFriend()) {
        QMessageBox::warning(this, "Thông báo", "Bạn đã gọi bạn rồi!");
        return;
    }

    bool ok;
    QString friendName = QInputDialog::getText(this, "Gọi bạn trợ giúp",
                                               "Nhập tên người bạn muốn gọi:",
                                               QLineEdit::Normal, "", &ok);

    if (!ok || friendName.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Thông báo", "Vui lòng nhập tên bạn bè!");
        return;
    }

    std::string friendAdvice = controller.useCallFriend(friendName.toStdString());

    if (!friendAdvice.empty()) {
        ui->btn_CallFriend->setEnabled(false);
        ui->btn_CallFriend->setStyleSheet("QPushButton { color: gray; background-color: rgba(100, 100, 100, 0.5); }");

        // Thay đổi thông báo tại đây: Bỏ phần nhắc nhở 30 giây suy nghĩ đi
        QMessageBox::information(this, "Gọi bạn trợ giúp",
                                 QString::fromStdString(friendAdvice) + "\n\nKết nối cuộc gọi thành công!");
    }
}

void MainWindow::on_btn_PlayAgain_clicked() {}
void MainWindow::showResultScreen(bool isWin) { Q_UNUSED(isWin); }
void MainWindow::on_btn_Start_clicked() {}