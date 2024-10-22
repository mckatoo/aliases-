#include "add_command.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void help() {
  cout << "Cli to manage aliases\n"
          "\n";
  exit(0);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    help();
    return 0;
  }

  string command = argv[1];
  cout << command << "\n";

  if (command == "add" || command == "a") {
    addCommand("l", "ls");
  }

  return 0;
}
