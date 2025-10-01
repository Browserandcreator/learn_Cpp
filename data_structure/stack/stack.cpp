#include <iostream>
#include <stack> // 引入栈的头文件

int main() {
    std::stack<int> s; // 创建一个存储 int 的栈

    // 入栈操作
    s.push(100);
    s.push(200);
    s.push(300);

    std::cout << "栈的大小: " << s.size() << std::endl;

    // 访问栈顶元素
    if (!s.empty()) {
        std::cout << "栈顶元素: " << s.top() << std::endl;
    }

    // 出栈操作
    s.pop();
    std::cout << "出栈一个元素后，新的栈顶: " << s.top() << std::endl;

    // 清空栈
    while (!s.empty()) {
        std::cout << "出栈元素: " << s.top() << std::endl;
        s.pop();
    }

    std::cout << "栈是否为空: " << (s.empty() ? "是" : "否") << std::endl;

    return 0;
}