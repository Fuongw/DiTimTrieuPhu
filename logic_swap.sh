#!/bin/bash

# Nhận mức độ khó từ C++ truyền vào ($1)
LEVEL=$1
FILE="data/questions_easy.txt"

# Nếu C++ truyền vào chữ HARD, thì đổi sang đọc file Khó
if [ "$LEVEL" == "HARD" ]; then
    FILE="data/questions_hard.txt"
fi

# Đếm tổng số dòng trong file, chia 6 để ra tổng số lượng câu hỏi
TOTAL_LINES=$(wc -l < "$FILE")
TOTAL_QUESTIONS=$((TOTAL_LINES / 6))

# Random một con số từ 0 đến (Tổng số câu - 1)
RANDOM_Q=$((RANDOM % TOTAL_QUESTIONS))

# Tính toán xem câu hỏi đó bắt đầu từ dòng số mấy
START_LINE=$((RANDOM_Q * 6 + 1))

# Cắt đúng 6 dòng của câu hỏi đó và trả về cho C++
tail -n +$START_LINE "$FILE" | head -n 6
