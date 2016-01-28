/* LintCode 55 Compare Strings
 *
 * 判断字符串A是否包含了B中所有字母，其中AB均由大写字母构成
 *
 * 令cnt[c]为字符c在A中的个数与在B中的个数的差
 * 若存在cnt[c]<0，则false
 * 否则true
 */

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int cnt[26] {};
        for (int i = 0; i < A.size(); ++i) ++cnt[A[i]-'A'];
        for (int i = 0; i < B.size(); ++i) {
            if (cnt[B[i]-'A'] == 0) return false;
            --cnt[B[i]-'A'];
        }
        return true;
    }
};
