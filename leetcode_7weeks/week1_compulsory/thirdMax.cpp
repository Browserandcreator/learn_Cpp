/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
*/

#include <set>
#include <vector>
#include <iterator> // 引入iterator头文件以使用std::advance
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // set为有序集合，自动去重并排序
        set<int> unique_nums;
        for (int num : nums) {
            unique_nums.insert(num);
        }
        if (unique_nums.size() < 3) {
            // 取出最右边即最大的数
            return *unique_nums.rbegin();
        }
        // it为迭代器，一开始指向超尾，即最后一位之后，前移三位后指向第三大的数
        auto it = unique_nums.end();
        advance(it, -3);
        return *it;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1};
    int result = s.thirdMax(nums);
    // 输出结果
    return 0;
}