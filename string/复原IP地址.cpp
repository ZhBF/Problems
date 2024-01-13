/*
力扣题库第93题：复原IP地址。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），
整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，
但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，
返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。


示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]

示例 2：

输入：s = "0000"
输出：["0.0.0.0"]

示例 3：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        // 解题思路如下。
        // 将 i, j, k 分别指向IP地址中的分隔符，
        // 遍历分隔符的可能位置，并将符合条件的加入列表。
        
        vector<string> answers;
        string str1, str2, str3, str4;
        size_t i, j, k, n = s.size();
        int num;

        // 如果s中包含少于4个数字，则不可能是有效IP。
        if (n < 4) return answers;

        // 将 i, j, k 分别指向IP地址中的分隔符的前一个字符。
        for (size_t i = 0; i < n - 3; i++) {
            
            // 如果i之前的数字有前导零，则退出。
            if (i > 0 && s[0] == '0') break;
            
            // 如果i之前的数字大于255，则退出。
            str1 = s.substr(0, i + 1);
            if (! strIn_0_255(str1)) break;

            for (size_t j = i + 1; j < n - 2; j++) {

                // 如果ij之间的数字有前导零，则退出
                if (j - i > 1 && s[i + 1] == '0') break;

                // 如果ij之间的数字大于255，则退出
                str2 = s.substr(i + 1, j - i);
                if (! strIn_0_255(str2)) break;

                for (size_t k = j + 1; k < n - 1; k++) {

                    // 如果jk之间的数字有前导零，则退出
                    if (k - j > 1 && s[j + 1] == '0') break;
                    
                    // 如果jk之间的数字大于255，则退出
                    str3 = s.substr(j + 1, k - j);
                    if (!strIn_0_255(str3)) break;

                    // 如果k之后的数字有前导零，则跳过
                    if (n - k - 1 > 1 && s[k + 1] == '0') continue;

                    // 如果k之后的数字小于等于255，则记录
                    str4 = s.substr(k + 1, n - k - 1);
                    if (strIn_0_255(str4)) {
                        answers.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                    }
                }
            }
        }
        return answers;
    }

    // 函数：strIn_0_255
    // 功能：判断一个仅由数字组成的字符串是否在0-255之间。
    bool strIn_0_255(const string& s) {
        size_t n = s.size();
        if (n < 3) return true;
        if (n > 3) return false;
        if (s[0] < '2') return true;
        if (s[0] > '2') return false;
        if (s[1] < '5') return true;
        if (s[1] > '5') return false;
        if (s[2] <= '5') return true;
        else return false;
    }
};


// 重载 vector 的 << 运算符。
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        if (i == 0) os << vec[i];
        else os << ", " << vec[i];
    }
    os << "]";
    return os;
}


int main()
{   
    Solution solution;

    string s1 = "25525511135";
    string s2 = "0000";
    string s3 = "101023";
    string s4 = "0279245587303";

    cout << solution.restoreIpAddresses(s1) << endl;
    cout << solution.restoreIpAddresses(s2) << endl;
    cout << solution.restoreIpAddresses(s3) << endl;
    cout << solution.restoreIpAddresses(s4) << endl;

    return 0;
}
