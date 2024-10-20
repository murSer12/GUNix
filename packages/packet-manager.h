using namespace std;

int warn_connect(){
    string ip = "104.26.14.72";
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cerr << "Socket creation error\n";
        return -1;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(80);

    if (inet_pton(AF_INET, ip.c_str(), &serverAddress.sin_addr) <= 0) {
       cout << "[FAILED] connect failed\n";
        cout << "[WARNING] if you see these message this means this ip adress is not supported!\n";    
        return -1;
    }
  if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
    cout << "[WARNING] You not connected to internet!\n";
    cout << "[WARNING] This project support only eth0!\n"; 
  }
  else {

   
    const char* message = "Hello, server!";
    if(send(clientSocket, message, strlen(message), 0) < 0){
        cout << "Message sending failed\n";
        return -1;
    }
    else { 
    cout << "[OK] Internet connected\n";
    cout << "[OK] Loading packet manager...\n";
    }

  }
    close(clientSocket);
    return 0; 
}
