DiTimTrieuPhu_UI/
├── data/                       
│   ├── questions_easy.txt      
│   ├── questions_hard.txt      
│   ├── leaderboard.txt         
│   ├── pool_easy.tmp           
│   └── pool_hard.tmp           
├── images/                     
├── include/                    
│   ├── Question.h              
│   ├── GameController.h        
│   └── mainwindow.h            
├── src/                        
│   ├── GameController.cpp      
│   ├── mainwindow.cpp          
│   └── main.cpp                
├── mainwindow.ui               
├── DiTimTrieuPhu_UI.pro        
├── menu.sh                     
├── play.sh                     
├── manage_questions.sh         
├── backup_system.sh            
├── clean_workspace.sh          
├── logic_random_game.sh        
├── logic_5050.sh               
├── logic_swap.sh               
└── .gitignore


## 1. Khu vực Dữ liệu (Database & Resources)
data/: Nơi lưu trữ toàn bộ cơ sở dữ liệu dạng văn bản của trò chơi.

questions_easy.txt / questions_hard.txt: Ngân hàng câu hỏi gốc chia theo độ khó.

leaderboard.txt: Bảng điểm vinh danh (lưu tên và số tiền).

*.tmp: Các file nhớ tạm do Shell Script tự sinh ra để quản lý việc "rút đề" mà không bị trùng lặp.

images/: Thư mục chứa các tài nguyên hình ảnh, biểu tượng, ảnh động (như chú mèo GIF) dùng để trang trí cho giao diện.

## 2. Khu vực Cấu trúc và Giao diện C++ (Frontend)
include/: Chứa các bản thiết kế (file Header .h). Đây là nơi định nghĩa biến, mảng và tên các hàm trước khi viết code thực tế.

src/: Chứa mã nguồn thực thi (file .cpp).

GameController.cpp: Lõi vận hành (Controller) làm nhiệm vụ gọi Shell Script xử lý tính toán.

mainwindow.cpp: Chịu trách nhiệm hiển thị màu sắc, âm thanh, thay đổi text và bắt sự kiện click chuột.

main.cpp: Điểm khởi chạy đầu tiên của phần mềm đồ họa.

mainwindow.ui: File giao diện trực quan. Khi mở bằng Qt Designer, bạn có thể kéo thả nút bấm mà không cần gõ code.

## 3. Khu vực Logic & Quản trị (Shell Script Backend)
menu.sh: Bảng điều khiển trung tâm lớn nhất, hiển thị menu điều hướng ra Terminal.

play.sh: Quản lý việc đăng nhập (nhập tên) và hiện Bảng Vàng Top 10 sau khi chơi xong.

manage_questions.sh: Dùng lệnh đếm (wc) và lọc (grep) để thống kê, tìm kiếm câu hỏi cho Admin.

backup_system.sh / clean_workspace.sh: Các công cụ quản trị hệ thống giúp nén file dự phòng sự cố và quét dọn rác biên dịch.

logic_*.sh: Khối "chất xám" của game. Nhận lệnh từ C++, dùng các thủ thuật dòng lệnh Linux (sed, shuf, awk, tail) để xáo trộn đề, tìm đáp án sai (50:50) và trích xuất câu hỏi đổi mới.

## 4. Khu vực Cấu hình Hệ thống
DiTimTrieuPhu_UI.pro: File cấu hình dự án của Qt, báo cho trình biên dịch biết cần gom những thư viện và file nào lại để build ra game.

.gitignore: File ẩn đóng vai trò "màng lọc", ngăn chặn các file rác hoặc file chạy tải lên kho lưu trữ GitHub chung của nhóm.
