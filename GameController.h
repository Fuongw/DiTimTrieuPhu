#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <vector>
#include <string>
#include "Question.h"

using namespace std;

class GameController {
private:
    string playerName;             // Tên người đang chơi

    // Kho chứa câu hỏi
    vector<Question> easyBank;     // Kho chứa toàn bộ câu dễ
    vector<Question> hardBank;     // Kho chứa toàn bộ câu khó
    vector<Question> current15Qs;  // Mảng 15 câu dùng riêng cho ván hiện tại (Đã gỡ bỏ currentSet bị trùng)

    // MỚI: KHO TẠM (Để rút dần, không cho lặp lại)
    vector<Question> availableEasy;
    vector<Question> availableHard;

    int currentIndex;              // Đang ở câu hỏi số mấy (0 đến 14)
    long currentMoney;             // Dùng kiểu long để chứa được số tiền lớn

    // Thang tiền thưởng 15 mốc
    long moneyLadder[15] = {1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 8000000, 10000000, 14000000, 22000000, 30000000, 60000000, 120000000, 250000000, 500000000};

    // Các biến trạng thái quản lý quyền trợ giúp (Chỉ được xài 1 lần)
    bool has5050;
    bool hasSwapQuestion;
    bool hasCallFriend;

    // Biến để lưu các đáp án bị ẩn (cho 50/50) - true = bị ẩn, false = vẫn hiển thị
    vector<bool> hiddenAnswers;

public:
    void setCurrentIndex(int index);
    GameController();

    // 1. Khởi tạo dữ liệu (Đã sửa lại thành 2 hàm cho khớp cấu trúc Dễ/Khó)
    void loadEasyQuestions(string filename);
    void loadHardQuestions(string filename);

    void startNewGame();           // Trộn câu Dễ và Khó vào current15Qs

    void setPlayerName(string name);
    string getPlayerName();

    // 2. Tương tác với lượt chơi
    Question getCurrentQuestion(int index);
    bool checkAnswer(int playerChoiceIndex);

    long getCurrentMoney();
    long getPrizeMoney();
    bool isGameOver();
    bool isGameWon();

    // 3. Xử lý quyền trợ giúp
    vector<int> use5050();      // Trả về danh sách index (0,1,2,3) của các đáp án bị ẩn
    void useSwapQuestion();
    string useCallFriend(string friendName = "");  // Nhận tên người gọi, nếu không nhập mặc định rỗng

    // Kiểm tra trạng thái quyền trợ giúp
    bool canUse5050();
    bool canUseSwapQuestion();
    bool canUseCallFriend();
    
    // Kiểm tra xem đáp án có bị ẩn không (cho 50/50)
    bool isAnswerHidden(int answerIndex);
};

#endif
