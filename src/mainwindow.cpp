#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QFontDatabase>
#include <QMessageBox>

// MỚI: Biến đếm xem người chơi đang ở câu số mấy (Bắt đầu từ câu 1)
int currentQuestionIndex = 1;

// MỚI: Mảng lưu trữ mức tiền thưởng của 15 câu (Bạn có thể tự sửa lại số tiền)
QString prizeMoney[15] = {"200", "400", "600", "1.000", "2.000",
                          "3.000", "6.000", "10.000", "14.000", "22.000",
                          "30.000", "40.000", "60.000", "80.000", "150.000"};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ================= MỚI: NẠP FONT PIXEL =================
    // Nhớ đổi tên "pixel_font.ttf" thành tên file thực tế của bạn
    int fontId = QFontDatabase::addApplicationFont("data/pixel_font.ttf");

    if (fontId != -1) { // Nếu load font thành công
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont customFont(fontFamily);
        customFont.setPointSize(17); // Chỉnh lại size chữ cho vừa mắt

        // Áp dụng font này cho các khung chữ
        ui->lbl_Question->setFont(customFont);
        ui->btn_AnswerA->setFont(customFont);
        ui->btn_AnswerB->setFont(customFont);
        ui->btn_AnswerC->setFont(customFont);
        ui->btn_AnswerD->setFont(customFont);
    }
    // ========================================================
    //=============Gia Tien====================================
       if (fontId != -1) { // Nếu load font thành công
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont customFont(fontFamily);
        customFont.setPointSize(20); // Chỉnh lại size chữ cho vừa mắt

        // Áp dụng font này cho các khung chữ
        ui->lbl_Question->setFont(customFont);
        ui->btn_AnswerA->setFont(customFont);
        ui->btn_AnswerB->setFont(customFont);
        ui->btn_AnswerC->setFont(customFont);
        ui->btn_AnswerD->setFont(customFont);

        // MỚI: Áp dụng font Pixel cho bảng tiền luôn cho "tông xuyệt tông"
        ui->lbl_Money->setFont(customFont);
    }
    //========================================================
    // Kích hoạt GIF chú mèo
    QMovie *movie = new QMovie("images/cat_hoi.gif");
    ui->cat_hoi->setMovie(movie);
    movie->start();

    // Gọi lệnh load file câu hỏi
    controller.loadEasyQuestions("data/questions_easy.txt");
    controller.loadHardQuestions("data/questions_hard.txt");

    // MỚI: Ẩn 3 nút quyền trợ giúp khi game mới bắt đầu (Chưa qua câu 5)
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

// Hàm "thay phông bạt": Dán nội dung câu hỏi mới lên các khung lục giác
void MainWindow::updateUI() {
    Question currentQ = controller.getCurrentQuestion(currentQuestionIndex);

    ui->lbl_Question->setText(QString::fromStdString(currentQ.text));

    ui->btn_AnswerA->setText(QString::fromStdString("A. " + currentQ.options[0]));
    ui->btn_AnswerB->setText(QString::fromStdString("B. " + currentQ.options[1]));
    ui->btn_AnswerC->setText(QString::fromStdString("C. " + currentQ.options[2]));
    ui->btn_AnswerD->setText(QString::fromStdString("D. " + currentQ.options[3]));
    // MỚI: Trả lại giao diện trong suốt cho 4 nút (Xóa màu xanh của câu trước)
    QString defaultStyle = "QPushButton { background-color: transparent; border: none; color: white; text-align: left; padding-left: 20px; }"
                           "QPushButton:hover { color: #FFD700; background-color: rgba(255, 255, 255, 0.1); border-radius: 20px; }";

    ui->btn_AnswerA->setStyleSheet(defaultStyle);
    ui->btn_AnswerB->setStyleSheet(defaultStyle);
    ui->btn_AnswerC->setStyleSheet(defaultStyle);
    ui->btn_AnswerD->setStyleSheet(defaultStyle);
    // MỚI: Mở khóa các nút (Phòng trường hợp ván trước bị thua và khóa nút)
    ui->btn_AnswerA->setEnabled(true);
    ui->btn_AnswerB->setEnabled(true);
    ui->btn_AnswerC->setEnabled(true);
    ui->btn_AnswerD->setEnabled(true);
    /// ================= MỚI: CHỈ HIỆN TIỀN ĐÃ TÍCH LŨY =================
    // Logic: Ở câu 1, tiền tích lũy = 0. Qua câu 2, tiền tích lũy = mốc tiền câu 1.
    QString accumulatedMoney = "0";

    if (currentQuestionIndex > 1) {
        // Lấy số tiền của câu liền trước đó (index - 2 vì mảng bắt đầu từ 0)
        accumulatedMoney = prizeMoney[currentQuestionIndex - 2];
    }

    // SỬA DÒNG NÀY: Ghép chữ "Câu ", số câu hiện tại, và số tiền lại với nhau
    ui->lbl_Money->setText("Câu " + QString::number(currentQuestionIndex) + ": " + accumulatedMoney);
    // ==================================================================
}

// =====================================================================
// TRÁM CÁC HÀM SỰ KIỆN TRỐNG ĐỂ TRÁNH LỖI "UNDEFINED REFERENCE"
// (Sau này bạn sẽ viết logic xử lý click nút vào bên trong các hàm này)
// =====================================================================

void MainWindow::showLoginScreen() {}
void MainWindow::on_btn_AnswerA_clicked() {
    handleAnswer(0);
}

void MainWindow::on_btn_AnswerB_clicked() {
    handleAnswer(1);
}

void MainWindow::on_btn_AnswerC_clicked() {
    handleAnswer(2);
}

