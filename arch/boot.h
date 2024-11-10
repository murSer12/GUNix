using namespace std;

bool warn_connect(){
    string ip = "104.26.14.72";
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cerr << "Socket creation error\n";
        return false;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(80);

    if (inet_pton(AF_INET, ip.c_str(), &serverAddress.sin_addr) <= 0) {
       cout << "[FAILED] connect failed\n";
        cout << "[WARNING] if you see these message this means this ip adress is not supported!\n";
        return false;
    }
  if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
    cout << "[FAILED] Cannot connect to Internet!\n";
    cout << "[WARNING] This project support only eth0 or wlan0!\n";
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
    return true;
}

int system_load(){
	cout << "[PROCCESS] Loading system...\n";
	bool load = warn_connect();
	if(load == false){
       cout << "[CRITICAL ERROR] Cannot load system!\n";
       cout << "Rebooting!\n";
       exit(0);
	}
	else {
		cout << "[OK] System loaded\n";
	}
	return 0;
}
