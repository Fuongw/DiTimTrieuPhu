#!/bin/bash

clear
echo "=========================================================="
echo "           HỆ THỐNG DỌN DẸP KHÔNG GIAN LÀM VIỆC           "
echo "=========================================================="
echo "Đang quét và tiêu hủy các file rác do Qt sinh ra..."

# 1. Gọi lệnh dọn dẹp mặc định của hệ thống build
make clean > /dev/null 2>&1

# 2. Xóa triệt để các file tàn dư còn sót lại (File .o, file cấu trúc giao diện ui_, file meta moc_)
rm -f *.o moc_* ui_* Makefile .qmake.stash

# 3. Xóa cả file chạy game cũ để lát build lại bản mới nhất cho sạch
rm -f DiTimTrieuPhu_UI

echo "✅ DỌN DẸP HOÀN TẤT!"
echo "Thư mục dự án của bạn đã trở lại trạng thái nguyên thủy sạch sẽ."
echo "=========================================================="
echo -n "👉 Nhấn Enter để quay lại Menu..."
read
