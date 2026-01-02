#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <mutex>
using namespace std;

struct WebRequest {
    int id;
    int priority; 
    
    WebRequest(int i, int p) : id(i), priority(p) {}
};

class OptimizedWebQueue {
private:
    vector<WebRequest> queue;
    int capacity;
    mutex mtx;  
    
    void resize() {
        capacity *= 2;
        queue.reserve(capacity);
    }
    
public:
    OptimizedWebQueue(int initialCapacity = 16) : capacity(initialCapacity) {
        queue.reserve(initialCapacity);
    }
    
    void enqueue(int id, int priority) {
        lock_guard<mutex> lock(mtx);
        
        if (queue.size() >= static_cast<size_t>(capacity)) {
            resize();
        }
        
        queue.emplace_back(id, priority);
        cout << "Enqueued request ID: " << id << " with priority: " << priority << endl;
    }
    
    bool dequeue() {
        lock_guard<mutex> lock(mtx);
        
        if (queue.empty()) {
            cout << "Queue is empty" << endl;
            return false;
        }
        
        WebRequest req = queue.front();
        queue.erase(queue.begin());
        cout << "Processed request ID: " << req.id << " with priority: " << req.priority << endl;
        return true;
    }
    
    void peek() {
        lock_guard<mutex> lock(mtx);
        if (queue.empty()) {
            cout << "Queue is empty" << endl;
        } else {
            WebRequest req = queue.front();
            cout << "Front request ID: " << req.id << " with priority: " << req.priority << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore();  // Clear newline
    
    OptimizedWebQueue webQueue;
    
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        
        if (line.empty()) continue;
        
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        
        if (cmd == "enqueue") {
            int id, priority;
            ss >> id >> priority;
            webQueue.enqueue(id, priority);
        }
        else if (cmd == "dequeue") {
            webQueue.dequeue();
        }
        else if (cmd == "peek") {
            webQueue.peek();
        }
    }
    
    return 0;
}
