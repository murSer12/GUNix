#include <iostream>
#include <string>

using namespace std;

class Root {
private:
  int password;
public:
  void create_root_pass();
};

void Root::create_root_pass(){
  cout << "Write password superuser (Integer type only!): ";
  cin >> password;
  cout << "Password created! : " << password << endl;
}

class User {
private:
    int password;
public:
    string username;
    bool isSelected = false;
    void create_user();
    bool isSelectedTest();
    bool writePassword();
};

void User::create_user() {
    int selectUser;
    cout << "Write username: ";
    cin >> username;
    cout << "Write password (Integer type only!): ";
    cin >> password;
    cout << "Do you want to select the user just created?\n";
    cout << "1 - Yes\n";
    cout << "2 - No\n";
    cin >> selectUser;
    if (selectUser == 1) {
        isSelected = true;
        cout << "User selected!\n";
    } else if (selectUser == 2) {
        isSelected = false;
        cout << "User not selected!\n";
    }
    cout << "User created!\n";
}

bool User::isSelectedTest() {
    return isSelected;
}

bool User::writePassword(){
  bool isPass;
  int attempts = 3;
  int user_pass;
  cout << "Write user password : ";
  cin >> user_pass;
  isPass = user_pass == password;
  if(isPass){
    return true;
  }
  else {
     while(user_pass != password){
       --attempts;
       int user_pass_again;
       cout << "Wrong password try again (you have " << attempts << " attempts)\n\n";
       cout << "Write user password : ";
       cin >> user_pass_again;
       if(attempts == 0){
         return false;
         break;
       }
       else{
         return true;
         break;
       }
     }
  }
}

void terminal() {
    bool userSel = false;
    bool canRoot = true;
    User user;
    Root root;
    string help[3][2] = {
      {"exit","Exit from gunix!"},
      {"echo","Show something in console"},
      {"create-user","Create user!"}
    };
    while (true) {
        if (user.isSelectedTest()) {
            userSel = true;
            canRoot = false;
            cout << user.username << "@gunix : ";
        } else {
            userSel = false;
            canRoot = true;
            cout << "root@gunix : ";
        }
        string console;
        cin >> console;

        if(userSel){
          bool isPass = user.writePassword();
          if(isPass){
            cout << "Starting operation...\n";
          }
          else {
            cout << "Wrong password exiting!";
            break;
          }
        }
        if (console == "exit") {
            cout << "Exiting...\n";
            break;
        } else if (console == "echo") {
            string echo;
            cout << "Write what you need to output: ";
            cin >> echo;
            cout << echo << endl;
        } else if (console == "create-user") {
            if(canRoot){
              user.create_user();
            }
            else {
              cout << "Only super user can do this operation!\n\n";
            }
        } else if (console == "help"){
          for(int i = 0; i < 3 ; ++i){
            for(int j = 0; j < 2 ; ++j){
              cout << help[i][j] << "\t" << endl;
            }
          }
        } else if (console == "passwd"){
          if(canRoot){
            root.create_root_pass();
          }
          else {
            cout << "Only super user can do this operation!\n\n";
          }
        }
    }
}
