#!/bin/bash

chmod +x play.sh manage_questions.sh backup_system.sh

while true; do
    clear
    echo "=========================================================="
    echo "     BỘ ĐIỀU HÀNH TRUNG TÂM: GAME ĐI TÌM TRIỆU PHÚ        "
    echo "=========================================================="
    echo " CHỌN MỘT CHỨC NĂNG ĐỂ VẬN HÀNH HỆ THỐNG:"
    echo "----------------------------------------------------------"
    echo " 1. 🎮 ĐĂNG NHẬP & VÀO CHƠI GAME"
    echo " 2. 📝 QUẢN LÝ NGÂN HÀNG CÂU HỎI"
    echo " 3. 💾 SAO LƯU DỮ LIỆU (Backup)"
    echo " 4. 🏆 XEM BẢNG VÀNG TOP 10"
    echo " 5. 🔄 RESET BẢNG VÀNG"
    echo " 6. 🧹 DỌN DẸP RÁC BIÊN DỊCH (Clean)"  # <--- Bổ sung dòng này
    echo " 7. ❌ THOÁT CHƯƠNG TRÌNH"             # <--- Đổi thành số 7
    echo "=========================================================="
    echo -n "Nhập số lệnh bạn muốn thực thi [1-7]: "
    read MAINCHOICE

    case $MAINCHOICE in
        1)
            ./play.sh
            ;;
        2)
            ./manage_questions.sh
            ;;
        3)
            ./backup_system.sh
            ;;
        4)
            clear
            echo "=========================================================="
            echo "               BẢNG VÀNG TOP 10 TRIỆU PHÚ                 "
            echo "=========================================================="
            if [ -f "data/leaderboard.txt" ]; then
                # Dùng awk để tạo cột tạm không có dấu chấm, sort theo cột tạm đó, rồi in ra
                awk -F',' '{
                    tien_goc=$2; 
                    tien_so=$2; 
                    gsub(/\./, "", tien_so); 
                    print tien_so "|" $1 "|" tien_goc 
                }' data/leaderboard.txt | sort -t'|' -k1 -nr | head -n 10 | awk -F'|' '{printf "👤 %-20s | 💰 %s VNĐ\n", $2, $3}'
            else
                echo "Chưa có dữ liệu người chơi nào."
            fi
            echo "=========================================================="
            echo -n "👉 Nhấn Enter để quay lại Menu..."
            read
            ;;
        5)
            clear
            echo "CẢNH BÁO: Bạn có chắc chắn muốn xóa sạch Bảng Xếp Hạng không?"
            echo -n "Gõ 'y' để Xóa, hoặc phím bất kỳ để Hủy: "
            read CONFIRM
            if [ "$CONFIRM" == "y" ] || [ "$CONFIRM" == "Y" ]; then
                rm -f data/leaderboard.txt
                echo "✅ Đã xóa toàn bộ dữ liệu Bảng Vàng thành công!"
            else
                echo "❌ Đã hủy thao tác xóa."
            fi
            echo -n "👉 Nhấn Enter để quay lại Menu..."
            read
            ;;
        6)
            clear
            echo "Cảm ơn Thầy và các bạn đã theo dõi!"
            exit 0
            ;;
        7)
            clear
            echo "Cảm ơn Thầy/Cô đã theo dõi phần thuyết trình của nhóm C04!"
            exit 0
            ;;
        *)
            echo "Lệnh không hợp lệ! Vui lòng nhấn Enter để chọn lại..."
            read
            ;;
    esac
done
