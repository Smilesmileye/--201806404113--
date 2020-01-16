public class LongestCommonSubsequence {
	int lcs(char[] X, char[] Y, int m, int n) {
		int L[][] = new int[m + 1][n + 1];
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 || j == 0)
					L[i][j] = 0;
				else if (X[i - 1] == Y[j - 1])
					L[i][j] = L[i - 1][j - 1] + 1;
				else
					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
		return L[m][n];
	}
	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	public static void main(String[] args) {
		LongestCommonSubsequence lcs = new LongestCommonSubsequence();
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter string-1:");
		String s1 = input.next();
		System.out.println("Please enter string-2:");
		String s2 = input.next();
		char[] X = s1.toCharArray();
		char[] Y = s2.toCharArray();
		int m = X.length;
		int n = Y.length;
		System.out.println("Result:");
		System.out.println("	公共最长子序列为" + " " + lcs.lcs(X, Y, m, n));
	}
}
