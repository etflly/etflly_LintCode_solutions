/* LintCode 78 Longest Common Prefix
 *
 * 求若干字符串的最长公共前缀
 *
 * 暴力枚举
 *
 */

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        for (int k = 0; k < strs[0].size(); ++k) {
            char c = strs[0][k];
            for (int i = 1; i < strs.size(); ++i)
                if (strs[i][k] != c) return strs[0].substr(0, k);
        }
        return strs[0];
    }
};
