#!/bin/bash

# Xóa màn hình Terminal cho gọn gàng
clear

echo "=========================================================="
echo "    HỆ THỐNG KHỞI ĐỘNG GAME: ĐI TÌM TRIỆU PHÚ (C04)       "
echo "=========================================================="
echo ""

# 1. Dọn dẹp các file build cũ (nếu có) để tránh xung đột
echo "[1/4] Đang dọn dẹp bộ nhớ đệm..."
make clean > /dev/null 2>&1

# 2. Chạy qmake để đọc file .pro và tạo ra file Makefile
echo "[2/4] Đang thiết lập cấu trúc biên dịch (qmake)..."
qmake DiTimTrieuPhu_UI.pro

# 3. Chạy make để dịch toàn bộ code C++ thành file thực thi
echo "[3/4] Đang tiến hành biên dịch mã nguồn (make)..."
make

# Kiểm tra xem quá trình dịch code có thành công không
if [ $? -eq 0 ]; then
    echo "[4/4] Biên dịch hoàn tất! Đang khởi động Giao diện Đồ họa..."
    echo "Đóng cửa sổ game để kết thúc phiên làm việc."
    echo ""
    
    # 4. Kích hoạt file chạy của game
    ./DiTimTrieuPhu_UI
    
    echo ""
    echo "Cảm ơn bạn đã chơi! Hẹn gặp lại."
else
    echo ""
    echo " LỖI: Quá trình biên dịch thất bại. Vui lòng kiểm tra lại code C++!"
    exit 1
fi