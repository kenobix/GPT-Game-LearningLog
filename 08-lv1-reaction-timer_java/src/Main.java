import java.io.*;
import java.util.Random;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);
    out.println("Reaction Timer (Lv1, Java). Type 'q' to quit.");

    Random rnd = new Random();
    boolean testMode = "1".equals(System.getenv("RT_TEST")); // CI向け

    while (true) {
      out.print("> press Enter when ready (q to quit): ");
      out.flush();
      String line = br.readLine();
      if (line == null) break;
      line = line.trim().toLowerCase();
      if (line.equals("q") || line.equals("quit") || line.equals("exit")) {
        out.println("bye!");
        break;
      }

      long delayMs = testMode ? 0 : 1500 + rnd.nextInt(2000); // 1.5〜3.5秒
      if (!testMode) out.println("...wait for it...");
      Thread.sleep(delayMs);

      out.println("GO!");
      long t0 = System.nanoTime();
      br.readLine();                 // Enter を待つ
      long t1 = System.nanoTime();
      double ms = (t1 - t0) / 1_000_000.0;
      out.printf("time: %.1f ms%n", ms);
    }
  }
}