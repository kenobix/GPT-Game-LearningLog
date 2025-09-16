# coin-flip  (04-lv1-coin-flip_rs)

## メタ情報
- **Date**: 2025-09-16
- **Language**: rs
- **Level**: Lv1
- **Environment**: WSL Ubuntu 22.04 / Windows 11
- **How to Run**:
  - Build: `mkdir -p bin && rustc src/main.rs -O -o bin/coin-flip`
  - Run  : `./bin/coin-flip`

## プログラム概要
コインの表裏（heads/tails）を当てるコンソールゲーム。入力は `h` / `t`（`q` で終了）。勝率を逐次表示。

## 今回の学習テーマ
- **アルゴリズム**: 乱数での二値選択・簡易スコアリング
- **言語機能**: 標準入出力、文字列処理、ループ、時刻由来シード
- **補足**: クレート不要にするため、簡易な XorShift64 で乱数を生成

## 設計メモ（要点）
- プロンプトを `print!` + `flush()` で明示的にフラッシュ
- 入力バリデーション：`h/t/q` 以外はリトライ（試行回数には数えない）
- 勝率は `wins / tries * 100` を小数1桁で表示

## 実行例
```

Coin Flip (heads/tails). Type 'q' to quit

> guess (h/t): h
> you: h / coin: tails -> LOSE
> score: 0/1 (0.0%)
> guess (h/t): t
> you: t / coin: tails -> WIN
> score: 1/2 (50.0%)
> guess (h/t): q
> bye! score: 1/2 (50.0%)

```

## GPT活用の要点
- **日時**: 2025-09-16
- **相談内容**: Lv1向けの最小構成・外部クレート無しの乱数
- **役立った回答の要旨**: XorShiftの採用と入出力の最小パターン
- **採用/却下した提案**: Cargo 初期化は今回は見送り（単一ファイル運用）

## 参考
- なし