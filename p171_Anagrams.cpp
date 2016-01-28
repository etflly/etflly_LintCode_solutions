/* LintCode 171 Anagrams
 *
 * 给定一个字符串数组，求其中是其他字符串的变位词的串
 *
 * 对每个字符串内部排序，维护map
 *
 */

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        map<string, int> hash;
        vector<string> ret;
        hash.clear();
        ret.clear();
        for (int i = 0 ; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (hash.count(s)) {
                if (hash[s] != -1) {
                    ret.push_back(strs[hash[s]]);
                    hash[s] = -1;
                }
                ret.push_back(strs[i]);
            }
            else hash[s] = i;
        }
        return ret;
    }
};
