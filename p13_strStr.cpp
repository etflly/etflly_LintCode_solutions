/* LintCode 13 strStr
 *
 * 给定字符串source，target，求target在source中首次出现的位置
 *
 * 暴力枚举，或者KMP
 *
 */

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) return -1;
        if (strlen(target) == 0) return 0;
        for (int i = 0; i < strlen(source); ++i) {
            bool flag = true;
            for (int j = 0; j < strlen(target); ++j)
                if (source[i+j] != target[j]) {
                    flag = false;
                    break;
                }
            if (flag) return i;
        }
        return -1;
    }
};
