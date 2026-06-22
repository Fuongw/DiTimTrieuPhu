#!/bin/bash

clear
while true; do
    echo "=========================================================="
    echo "         HỆ THỐNG QUẢN LÝ NGÂN HÀNG CÂU HỎI               "
    echo "=========================================================="
    echo "1. Thống kê số lượng câu hỏi hiện có"
    echo "2. Tìm kiếm câu hỏi theo từ khóa (Dùng lệnh Grep)"
    echo "3. Quay lại Menu chính"
    echo "=========================================================="
    echo -n "Nhập lựa chọn của bạn [1-3]: "
    read QCHOICE

    case $QCHOICE in
        1)
            clear
            echo "--- THỐNG KÊ SỐ LƯỢNG CÂU HỎI ---"
            if [ -f "data/questions_easy.txt" ] && [ -f "data/questions_hard.txt" ]; then
                # Cấu trúc file là 6 dòng/câu hỏi. Lấy tổng số dòng chia 6 sẽ ra số câu.
                LINE_EASY=$(wc -l < data/questions_easy.txt)
                LINE_HARD=$(wc -l < data/questions_hard.txt)
                
                COUNT_EASY=$((LINE_EASY / 6))
                COUNT_HARD=$((LINE_HARD / 6))
                
                echo "Số câu hỏi DỄ đang có: $COUNT_EASY câu ($LINE_EASY dòng dữ liệu)."
                echo "Số câu hỏi KHÓ đang có: $COUNT_HARD câu ($LINE_HARD dòng dữ liệu)."
                echo "Tổng cộng kho đề có: $((COUNT_EASY + COUNT_HARD)) câu hỏi."
            else
                echo "Lỗi: Không tìm thấy các file dữ liệu câu hỏi trong thư mục data/!"
            fi
            echo ""
            ;;
        2)
            echo -n "Nhập từ khóa cần tìm trong bộ đề: "
            read KEYWORD
            clear
            echo "--- KẾT QUẢ TÌM KIẾM TỪ KHÓA '$KEYWORD' ---"
            echo "🔎 Tìm trong kho câu hỏi DỄ:"
            grep -n "$KEYWORD" data/questions_easy.txt
            echo "----------------------------------------------------"
            echo "🔎 Tìm trong kho câu hỏi KHÓ:"
            grep -n "$KEYWORD" data/questions_hard.txt
            echo ""
            ;;
        3)
            break
            ;;
        *)
            echo "Lựa chọn không hợp lệ!"
            ;;
    esac
done
