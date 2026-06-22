#!/bin/bash

clear
echo "=========================================================="
echo "         HỆ THỐNG SAO LƯU DỮ LIỆU TỰ ĐỘNG (TAR)           "
echo "=========================================================="
echo "Đang tiến hành quét hệ thống và đóng gói dữ liệu..."

# Tạo thư mục chứa các bản sao lưu nếu chưa có
mkdir -p backups

# Lấy ngày giờ hiện tại làm tên file (Ví dụ: backup_22-06-2026.tar.gz)
BACKUP_NAME="backups/backup_$(date +%d-%m-%Y_%H-%M-%S).tar.gz"

# Tiến hành nén thư mục data và images
tar -czf "$BACKUP_NAME" data images 2>/dev/null

if [ $? -eq 0 ]; then
    echo "🎉 SAO LƯU THÀNH CÔNG!"
    echo "📦 File sao lưu đã được lưu tại: $BACKUP_NAME"
    echo "📂 Danh sách các bản sao lưu hiện có trong máy:"
    ls -lh backups
else
    echo "❌ Lỗi: Quá trình sao lưu thất bại!"
fi
echo "=========================================================="
echo -n "Nhấn Enter để quay lại..."
read
