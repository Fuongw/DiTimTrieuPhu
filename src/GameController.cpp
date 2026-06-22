#include <QProcess>
#include <QStringList>
#include "GameController.h"
#include <fstream>
#include <iostream>
#include <algorithm> // Hỗ trợ thuật toán trộn
#include <random>    // Hỗ trợ random số

using namespace std;

// 1. Khởi tạo GameController
GameController::GameController() {
    // Reset trạng thái khi mới tạo
    currentIndex = 0;
    currentMoney = 0;
    has5050 = true;
    hasSwapQuestion = true;
    hasCallFriend = true;
}

// 2A. Hàm đọc file câu hỏi Dễ
void GameController::loadEasyQuestions(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Lỗi: Không thể mở file " << filename << endl;
        return;
    }
    string text, ansA, ansB, ansC, ansD;
    char correctAns;
    while (getline(file, text)) {
        getline(file, ansA); getline(file, ansB); getline(file, ansC); getline(file, ansD);
        file >> correctAns; file.ignore();
        Question q; q.text = text; q.options[0] = ansA; q.options[1] = ansB; q.options[2] = ansC; q.options[3] = ansD; q.correctAnswer = correctAns;
        easyBank.push_back(q);
    }
    availableEasy = easyBank; // MỚI: Lần đầu load file thì nạp đầy luôn kho tạm
    file.close();
}

// 2B. Hàm đọc file câu hỏi Khó
void GameController::loadHardQuestions(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Lỗi: Không thể mở file " << filename << endl;
        return;
    }
    string text, ansA, ansB, ansC, ansD;
    char correctAns;
    while (getline(file, text)) {
        getline(file, ansA); getline(file, ansB); getline(file, ansC); getline(file, ansD);
        file >> correctAns; file.ignore();
        Question q; q.text = text; q.options[0] = ansA; q.options[1] = ansB; q.options[2] = ansC; q.options[3] = ansD; q.correctAnswer = correctAns;
        hardBank.push_back(q);
    }
    availableHard = hardBank; // MỚI: Nạp đầy kho tạm khó
    file.close();
}

// 3. Bắt đầu ván mới: Trộn và bốc 15 câu (5 Dễ + 10 Khó)
void GameController::startNewGame() {
    current15Qs.clear(); // Xóa mảng ván cũ

    // Reset quyền trợ giúp
    has5050 = true;
    hasSwapQuestion = true;
    hasCallFriend = true;

    // 1. Gọi Shell Script thực hiện trộn và nặn ra 15 câu mới
    QProcess process;
    process.start("./logic_random_game.sh");
    process.waitForFinished();

    // 2. C++ chỉ việc đọc file kết quả do Shell vừa tạo ra
    std::ifstream file("data/current_15Qs.txt");
    if (!file.is_open()) {
        std::cout << "Lỗi: Shell Script chưa tạo được file 15 câu hỏi!" << std::endl;
        return;
    }

    std::string text, ansA, ansB, ansC, ansD;
    char correctAns;
    while (getline(file, text)) {
        getline(file, ansA); getline(file, ansB); getline(file, ansC); getline(file, ansD);
        file >> correctAns; file.ignore(); // Bỏ qua ký tự xuống dòng

        Question q;
        q.text = text; q.options[0] = ansA; q.options[1] = ansB; q.options[2] = ansC; q.options[3] = ansD;
        q.correctAnswer = correctAns;

        current15Qs.push_back(q);
    }
    file.close();
}
// 4. Lấy câu hỏi hiện tại để dán lên Giao diện
Question GameController::getCurrentQuestion(int index) {
    if (!current15Qs.empty() && (index - 1) < current15Qs.size()) {
        return current15Qs[index - 1];
    }

    // Trả về câu hỏi mặc định nếu lỗi
    Question emptyQ;
    emptyQ.text = "Lỗi: Đang chờ tải câu hỏi...";
    emptyQ.options[0] = "..."; emptyQ.options[1] = "..."; emptyQ.options[2] = "..."; emptyQ.options[3] = "...";
    return emptyQ;
}

// ====================================================================================
// KHU VỰC CÁC HÀM TRỐNG ĐỂ CHỐNG LỖI UNDEFINED REFERENCE (Sẽ viết logic chi tiết sau)
// ====================================================================================

