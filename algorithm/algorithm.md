# 🚀 C++ `<algorithm>` 最常用 10 个函数小抄（含复杂度）

## 1. sort —— 排序
sort(v.begin(), v.end());                 // 升序  
sort(v.begin(), v.end(), greater<int>()); // 降序  
- 复杂度：O(n log n)

---

## 2. reverse —— 反转
reverse(v.begin(), v.end());  
- 复杂度：O(n)

---

## 3. max_element / min_element —— 最大值 & 最小值
auto it1 = max_element(v.begin(), v.end()); // 返回迭代器  
auto it2 = min_element(v.begin(), v.end());  
int maxVal = *it1;  
int minVal = *it2;  
- 复杂度：O(n)

---

## 4. binary_search —— 二分查找（序列必须已排序）
if (binary_search(v.begin(), v.end(), x)) {  
    cout << "found!";  
}  
- 复杂度：O(log n)

---

## 5. lower_bound / upper_bound —— 查找边界
auto it1 = lower_bound(v.begin(), v.end(), x); // 第一个 >= x  
auto it2 = upper_bound(v.begin(), v.end(), x); // 第一个 > x  
- 复杂度：O(log n)

---

## 6. unique —— 去重（需配合 erase）
sort(v.begin(), v.end());  
v.erase(unique(v.begin(), v.end()), v.end());  
- 复杂度：O(n)（去重部分，不含排序）

---

## 7. find —— 查找元素
auto it = find(v.begin(), v.end(), x);  
if (it != v.end()) cout << "found at " << distance(v.begin(), it);  
- 复杂度：O(n)

---

## 8. count —— 统计元素出现次数
int cnt = count(v.begin(), v.end(), x);  
- 复杂度：O(n)

---

## 9. all_of / any_of / none_of —— 条件判断
bool allPos = all_of(v.begin(), v.end(), [](int x){ return x > 0; });  
bool hasNeg = any_of(v.begin(), v.end(), [](int x){ return x < 0; });  
bool noZero = none_of(v.begin(), v.end(), [](int x){ return x == 0; });  
- 复杂度：O(n)

---

## 10. next_permutation —— 下一个排列
vector<int> v = {1, 2, 3};  
do {  
    for (int x : v) cout << x << " ";  
    cout << "\n";  
} while (next_permutation(v.begin(), v.end()));  
- 复杂度：O(n)

---

✅ **背熟这 10 个函数 + 复杂度，就能应付大多数算法题**
