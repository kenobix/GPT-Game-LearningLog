import * as readline from "readline";

const WORDS = [
  "cat", "dog", "tree", "book", "game",
  "quest", "robot", "apple", "music", "train"
];

function shuffle(str: string): string {
  const a = str.split("");
  for (let i = a.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [a[i], a[j]] = [a[j], a[i]];
  }
  return a.join("");
}

function makePuzzle(): { answer: string; puzzle: string } {
  const answer = WORDS[Math.floor(Math.random() * WORDS.length)];
  let puzzle = answer;
  // 同じ並びを避けるため最大10回シャッフル
  for (let k = 0; k < 10 && puzzle === answer; k++) {
    puzzle = shuffle(answer);
  }
  return { answer, puzzle };
}

function main() {
  console.log("Word Scramble (Lv1, TS). Type 'q' to quit.");

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  let wins = 0;
  let tries = 0;

  function ask() {
    const { answer, puzzle } = makePuzzle();
    rl.question(`> unscramble: ${puzzle} = `, (line) => {
      const s = line.trim().toLowerCase();
      if (s === "q" || s === "quit" || s === "exit") {
        const pct = tries > 0 ? (wins / tries) * 100 : 0;
        console.log(`bye! score: ${wins}/${tries} (${pct.toFixed(1)}%)`);
        rl.close();
        return;
      }
      tries++;
      if (s === answer) {
        wins++;
        console.log(`correct! (${answer})`);
      } else {
        console.log(`oops, answer = ${answer}`);
      }
      const pct = (wins / tries) * 100;
      console.log(`score: ${wins}/${tries} (${pct.toFixed(1)}%)`);
      ask();
    });
  }

  ask();
}

main();