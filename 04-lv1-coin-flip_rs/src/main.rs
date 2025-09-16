use std::io::{self, Write};
use std::time::{SystemTime, UNIX_EPOCH};

struct XorShift64 {
    state: u64,
}
impl XorShift64 {
    fn new(seed: u64) -> Self {
        // seed が 0 のときの固定値（適当な奇数）
        let s = if seed == 0 { 0x9E37_79B9_7F4A_7C15 } else { seed };
        Self { state: s }
    }
    fn next_u64(&mut self) -> u64 {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x
    }
    fn next_bool(&mut self) -> bool {
        (self.next_u64() & 1) == 1
    }
}

fn main() {
    println!("Coin Flip (heads/tails). Type 'q' to quit");

    // 時刻からシード生成
    let nanos = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap()
        .as_nanos() as u64;
    let mut rng = XorShift64::new(nanos);

    let mut wins: u32 = 0;
    let mut tries: u32 = 0;

    loop {
        print!("> guess (h/t): ");
        io::stdout().flush().ok();

        let mut s = String::new();
        if io::stdin().read_line(&mut s).is_err() {
            println!("bye!");
            break;
        }
        let g = s.trim().to_lowercase();
        if g == "q" || g == "quit" || g == "exit" {
            println!("bye! score: {}/{} ({:.1}%)",
                     wins, tries,
                     if tries > 0 { wins as f64 / tries as f64 * 100.0 } else { 0.0 });
            break;
        }

        let guess = match g.as_str() {
            "h" | "head" | "heads" => Some(true),
            "t" | "tail" | "tails" => Some(false),
            _ => None,
        };
        if guess.is_none() {
            println!("please type 'h' (heads), 't' (tails) or 'q' to quit");
            continue;
        }

        let is_heads = rng.next_bool();
        let actual = if is_heads { "heads" } else { "tails" };
        let correct = (guess.unwrap() && is_heads) || (!guess.unwrap() && !is_heads);

        tries += 1;
        if correct {
            wins += 1;
            println!("you: {} / coin: {} -> WIN", g, actual);
        } else {
            println!("you: {} / coin: {} -> LOSE", g, actual);
        }
        let pct = wins as f64 / tries as f64 * 100.0;
        println!("score: {}/{} ({:.1}%)", wins, tries, pct);
    }
}