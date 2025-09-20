# word-scramble  (07-lv1-word-scramble_ts)

## メタ情報
- **Date**: 2025-09-19
- **Language**: ts
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - `npm install`
  - `npm run build`
  - `npm start`

## プログラム概要
短い英単語をシャッフルして表示し、元の単語を当てるコンソールゲーム。`q` で終了し、勝率を表示。

## 今回の学習テーマ
- **アルゴリズム**: フィッシャー–イェーツでのシャッフル
- **言語機能**: 標準入出力（readline）、ループ制御、軽い入力検証

## 設計メモ（要点）
- 出題関数を毎回呼び出し、同一並びを避けるために最大10回まで再シャッフル
- スコアは都度表示（小数1桁）