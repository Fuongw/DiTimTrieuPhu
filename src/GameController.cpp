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
    current15Qs.clear(); // Xóa dữ liệu ván cũ

    has5050 = true;
    hasSwapQuestion = true;
    hasCallFriend = true;

    // ================= LOGIC CHỐNG LẶP CÂU HỎI =================
    // 1. Nếu kho tạm hết (hoặc không đủ rút), thì nạp lại đầy từ kho gốc
    if (availableEasy.size() < 5) availableEasy = easyBank;
    if (availableHard.size() < 10) availableHard = hardBank;

    // 2. Chỉ trộn những câu CÒN LẠI trong kho tạm
    random_device rd;
    mt19937 g(rd());
    shuffle(availableEasy.begin(), availableEasy.end(), g);
    shuffle(availableHard.begin(), availableHard.end(), g);

    // 3. Rút 5 câu dễ: Lấy câu cuối cùng ra, tống vào mảng chơi, rồi xóa khỏi kho tạm
    for(int i = 0; i < 5; i++) {
        current15Qs.push_back(availableEasy.back());
        availableEasy.pop_back(); // Lệnh này giúp câu hỏi vĩnh viễn biến mất khỏi kho tạm
    }

    // 4. Rút 10 câu khó tương tự
    for(int i = 0; i < 10; i++) {
        current15Qs.push_back(availableHard.back());
        availableHard.pop_back();
    }
    // ==========================================================
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

bool GameController::checkAnswer(int playerChoiceIndex) { return false; } // Tạm thời trả về false

long GameController::getCurrentMoney() { return currentMoney; }
long GameController::getPrizeMoney() { return 0; }
bool GameController::isGameOver() { return false; }
bool GameController::isGameWon() { return false; }

// Các hàm quyền trợ giúp
vector<string> GameController::use5050() { return vector<string>(); }
void GameController::useSwapQuestion() {}
string GameController::useCallFriend() { return ""; }

bool GameController::canUse5050() { return has5050; }
bool GameController::canUseSwapQuestion() { return hasSwapQuestion; }
bool GameController::canUseCallFriend() { return hasCallFriend; }
