# GPT-Game-LearningLog

A personal learning log of programming and algorithms through game development with ChatGPT.  
各プロジェクトで新しい言語機能やアルゴリズムを小さく学び、実装・振り返り・記録までを一気通貫で行います。

---

## Purpose
- ゲーム制作を通じて、**言語機能**・**アルゴリズム**・**設計**を段階的に学習する
- 1プロジェクト＝1言語/1テーマ（移植はしない）
- 学習ログを重視（各プロジェクト README に学習テーマ/GPT活用を記録）

## Policy
- **無償ツール / WSL + Windows** を基本とする
- 迷ったら最小構成（後から拡張）
- コミットは小さく、PRでまとめて説明
- 実行方法（How to Run）を必ず README に明記

## Environment
- Windows 11 + WSL2 (Ubuntu 22.04)
- Git / GitHub
- 言語: Python, C++, Rust など（プロジェクトごとに固定）

## Naming
`NN-lvX-slug_lang`  
例: `01-lv1-rock-paper-scissors_py`, `02-lv1-number-guessing_cpp`

## Level Criteria
- **Lv1**: 標準入出力／基本制御構文
- **Lv2**: 関数分割・モジュール化／例外処理
- **Lv3**: データ構造（配列/連想/集合）・簡易アルゴリズム
- **Lv4**: 設計（テスト・I/O分離）・外部入出力
- **Lv5**: 小さなアーキテクチャ／アルゴリズム最適化

---

## Project Index & Status

| #  | Project (Dir)                              | Lang | Level | Status                 | Verified (Local) | Notes |
|----|-------------------------------------------|------|-------|------------------------|------------------|-------|
| 01 | **rock-paper-scissors** (`01-lv1-..._py`) | py   | Lv1   | ✅ Done (run verified) | 2025-09-13       | `python3 src/main.py` |
| 02 | **number-guessing** (`02-lv1-..._cpp`)    | cpp  | Lv1   | ✅ Done (run verified) | 2025-09-14       | `g++ ... -o bin/number-guessing && ./bin/number-guessing` |

> 詳細な実行手順や学習メモは各プロジェクト配下の `README.md` を参照。

---

## How to add a project

1. ひな形作成（スクリプト）
   ```bash
   ./scripts/new_project.sh <NN> <LV> <slug> <lang>
   # 例: ./scripts/new_project.sh 3 1 hangman rs
    ```

2. `src/` に実装 → `README.md`（テンプレ）を埋める
3. 動作確認（最低限の入出力）
4. ブランチを push → PR 作成 → セルフレビュー → Merge → ブランチ削除

### Commit / Branch

* Prefix: `feat`, `fix`, `docs`, `chore`, `ci`
* 例: `feat(rps): add 01-lv1-rock-paper-scissors (Lv1, Python)`
* 既定ブランチは `main`。機能追加は `feat/<NN-slug>` を切る

---

## CI

* GitHub Actions（`on: push, pull_request`）で簡易スモークを実行（徐々に各言語のビルド/実行を追加予定）

---

## Repo Layout (excerpt)

```
.
├─ 01-lv1-rock-paper-scissors_py/
│   ├─ src/main.py
│   └─ README.md
├─ 02-lv1-number-guessing_cpp/
│   ├─ src/main.cpp
│   └─ README.md
├─ TEMPLATES/
│   └─ project-readme.md
├─ scripts/
│   └─ new_project.sh
└─ .github/
    └─ workflows/ci.yml
```

## Roadmap (Lv1 フォーカス)

* 03: **math-quiz**（Python, Lv1）— 四則演算の出題と採点（分岐/ループ/入出力）
* 04: **coin-flip**（Rust, Lv1）— 乱数と入力、勝率表示（基礎I/O）
* 05: **dice-roll-stats**（C++, Lv1）— サイコロを複数回振って頻度集計（ループ）
* 06: **mad-libs**（Python, Lv1）— 文字列入力とテンプレ埋め（文字列操作）
* 07: **prime-quiz**（Rust, Lv1）— 素数かどうかを当てるクイズ（条件分岐）

## License

MIT