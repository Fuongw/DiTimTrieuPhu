#!/bin/bash

# Nhận đáp án đúng từ C++ truyền vào (tham số $1)
CORRECT_ANS=$1

# Mảng chứa 4 đáp án
OPTIONS=("A" "B" "C" "D")
WRONG_OPTIONS=()

# Lọc ra 3 đáp án sai
for opt in "${OPTIONS[@]}"; do
    if [ "$opt" != "$CORRECT_ANS" ]; then
        WRONG_OPTIONS+=("$opt")
    fi
done

# Dùng lệnh printf in 3 đáp án sai ra, truyền qua lệnh shuf để trộn ngẫu nhiên, 
# sau đó dùng lệnh head để lấy đúng 2 cái đầu tiên và in ra màn hình.
printf "%s\n" "${WRONG_OPTIONS[@]}" | shuf | head -n 2
