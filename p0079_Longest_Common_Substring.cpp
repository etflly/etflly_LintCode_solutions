/* LintCode 79 Longest Common Substring
 *
 * 求两字符串的最长公共字串（字串是连续的，子序列可以不连续）
 *
 * d[i][j]表示以A[i], B[j]结尾的最长公共子序列
 * d[i][j] = 0 (A[i] != B[j])
 *           1 (A[i] == B[j] && (i == 0 || j == 0))
 *           d[i-1][j-1]+1 (o.w.)
 *
 */

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int ret = 0;
        vector<vector<int>> d(A.size(), vector<int>(B.size(), 0));
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j])
                    if (i == 0 || j == 0) d[i][j] = 1;
                    else d[i][j] = d[i-1][j-1] + 1;
                ret = max(ret, d[i][j]);
            }
        return ret;
    }
};
