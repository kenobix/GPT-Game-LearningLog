#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout << "Number Guessing (1-100). Type q to quit.\n";
  std::srand((unsigned)std::time(nullptr));
  const int target = std::rand() % 100 + 1;

  std::string s;
  while (true) {
    std::cout << "> " << std::flush;        // ← ここが重要（都度フラッシュ）
    if (!std::getline(std::cin, s)) break;

    if (s == "q" || s == "quit" || s == "exit") {
      std::cout << "bye!\n";
      break;
    }

    try {
      int x = std::stoi(s);
      if (x < 1 || x > 100) {
        std::cout << "type 1..100\n";
        continue;
      }
      if (x == target) {
        std::cout << "correct!\n";
        break;
      }
      std::cout << (x < target ? "higher\n" : "lower\n");
    } catch (...) {
      std::cout << "please type a number or q\n";
    }
  }
  return 0;
}
