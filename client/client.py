from socket import *
import threading, re, gmpy2

def send(sock):
    while True:
        encryptedL = []

        Message = list(input(""))
        
        for M in Message:
            encryptedL.append(gmpy2.powmod(ord(M), E, N))
            
        sock.send(str(encryptedL).encode('utf-8'))
    
def receive(sock):
    while True:
        data = sock.recv(1024).decode('utf-8')
        if data :
            decryptedL = []
            decryptedL2 = []
            
            dataL = [int(match.group(1)) for match in re.finditer(r'mpz\((\d+)\)', data)]
            for En in dataL:
                decryptedL.append(gmpy2.powmod(En, D, N))
                
            for de in decryptedL:
                decryptedL2.append(chr(de))

            dataDecrypted = "".join(decryptedL2)
            
            print('\n상대방 : ' + dataDecrypted + '\n')
        else : pass

port = int(input("port : "))
clientSock = socket(AF_INET, SOCK_STREAM)
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