# anagram-duel  (09-lv1-anagram-duel_cs)

## メタ情報
- **Date**: 2025-09-21
- **Language**: csharp
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - Build: `dotnet build -c Release`
  - Run  : `dotnet run --project . -c Release`

## プログラム概要
2つの単語 A/B が **アナグラム**（同じ文字集合の並べ替え）かを判定するコンソールゲーム。  
英字のみ・大小区別なし・空白や記号は無視。`q` で終了し、正答/試行のスコアを表示。

## 今回の学習テーマ
- **アルゴリズム**: 正規化（前処理）→ソート比較で同一性判定
- **言語機能**: 文字列処理、LINQ（`Where`/`OrderBy`）、ループと条件分岐、標準入出力

## 設計メモ（要点）
- `Normalize()` で英字のみ抽出→小文字化→ソートして比較を単純化
- スコア表示で学習効果（反復）を可視化