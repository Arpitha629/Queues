#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class AntiFragmentationQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;
    
public:
    AntiFragmentationQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    
    ~AntiFragmentationQueue() {
        delete[] arr;
    }
    
    bool enqueue(int id) {
        if (count == capacity) {
            cout << "Queue is full" << endl;
            return false;
        }
        
       
        rear = (rear + 1) % capacity;
        arr[rear] = id;
        count++;
        cout << "Enqueued request ID: " << id << endl;
        return true;
    }
    
    bool dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return false;
        }
        
        cout << "Processed request ID: " << arr[front] << endl;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    int size() {
        return count;
    }
    
    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        int temp = front;
        for (int i = 0; i < count; i++) {
            cout << arr[temp];
            if (i < count - 1) cout << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int N, capacity;
    cin >> N >> capacity;
    cin.ignore(); 
    
    AntiFragmentationQueue queue(capacity);
    
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        if (line.empty()) continue;
        
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        
        if (cmd == "enqueue") {
            int id;
            ss >> id;
            queue.enqueue(id);
        }
        else if (cmd == "dequeue") {
            queue.dequeue();
        }
        else if (cmd == "size") {
            cout << "Current queue size: " << queue.size() << endl;
        }
        else if (cmd == "display") {
            queue.display();
        }
    }
    
    return 0;
}
