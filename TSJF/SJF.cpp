#include "SJF.hpp"

void SJF::Schedule() {
    int currentTime = 0;
    SortProcessQueue();
    queue<Process*> ready_queue;
    Process* p;
    while (!processQueue.empty() || !ready_queue.empty()) {
        ready_filler(ready_queue, currentTime, true);
        p = GetMinReady(ready_queue, Process::cmp_burst);
        if (currentTime < p->arrivalTime) {
            currentTime = p->arrivalTime;
        }
        p->completionTime = currentTime + p->burstTime;
        p->waitingTime = p->completionTime - p->arrivalTime - p->burstTime;
        p->turnaroundTime = p->completionTime - p->arrivalTime;
        currentTime = p->completionTime;
        processOrder.push_back({p->pid, p->burstTime});
    }
}
