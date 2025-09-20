# dice-roll-stats  (05-lv1-dice-roll-stats_cpp)

## メタ情報
- **Date**: 2025-09-17
- **Language**: cpp
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - Build: `g++ -std=c++17 -O2 -Wall -Wextra src/main.cpp -o bin/dice-roll-stats`
  - Run  : `./bin/dice-roll-stats`

## プログラム概要
サイコロを指定回数（1〜100000）振り、各目（1〜6）の出現回数と割合を表示。ヒストグラムを簡易表示。`q` で終了。

## 今回の学習テーマ
- **アルゴリズム**: 乱数生成・頻度集計・パーセンテージ表示
- **言語機能**: 標準入出力、例外処理、ループ、`<random>`、整形出力

## 設計メモ（要点）
- `std::mt19937` + `std::uniform_int_distribution<int>` で 1..6 の乱数
- 入力検証：範囲外や非数値は再入力を促す
- プロンプトは `<< std::flush` で即表示

## 実行例
```

Dice Roll Stats (1-6). Type q to quit.
How many rolls? (1..100000): 20

face  count   percent  histogram
1        5    25.0%  #############
2        2    10.0%  #####
3        5    25.0%  #############
4        4    20.0%  ##########
5        3    15.0%  #######
6        1     5.0%  ###

```

## GPT活用の要点
- **日時**: 2025-09-16
- **相談内容**: Lv1向けの最小構成・ヒストグラムの出力・入出力の安定化
- **役立った回答の要旨**: `<random>` の使い方とプロンプトのフラッシュ