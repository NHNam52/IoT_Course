# code for IOT device

import bluetooth  #import bluez
import numpy as np
# create socket
server_sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
# define port
port = 1
# bind socket to port 1 
server_sock.bind(("",port))

# wait for client
server_sock.listen(1)

client_sock,address = server_sock.accept()
print ("Accepted connection from ",address)

while True:
    data = client_sock.recv(1024)
    if data.decode("utf-8") == "Temp":
        temp = np.random.randint(20,50)
        client_sock.send(temp)

client_sock.close()
server_sock.close()