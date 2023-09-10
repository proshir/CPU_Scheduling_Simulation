#include "FCFS.hpp"
#include <iostream>

void FCFS::Schedule() {
    int currentTime = 0;
    SortProcessQueue();
    while (!processQueue.empty()) {
        Process* p = processQueue.front();
        processQueue.pop();
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

