/* LintCode 54 String to Integer II
 *
 * 实现atoi
 *
 * 注：
 * 1. 忽略空白字符
 * 2. 只考虑第一个正负号
 * 3. 若遇到非法字符，输出已转换好的答案（即非法字符之前的）
 *
 */

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int pre = 0;
        bool minus = false;
        long long ret = 0;
        while (pre < str.size() && isspace(str[pre])) {
            if (str[pre] == '-') minus = !minus;
            ++pre;
        }
        if (str[pre] == '-' || str[pre] == '+') {
            if (str[pre] == '-') minus = true;
            ++pre;
        }
        str = str.substr(pre);
        if (str.size() == 0) return 0;
        for (int k = 0; k < str.size(); ++k) {
            char c = str[k];
            if (isspace(c)) continue;
            if ('0' > c || c > '9') return minus ? -ret : ret;
            ret = ret * 10 + (c - '0');
            if (!minus && ret > INT_MAX) return INT_MAX;
            if (minus && -ret < INT_MIN) return INT_MIN;
        }
        return minus ? -ret : ret;
    }
};