void MainWindow::on_btn_AnswerD_clicked() {
    handleAnswer(3);
}
void MainWindow::handleAnswer(int choiceIndex) {
    Question currentQ = controller.getCurrentQuestion(currentQuestionIndex);
    char choiceChar = '0' + choiceIndex;

    // TRƯỜNG HỢP 1: NGƯỜI CHƠI TRẢ LỜI ĐÚNG
    if (choiceChar == currentQ.correctAnswer) {

        if (currentQuestionIndex == 15) {
            // ================= MỚI: XỬ LÝ PHÁ ĐẢO CÂU 15 =================
            QMessageBox::information(this, "CHIẾN THẮNG VĨ ĐẠI",
                                     "CHÚC MỪNG! Bạn đã xuất sắc vượt qua toàn bộ 15 câu hỏi.\nBạn chính thức trở thành TRIỆU MEOWWWWWWWW!!!!!");

            // Tự động Reset lại từ đầu sau khi nhận giải
            currentQuestionIndex = 1;
            controller.startNewGame();
            ui->btn_5050->setVisible(false);
            ui->btn_Swap->setVisible(false);
            ui->btn_CallFriend->setVisible(false);
            updateUI();
            // ==============================================================

        } else if (currentQuestionIndex == 5) {
            // Đã qua 5 câu -> Hiện thông báo đặc biệt
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Mốc Quan Trọng",
                                          "Chúc mừng! Bạn đã vượt qua 5 câu đầu tiên và chắc chắn nhận được 2.000 cá.\nBạn có muốn đi tiếp để chinh phục các mốc cao hơn không?",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                // Chọn ĐI TIẾP: Mở khóa các quyền trợ giúp
                ui->btn_5050->setVisible(true);
                ui->btn_Swap->setVisible(true);
                ui->btn_CallFriend->setVisible(true);

                // Chuyển sang câu số 6
                currentQuestionIndex++;

                // GỌI HÀM CẬP NHẬT GIAO DIỆN CÂU MỚI TẠI ĐÂY LÚC NHÓM RÁP CODE
                QMessageBox::information(this, "Tiếp tục", "Các quyền trợ giúp đã được mở khóa!");
                updateUI();
            } else {
                // Chọn DỪNG LẠI
                QMessageBox::information(this, "Kết thúc", "Bạn đã quyết định dừng cuộc chơi và mang về 2.000.000 VNĐ!");
            }
        } else {
            // Trả lời đúng các câu bình thường (Không phải mốc số 5)
            QMessageBox::information(this, "Kết quả", "CHÍNH XÁC! Bạn nhận được " + prizeMoney[currentQuestionIndex - 1] + " VNĐ.");
            currentQuestionIndex++;
            updateUI();
        }

        // TRƯỜNG HỢP 2: NGƯỜI CHƠI TRẢ LỜI SAI
    } else {
        // 1. SỬA Ở ĐÂY: Đổi style để chỉ tô màu chữ (color: #00FF00) thành xanh lá cây nổi bật, nền vẫn trong suốt
        QString correctStyle = "background-color: transparent; border: none; color: #00FF00; font-size: 20px; font-weight: bold; text-align: left; padding-left: 20px;";

        if (currentQ.correctAnswer == '0') ui->btn_AnswerA->setStyleSheet(correctStyle);
        else if (currentQ.correctAnswer == '1') ui->btn_AnswerB->setStyleSheet(correctStyle);
        else if (currentQ.correctAnswer == '2') ui->btn_AnswerC->setStyleSheet(correctStyle);
        else if (currentQ.correctAnswer == '3') ui->btn_AnswerD->setStyleSheet(correctStyle);

        // 2. MỚI: Khóa (Disable) cả 4 nút lại để người chơi không thể click lung tung nữa -> Chính thức kết thúc trò chơi
        ui->btn_AnswerA->setEnabled(false);
        ui->btn_AnswerB->setEnabled(false);
        ui->btn_AnswerC->setEnabled(false);
        ui->btn_AnswerD->setEnabled(false);

        // 3. Hiện thông báo kết thúc
        if (currentQuestionIndex <= 5) {
            QMessageBox::critical(this, "Sai rồi", "Rất tiếc, bạn đã trả lời sai ở 5 câu đầu.\nBạn phải ra về với mức thưởng 0 VNĐ.");
        } else {
            QMessageBox::critical(this, "Sai rồi", "Rất tiếc! Bạn đã trả lời sai. Trò chơi kết thúc.\nBạn ra về với 2.000.000 VNĐ.");
        }

        // ================= MỚI: RESET LẠI TOÀN BỘ VÁN GAME =================
        currentQuestionIndex = 1;          // 1. Đưa mốc câu hỏi về 1 (Tiền trên UI sẽ tự động tính lại = 0)

        controller.startNewGame();         // 2. Trộn và bốc lại một bộ 15 câu hỏi hoàn toàn mới

        // 3. Giấu 3 nút quyền trợ giúp đi cho ván mới
        ui->btn_5050->setVisible(false);
        ui->btn_Swap->setVisible(false);
        ui->btn_CallFriend->setVisible(false);

        updateUI();                        // 4. Load câu hỏi 1 lên màn hình (Lệnh này cũng tự động mở khóa các nút luôn)
        // ===================================================================
    }
}



void MainWindow::on_btn_5050_clicked() {}
void MainWindow::on_btn_Swap_clicked() {}
void MainWindow::on_btn_CallFriend_clicked() {}

void MainWindow::on_btn_PlayAgain_clicked() {}
void MainWindow::showResultScreen(bool isWin) {}
void MainWindow::on_btn_Start_clicked() {
    // Tạm thời để trống để vượt qua vòng biên dịch
}
