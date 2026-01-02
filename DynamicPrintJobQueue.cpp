#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct PrintJob {
    string jobId;
    int priority;
    
    PrintJob(string id, int prio) : jobId(id), priority(prio) {}
};

class DynamicPrintQueue {
private:
    vector<PrintJob> queue;
    
public:
    DynamicPrintQueue() {}
    
    bool addJob(string jobId, int priority) {
        queue.push_back(PrintJob(jobId, priority));
        cout << "Added: Job ID: " << jobId << ", Priority: " << priority << endl;
        return true;
    }
    
    void processJobs() {
        if (queue.empty()) {
            return;
        }
        
        cout << "Processing print jobs:" << endl;
        for (auto it = queue.begin(); it != queue.end(); ++it) {
            cout << "Processing Job ID: " << it->jobId 
                 << ", Priority: " << it->priority << endl;
        }
        queue.clear();
    }
    
    int queueSize() {
        return queue.size();
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); 
    
    DynamicPrintQueue printQueue;
    
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        if (line.empty()) continue;
        
        stringstream ss(line);
        string token;
        ss >> token;
        
        if (token == "add_job") {
            string jobId;
            int priority;
            ss >> jobId >> priority;
            printQueue.addJob(jobId, priority);
        }
        else if (token == "process_jobs") {
            printQueue.processJobs();
        }
        else if (token == "queue_size") {
            cout << "Current queue size: " << printQueue.queueSize() << endl;
        }
    }
    
    return 0;
}
