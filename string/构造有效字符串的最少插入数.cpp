/*
构造有效字符串的最小插入数

给你一个字符串 word ，
你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，
返回使 word 有效 需要插入的最少字母数。

如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。

示例 1：

输入：word = "b"
输出：2
解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。
示例 2：

输入：word = "aaa"
输出：6
解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。
示例 3：

输入：word = "abc"
输出：0
解释：word 已经是有效字符串，不需要进行修改。


提示：
1 <= word.length <= 50
word 仅由字母 "a"、"b" 和 "c" 组成。
*/


#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int addMinimum(string word) {

        // 解题思路。
        // 对word做分段处理，每一段经过插入后成为"abc"；
        // 分段的依据是如果下个字母小于当前字母，则分出新的一段；
        // 分别统计每一段的插入此处，并累加。
        // 时间复杂度：O(n)
        // 空间复杂度：O(1)

        int n = word.size();
        int a = 0, b = 0, c = 0, i = 0, ans = 0;

        while (i < n)
        {
            // 记录当前段a/b/c分别是否出现
            if (word[i] == 'a') a = 1;
            if (word[i] == 'b') b = 1;
            if (word[i] == 'c') c = 1;

            // 如果已经是最后一个元素，结束当前段
            if (i == (n - 1)) {
                ans += (3 - a - b - c);
                break;
            }

            // 如果下个字母开始是新的段，结束当前段
            if (word[i] >= word[i + 1]) {
                ans += (3 - a - b - c);
                a = 0;
                b = 0;
                c = 0;
            }

            i++;
        }

        return ans;
    }
};


int main()
{   
    Solution solution;

    cout << solution.addMinimum("b") << endl;
    cout << solution.addMinimum("aaa") << endl;
    cout << solution.addMinimum("abc") << endl;

    return 0;
}
