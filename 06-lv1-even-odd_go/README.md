# even-odd  (06-lv1-even-odd_go)

## メタ情報
- **Date**: 2025-09-17
- **Language**: go
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - Run  : `go run src/main.go`
  - Build: `go build -o bin/even-odd src/main.go` → `./bin/even-odd`

## プログラム概要
1〜100の乱数の偶奇（even/odd）を当てるコンソールゲーム。`e`/`o`/`q` を受け付け、勝率を表示。

## 今回の学習テーマ
- **アルゴリズム**: 偶奇判定とスコア計算
- **言語機能**: 標準入出力（バッファリング＆明示的フラッシュ）、乱数（時刻シード）、文字列処理

## 設計メモ（要点）
- `bufio.NewWriter` + `Flush()` でプロンプトを即時表示
- 入力は小文字化して `e|even` / `o|odd` / `q|quit|exit` を許容