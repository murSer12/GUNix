using namespace std;

int system_load(){
	cout << "Loading system...\n";
	int load = 1;
	if(load == 0){
	   char true_false;
       cout << "Recreate system load? [Y/n] : ";
       cin >> true_false;
       if(true_false == 'Y'){
         cout << "[PROCCESS] Loading Bytes...\n";
         cout << "[OK] Loaded Byte\n";
         cout << "Reload system!\n";
         exit(0);
       }

	}
	else {
		cout << "[OK] System loaded\n";
	}
	int socfd = socket(AF_INET , SOCK_STREAM , 0);
	if(socfd < 0){
		cout << "[FAILED] connected 0\n";
		cout << "[FAILED] Failed to create socket\n";
		exit(0);
	}
	else {
		cout << "[OK] Socket creating \n";
		cout << "[OK] Socket created!\n";
	}

	return 0;
}
