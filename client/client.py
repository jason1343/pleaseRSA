from socket import *
import threading, gmpy2, pickle

def send(sock):
    while True:
        encryptedL = []

        Message = list(input(""))
        
        for M in Message:
            encryptedL.append(gmpy2.powmod(ord(M), E, N))
        
        data = pickle.dumps(encryptedL)
        
        sock.sendall(data)
    
def receive(sock):
    while True:
        data = sock.recv(4096)
        data = pickle.loads(data)

        if data :
            decryptedL = []
            decryptedL2 = []
            
            for En in data:
                decryptedL.append(gmpy2.powmod(En, D, N))
                
            for de in decryptedL:
                decryptedL2.append(chr(de))

            dataDecrypted = "".join(decryptedL2)
            
            print('\n상대방 : ' + dataDecrypted + '\n')
        else : pass

port = int(input("port : "))
clientSock = socket(AF_INET, SOCK_STREAM)
#clientSock.connect(('15.165.19.31', port))
clientSock.connect(('127.0.0.1', port))
print('연결 확인 됐습니다.')

##D, N을 전달받아야함
E = int(clientSock.recv(1024).decode('utf-8'))
D = int(clientSock.recv(1024).decode('utf-8'))
N = int(clientSock.recv(1024).decode('utf-8'))

sender = threading.Thread(target=send, args=(clientSock,))
receiver = threading.Thread(target=receive, args=(clientSock,))

sender.start()
receiver.start()

# while True:
#     time.sleep(1)
#     pass