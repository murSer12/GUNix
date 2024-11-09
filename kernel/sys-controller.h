#include <iostream>
#include <string>

using namespace std;

class User {
private:
    int password;
public:
    string username;
    bool isSelected = false;
    void create_user();
    bool isSelectedTest();
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

void terminal() {
    User user;

    while (true) {
        if (user.isSelectedTest()) {
            cout << user.username << "@gunix : ";
        } else {
            cout << "root@gunix : ";
        }

        string console;
        cin >> console;

        if (console == "exit") {
            cout << "Exiting...\n";
            break;
        } else if (console == "echo") {
            string echo;
            cout << "Write what you need to output: ";
            cin >> echo;
            cout << echo << endl;
        } else if (console == "create-user") {
            user.create_user();
        }
    }
}
