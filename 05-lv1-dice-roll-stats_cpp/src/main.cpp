#include <iostream>
#include <string>
#include <random>
#include <array>
#include <iomanip>

// Dice Roll Stats (1..6) - Lv1
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout << "Dice Roll Stats (1-6). Type q to quit.\n";

  std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(1, 6);

  std::string s;
  while (true) {
    std::cout << "How many rolls? (1..100000): " << std::flush;
    if (!std::getline(std::cin, s)) break;
    if (s == "q" || s == "quit" || s == "exit") {
      std::cout << "bye!\n";
      break;
    }

    try {
      int n = std::stoi(s);
      if (n < 1 || n > 100000) {
        std::cout << "type 1..100000\n";
        continue;
      }

      std::array<int, 7> cnt{}; // 1..6 を使用
      for (int i = 0; i < n; ++i) {
        int d = dist(rng);
        ++cnt[d];
      }

      std::cout << "\nface  count   percent  histogram\n";
      for (int face = 1; face <= 6; ++face) {
        double pct = 100.0 * cnt[face] / n;
        int bars = static_cast<int>(pct / 2.0 + 0.5); // 50バー=100%
        std::cout << "  " << face << "   "
                  << std::setw(6) << cnt[face] << "   "
                  << std::fixed << std::setprecision(1)
                  << std::setw(6) << pct << "%  "
                  << std::string(bars, '#') << "\n";
      }
      std::cout << "\n";
    } catch (...) {
      std::cout << "please type a number or q\n";
    }
  }
  return 0;
}