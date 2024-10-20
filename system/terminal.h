using namespace std;

void terminal(){
  cout << "[OK] Terminal started!\n";
  while(true){
    string input;
    cout << "root@gunix : ";
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
    else {
      cout << "Unknown command!\n";
    }
  }
}