void GameController::setPlayerName(string name) { playerName = name; }
string GameController::getPlayerName() { return playerName; }

bool GameController::checkAnswer(int playerChoiceIndex) {
    // Lấy câu hỏi hiện tại ra để đối chiếu
    Question currentQ = getCurrentQuestion(currentIndex + 1);

    // Chuyển index lựa chọn (0, 1, 2, 3) thành ký tự ('0', '1', '2', '3') để so với correctAnswer
    char choiceChar = '0' + playerChoiceIndex;

    // Nếu trả lời đúng
    if (choiceChar == currentQ.correctAnswer) {
        currentIndex++; // Tăng cấp câu hỏi lên trong bộ đếm của controller
        return true;
    }

    return false;
} // Tạm thời trả về false

long GameController::getCurrentMoney() { return currentMoney; }
long GameController::getPrizeMoney() { return 0; }
bool GameController::isGameOver() { return false; }
bool GameController::isGameWon() { return false; }

// Các hàm quyền trợ giúp
vector<string> GameController::use5050() {
    vector<string> hiddenOptions;
    if (!has5050) return hiddenOptions;
    has5050 = false;

    Question currentQ = getCurrentQuestion(currentIndex + 1);
    QString correctAns = QString(currentQ.correctAnswer);

    // Xóa thuật toán trộn C++ cũ đi, thay bằng lệnh nhờ vả Shell Script
    QProcess process;
    process.start("./logic_5050.sh", QStringList() << correctAns);
    process.waitForFinished();

    QString output = process.readAllStandardOutput().trimmed();

    QStringList lines = output.split('\n');
    for(QString line : lines) {
        if(!line.isEmpty()) {
            hiddenOptions.push_back(line.toStdString());
        }
    }

    return hiddenOptions;
}

void GameController::useSwapQuestion(int index) {
    if (!hasSwapQuestion) return;
    hasSwapQuestion = false; // Đánh dấu đã dùng

    // Xác định đang ở mốc Dễ (câu 1-5) hay Khó (câu 6-15) để báo cho Shell Script
    QString level = (index <= 5) ? "EASY" : "HARD";

    // ================= MỚI: GỌI SHELL SCRIPT XỬ LÝ ĐỔI CÂU HỎI =================
    QProcess process;
    process.start("./logic_swap.sh", QStringList() << level);
    process.waitForFinished();

    // Đọc trọn vẹn 6 dòng do Shell Script nhả ra
    QString output = process.readAllStandardOutput().trimmed();
    QStringList lines = output.split('\n');

    // Nếu lấy đủ 6 dòng, tiến hành đóng gói thành một Câu hỏi mới
    if (lines.size() >= 6) {
        Question newQ;
        newQ.text = lines[0].toStdString();
        newQ.options[0] = lines[1].toStdString();
        newQ.options[1] = lines[2].toStdString();
        newQ.options[2] = lines[3].toStdString();
        newQ.options[3] = lines[4].toStdString();

        // Cắt bỏ các khoảng trắng dư thừa và lấy ký tự đáp án đúng (A/B/C/D)
        newQ.correctAnswer = lines[5].trimmed().at(0).toLatin1();

        // Xóa câu hỏi cũ trong mảng current15Qs và chèn câu hỏi mới này vào
        if (!current15Qs.empty() && (index - 1) < current15Qs.size()) {
            current15Qs[index - 1] = newQ;
        }
    }
    // ===========================================================================
}

string GameController::useCallFriend(string friendName) {
    if (!hasCallFriend) return "";
    hasCallFriend = false;

    // Nếu người chơi nhập tên bạn, trả về tên đó
    if (!friendName.empty()) {
        return "Gọi " + friendName + " để hỗ trợ";
    }

}

bool GameController::canUse5050() { return has5050; }
bool GameController::canUseSwapQuestion() { return hasSwapQuestion; }
bool GameController::canUseCallFriend() { return hasCallFriend; }

bool GameController::isAnswerHidden(int answerIndex) {
    if (answerIndex >= 0 && answerIndex < hiddenAnswers.size()) {
        return hiddenAnswers[answerIndex];
    }
    return false;
}
void GameController::setCurrentIndex(int index) {
    if (index >= 0 && index < 15) {
        currentIndex = index;
    }
}
