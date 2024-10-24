using namespace std;

bool wrong_root = false;
bool en = true;
bool have_user = false;
bool root_password_b = false;
string root_password = NULL;
bool user_password_b = false;
bool username_b = false; 
extern string username;
string user_password = NULL;
bool logined_user = false;

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

bool isLogined(){
  if(logined_user){
    return true;
  }
  else {
    return false;
  }
}

void terminal(){
  cout << "[OK] Terminal started!\n";
    if(choose_user){
    while (true){
    string input;
    cout << username + "@gunix : ";
    cin >> input;
    if(input == "exit"){
      exit(0);
    }
    else if(input == "language-show"){
      language_show();
    }
    else if(input == "language-set"){
      language_set();
    }
    else if(input == "passwd"){
      passwd();
    }
    else if(input == "create-user"){
      create_user();
    }
    else if(input == "choose-user"){
      choose_user();
    }
    else if(input == "show-user"){
      show_user();
    }
    else {
      cout << "Unknown command!\n";
    }
    }
    }
    else {

    }
}

void language_show(){
  cout << "Supports only English\n";
  cout << "Now language is English\n";
  cout << "Showing Languages...\n";
  cout << "en_US.UTF8\n";
  cout << "ru_RU.UTF8\n";
}

void language_set(){
  string language;
  cout << "Write language form language-show\n";
  cout << "> ";
  cin >> language;
  if(en){
    cout << "Language not changed (English already in system)\n";
  }
  else if(!en && language == "en_US.UTF8"){
    cout << "Changed language to English\n";
  }
  else {
    cout << "Cannot found language!\n";
  }
}

void passwd(){
  if(root_password_b == false){
    string root_password_test;
    cout << "\n";
    cout << "Write new password : ";
    cin >> root_password;
    cout << "\n";
    cout << "Retype password : ";
    cin >> root_password_test;
    if(root_password_test != root_password){
      while(true){
      cout << "Wrong password retype again!\n";
      cout << "\n";
      cout << "Retype password : ";
      cin >> root_password_test;
      if(root_password_test == root_password){
        root_password_b = true;
        cout << "Root password created\n";
      }
    }
  }
  else {
    cout << "Root already has password\n";
  }
}
}


void create_user(){
  if(username_b == false){
    cout << "\n";
    cout << "Write username : ";
    cin >> username;
    cout << "\n";
    string user_password_test;
    cout << "Write new password : ";
    cin >> user_password;
    cout << "\n";
    cout << "Retype password : ";
    cin >> user_password_test;
    if(user_password_test != user_password){
      while(true){
      cout << "Wrong password retype again!\n";
      cout << "\n";
      cout << "Retype password : ";
      cin >> user_password_test;
      if(user_password_test == user_password){
        username_b = true;
        user_password_b = true;
        cout << "User created\n";
      }
    }
    }
  }
}

void show_user(){
  cout << "Your user is : " + username + "\n";
}

bool choose_user(){
  string username_test;
  string user_password_test;
  cout << "\n";
  cout << "Write username : ";
  cin >> username_test;
  if(username_test == username){
    cout << "\n";
    cout << "Write user password : ";
    cin >> user_password_test;
    if(user_password_test == user_password){
      logined_user = true;
      cout << "Logined successfully";
    }
    else {
      while(true){
      cout << "Wrong password try again!\n";
      cout << "\n";
      cout << "Write user password : ";
      cin >> user_password_test;
      if(user_password_test == user_password){
        logined_user = true;
        cout << "Welcome , \n" + username;
        return true;
        break;
      }
      }
    }
  }
  else {
    while(true){
    cout << "Wrong username try again!\n";
    cout << "\n";
    cout << "Write username : ";
    cin >> username_test;
    if(username_test == username){
        logined_user = true;
        cout << "Welcome , \n" + username;
        break;
    }
    }
  }
}

