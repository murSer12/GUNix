using namespace std;

int system_load(){
	cout << "Loading system...\n";
	int critical_load = 1;
	if(critical_load == 0){
       cout << "[CRITICAL ERROR] Cannot load system!\n";
       cout << "Rebooting!\n";
       exit(0);
	}
	else {
		cout << "[OK] System loaded\n";
	}
	delete critical_load;

	return 0;
	
}
