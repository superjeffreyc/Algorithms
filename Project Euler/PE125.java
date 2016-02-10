import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class PE125 {

	public static void main(String[] args) throws IOException {
		int numCases = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		numCases = Integer.parseInt(br.readLine());
		String[] line = new String[numCases];
		int[][] lineParts = new int[numCases][2];

		for (int i = 0; i < numCases; i++) {
			line[i] = br.readLine();
			String[] parts = line[i].split("\\s+");
			lineParts[i][0] = Integer.parseInt(parts[0]);
			lineParts[i][1] = Integer.parseInt(parts[1]);
		}
		br.close();

		HashSet<String> set = new HashSet<>();
		int b = 0, j = 0, k = 0, d = 0, N = 0, max_n = 0, squareSum = 0;
		long totalSum = 0;
		String intStr = null;

		for (int i = 0; i < numCases; i++) {
			totalSum = 0;
			set.clear();

			N = lineParts[i][0];
			d = lineParts[i][1];

			max_n = (int) Math.sqrt(N);

			for (b = 1; b <= d; b++) {

				if (b + d > max_n) {
					break;
				}

				for (j = b; j <= max_n; j += d) {

					squareSum = j * j;

					if (squareSum >= N / 2) {
						break;
					}

					for (k = j + d; k <= max_n; k += d) {

						squareSum += k * k;

						if (squareSum >= N) {
							break;
						}

						if (squareSum % 10 == 0) {
							continue;
						}

						intStr = Integer.toString(squareSum);

						if (isPalindrome(intStr) && !set.contains(intStr)) {
							totalSum += squareSum;
							set.add(intStr);
						}

					}

				}
			}

			System.out.println(totalSum);
		}

	}

	public static boolean isPalindrome(String s) {
		int length = s.length();
		for (int i = 0; i < length / 2; i++) {
			if (s.charAt(length - 1 - i) != s.charAt(i)) {
				return false;
			}
		}
		return true;
	}

}