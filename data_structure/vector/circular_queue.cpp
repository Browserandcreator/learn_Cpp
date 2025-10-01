# include <iostream>
# include <vector>

class MyCircularQueue {
private:
    std::vector<int> data; // 存储队列元素的数组
    int front; // 队头指针
    int rear;  // 队尾指针
    int maxSize; // 队列最大容量
    
public:
    MyCircularQueue(int k) {
        maxSize = k;
        front = 0;
        rear = 0;
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % maxSize;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % maxSize;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + maxSize) % maxSize];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
};

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    std::cout << obj->enQueue(1) << std::endl; // 返回 true
    std::cout << obj->enQueue(2) << std::endl; // 返回 true
    std::cout << obj->enQueue(3) << std::endl; // 返回 true
    std::cout << obj->enQueue(4) << std::endl; // 返回 false，队列已满
    std::cout << obj->Rear() << std::endl;     // 返回 3
    std::cout << obj->isFull() << std::endl;   // 返回 true
    std::cout << obj->deQueue() << std::endl;  // 返回 true
    std::cout << obj->enQueue(4) << std::endl; // 返回 true
    std::cout << obj->Rear() << std::endl;     // 返回 4
    delete obj;
    return 0;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */