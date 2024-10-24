#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <mutex>
#include "arch/boot.h"
#include "kernel/sys-controller.h"


using namespace std;

int main(){
  system_load();
  warn_connect();
  return 0;
}
