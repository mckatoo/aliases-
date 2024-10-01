#include <iostream>
#include <string>

using namespace std;

void addCommand(const string &name, const string &command) {
  string alias = "alias " + name + "=\"" + command + "\"\n";
  cout << alias << endl;
  exit(0);
}
