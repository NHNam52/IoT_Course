#code for central device


import bluetooth
from time import sleep

bd_addr = "01:23:45:67:89:AB"  # server's MAC address
port = 1
sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
# ask for connecton
sock.connect((bd_addr, port))
# send and receive data
while True:
    sock.send("Temp")
    data = sock.recv(1024)
    print(data)
    sleep(2)

sock.close()