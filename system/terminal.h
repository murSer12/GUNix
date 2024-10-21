using namespace std;

bool isUser = false;

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
