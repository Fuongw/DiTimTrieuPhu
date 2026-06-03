#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <vector>
#include <string>
#include "Question.h"

using namespace std;

class GameController {
private:
    vector<Question> allQuestions; // Chứa toàn bộ ngân hàng câu hỏi (có thể vài chục câu)
    vector<Question> currentSet;   // Chỉ chứa đúng 10 câu đã được random cho lượt chơi hiện tại
    
    int currentIndex; // Đang ở câu hỏi số mấy (0 đến 9)
    int currentMoney;
    
    // Thang tiền thưởng 10 mốc (Ví dụ: 200k, 400k, 600k...)
    int moneyLadder[10] = {200, 400, 600, 1000, 2000, 3000, 6000, 10000, 14000, 22000}; 

    // Các biến trạng thái quản lý quyền trợ giúp (Chỉ được xài 1 lần)
    bool has5050;
    bool hasSwapQuestion;

public:
    GameController();

    // 1. Khởi tạo dữ liệu
    void loadQuestionsFromFile(string filename); 
    void startNewGame(); // Hàm này sẽ trộn (shuffle) allQuestions và bốc 10 câu đưa vào currentSet

    // 2. Tương tác với lượt chơi
    Question getCurrentQuestion();
    bool checkAnswer(int playerChoiceIndex); // Đổi thành int (0,1,2,3)
    int getCurrentMoney();
    int getPrizeMoney(); // MỚI: Lấy tiền chốt mang về khi kết thúc
    bool isGameOver();
    bool isGameWon();    // MỚI: Kiểm tra xem có qua hết 10 câu không

    // 3. Xử lý quyền trợ giúp
    // Khi gọi hàm này, ẩn đi 2 đáp án sai, và set has5050 = false
    vector<string> use5050(); 
    
    // Bốc 1 câu hỏi khác từ allQuestions (nhưng không nằm trong 10 câu hiện tại) để thay thế
    void useSwapQuestion(); 

    // Kiểm tra xem quyền trợ giúp còn không để hiển thị/ẩn nút bấm trên giao diện
    bool canUse5050();
    bool canUseSwapQuestion();
};

#endif
