#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << "Number Guessing (1-100). Type q to quit.\n";
  srand((unsigned)time(nullptr));
  int target = rand() % 100 + 1;

  string s;
  while (true) {
    cout << "> ";
    if (!getline(cin, s)) break;
    if (s=="q" || s=="quit" || s=="exit") { cout << "bye!\n"; break; }

    try {
      int x = stoi(s);
      if (x < 1 || x > 100) { cout << "type 1..100\n"; continue; }
      if (x == target) { cout << "correct!\n"; break; }
      cout << (x < target ? "higher\n" : "lower\n");
    } catch (...) {
      cout << "please type a number or q\n";
    }
  }
  return 0;
}
