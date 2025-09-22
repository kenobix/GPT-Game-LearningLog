using System;
using System.Linq;

static class Anagram
{
    // 英字のみ・小文字化してソート
    public static string Normalize(string s) =>
        new string(s.ToLowerInvariant().Where(char.IsLetter).OrderBy(c => c).ToArray());

    public static bool IsAnagram(string a, string b) => Normalize(a) == Normalize(b);
}

class Program
{
    static void Main()
    {
        Console.WriteLine("Anagram Duel (Lv1, C#). Type 'q' to quit.");
        int wins = 0, tries = 0;

        while (true)
        {
            Console.Write("> word A: ");
            var a = Console.ReadLine();
            if (a == null) break;
            a = a.Trim();
            if (a.Equals("q", StringComparison.OrdinalIgnoreCase) ||
                a.Equals("quit", StringComparison.OrdinalIgnoreCase) ||
                a.Equals("exit", StringComparison.OrdinalIgnoreCase))
            {
                break;
            }

            Console.Write("> word B: ");
            var b = Console.ReadLine();
            if (b == null) break;
            b = b.Trim();
            if (b.Equals("q", StringComparison.OrdinalIgnoreCase) ||
                b.Equals("quit", StringComparison.OrdinalIgnoreCase) ||
                b.Equals("exit", StringComparison.OrdinalIgnoreCase))
            {
                break;
            }

            tries++;
            if (Anagram.IsAnagram(a, b))
            {
                wins++;
                Console.WriteLine("anagram! ✅");
            }
            else
            {
                Console.WriteLine("not an anagram ❌");
            }
            var pct = tries > 0 ? (wins * 100.0 / tries) : 0.0;
            Console.WriteLine($"score: {wins}/{tries} ({pct:F1}%)");
        }

        Console.WriteLine("bye!");
    }
}