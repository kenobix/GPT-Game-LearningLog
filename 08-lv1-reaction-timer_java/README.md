# reaction-timer  (08-lv1-reaction-timer_java)

## メタ情報
- **Date**: 2025-09-19
- **Language**: java
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - Build: `javac -encoding UTF-8 -d bin src/Main.java`
  - Run  : `java -cp bin Main`

## プログラム概要
合図「GO!」が出てから Enter を押すまでの反応時間を計測するコンソールアプリ。`q` で終了。

## 今回の学習テーマ
- **アルゴリズム**: 時間計測（`System.nanoTime()`）
- **言語機能**: 標準入出力、ループ、例外処理、`Thread.sleep`

## 設計メモ（要点）
- ランダム遅延（1.5〜3.5秒）後に「GO!」を表示
- CI 簡易スモーク用に `RT_TEST=1` で遅延を 0ms にできるフラグを用意