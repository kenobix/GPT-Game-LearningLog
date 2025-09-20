package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strings"
	"time"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	fmt.Fprintln(out, "Even/Odd Guess (1-100). Type 'q' to quit.")
	rng := rand.New(rand.NewSource(time.Now().UnixNano()))

	wins, tries := 0, 0

	for {
		n := rng.Intn(100) + 1
		fmt.Fprint(out, "> guess (e/o): ")
		out.Flush()

		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(strings.ToLower(line))

		if line == "q" || line == "quit" || line == "exit" {
			pct := 0.0
			if tries > 0 {
				pct = float64(wins) / float64(tries) * 100.0
			}
			fmt.Fprintf(out, "bye! score: %d/%d (%.1f%%)\n", wins, tries, pct)
			return
		}

		valid := true
		guessEven := false
		switch line {
		case "e", "even":
			guessEven = true
		case "o", "odd":
			guessEven = false
		default:
			valid = false
		}
		if !valid {
			fmt.Fprintln(out, "please type 'e' (even), 'o' (odd) or 'q'")
			continue
		}

		isEven := (n % 2) == 0
		tries++
		actual := map[bool]string{true: "even", false: "odd"}[isEven]

		if (guessEven && isEven) || (!guessEven && !isEven) {
			wins++
			fmt.Fprintf(out, "n=%d -> %s : WIN\n", n, actual)
		} else {
			fmt.Fprintf(out, "n=%d -> %s : LOSE\n", n, actual)
		}
		fmt.Fprintf(out, "score: %d/%d (%.1f%%)\n", wins, tries, float64(wins)/float64(tries)*100.0)
	}
}