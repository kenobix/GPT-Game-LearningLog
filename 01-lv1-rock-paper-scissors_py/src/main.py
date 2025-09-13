import random

CHOICES = ["rock", "paper", "scissors"]

def judge(p: str, c: str) -> str:
    if p == c:
        return "draw"
    wins = {("rock", "scissors"), ("scissors", "paper"), ("paper", "rock")}
    return "win" if (p, c) in wins else "lose"

def main():
    print("Rock-Paper-Scissors (rock/paper/scissors, or 'q' to quit)")
    while True:
        p = input("> ").strip().lower()
        if p in ("q", "quit", "exit"):
            print("bye!")
            break
        if p not in CHOICES:
            print("Please type: rock / paper / scissors")
            continue
        c = random.choice(CHOICES)
        result = judge(p, c)
        print(f"you: {p}, cpu: {c} -> {result}")

if __name__ == "__main__":
    main()
