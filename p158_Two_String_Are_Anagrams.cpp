/*
 * LintCode 158 Two String Are Anagrams
 *
 * 判断两个字符串是否是颠倒字母顺序构成的
 * 
 * 如果两个字符串所含字母数不等时，则不是变位词
 * 令计数数组count[c]表示s中字母c出现的次数（不限大小写）与t中字母c出现的次数的差
 * 当存在某个count[c] < 0时，则不是变位词
 * 否则是变位词
 */

class Solution {
    public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        int count[26] {};
        int alpha = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') ++count[s[i]-'A'], ++alpha;
            if (s[i] >= 'a' && s[i] <= 'z') ++count[s[i]-'a'], ++alpha;
        }
        for (int i = 0; i < t.size(); ++i) {
            int k = -1;
            if (t[i] >= 'A' && t[i] <= 'Z') k = t[i] - 'A', --alpha;
            if (t[i] >= 'a' && t[i] <= 'z') k = t[i] - 'a', --alpha;
            if (k == -1) continue;
            if (count[k] == 0) return false;
            --count[k];
        }
        return alpha == 0;
    }
};
