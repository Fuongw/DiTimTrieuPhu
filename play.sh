#!/bin/bash

# Xóa màn hình cho đẹp
clear

echo "=========================================================="
echo "          HỆ THỐNG ĐĂNG NHẬP: AI LÀ TRIỆU PHÚ             "
echo "=========================================================="
echo -n "Nhập tên người chơi của bạn (Viết liền không dấu): "
read USERNAME

# Xử lý nếu người chơi bấm Enter mà không nhập gì
if [ -z "$USERNAME" ]; then
    USERNAME="Nguoi_Choi_An_Danh"
fi

echo "Xin chào $USERNAME! Đang khởi chạy hệ thống đồ họa..."
# ================= MỚI: TỰ ĐỘNG BIÊN DỊCH CODE MỚI NHẤT =================
qmake DiTimTrieuPhu_UI.pro > /dev/null 2>&1
make > /dev/null 2>&1
# =======================================================================
echo "Vui lòng chơi trên cửa sổ Game. Bảng xếp hạng sẽ hiện ra sau khi bạn tắt Game."

# 1. Gọi phần mềm C++ chạy lên và TRUYỀN cái tên $USERNAME vào làm đối số
# (Lưu ý: Bạn nhớ sửa ./DiTimTrieuPhu_UI thành đúng đường dẫn file chạy của bạn nhé)
./DiTimTrieuPhu_UI "$USERNAME"

# ----- LÚC NÀY GAME C++ SẼ BẬT LÊN. SHELL SCRIPT SẼ ĐỨNG CHỜ ĐẾN KHI GAME TẮT -----

# ... (Phần trên của play.sh giữ nguyên)
clear
echo "=========================================================="
echo "               BẢNG VÀNG TOP 10 TRIỆU PHÚ                 "
echo "=========================================================="

if [ -f "data/leaderboard.txt" ]; then
    # ================= MÃ SẮP XẾP MỚI ĐÃ FIX LỖI DẤU CHẤM =================
    awk -F',' '{
        tien_goc=$2; 
        tien_so=$2; 
        gsub(/\./, "", tien_so); 
        print tien_so "|" $1 "|" tien_goc 
    }' data/leaderboard.txt | sort -t'|' -k1 -nr | head -n 10 | awk -F'|' '{printf "👤 %-20s | 💰 %s VNĐ\n", $2, $3}'
    # ======================================================================
else
    echo "Chưa có dữ liệu người chơi nào."
fi
echo "=========================================================="

echo ""
echo -n "👉 Nhấn Enter để quay lại Menu Trung Tâm..."
read
