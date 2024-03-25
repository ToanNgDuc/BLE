import socket
import numpy as np
import re
import math

HOST = '192.168.66.42'  # Địa chỉ IP của máy tính chạy server
PORT = 8050

# Tạo socket server
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen(1)

print('Waiting for connection...')

# Chấp nhận kết nối từ client ESP32
client_socket, addr = server_socket.accept()
print('Connected to:', addr)

# Nhận dữ liệu từ client socket
data = client_socket.recv(32)

# Chuyển đổi dữ liệu thành chuỗi
data_str = data.decode('utf-8')

# Tìm kiếm các giá trị số trong chuỗi dữ liệu
data_stream = re.findall(r'\d+', data_str)
data_stream = np.array([int(num) for num in data_stream])


# Đóng client socket và server socket
client_socket.close()
server_socket.close()