import random

OPS = [
    ("+", lambda a, b: a + b),
    ("-", lambda a, b: a - b),
    ("*", lambda a, b: a * b),
]


def make_question():
    op, fn = random.choice(OPS)
    if op == "+":
        a, b = random.randint(0, 20), random.randint(0, 20)
    elif op == "-":
        a = random.randint(0, 20)
        b = random.randint(0, a)  # 負の答えを避ける
    else:  # "*"
        a, b = random.randint(0, 12), random.randint(0, 12)
    return a, op, b, fn(a, b)


def main():
    print("Math Quiz (Lv1)  - type 'q' to quit")
    score = 0
    asked = 0

    while True:
        a, op, b, ans = make_question()
        while True:
            s = input(f"{a} {op} {b} = ").strip().lower()
            if s in ("q", "quit", "exit"):
                print(f"bye! score: {score}/{asked}")
                return
            # 数値判定（負数も許可：-10 等）
            if s.lstrip("-").isdigit():
                asked += 1
                if int(s) == ans:
                    print("correct!")
                    score += 1
                else:
                    print(f"oops, answer = {ans}")
                break
            else:
                print("please type a number or 'q' to quit")


if __name__ == "__main__":
    main()
