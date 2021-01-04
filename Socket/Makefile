CFLAGS=-g 
LDFLAGS=-g 

EXE=BroadcastReceiver BroadcastSender MulticastReceiver MulticastSender sclient SigAction sniffer sortclient sortserverP sserver sserverP TCPEchoClient TCPEchoServer TCPEchoServer-Fork TCPEchoServer-ForkN TCPEchoServer-Fork-SIGCHLD TCPEchoServer-Select UDPEchoClient UDPEchoClient-Timeout UDPEchoServer UDPEchoServer-SIGIO sniffer rawethsnd rawethrcv

all: $(EXE)

clean:
	rm -f $(EXE) *.o

TCPEchoServer:TCPEchoServer.o HandleTCPClient.o DieWithError.o 

TCPEchoClient:TCPEchoClient.o DieWithError.o 

TCPEchoServer-Fork:TCPEchoServer-Fork.o AcceptTCPConnection.o CreateTCPServerSocket.o HandleTCPClient.o DieWithError.o 

TCPEchoServer-Fork-SIGCHLD:TCPEchoServer-Fork-SIGCHLD.o AcceptTCPConnection.o CreateTCPServerSocket.o HandleTCPClient.o DieWithError.o 

TCPEchoServer-ForkN:TCPEchoServer-ForkN.o AcceptTCPConnection.o CreateTCPServerSocket.o HandleTCPClient.o DieWithError.o 

TCPEchoServer-Select:TCPEchoServer-Select.o AcceptTCPConnection.o CreateTCPServerSocket.o HandleTCPClient.o DieWithError.o 

UDPEchoClient:UDPEchoClient.o DieWithError.o 

UDPEchoClient-Timeout:UDPEchoClient-Timeout.o DieWithError.o 

UDPEchoServer:UDPEchoServer.o DieWithError.o 

UDPEchoServer-SIGIO:UDPEchoServer-SIGIO.o DieWithError.o 

sserver:sserver.o 

sserverP:sserverP.o 

sortclient:sortclient.o 

sortclient:sortclient.o 

sortclient:sortclient.o 

sortserverP:sortserverP.o 

sortserverP:sortserverP.o 

sclient:sclient.o 

sclient:sclient.o 

SigAction:SigAction.o DieWithError.o 

MulticastReceiver:MulticastReceiver.o DieWithError.o 

MulticastSender:MulticastSender.o DieWithError.o 

sniffer:sniffer.o 

BroadcastSender:BroadcastSender.o DieWithError.o 

BroadcastReceiver:BroadcastReceiver.o DieWithError.o 

rawethsnd: raw.o

rawethrcv: raw.o
