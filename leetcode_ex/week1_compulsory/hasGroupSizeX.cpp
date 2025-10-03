/*
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/leetcamp-3-plus/vhcvng/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <numeric> // std::gcd
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // 统计每个数字的出现次数
        unordered_map<int, int> count;
        for (int card : deck) {
            count[card]++;
        }
        // 计算所有出现次数的GCD
        int gcd = 0;
        // 此处循环过程中将pair解构为num和cnt
        for (const auto& [num, cnt] : count) {
            gcd = std::gcd(gcd, cnt);
        }
        // 只有当GCD大于等于2时，才能分组
        return gcd >= 2;
    }
};
int main() {
    Solution s;
    vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
    cout << s.hasGroupsSizeX(deck) << endl;  // 输出结果
    return 0;
}