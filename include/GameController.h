#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <vector>
#include <string>
#include "Question.h"

using namespace std;

class GameController {
private:
    string playerName;             // Tên người đang chơi
    vector<Question> allQuestions; // Chứa toàn bộ ngân hàng câu hỏi
    vector<Question> currentSet;   // Chỉ chứa đúng 15 câu đã được random cho lượt chơi hiện tại
    
    int currentIndex;              // Đang ở câu hỏi số mấy (0 đến 14)
    long currentMoney;             // Dùng kiểu long để chứa được số tiền lớn
    
    // Thang tiền thưởng 15 mốc
    long moneyLadder[15] = {1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 8000000, 10000000, 14000000, 22000000, 30000000, 60000000, 120000000, 250000000, 500000000}; 

    // Các biến trạng thái quản lý quyền trợ giúp (Chỉ được xài 1 lần)
    bool has5050;
    bool hasSwapQuestion;
    bool hasCallFriend;            // MỚI: Biến quản lý quyền gọi người thân

public:
    GameController();

    // 1. Khởi tạo dữ liệu
    void loadQuestionsFromFile(string filename); 
    void startNewGame();           // Trộn allQuestions và bốc 15 câu đưa vào currentSet
    
    void setPlayerName(string name);
    string getPlayerName();        // Trả về tên người chơi để in ra lúc kết thúc
    
    // 2. Tương tác với lượt chơi
    Question getCurrentQuestion();
    bool checkAnswer(int playerChoiceIndex); 
    
    long getCurrentMoney();        // Trả về kiểu long
    long getPrizeMoney();          // Trả về kiểu long
    bool isGameOver();
    bool isGameWon();              // Kiểm tra xem có qua hết 15 câu không

    // 3. Xử lý quyền trợ giúp
    vector<string> use5050(); 
    void useSwapQuestion(); 
    string useCallFriend();        // Hàm thực thi gọi người thân (Trả về câu thoại gợi ý đáp án)

    // Kiểm tra xem quyền trợ giúp còn không để hiển thị/ẩn nút bấm trên UI
    bool canUse5050();
    bool canUseSwapQuestion();
    bool canUseCallFriend();       // MỚI: Kiểm tra trạng thái nút gọi người thân
};

#endif
