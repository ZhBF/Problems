/*
力扣题库第39题：组合总和。

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
并以列表形式返回。
你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。
如果至少一个数字的被选数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的不同组合数少于 150 个。



示例 1：

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []


提示：

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
candidates 的所有元素 互不相同
1 <= target <= 40
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:

    // 解题思路如下。
    // 设问题 P(nums, i, t) 为nums的前i个数可组合出t的列表，
    // 原问题等价于 P(candidates, candidates.size(), target)，
    // 问题可递归，P(nums, i, t) = P(nums, i-1, t - nums[i] * j), j=0..t/nums[i]
    // 边界问题 P(nums, 1, t) 可直接求解。

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum(candidates, candidates.size(), target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int n, int target) {
        vector<vector<int>> answers, sub_answers;
        vector<int> ans;

        if (n == 0) {
            return answers;
        }

        if (n == 1) {
            if (target % candidates[0] == 0) {
                ans.insert(ans.end(), target / candidates[0], candidates[0]);
                answers.push_back(ans);
            }
            return answers;
        }
        
        for (int i = 0; candidates[n-1] * i <= target; i++) {
            sub_answers = combinationSum(candidates, n - 1, target - i * candidates[n - 1]);
            for (int j = 0; j < sub_answers.size(); j++) {
                sub_answers[j].insert(sub_answers[j].end(), i, candidates[n - 1]);
            }
            answers.insert(answers.end(), sub_answers.begin(), sub_answers.end());
        }
        
        return answers;
    }
};


template <typename T> ostream& operator<<(ostream& os, const vector<T>& vec) {
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

    vector<int> candidates1 = { 2,3,6,7 };
    vector<int> candidates2 = { 2,3,5 };
    vector<int> candidates3 = { 2 };

    vector<vector<int>> ans1, ans2, ans3;

    ans1 = solution.combinationSum(candidates1, 7);
    ans2 = solution.combinationSum(candidates2, 8);
    ans3 = solution.combinationSum(candidates3, 1);

    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;

    return 0;
}
