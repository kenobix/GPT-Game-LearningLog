cat > 02-lv1-number-guessing_cpp/README.md <<'MD'
# number-guessing  (02-lv1-number-guessing_cpp)

## メタ情報
- **Date**: 2025-09-14
- **Language**: cpp
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - Build: `g++ -std=c++17 -O2 -Wall -Wextra src/main.cpp -o bin/number-guessing`
  - Run : `./bin/number-guessing`

## プログラム概要
1〜100のランダムな整数を当てるコンソールゲーム。数値を入力して範囲を絞り、`q` で終了。

## 今回の学習テーマ
- **アルゴリズム**: 二分探索的絞り込みの思考（higher/lower フィードバック）
- **言語機能**: 標準入出力、文字列→数値変換（`stoi`）、例外処理、乱数

## 設計メモ（要点）
- 例外で非数値入力をハンドリング
- 入力検証（1..100）を明示
- 終了コマンド `q/quit/exit` を受け付ける

## GPT活用の要点
- **日時**: 2025-09-14
- **相談内容**: 雛形、README 体裁、ブランチ運用
- **役立った回答の要旨**: ひな型スクリプトと最小CI
- **採用/却下した提案**: CIのC++拡張は次回対応

## 参考
- なし
MD