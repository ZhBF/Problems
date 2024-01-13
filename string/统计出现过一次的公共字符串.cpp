/*
力扣题库第2085题：统计出现过一次的公共字符串。

给你两个字符串数组 words1 和 words2 ，
请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。


示例 1：

输入：words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
输出：2
解释：
- "leetcode" 在两个数组中都恰好出现一次，计入答案。
- "amazing" 在两个数组中都恰好出现一次，计入答案。
- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
所以，有 2 个字符串在两个数组中都恰好出现了一次。

示例 2：

输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
输出：0
解释：没有字符串在两个数组中都恰好出现一次。

示例 3：

输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
输出：1
解释：唯一在两个数组中都出现一次的字符串是 "ab" 。


提示：

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] 和 words2[j] 都只包含小写英文字母。
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {

        // 解题思路如下。
        // 分别记录两个列表中各字符串的出现次数，并找到符合条件的进行计数。
        // 使用哈希表存储，以提高查找效率。
        // 找第二个列表时只关注第一个列表中满足次数条件的。

        unordered_map<string, int> umap1, umap2;
        int ans = 0;

        // 记录第一个列表中各个字符串的出现次数。
        for (auto& s : words1) {
            if (umap1.find(s) == umap1.end()) umap1[s] = 1;
            else umap1[s] += 1;
        }
        
        // 记录第二个列表中在第一个列表中出现一次的字符串的出现次数。
        for (auto& s : words2) {
            if (umap1.find(s) != umap1.end() && umap1[s] == 1) {
                if (umap2.find(s) == umap2.end()) umap2[s] = 1;
                else umap2[s] += 1;
            }
        }

        // 计数满足条件的字符串数量。
        for (auto& kv : umap2) {
            if (kv.second == 1) ans++;
        }
        
        return ans;
    }
};


int main()
{   
    Solution solution;

    vector<string> word11 = { "leetcode", "is", "amazing", "as", "is" };
    vector<string> word12 = { "amazing", "leetcode", "is" };
    vector<string> word21 = { "b", "bb", "bbb" };
    vector<string> word22 = { "a", "aa", "aaa" };
    vector<string> word31 = { "a", "ab" };
    vector<string> word32 = { "a", "a", "a", "ab" };

    cout << solution.countWords(word11, word12) << endl;
    cout << solution.countWords(word21, word22) << endl;
    cout << solution.countWords(word31, word32) << endl;

    return 0;
}
