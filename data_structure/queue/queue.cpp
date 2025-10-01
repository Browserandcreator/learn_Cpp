#include <iostream>
#include <queue> // 引入队列头文件

int main() {
    // 标准库命名空间的queue容器
    std::queue<int> q; // 创建一个存储 int 的队列

    // 入队操作，注意在队尾入队
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "队列的大小: " << q.size() << std::endl;

    // 访问队首元素
    if (!q.empty()) {
        std::cout << "队首元素: " << q.front() << std::endl;
    }

    // 出队操作
    q.pop();
    std::cout << "出队一个元素后，新的队首: " << q.front() << std::endl;

    // 访问队尾元素
    std::cout << "队尾元素: " << q.back() << std::endl;

    // 清空队列
    while (!q.empty()) {
        std::cout << "出队元素: " << q.front() << std::endl;
        q.pop();
    }

    std::cout << "队列是否为空: " << (q.empty() ? "是" : "否") << std::endl;

    return 0;
}