#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    // 使用两个指针，一个不断自增，代表不同数的个数
    // 另一个遇到重复的就++，将后面的数组元素传给前面
    // j >= i，优先考虑j的边界
        if (nums.empty()) return 0;

        int i = 0;
        for ( int j = 1; j < nums.size(); j++) {
            if ( nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    Solution s;
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int len = s.removeDuplicates(v);
    for (int i = 0; i < len; i++) {
        cout << v[i] << ", ";
    }
    cout << "\n";
}