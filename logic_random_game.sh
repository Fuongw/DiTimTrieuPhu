#!/bin/bash

# Các file kho gốc
EASY_BASE="data/questions_easy.txt"
HARD_BASE="data/questions_hard.txt"

# Các file kho tạm (dùng để lưu trạng thái "rút dần" qua nhiều ván)
EASY_POOL="data/pool_easy.tmp"
HARD_POOL="data/pool_hard.tmp"

# File kết quả xuất ra cho C++ đọc
OUTPUT="data/current_15Qs.txt"

# Xóa file output cũ của ván trước
rm -f "$OUTPUT"

# ====================================================================
# BƯỚC 1: XỬ LÝ 5 CÂU DỄ
# ====================================================================

# Kiểm tra xem file kho tạm Dễ có tồn tại và còn ĐỦ 5 câu (5 dòng) không?
if [ ! -f "$EASY_POOL" ] || [ $(wc -l < "$EASY_POOL") -lt 5 ]; then
    # Nếu hết đề (hoặc không đủ), thì nạp đầy lại từ file gốc.
    # Ép 6 dòng thành 1 dòng ngang, xáo trộn, rồi lưu vào file tạm.
    paste - - - - - - < "$EASY_BASE" | shuf > "$EASY_POOL"
fi

# Rút 5 câu đầu tiên từ kho tạm, bẻ nó lại thành 6 dòng/câu, và ném vào file Output
head -n 5 "$EASY_POOL" | tr '\t' '\n' >> "$OUTPUT"

# Lệnh XÓA: Dùng 'sed' xóa vĩnh viễn 5 dòng vừa rút ra khỏi file tạm (Giống pop_back)
sed -i '1,5d' "$EASY_POOL"


# ====================================================================
# BƯỚC 2: XỬ LÝ 10 CÂU KHÓ
# ====================================================================

# Kiểm tra xem file kho tạm Khó có còn ĐỦ 10 câu không?
if [ ! -f "$HARD_POOL" ] || [ $(wc -l < "$HARD_POOL") -lt 10 ]; then
    # Nếu cạn kiệt, nạp lại và trộn mới
    paste - - - - - - < "$HARD_BASE" | shuf > "$HARD_POOL"
fi

# Rút 10 câu đầu tiên đưa vào Output
head -n 10 "$HARD_POOL" | tr '\t' '\n' >> "$OUTPUT"

# Xóa 10 dòng đó khỏi kho tạm
sed -i '1,10d' "$HARD_POOL"

echo "Đã rút 15 câu không trùng lặp đưa vào $OUTPUT"
