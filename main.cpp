#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <mutex>
#include "system/boot.h"
#include "system/terminal.h"
#include "packages/packet-manager.h"

using namespace std;

int main(){
  system_load();
  warn_connect();
  terminal();
  return 0;
}
